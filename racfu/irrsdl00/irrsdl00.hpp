#ifndef __IRRSDL00_H_
#define __IRRSDL00_H_

#include <stdint.h>

#include "extract_sdl.hpp"

#include "racfu_result.h"

/* Prototype for IRRSDL64 */
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

char *extract_keyring(keyring_extract_arg_area_t *arg_area_keyring, racfu_return_codes_t *, Logger *logger_p);

#endif /* IRRSDL00_H_ */
