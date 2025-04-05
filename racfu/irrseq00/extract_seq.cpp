#include "extract_seq.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <cstring>

#include "logger.hpp"
#include "messages.h"

// Use htonl() to convert 32-bit values from little endian to big endian.
// use ntohl() to convert 16-bit values from big endian to little endian.
// On z/OS these macros do nothing since "network order" and z/Architecture are
// both big endian. This is only necessary for unit testing off platform.
#define _POSIX_C_SOURCE 200112L
#include <arpa/inet.h>

char *extract_seq(
    const char *profile_name,  // Required for everything except setropts
    const char *class_name,    // Only required for general resource profile
    uint8_t function_code,     // Always required
    char **raw_request,        // Always required
    int *raw_request_length,   // Always required
    racfu_return_codes_t *return_codes,  // Always required,
    Logger *logger_p) {
  uint32_t rc;

  char *result_buffer;

  /*************************************************************************/
  /* Setropts Extract                                                      */
  /*************************************************************************/
  if (function_code == SETROPTS_EXTRACT_FUNCTION_CODE) {
    // Build 31-bit Arg Area
    setropts_extract_underbar_arg_area_t *arg_area_setropts;
    arg_area_setropts = build_setropts_extract_parms();
    if (arg_area_setropts == NULL) {
      return NULL;
    }
    // Preserve the raw request data
    *raw_request_length = (int)sizeof(setropts_extract_underbar_arg_area_t);
    logger_p->debug(
        MSG_REQUEST_SEQ_SETROPTS,
        logger_p->cast_hex_string(reinterpret_cast<char *>(arg_area_setropts),
                                  *raw_request_length));

    preserve_raw_request(reinterpret_cast<char *>(arg_area_setropts),
                         raw_request, raw_request_length);

    logger_p->debug(MSG_CALLING_SEQ);

    // Call R_Admin
    rc = callRadmin(
        reinterpret_cast<char *__ptr32>(&arg_area_setropts->arg_pointers));
    logger_p->debug(MSG_DONE);

    result_buffer = arg_area_setropts->args.pResult_buffer;
    // Preserve Return & Reason Codes
    return_codes->saf_return_code  = ntohl(arg_area_setropts->args.SAF_rc);
    return_codes->racf_return_code = ntohl(arg_area_setropts->args.RACF_rc);
    return_codes->racf_reason_code = ntohl(arg_area_setropts->args.RACF_rsn);
    // Free Arg Area
    free(arg_area_setropts);
  }
  /***************************************************************************/
  /* Generic Extract                                                         */
  /*                                                                         */
  /* Use For:                                                                */
  /*   - User Extract                                                        */
  /*   - Group Extract                                                       */
  /*   - Group Connection Extract                                            */
  /*   - Resource Extract                                                    */
  /*   - Data Set Extract                                                    */
  /***************************************************************************/
  else {
    // Build 31-bit Arg Area
    generic_extract_underbar_arg_area_t *arg_area_generic;
    arg_area_generic =
        build_generic_extract_parms(profile_name, class_name, function_code);
    if (arg_area_generic == NULL) {
      return NULL;
    }
    // Preserve the raw request data
    *raw_request_length = (int)sizeof(generic_extract_underbar_arg_area_t);
    logger_p->debug(
        MSG_REQUEST_SEQ_GENERIC,
        logger_p->cast_hex_string(reinterpret_cast<char *>(arg_area_generic),
                                  *raw_request_length));

    preserve_raw_request(reinterpret_cast<char *>(arg_area_generic),
                         raw_request, raw_request_length);
    logger_p->debug(MSG_CALLING_SEQ);

    // Call R_Admin
    rc = callRadmin(
        reinterpret_cast<char *__ptr32>(&arg_area_generic->arg_pointers));
    logger_p->debug(MSG_DONE);

    result_buffer = arg_area_generic->args.pResult_buffer;
    // Preserve Return & Reason Codes
    return_codes->saf_return_code  = ntohl(arg_area_generic->args.SAF_rc);
    return_codes->racf_return_code = ntohl(arg_area_generic->args.RACF_rc);
    return_codes->racf_reason_code = ntohl(arg_area_generic->args.RACF_rsn);
    // Free Arg Area
    free(arg_area_generic);
  }

  // Check Return Codes
  if (return_codes->saf_return_code != 0 ||
      return_codes->racf_return_code != 0 ||
      return_codes->racf_reason_code != 0 || rc != 0) {
    // Free Result Buffer & Return 'NULL' if not successful.
    free(result_buffer);
    return NULL;
  }

  // Return Result if Successful
  return result_buffer;
}

