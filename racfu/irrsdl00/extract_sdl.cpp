#include "extract_sdl.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <cstring>

#include "irrsdl00.hpp"

char *extract_sdl(
    const char *profile_name,  // Required for everything
    const char *racf_user_id,  // Required for everything
    uint8_t function_code,     // Always required
    char **raw_request,        // Always required
    int *raw_request_length,   // Always required
    racfu_return_codes_t *return_codes_p,  // Always required,
    Logger *logger_p) {
  keyring_extract_parms_results_t *results = (keyring_extract_parms_results_t*) calloc(1, sizeof(keyring_extract_parms_results_t));

  /*************************************************************************/
  /* Invoke IRRSDL64 for GetRingInfo function                              */
  /*************************************************************************/
  if (function_code == KEYRING_EXTRACT_FUNCTION_CODE) {
    keyring_extract_arg_area_t *arg_area_keyring;
    arg_area_keyring = build_keyring_extract_parms(profile_name, racf_user_id);
    if (arg_area_keyring == NULL) {
      return NULL;
    }
    *raw_request_length = (int)sizeof(keyring_extract_arg_area_t);
    logger_p->debug(
        MSG_REQUEST_SDL_KEYRING,
        logger_p->cast_hex_string((char*) arg_area_keyring, *raw_request_length));
      
    preserve_raw_request((char*) arg_area_keyring, raw_request, raw_request_length);

    logger_p->debug(MSG_CALLING_SDL);

    results->result_buffer = (cddlx_get_ring_t*) extract_keyring(arg_area_keyring, return_codes_p, logger_p);

    logger_p->debug(MSG_DONE);

    // Preserve Return & Reason Codes
    return_codes_p->saf_return_code  = arg_area_keyring->args.SAF_rc;
    return_codes_p->racf_return_code = arg_area_keyring->args.RACF_rc;
    return_codes_p->racf_reason_code = arg_area_keyring->args.RACF_rsn;

    if (results->result_buffer != NULL) {
      results->result_buffer_length = sizeof(cddlx_get_ring_t);

      if (return_codes_p->saf_return_code <= 4 &&
          return_codes_p->racf_return_code <= 4 &&
          return_codes_p->racf_reason_code == 0) {
        // Calculate buffer length
        int nRingCount = ((ring_result_t*) ((cddlx_get_ring_t*) results->result_buffer)->cddlx_ring_res_ptr)->ring_count;
        logger_p->debug("Ring count", logger_p->cast_hex_string((char*) &nRingCount, 4));
        char *work = &((ring_result_t*) ((cddlx_get_ring_t*) results->result_buffer)->cddlx_ring_res_ptr)->ring_info;
        logger_p->debug("Ring info", logger_p->cast_hex_string(work, 16));
        int nLen = 0;

        for (int i = 0; i < nRingCount; i++) {
          // Count ring owner
          nLen += 1 + *work;
          work += 1 + *work;

          // Count ring name
          nLen += 1 + *work;
          work += 1 + *work;

          logger_p->debug("Parsing ring info", logger_p->cast_hex_string(work, 16));

          // Count cert count
          nLen += 4;
          unsigned int certCount = *((unsigned int*) work);
          work += 4;

          for (int j = 0; j < certCount; j++) {
            // Count cert owner
            nLen += 1 + *work;
            work += 1 + *work;

            // Count cert name
            nLen += 1 + *work;
            work += 1 + *work;
          }
        }

        results->ring_info_length = nLen;
      }
    }

    // Free Arg Area
    free(arg_area_keyring);
  }

  // Check Return Codes
  if (return_codes_p->saf_return_code > 4 ||
      return_codes_p->racf_return_code > 4 ||
      return_codes_p->racf_reason_code != 0) {
    // Free Result Buffer & Return 'NULL' if not successful.
    if (results != NULL) {
      if (results->result_buffer->cddlx_ring_res_ptr != NULL) {
        free(results->result_buffer->cddlx_ring_res_ptr);
      }
      free(results);
      results = NULL;
    }
  }

  // Return Result if Successful
  return (char*) results;
}

keyring_extract_arg_area_t *build_keyring_extract_parms(
    const char *profile_name,
    const char *racf_user_id) {
  int profile_name_length;
  if (profile_name != NULL) {
    profile_name_length = strlen(profile_name);
  }
  int racf_user_id_length;
  if (racf_user_id != NULL) {
    racf_user_id_length = strlen(racf_user_id);
  }
  
  keyring_extract_arg_area_t *arg_area_keyring;
  arg_area_keyring = (keyring_extract_arg_area_t*) calloc(sizeof(keyring_extract_arg_area_t), sizeof(char));
  if (arg_area_keyring == NULL) {
    perror(
        "Fatal - Unable to allocate space for "
        "'keyring_extract_arg_area_t'.\n");
    return NULL;
  }

  if (profile_name != NULL) {
    strncpy(&arg_area_keyring->args.keyring_extract_parms.cRingName[1], profile_name, 237);
    arg_area_keyring->args.keyring_extract_parms.cRingName[0] = strlen(&arg_area_keyring->args.keyring_extract_parms.cRingName[1]);
    __a2e_l(&arg_area_keyring->args.keyring_extract_parms.cRingName[1], strlen(&arg_area_keyring->args.keyring_extract_parms.cRingName[1]));
  }

  if (racf_user_id != NULL) {
    strncpy(&arg_area_keyring->args.keyring_extract_parms.cRACFUserId[1], racf_user_id, 8);
    arg_area_keyring->args.keyring_extract_parms.cRACFUserId[0] = strlen(&arg_area_keyring->args.keyring_extract_parms.cRACFUserId[1]);
    __a2e_l(&arg_area_keyring->args.keyring_extract_parms.cRACFUserId[1], strlen(&arg_area_keyring->args.keyring_extract_parms.cRACFUserId[1]));
  }

  return arg_area_keyring;
}
