#ifndef __IRRSMO64_H_
#define __IRRSMO64_H_

#include <stdio.h>

// These globals need to be defined differently depending
// on where they are compiled since BINDER on z/OS
// and off platform link editors (i.e., Mac/Linux)
// resolve symbols differently.
#ifndef __TOS_390__
// Mocked Values
extern char *irrsmo64_result_mock;
extern int irrsmo64_result_size_mock;
extern int irrsmo64_saf_rc_mock;
extern int irrsmo64_racf_rc_mock;
extern int irrsmo64_racf_reason_mock;
// Preserved Values
extern int irrsmo00_options_actual;
#else
// Mocked Values
char *irrsmo64_result_mock    = NULL;
int irrsmo64_result_size_mock = 0;
int irrsmo64_saf_rc_mock      = 0;
int irrsmo64_racf_rc_mock     = 0;
int irrsmo64_racf_reason_mock = 0;
// Preserved Values
int irrsmo00_options_actual = 0;
#endif

typedef struct {
  unsigned char running_userid_length;
  char running_userid[8];
} running_userid_t;

extern "C" {
void IRRSMO64(char *,               // Workarea
              unsigned int, int *,  // safrc
              unsigned int, int *,  // racfrc
              unsigned int, int *,  // racfrsn
              int *,                // Numparms
              int *,                // Function code
              int *,                // options
              int *,                // Request Length
              char *,               // Request
              char *,               // Request Handle
              char *,               // run as user
              unsigned int,         // ACEE (not used)
              int *,                // Result buffer
              char *                // Result
);
}

#endif
