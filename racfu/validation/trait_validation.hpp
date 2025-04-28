#ifndef __RACFU_TRAIT_VALIDATION_H_
#define __RACFU_TRAIT_VALIDATION_H_

#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "security_request.hpp"

void validate_traits(const std::string& admin_type,
                     RACFu::SecurityRequest& request);
void validate_json_value_to_string(const nlohmann::json& trait,
                                   char expected_type,
                                   std::vector<std::string>& errors);

#endif
