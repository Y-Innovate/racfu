#ifndef __RACFU_KEYRING_EXTRACTOR_H_
#define __RACFU_KEYRING_EXTRACTOR_H_

#include "extractor.hpp"
#include "irrsdl00.hpp"
#include "security_request.hpp"

namespace RACFu {
class KeyringExtractor : public Extractor {
 private:
  static void buildKeyringExtractRequest(keyring_extract_arg_area_t *p_arg_area,
                                         std::string &owner,
                                         const std::string &keyring,
                                         uint8_t function_code);
  static char *preserveRawRequest(const char *p_arg_area,
                                  const int &raw_request_length);

 public:
  void extract(SecurityRequest &request) override;
};
}  // namespace RACFu

#endif