generic_extract_underbar_arg_area_t *build_generic_extract_parms(
    const char *profile_name,  // Required always.
    const char *class_name,    // Required only for resource extract.
    uint8_t function_code      // Required always.
) {
  int profile_name_length;
  if (profile_name != NULL) {
    profile_name_length = strlen(profile_name);
  }
  int class_name_length;
  if (class_name != NULL) {
    class_name_length = strlen(class_name);
  }

  /***************************************************************************/
  /* Allocate 31-bit Area For IRRSEQ00 Parameters/Arguments                  */
  /***************************************************************************/
  generic_extract_underbar_arg_area_t *arg_area;
  arg_area = reinterpret_cast<generic_extract_underbar_arg_area_t *>(
      __malloc31(sizeof(generic_extract_underbar_arg_area_t)));
  if (arg_area == NULL) {
    perror(
        "Fatal - Unable to allocate space in 31-bit storage "
        "for 'generic_extract_underbar_arg_area_t'.\n");
    return NULL;
  }
  // Make sure buffer is clear.
  memset(arg_area, 0, sizeof(generic_extract_underbar_arg_area_t));

  generic_extract_args_t *args                 = &arg_area->args;
  generic_extract_arg_pointers_t *arg_pointers = &arg_area->arg_pointers;
  generic_extract_parms_results_t *profile_extract_parms =
      &args->profile_extract_parms;

  /***************************************************************************/
  /* Set Extract Arguments                                                   */
  /***************************************************************************/
  SET_COMMON_ARGS
  args->function_code = function_code;

  // Copy profile name and class name.
  memcpy(args->profile_name, profile_name, profile_name_length);
  // Encode profile name as IBM-1047.
  __a2e_l(args->profile_name, profile_name_length);
  if (class_name != NULL) {
    // Class name must be padded with blanks.
    memset(&profile_extract_parms->class_name, ' ', 8);
    memcpy(profile_extract_parms->class_name, class_name, class_name_length);
    // Encode class name as IBM-1047.
    __a2e_l(profile_extract_parms->class_name, class_name_length);
  }
  profile_extract_parms->profile_name_length = htonl(profile_name_length);

  /***************************************************************************/
  /* Set Extract Argument Pointers                                           */
  /*                                                                         */
  /* Enable transition from 64-bit XPLINK to 31-bit OSLINK.                  */
  /***************************************************************************/
  SET_COMMON_ARG_POINTERS
  arg_pointers->pProfile_extract_parms = profile_extract_parms;

  return arg_area;
}

setropts_extract_underbar_arg_area_t *build_setropts_extract_parms() {
  /***************************************************************************/
  /* Allocate 31-bit Area For IRRSEQ00 Parameters/Arguments                  */
  /***************************************************************************/
  setropts_extract_underbar_arg_area_t *arg_area;
  arg_area = reinterpret_cast<setropts_extract_underbar_arg_area_t *>(
      __malloc31(sizeof(setropts_extract_underbar_arg_area_t)));
  if (arg_area == NULL) {
    perror(
        "Fatal - Unable to allocate space in 31-bit storage "
        "for 'setropts_extract_underbar_arg_area_t'.\n");
    return NULL;
  }
  // Make sure buffer is clear.
  memset(arg_area, 0, sizeof(setropts_extract_underbar_arg_area_t));

  setropts_extract_args_t *args                 = &arg_area->args;
  setropts_extract_arg_pointers_t *arg_pointers = &arg_area->arg_pointers;
  setropts_extract_parms_t *setropts_extract_parms =
      &args->setropts_extract_parms;

  /***************************************************************************/
  /* Set Extract Arguments                                                   */
  /***************************************************************************/
  SET_COMMON_ARGS
  args->function_code = SETROPTS_EXTRACT_FUNCTION_CODE;

  /***************************************************************************/
  /* Set Extract Argument Pointers                                           */
  /*                                                                         */
  /* Enable transition from 64-bit XPLINK to 31-bit OSLINK.                  */
  /***************************************************************************/
  SET_COMMON_ARG_POINTERS
  arg_pointers->pSetropts_extract_parms = setropts_extract_parms;

  return arg_area;
}

void preserve_raw_request(const char *arg_area, char **raw_request,
                          const int *raw_request_length) {
  *raw_request = static_cast<char *>(calloc(*raw_request_length, sizeof(char)));
  if (*raw_request == NULL) {
    perror(
        "Warn - Unable to allocate space to preserve the "
        "raw request for profile extract.\n");
    return;
  }
  memcpy(*raw_request, arg_area, *raw_request_length);
}
