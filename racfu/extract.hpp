#ifndef __RACFU_EXTRACT_H_
#define __RACFU_EXTRACT_H_

#include <stdint.h>

#include "logger.hpp"
#include "racfu_result.h"

/*************************************************************************/
/* Function Codes                                                        */
/*************************************************************************/
const uint8_t SETROPTS_EXTRACT_FUNCTION_CODE         = 0x16;
const uint8_t USER_EXTRACT_FUNCTION_CODE             = 0x19;
const uint8_t GROUP_EXTRACT_FUNCTION_CODE            = 0x1b;
const uint8_t GROUP_CONNECTION_EXTRACT_FUNCTION_CODE = 0x1d;
const uint8_t RESOURCE_EXTRACT_FUNCTION_CODE         = 0x1f;
const uint8_t DATA_SET_EXTRACT_FUNCTION_CODE         = 0x22;
const uint8_t KEYRING_EXTRACT_FUNCTION_CODE          = 0x24;

/*************************************************************************/
/* Field Descriptor Information                                          */
/*************************************************************************/
// Field types
const uint16_t t_member_repeat_group = 0x8000;  // member of a repeat group
const uint16_t t_reserved            = 0x4000;  // reserved
const uint16_t t_boolean_field       = 0x2000;  // flag (boolean) field
const uint16_t t_repeat_field_header = 0x1000;  // repeat field header

// Field descriptor flags
const uint32_t f_boolean_field = 0x80000000;  // value of a boolean field
const uint32_t f_output_only   = 0x40000000;  // output-only field

/*************************************************************************/
/* Common Aliases                                                        */
/*************************************************************************/
const uint8_t RESULT_BUFFER_SUBPOOL = 127;
const uint32_t ALET                 = 0x00000000;  // primary address space
const uint32_t ACEE                 = 0x00000000;

/*************************************************************************/
/* Setropts Constants                                                    */
/*************************************************************************/
const char SETROPTS_FIELD_TYPE_LIST    = 0;
const char SETROPTS_FIELD_TYPE_STRING  = 1;
const char SETROPTS_FIELD_TYPE_NUMBER  = 2;
const char SETROPTS_FIELD_TYPE_BOOLEAN = 3;

/*************************************************************************/
/* Common Structure Data Macros                                          */
/*************************************************************************/
#define PROFILE_NAME_MAX_LENGTH 247

#define COMMON_START_ARGS           \
  char RACF_work_area[1024];        \
  /* return and reason codes */     \
  uint32_t ALET_SAF_rc;             \
  uint32_t SAF_rc;                  \
  uint32_t ALET_RACF_rc;            \
  uint32_t RACF_rc;                 \
  uint32_t ALET_RACF_rsn;           \
  uint32_t RACF_rsn;                \
  /* extract function to perform */ \
  uint8_t function_code;

#define COMMON_START_ARG_POINTERS   \
  char *__ptr32 pWork_area;         \
  /* return and reason code */      \
  uint32_t *__ptr32 pALET_SAF_rc;   \
  uint32_t *__ptr32 pSAF_rc;        \
  uint32_t *__ptr32 pALET_RACF_rc;  \
  uint32_t *__ptr32 pRACF_rc;       \
  uint32_t *__ptr32 pALET_RACF_rsn; \
  uint32_t *__ptr32 pRACF_rsn;      \
  /* extract function to perform */ \
  uint8_t *__ptr32 pFunction_code;

#define COMMON_END_ARGS                           \
  /* Max of 247 + 1 for null terimnator */        \
  char profile_name[PROFILE_NAME_MAX_LENGTH + 1]; \
  /* Result area for the service */               \
  uint32_t ACEE;                                  \
  uint8_t result_buffer_subpool;                  \
  /* R_admin returns data here */                 \
  char *__ptr32 pResult_buffer;

#define COMMON_END_ARG_POINTERS            \
  char *__ptr32 pProfile_name;             \
  /* Result area for the service */        \
  uint32_t *__ptr32 pACEE;                 \
  uint8_t *__ptr32 pResult_buffer_subpool; \
  /* R_admin returns data here */          \
  char *__ptr32 *__ptr32 ppResult_buffer;

#define SET_COMMON_ARGS               \
  args->ALET_SAF_rc           = ALET; \
  args->ALET_RACF_rc          = ALET; \
  args->ALET_RACF_rsn         = ALET; \
  args->ACEE                  = ACEE; \
  args->result_buffer_subpool = RESULT_BUFFER_SUBPOOL;

