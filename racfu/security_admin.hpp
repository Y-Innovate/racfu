#ifndef __RACFU_SECURITY_ADMIN_H_
#define __RACFU_SECURITY_ADMIN_H_

#include <cstdint>
#include <nlohmann/json-schema.hpp>
#include <nlohmann/json.hpp>

#include "extractor.hpp"
#include "logger.hpp"
#include "racfu_result.h"
#include "racfu_schema.hpp"
#include "security_request.hpp"

namespace RACFu {
static const nlohmann::json RACFU_SCHEMA_JSON = RACFU_SCHEMA;
static const nlohmann::json_schema::json_validator RACFU_SCHEMA_VALIDATOR{
    RACFU_SCHEMA_JSON};

class SecurityAdmin {
 private:
  SecurityRequest request_;
  void doExtract(Extractor &extractor);
  void doAddAlterDelete();

 public:
  SecurityAdmin(racfu_result_t *p_result, bool debug);
  void makeRequest(const char *p_request_json_string);
};
}  // namespace RACFu

#endif
