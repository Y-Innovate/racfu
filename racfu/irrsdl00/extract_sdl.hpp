#ifndef __RACFU_EXTRACT_SDL_H_
#define __RACFU_EXTRACT_SDL_H_

#include <stdint.h>

#include "extract.hpp"
#include "logger.hpp"
#include "messages.h"
#include "racfu_result.h"

char *extract_sdl(const char *profile_name, const char *racf_user_id,
    uint8_t function_code, char **raw_request, int *raw_request_length,
    racfu_return_codes_t *return_codes_p, Logger *logger_p);

keyring_extract_arg_area_t *build_keyring_extract_parms(
    const char *profile_name, const char *racf_user_id);

#endif