#define SET_COMMON_ARG_POINTERS                                              \
  arg_pointers->pWork_area =                                                 \
      reinterpret_cast<char *__ptr32>(&args->RACF_work_area);                \
  arg_pointers->pALET_SAF_rc   = &(args->ALET_SAF_rc);                       \
  arg_pointers->pSAF_rc        = &(args->SAF_rc);                            \
  arg_pointers->pALET_RACF_rc  = &(args->ALET_RACF_rc);                      \
  arg_pointers->pRACF_rc       = &(args->RACF_rc);                           \
  arg_pointers->pALET_RACF_rsn = &(args->ALET_RACF_rsn);                     \
  arg_pointers->pRACF_rsn      = &(args->RACF_rsn);                          \
                                                                             \
  arg_pointers->pFunction_code = &(args->function_code);                     \
  /* Function specific parms between function code and profile name */       \
  arg_pointers->pProfile_name          = &(args->profile_name[0]);           \
  arg_pointers->pACEE                  = &(args->ACEE);                      \
  arg_pointers->pResult_buffer_subpool = &(args->result_buffer_subpool);     \
  arg_pointers->ppResult_buffer        = &(args->pResult_buffer);            \
                                                                             \
  /* Turn on the hight order bit of the last argument - marks the end of the \
   */                                                                        \
  /* argument list. */                                                       \
  *(reinterpret_cast<uint32_t *__ptr32>(&arg_pointers->ppResult_buffer)) |=  \
      0x80000000;

#pragma pack(push, 1)  // Don't byte align structure members.

/*************************************************************************/
/* Generic Extract Structures                                            */
/*                                                                       */
/* Use For:                                                              */
/*   - User Extract                                                      */
/*   - Group Extract                                                     */
/*   - Group Connection Extract                                          */
/*   - Resource Extract                                                  */
/*   - Data Set Extract                                                  */
/*************************************************************************/
typedef struct {
  char eyecatcher[4];             // 'PXTR'
  uint32_t result_buffer_length;  // result buffer length
  uint8_t subpool;                // subpool of result buffer
  uint8_t version;                // parameter list version
  uint8_t reserved_1[2];          // reserved
  char class_name[8];             // class name - upper case, blank pad
  uint32_t profile_name_length;   // length of profile name
  char reserved_2[2];             // reserved
  char volume[6];                 // volume (for data set extract)
  char reserved_3[4];             // reserved
  uint32_t flags;                 // see flag constants below
  uint32_t segment_count;         // number of segments
  char reserved_4[16];            // reserved
                                  // start of extracted data
} generic_extract_parms_results_t;
// Note: This structure is used for both input & output.

typedef struct {
  COMMON_START_ARGS
  generic_extract_parms_results_t profile_extract_parms;
  COMMON_END_ARGS
} generic_extract_args_t;

typedef struct {
  COMMON_START_ARG_POINTERS
  generic_extract_parms_results_t *__ptr32 pProfile_extract_parms;
  COMMON_END_ARG_POINTERS
} generic_extract_arg_pointers_t;

// 31-bit for IRRSEQ00 arguments.
typedef struct {
  generic_extract_args_t args;
  generic_extract_arg_pointers_t arg_pointers;
} generic_extract_underbar_arg_area_t;

/*************************************************************************/
/* Generic Segment/Field Descriptor Structures                           */
/*                                                                       */
/* Used to interpret extracted generic profile data                      */
/*************************************************************************/
typedef struct {
  char name[8];                      // segment name, upper case, blank padded
  uint32_t flags;                    //
  uint32_t field_count;              // number of fields
  char reserved_1[4];                // reserved
  uint32_t field_descriptor_offset;  // offset to first field descriptor
  char reserved_2[16];               // reserved
                                     // start of next segment descriptor
} generic_segment_descriptor_t;

typedef union {
  uint32_t field_data_length;   // length of field data or ...
  uint32_t repeat_group_count;  // number of repeat groups
} generic_field_data_length_repeat_group_count_t;

typedef union {
  uint32_t field_data_offset;           // offset to field data or ...
  uint32_t repeat_group_element_count;  // number of elems in repeat field hdrs
} generic_field_data_offset_repeat_group_element_count_t;

typedef struct {
  char name[8];  // field name, upper case, blank padded
  uint16_t type;
  char reserved_1[2];
  uint32_t flags;
  generic_field_data_length_repeat_group_count_t
      field_data_length_repeat_group_count;
  char rserved_2[4];
  generic_field_data_offset_repeat_group_element_count_t
      field_data_offset_repeat_group_element_count;
  char reserved_3[16];
  // start of next field descriptor
} generic_field_descriptor_t;

