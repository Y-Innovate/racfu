#ifndef __IRRSDL00_H_
#define __IRRSDL00_H_

#include "extractor.hpp"

#ifdef __TOS_390__
#include <unistd.h>
#else
#include "zoslib.h"
#endif

// Use htonl() to convert 32-bit values from little endian to big endian.
// use ntohl() to convert 16-bit values from big endian to little endian.
// On z/OS these macros do nothing since "network order" and z/Architecture are
// both big endian. This is only necessary for unit testing off platform.
#include <arpa/inet.h>

#define RING_INFO_BUFFER_SIZE 4096
#define CERT_BUFFER_SIZE 4096
#define PKEY_BUFFER_SIZE 4096
#define LABEL_BUFFER_SIZE 238
#define SDN_BUFFER_SIZE 1024
#define RECID_BUFFER_SIZE 246

/*************************************************************************/
/* Function Codes                                                        */
/*************************************************************************/
const uint8_t KEYRING_EXTRACT_FUNCTION_CODE = 0x25;

#pragma pack(push, 1)  // Don't byte align structure members.

/*************************************************************************/
/* Keyring Extract Structures (IRRSDL00 GetRingInfo)                     */
/*************************************************************************/
typedef struct {
  uint32_t ring_count;
  uint8_t ring_info;
} ring_result_t;

typedef struct {                 /* FSPL for GetRingInfo                   */
  uint32_t cddlx_ring_srch_type; /* A 4 byte input value which
                                    identifies more rings to be returned when
                                    both ring owner and ring name are specified
                                    x'00000000' - Return just the ring with the
                                    specified ring owner and ring name
                                    x'00000001' - Return all rings after the
                                    ring specified by ring owner and ring name
                                    x'00000002' - Return all rings with the same
                                    owner after the ring specified by ring owner
                                    and ring name x'00000003' - Return all rings
                                    with the same name after the ring specified
                                    by ring owner and ring name               */
  uint32_t cddlx_ring_res_len;   /* A 4 byte value containing the size of the
                                    field pointed to by Ring_result_ptr       */
  ring_result_t *cddlx_ring_res_ptr; /* An input value containing the address of
                                        the ring result area */
} cddlx_get_ring_t;

typedef struct {             /* Mapping of area pointed to by
                             CDDLX_RES_HANDLE & CDDLX_PREV_HANDLE      */
  uint32_t cddlx_token;      /* Reserved for use by the security server.
                             This value must be preserved for subsequent
                             calls to DataGetNext and DataAbortQuery   */
  uint32_t cddlx_predicates; /* Input value specifying the selection
                             criteria. See constants below             */
  uint32_t cddlx_attr_id;    /* Input value specifying the attribute to
                             query on. Ignored if CDDLX_PREDICATES is 0.
                             See constants below for possible values.  */
  uint32_t cddlx_attr_len;   /* Input value containing the length of the
                             attributes supplied in CDDLX_ATTR_PTR     */
  void *cddlx_attr_ptr;      /* Input value containing the address of
                             query attribute data. Type of data supplied
                             determined by CDDLX_ATTR_ID               */
} cddlx_handle_map_t;

typedef struct {                        /* Parameter list for DataGetFirst and
                                        DataGetNext                               */
  cddlx_handle_map_t *cddlx_res_handle; /* Address of input/output area mapped
                                        by CDDLX_HANDLE_MAP */
  unsigned char cddlx_cert_usage[4];    /* 4 byte output area containing
                                        certificate usage flags x'00000000' - Usage
                                        is SITE x'00000002' - Usage is CERTAUTH
                                        x'00000008' - Usage is PERSONAL x'FFFFFFF5'
                                        - reserved bits must be set to zero    */
  uint32_t cddlx_cert_default;          /* Output default indicator. Zero value
                                        indicates not default certificate for ring,
                                        non-zero indicates this is the default
                                        certificate.                              */
  uint32_t cddlx_cert_len;              /* On input, contains the length of the
                                        certificate area pointed to by
                                        CDDLX_CERT_PTR. On output, contains the
                                        actual size of the certificate returned or 0
                                        if no certificate returned.               */
  int32_t irrpcomx_dummy_13;      /* alignment                              */
  unsigned char *cddlx_cert_ptr;  /* Input value specifying address of output
                                  certificate data area                     */
  uint32_t cddlx_pk_len;          /* On input, contains size of private key
                                  area pointed to by CDDLX_PK_PTR. On output
                                  contains the length of the private key
                                  returned at address CDDLX_PK_PTR or 0 if no
                                  private key was returned                  */
  int32_t irrpcomx_dummy_14;      /* alignment                              */
  unsigned char *cddlx_pk_ptr;    /* Input value specifying address of private
                                  key output data area                      */
  uint32_t cddlx_pk_type;         /* Output value indicating type of private
                                  key. See constants below.                 */
  uint32_t cddlx_pk_bitsize;      /* Output value indicating the size of the
                                  private key modulus in bits               */
  uint32_t cddlx_label_len;       /* On input, contains the length of the
                                  field pointed to by CDDLX_LABEL_PTR, and
                                  must be at least 32. On output, contains the
                                  length of the label returned at the address
                                  in CDDLX_LABEL_PTR, and will be 32 or less.
                                                                            */
  int32_t irrpcomx_dummy_15;      /* alignment                              */
  unsigned char *cddlx_label_ptr; /* Input value specifying the address of the
                                  output area to be used for the label name
                                                                            */
  unsigned char cddlx_racf_userid[9]; /* Input value containing a 1 byte
                                      length followed by the certificate owning
                                      userid. The combination of the output
                                      label and this field uniquely identify a
                                      certificate */
  unsigned char irrpcomx_dummy_16[3]; /* Reserved */
  uint32_t cddlx_sdn_len;             /* On input, contains the length of the
                                      output buffer pointed to by CDDLX_SDN_PTR.
                                      On output, contains the length of the BER
                                      encoded Subject's Distinguished Name
                                      returned in CDDLX_SDN_LEN.                */
  unsigned char *cddlx_sdn_ptr;   /* Input value specifying the address of the
                                  output area to be used for the Subjects's
                                  Distinguished Name.                       */
  uint32_t cddlx_recid_len;       /* Output value containing the length of the
                                  record ID returned in area pointed to by
                                  CDDLX_RECID_PTR, or 0 if no record returned.
                                                                            */
  int32_t irrpcomx_dummy_17;      /* alignment                              */
  unsigned char *cddlx_recid_ptr; /* Input value specifying the address of a
                                  246 byte area to contain output record ID
                                  data                                      */
  unsigned char cddlx_status[4];  /* Certificate status x'80000000' - TRUST
                                  x'40000000' - HIGHTRUST x'20000000' -
                                  NOTRUST x'00000000' - ANY (input only)    */
} cddlx_get_cert_t;

