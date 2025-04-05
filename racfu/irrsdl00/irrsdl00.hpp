#ifndef __IRRSDL00_H_
#define __IRRSDL00_H_

/* Prototype for IRRSMO64 */
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

// We need to ignore this pragma for unit tests since the
// IRRSDL64 mock is compiled for XPLINK.
#ifndef UNIT_TEST
#pragma linkage(IRRSDL64, OS_NOSTACK)
#endif

char *call_irrsdl00(unsigned int *result_buffer_size_p, int irrsdl00_options,
                    int *saf_rc_p, int *racf_rc_p, int *racf_rsn_p);

#endif /* IRRSDL00_H_ */