/*************************************************************************/
/* Setropts Extract Structures                                           */
/*                                                                       */
/* Specific to Setropts Extract.                                         */
/*************************************************************************/
typedef struct {
  uint32_t request_flags;
  uint8_t reserved_1[10];
} setropts_extract_parms_t;

typedef struct {
  COMMON_START_ARGS
  setropts_extract_parms_t setropts_extract_parms;
  COMMON_END_ARGS
} setropts_extract_args_t;

typedef struct {
  COMMON_START_ARG_POINTERS
  setropts_extract_parms_t *__ptr32 pSetropts_extract_parms;
  COMMON_END_ARG_POINTERS
} setropts_extract_arg_pointers_t;

// 31-bit for IRRSEQ00 arguments.
typedef struct {
  setropts_extract_args_t args;
  setropts_extract_arg_pointers_t arg_pointers;
} setropts_extract_underbar_arg_area_t;

/*************************************************************************/
/* Setropts Segment/Field Descriptor Structures                          */
/*                                                                       */
/* Used to interpret extracted setropts profile data                     */
/*************************************************************************/
typedef struct {
  char eyecatcher[4];
  uint32_t result_buffer_length;
  char reserved_2[4];
  uint16_t segment_count;
  // Start of first segment descriptor.
} setropts_extract_results_t;

typedef struct {
  char name[8];
  uint8_t flag;
  uint16_t field_count;
  // Start of first field descriptor
} setropts_segment_descriptor_t;

typedef struct {
  char name[8];
  uint8_t flag;
  uint16_t field_length;
  // Start of next field descriptor, next segment, or end of data
} setropts_field_descriptor_t;

typedef struct {
  char key[8 + 1];
  char type;
} setropts_field_type_t;

/*************************************************************************/
/* Keyring Extract Structures (IRRSDL00 GetRingInfo)                     */
/*************************************************************************/
typedef struct {
  char cFunctionCode;
  unsigned int nAttributes;
  char cRACFUserId[10];
  char cRingName[239];
} keyring_extract_parms_t;

typedef struct {
  COMMON_START_ARGS
  keyring_extract_parms_t keyring_extract_parms;
  COMMON_END_ARGS
} keyring_extract_args_t;

typedef struct {
  keyring_extract_args_t args;
} keyring_extract_arg_area_t;

/*************************************************************************/
/* Keyring Extract Result Structures (IRRSDL00 GetRingInfo)              */
/*************************************************************************/
typedef struct {
  unsigned int ring_count;
  char * ring_info;
} keyring_extract_results_t;

typedef struct {
  unsigned int result_buffer_length;
  keyring_extract_results_t * result_buffer;
} keyring_extract_parms_results_t;

#pragma pack(pop)  // Restore default structure packing options.