typedef struct {
  cddlx_get_cert_t result_buffer_get_cert;
  uint32_t filler_01;
  uint8_t cert_buffer[CERT_BUFFER_SIZE];
  uint8_t pkey_buffer[PKEY_BUFFER_SIZE];
  uint8_t label_buffer[LABEL_BUFFER_SIZE];
  uint8_t filler_02[2];
  uint8_t cert_sdn_buffer[SDN_BUFFER_SIZE];
  uint8_t cert_recid_buffer[RECID_BUFFER_SIZE];
  uint8_t filler_03[2];
} get_cert_buffer_t;

typedef struct {
  uint32_t result_buffer_length;
  uint32_t ring_info_length;
  uint32_t cert_count;
  uint32_t filler_01;
  cddlx_get_ring_t result_buffer_get_ring;
  union {
    ring_result_t ring_result;
    uint8_t ring_result_buffer[RING_INFO_BUFFER_SIZE];
  } union_ring_result;
  cddlx_handle_map_t handle_map;
  uint32_t filler_02;
  get_cert_buffer_t *p_get_cert_buffer;
} keyring_extract_parms_results_t;

typedef struct {
  char RACF_work_area[1024];
  // return and reason codes
  uint32_t ALET_SAF_rc;
  uint32_t SAF_rc;
  uint32_t ALET_RACF_rc;
  uint32_t RACF_rc;
  uint32_t ALET_RACF_rsn;
  uint32_t RACF_rsn;
  // extract function to perform
  uint8_t function_code;
  // IRRSDL00 specific
  uint32_t attributes;
  char RACF_user_id[10];
  char ring_name[239];
  keyring_extract_parms_results_t *p_result_buffer;
} keyring_extract_args_t;

typedef struct {
  keyring_extract_args_t args;
} keyring_extract_arg_area_t;

#pragma pack(pop)  // Restore default structure packing options.

/* Prototype for IRRSDL64 */
extern "C" {
void IRRSDL64(uint32_t *,            // Num parms
              char *,                // Workarea
              uint32_t, uint32_t *,  // safrc
              uint32_t, uint32_t *,  // racfrc
              uint32_t, uint32_t *,  // racfrsn
              uint8_t *,             // Function code
              uint32_t *,            // Attributes
              char *,                // RACF Userid
              char *,                // RACF Ring name
              uint32_t *,            // Parmlist version
              void *                 // Parmlist
);
}

// We need to ignore this pragma for unit tests since the
// IRRSDL64 mock is compiled for XPLINK.
#ifndef UNIT_TEST
#pragma linkage(IRRSDL64, OS_NOSTACK)
#endif

namespace RACFu {
class IRRSDL00 {
 private:
  static void callIRRSDL00(keyring_extract_arg_area_t *p_arg_area,
                           uint32_t *p_parmlist_version, void *p_parmlist);
  static void extractCert(const SecurityRequest &request,
                          keyring_extract_arg_area_t *p_arg_area_keyring,
                          get_cert_buffer_t *p_get_cert_buffer,
                          unsigned char *p_owner, unsigned char *p_label);

 public:
  static void extractKeyring(SecurityRequest &request,
                             keyring_extract_arg_area_t *p_arg_area_keyring);
};
}  // namespace RACFu

#endif /* __IRRSDL00_H_ */
