#ifndef __IRRSMO00_H_
#define __IRRSMO00_H_

#include <nlohmann/json.hpp>
#include <string>

#include "racfu_result.h"
#include "security_request.hpp"

typedef struct {
  unsigned char running_userid_length;
  char running_userid[8];
} running_userid_t;

/* Prototype for IRRSMO64 */
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

// We need to ignore this pragma for unit tests since the
// IRRSMO64 mock is compiled for XPLINK.
#ifndef UNIT_TEST
#pragma linkage(IRRSMO64, OS_NOSTACK)
#endif

namespace RACFu {
class IRRSMO00 {
 public:
  void call_irrsmo00(SecurityRequest &request, bool profile_exists_check);
  bool does_profile_exist(SecurityRequest &request);
  void post_process_smo_json(SecurityRequest &request);
};
}  // namespace RACFu

#endif /* IRRSMO00_H_ */