// Since the setropts field descriptor structure in the extracted
// setropts data do not describe what kind of data is in each field,
// we need to use this list to look up the field type for each
// setropts field.
const setropts_field_type_t SETROPTS_FIELD_TYPES[]{
    {"addcreat", SETROPTS_FIELD_TYPE_BOOLEAN},
    {    "adsp", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"applaudt", SETROPTS_FIELD_TYPE_BOOLEAN},
    {   "audit",    SETROPTS_FIELD_TYPE_LIST},
    { "catdsns",  SETROPTS_FIELD_TYPE_STRING},
    {"classact",    SETROPTS_FIELD_TYPE_LIST},
    {"classtat",    SETROPTS_FIELD_TYPE_LIST},
    { "cmdviol", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"compmode", SETROPTS_FIELD_TYPE_BOOLEAN},
    {     "egn", SETROPTS_FIELD_TYPE_BOOLEAN},
    {   "erase", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"eraseall", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"erasesec",  SETROPTS_FIELD_TYPE_STRING},
    {  "gencmd",    SETROPTS_FIELD_TYPE_LIST},
    { "generic",    SETROPTS_FIELD_TYPE_LIST},
    { "genlist",    SETROPTS_FIELD_TYPE_LIST},
    {"genowner", SETROPTS_FIELD_TYPE_BOOLEAN},
    {  "global",    SETROPTS_FIELD_TYPE_LIST},
    { "grplist", SETROPTS_FIELD_TYPE_BOOLEAN},
    { "history",  SETROPTS_FIELD_TYPE_STRING},
    {"inactive",  SETROPTS_FIELD_TYPE_NUMBER},
    {"initstat", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"interval",  SETROPTS_FIELD_TYPE_NUMBER},
    {"jesbatch", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"jesearly", SETROPTS_FIELD_TYPE_BOOLEAN},
    {  "jesnje",  SETROPTS_FIELD_TYPE_STRING},
    {"jesundef",  SETROPTS_FIELD_TYPE_STRING},
    {  "jesxbm", SETROPTS_FIELD_TYPE_BOOLEAN},
    { "kerblvl",  SETROPTS_FIELD_TYPE_NUMBER},
    {    "list", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"logalwys",    SETROPTS_FIELD_TYPE_LIST},
    {"logdeflt",    SETROPTS_FIELD_TYPE_LIST},
    { "logfail",    SETROPTS_FIELD_TYPE_LIST},
    {"lognever",    SETROPTS_FIELD_TYPE_LIST},
    { "logsucc",    SETROPTS_FIELD_TYPE_LIST},
    {"minchang",  SETROPTS_FIELD_TYPE_NUMBER},
    {"mixdcase", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"mlactive",  SETROPTS_FIELD_TYPE_STRING},
    {    "mlfs",  SETROPTS_FIELD_TYPE_STRING},
    {   "mlipc",  SETROPTS_FIELD_TYPE_STRING},
    { "mlnames", SETROPTS_FIELD_TYPE_BOOLEAN},
    { "mlquiet", SETROPTS_FIELD_TYPE_BOOLEAN},
    {     "mls",  SETROPTS_FIELD_TYPE_STRING},
    {"mlstable", SETROPTS_FIELD_TYPE_BOOLEAN},
    {   "model", SETROPTS_FIELD_TYPE_BOOLEAN},
    {  "modgdg", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"modgroup", SETROPTS_FIELD_TYPE_BOOLEAN},
    { "moduser", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"operaudt", SETROPTS_FIELD_TYPE_BOOLEAN},
    {  "phrint",  SETROPTS_FIELD_TYPE_NUMBER},
    {  "prefix",  SETROPTS_FIELD_TYPE_STRING},
    {"primlang",  SETROPTS_FIELD_TYPE_STRING},
    { "protall",  SETROPTS_FIELD_TYPE_STRING},
    {  "pwdalg",  SETROPTS_FIELD_TYPE_STRING},
    { "pwdspec", SETROPTS_FIELD_TYPE_BOOLEAN},
    { "raclist",    SETROPTS_FIELD_TYPE_LIST},
    { "realdsn", SETROPTS_FIELD_TYPE_BOOLEAN},
    {   "retpd",  SETROPTS_FIELD_TYPE_NUMBER},
    {  "revoke",  SETROPTS_FIELD_TYPE_STRING},
    {   "rule1",  SETROPTS_FIELD_TYPE_STRING},
    {   "rule2",  SETROPTS_FIELD_TYPE_STRING},
    {   "rule3",  SETROPTS_FIELD_TYPE_STRING},
    {   "rule4",  SETROPTS_FIELD_TYPE_STRING},
    {   "rule5",  SETROPTS_FIELD_TYPE_STRING},
    {   "rule6",  SETROPTS_FIELD_TYPE_STRING},
    {   "rule7",  SETROPTS_FIELD_TYPE_STRING},
    {   "rule8",  SETROPTS_FIELD_TYPE_STRING},
    {"rvarstfm",  SETROPTS_FIELD_TYPE_STRING},
    {"rvarstpw",  SETROPTS_FIELD_TYPE_STRING},
    {"rvarswfm",  SETROPTS_FIELD_TYPE_STRING},
    {"rvarswpw",  SETROPTS_FIELD_TYPE_STRING},
    {  "saudit", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"seclabct", SETROPTS_FIELD_TYPE_BOOLEAN},
    { "seclang",  SETROPTS_FIELD_TYPE_STRING},
    { "sessint",  SETROPTS_FIELD_TYPE_NUMBER},
    {"slabaudt", SETROPTS_FIELD_TYPE_BOOLEAN},
    { "slbysys", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"slevaudt",  SETROPTS_FIELD_TYPE_STRING},
    { "tapedsn", SETROPTS_FIELD_TYPE_BOOLEAN},
    {"terminal",  SETROPTS_FIELD_TYPE_STRING},
    { "warning",  SETROPTS_FIELD_TYPE_NUMBER},
    {"whenprog", SETROPTS_FIELD_TYPE_BOOLEAN}
};

void preserve_raw_request(const char *arg_area, char **raw_request,
                          const int *raw_request_length);

#endif
