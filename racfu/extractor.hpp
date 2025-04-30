#ifndef __EXTRACT_H_
#define __EXTRACT_H_

#include "security_request.hpp"

/*************************************************************************/
/* Common Aliases                                                        */
/*************************************************************************/
const uint8_t RESULT_BUFFER_SUBPOOL = 127;
const uint32_t ALET                 = 0x00000000;  // primary address space
const uint32_t ACEE                 = 0x00000000;

namespace RACFu {
class Extractor {
 public:
  virtual void extract(SecurityRequest &request) = 0;
};
}  // namespace RACFu

#endif
