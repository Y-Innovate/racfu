#ifndef __IRRSDL64_H_
#define __IRRSDL64_H_

#include <stdio.h>

// These globals need to be defined differently depending
// on where they are compiled since BINDER on z/OS
// and off platform link editors (i.e., Mac/Linux)
// resolve symbols differently.
#ifndef __TOS_390__
extern char *irrsdl64_result_mock;
extern int irrsdl64_result_size_mock;
extern int irrsdl64_saf_rc_mock;
extern int irrsdl64_racf_rc_mock;
extern int irrsdl64_racf_reason_mock;
#else
char *irrsdl64_result_mock    = NULL;
int irrsdl64_result_size_mock = 0;
int irrsdl64_saf_rc_mock      = 0;
int irrsdl64_racf_rc_mock     = 0;
int irrsdl64_racf_reason_mock = 0;
#endif

extern "C" {
void IRRSDL64(int *,                // Num parms
              char *,               // Workarea
              unsigned int, int *,  // safrc
              unsigned int, int *,  // racfrc
              unsigned int, int *,  // racfrsn
              char *,               // Function code
              unsigned int *,       // Attributes
              char *,               // RACF Userid
              char *,               // RACF Ring name
              int *,                // Parmlist version
              void *                // Parmlist
);
}    

#endif
