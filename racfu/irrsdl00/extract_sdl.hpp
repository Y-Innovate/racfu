#ifndef __RACFU_EXTRACT_SDL_H_
#define __RACFU_EXTRACT_SDL_H_

#include <stdint.h>

#include "logger.hpp"

#include "racfu_result.h"

/*************************************************************************/
/* Function Codes                                                        */
/*************************************************************************/
const uint8_t KEYRING_EXTRACT_FUNCTION_CODE          = 0x16;

char *extract_sdl(const char *profile_name, uint8_t function_code,
    char **raw_request, int *raw_request_length,
    racfu_return_codes_t *return_codes, Logger *logger_p);

#endif
