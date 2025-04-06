#ifndef __RACFU_EXTRACT_SEQ_H_
#define __RACFU_EXTRACT_SEQ_H_

#include <stdint.h>

#include "extract.hpp"
#include "logger.hpp"
#include "messages.h"
#include "racfu_result.h"

#ifdef __TOS_390__
#include <unistd.h>
#else
#include "zoslib.h"
#endif

// Glue code to call IRRSEQ00 assembler code.
extern "C" uint32_t callRadmin(char *__ptr32);

char *extract_seq(const char *profile_name, const char *class_name,
                  uint8_t function_code, char **raw_request,
                  int *raw_request_length, racfu_return_codes_t *return_codes,
                  Logger *logger_p);

generic_extract_underbar_arg_area_t *build_generic_extract_parms(
    const char *profile_name, const char *class_name, uint8_t function_code);

setropts_extract_underbar_arg_area_t *build_setropts_extract_parms();

#endif
