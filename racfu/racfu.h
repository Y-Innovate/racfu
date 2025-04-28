#ifndef __RACFU_H_
#define __RACFU_H_

#include "racfu_result.h"

#ifdef __cplusplus
extern "C" {
#endif

racfu_result_t *racfu(const char *request_json, bool debug);

#ifdef __cplusplus
}
#endif

#pragma export(racfu)

#endif
