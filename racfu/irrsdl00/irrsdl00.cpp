#include "irrsdl00.hpp"

#include "extract_sdl.hpp"

//#include <irrpcomx.h>

#include "errors.hpp"

void call_irrsdl00(keyring_extract_arg_area_t *arg_area,
                    int nParmlistVersion, void *lpParmlist,
                    racfu_return_codes_t *return_codes_p) {
  int nNumParms = 14;
  char work_area[1024];
  unsigned int alet = 0;

  IRRSDL64(&nNumParms, &work_area[0],
           alet, &return_codes_p->saf_return_code,
           alet, &return_codes_p->racf_return_code,
           alet, &return_codes_p->racf_reason_code,
           &arg_area->args.keyring_extract_parms.cFunctionCode,
           &arg_area->args.keyring_extract_parms.nAttributes,
           &arg_area->args.keyring_extract_parms.cRACFUserId[0],
           &arg_area->args.keyring_extract_parms.cRingName[0],
           &nParmlistVersion, lpParmlist);
}

char *extract_keyring(keyring_extract_arg_area_t *arg_area_keyring,
                      racfu_return_codes_t *return_codes_p) {
  arg_area_keyring->args.keyring_extract_parms.cFunctionCode = 0x0D;  // GetRingInfo
  arg_area_keyring->args.keyring_extract_parms.nAttributes = 0;

  int nParmlistVersion = 0;
    cddlx_get_ring_t *lpParmlGetRing;

  lpParmlGetRing = (cddlx_get_ring_t*) (sizeof(cddlx_get_ring_t));

  if (lpParmlGetRing != NULL) {
    memset(lpParmlGetRing, 0, sizeof(cddlx_get_ring_t));
    lpParmlGetRing->cddlx_ring_res_len = 4096;
    lpParmlGetRing->cddlx_ring_res_ptr = malloc(lpParmlGetRing->cddlx_ring_res_len);

    call_irrsdl00(arg_area_keyring, nParmlistVersion, lpParmlGetRing, return_codes_p);
  }
 
  return (char*) lpParmlGetRing;
}