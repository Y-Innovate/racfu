#ifndef __IRRSDL00_H_
#define __IRRSDL00_H_

#include <stdint.h>

#include "extract_sdl.hpp"

#include "racfu_result.h"

typedef struct {                      /* FSPL for GetRingInfo                   */ 
    unsigned char cddlx_ring_srch_type[4]; /* A 4 byte input value which          
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
    uint32_t cddlx_ring_res_len;      /* A 4 byte value containing the size of the 
                                         field pointed to by Ring_result_ptr       */ 
    void *cddlx_ring_res_ptr;         /* An input value containing the address of  
                                         the ring result area                      */ 
} cddlx_get_ring_t;

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

char *extract_keyring(keyring_extract_arg_area_t *arg_area_keyring, racfu_return_codes_t *);

#endif /* IRRSDL00_H_ */
