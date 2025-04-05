#include "extract_sdl.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <cstring>

#include "logger.hpp"
#include "messages.h"
#include "irrsdl00.hpp"

// Use htonl() to convert 32-bit values from little endian to big endian.
// use ntohl() to convert 16-bit values from big endian to little endian.
// On z/OS these macros do nothing since "network order" and z/Architecture are
// both big endian. This is only necessary for unit testing off platform.
#define _POSIX_C_SOURCE 200112L
#include <arpa/inet.h>

char *extract_sdl(
    const char *profile_name,  // Required for everything
    uint8_t function_code,     // Always required
    char **raw_request,        // Always required
    int *raw_request_length,   // Always required
    racfu_return_codes_t *return_codes,  // Always required,
    Logger *logger_p) {
  uint32_t rc;

  char *result_buffer;


  // Check Return Codes
  if (return_codes->saf_return_code != 0 ||
      return_codes->racf_return_code != 0 ||
      return_codes->racf_reason_code != 0 || rc != 0) {
    // Free Result Buffer & Return 'NULL' if not successful.
    free(result_buffer);
    return NULL;
  }

  // Return Result if Successful
  return result_buffer;
}