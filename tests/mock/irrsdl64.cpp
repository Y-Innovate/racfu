#include "irrsdl64.hpp"

#include <stdlib.h>

#include <cstring>

#include "irrsdl00.hpp"

// These globals need to be defined differently depending
// on where they are compiled since BINDER on z/OS
// and off platform link editors (i.e., Mac/Linux)
// resolve symbols differently.
#ifndef __TOS_390__
// Mocked Values
char *irrsdl64_result_mock    = NULL;
int irrsdl64_result_size_mock = 0;
int irrsdl64_saf_rc_mock      = 0;
int irrsdl64_racf_rc_mock     = 0;
int irrsdl64_racf_reason_mock = 0;
#endif

extern void IRRSDL64(uint32_t *p_num_parms, char *p_workarea,
                     uint32_t ALET_SAF_RC, uint32_t *p_SAF_RC,
                     uint32_t ALET_RACF_RC, uint32_t *p_RACF_RC,
                     uint32_t ALET_RACF_RSN, uint32_t *p_RACF_RSN,
                     uint8_t *p_function_code, uint32_t *p_attributes,
                     char *p_RACF_user_id, char *p_ring_name,
                     uint32_t *p_parmlist_version, void *p_parmlist) {
  if (irrsdl64_result_mock != NULL && irrsdl64_result_size_mock > 0) {
    if (*p_function_code == 0x0D) {
      // Copy mock result for GetRingInfo to the result buffer.
      memcpy(p_parmlist,
             &(reinterpret_cast<keyring_extract_parms_results_t *>(
                   irrsdl64_result_mock))
                  ->result_buffer_get_ring,
             sizeof(cddlx_get_ring_t) + RING_INFO_BUFFER_SIZE);

      (reinterpret_cast<cddlx_get_ring_t *>(p_parmlist))->cddlx_ring_res_ptr =
          reinterpret_cast<ring_result_t *>(
              ((reinterpret_cast<uint64_t>(p_parmlist)) +
               sizeof(cddlx_get_ring_t)));
    } else if (*p_function_code == 1) {
      // Copy mock result for DataGetFirst to the result buffer.
      memcpy(p_parmlist,
             irrsdl64_result_mock + sizeof(keyring_extract_parms_results_t),
             sizeof(get_cert_buffer_t));

      (reinterpret_cast<get_cert_buffer_t *>(p_parmlist))
          ->result_buffer_get_cert.cddlx_cert_ptr =
          &(reinterpret_cast<get_cert_buffer_t *>(p_parmlist))->cert_buffer[0];
      (reinterpret_cast<get_cert_buffer_t *>(p_parmlist))
          ->result_buffer_get_cert.cddlx_label_ptr =
          &(reinterpret_cast<get_cert_buffer_t *>(p_parmlist))->label_buffer[0];
      (reinterpret_cast<get_cert_buffer_t *>(p_parmlist))
          ->result_buffer_get_cert.cddlx_pk_ptr =
          &(reinterpret_cast<get_cert_buffer_t *>(p_parmlist))->pkey_buffer[0];
      (reinterpret_cast<get_cert_buffer_t *>(p_parmlist))
          ->result_buffer_get_cert.cddlx_sdn_ptr =
          &(reinterpret_cast<get_cert_buffer_t *>(p_parmlist))
               ->cert_sdn_buffer[0];
      (reinterpret_cast<get_cert_buffer_t *>(p_parmlist))
          ->result_buffer_get_cert.cddlx_recid_ptr =
          &(reinterpret_cast<get_cert_buffer_t *>(p_parmlist))
               ->cert_recid_buffer[0];
    }
  }

  // Mock return and reason codes
  *p_SAF_RC   = irrsdl64_saf_rc_mock;
  *p_RACF_RC  = irrsdl64_racf_rc_mock;
  *p_RACF_RSN = irrsdl64_racf_reason_mock;

  return;
}
