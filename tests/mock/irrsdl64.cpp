#include "irrsdl64.hpp"

#include <stdlib.h>

#include <cstring>

// These globals need to be defined differently depending
// on where they are compiled since BINDER on z/OS
// and off platform link editors (i.e., Mac/Linux)
// resolve symbols differently.
#ifndef __TOS_390__
char* irrsdl64_result_mock    = NULL;
int irrsdl64_result_size_mock = 0;
int irrsdl64_saf_rc_mock      = 0;
int irrsdl64_racf_rc_mock     = 0;
int irrsdl64_racf_reason_mock = 0;
#endif

extern void IRRSDL64(int* num_parms, char* work_area,
                     unsigned int alet_saf_rc, int* saf_rc,
                     unsigned int alet_racf_rc, int* racf_rc,
                     unsigned int alet_racf_rsn, int* racf_rsn,
                     char* function_code, unsigned int* attributes,
                     char* racf_user_id, char* ring_name,
                     int* parmlist_version, void* parmlist) {
  if (irrsdl64_result_mock != NULL && irrsdl64_result_size_mock > 0) {
    // Copy mock result to the result buffer.
    memcpy(parmlist, irrsdl64_result_mock, irrsdl64_result_size_mock);
  }

  // Mock return and reason codes
  *saf_rc   = irrsdl64_saf_rc_mock;
  *racf_rc  = irrsdl64_racf_rc_mock;
  *racf_rsn = irrsdl64_racf_reason_mock;
  return;
}
