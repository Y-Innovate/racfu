#include "irrsmo64.hpp"

#include <stdlib.h>

#include <cstring>

// These globals need to be defined differently depending
// on where they are compiled since BINDER on z/OS
// and off platform link editors (i.e., Mac/Linux)
// resolve symbols differently.
#ifndef __TOS_390__
// Mocked Values
char* irrsmo64_result_mock    = NULL;
int irrsmo64_result_size_mock = 0;
int irrsmo64_saf_rc_mock      = 0;
int irrsmo64_racf_rc_mock     = 0;
int irrsmo64_racf_reason_mock = 0;
// Preserved Values
int irrsmo00_options_actual = 0;
#endif

extern void IRRSMO64(char work_area[1024], unsigned int alet_saf_rc,
                     int* saf_rc, unsigned int alet_racf_rc, int* racf_rc,
                     unsigned int alet_racf_rsn, int* racf_rsn, int* num_parms,
                     int* fn, int* irrsmo00_options, int* request_xml_length,
                     char* request_xml, char* request_handle, char* userid,
                     unsigned int acee, int* result_len, char* result_buffer) {
  if (irrsmo64_result_mock != NULL && irrsmo64_result_size_mock > 0) {
    // Copy mock result to the result buffer.
    memcpy(result_buffer, irrsmo64_result_mock, irrsmo64_result_size_mock);
    // Get the length of the XML in the result buffer
    for (int i = 0; i < irrsmo64_result_size_mock; i++) {
      // 0x6e is '>' in EBCDIC.
      // The last occurance of this byte in the buffer indicates
      // that we have reached the end of the result XML.
      if (irrsmo64_result_mock[i] == 0x6e) {
        *result_len = i + 1;
      }
    }
  } else {
    *result_len = 0;
  }
  // Mock return and reason codes
  *saf_rc   = irrsmo64_saf_rc_mock;
  *racf_rc  = irrsmo64_racf_rc_mock;
  *racf_rsn = irrsmo64_racf_reason_mock;
  // Preserve IRRSMO00 Options
  irrsmo00_options_actual = *irrsmo00_options;
  return;
}
