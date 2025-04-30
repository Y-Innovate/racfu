#ifndef __IRRSDL64_H_
#define __IRRSDL64_H_

#include <stdio.h>

#include <cstdint>

// These globals need to be defined differently depending
// on where they are compiled since BINDER on z/OS
// and off platform link editors (i.e., Mac/Linux)
// resolve symbols differently.
#ifndef __TOS_390__
// Mocked Values
extern char *irrsdl64_result_mock;
extern int irrsdl64_result_size_mock;
extern int irrsdl64_saf_rc_mock;
extern int irrsdl64_racf_rc_mock;
extern int irrsdl64_racf_reason_mock;
#else
// Mocked Values
char *irrsdl64_result_mock    = NULL;
int irrsdl64_result_size_mock = 0;
int irrsdl64_saf_rc_mock      = 0;
int irrsdl64_racf_rc_mock     = 0;
int irrsdl64_racf_reason_mock = 0;
#endif

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

#endif
