#ifndef __RACFU_PARAMETER_VALIDATION_H_
#define __RACFU_PARAMETER_VALIDATION_H_

#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

void validate_parameters(nlohmann::json* request_p, nlohmann::json* errors_p,
                         std::string* operation_p, std::string* admin_type_p,
                         std::string* profile_name_p, std::string* auth_id,
                         std::string* class_name_p);

uint8_t validate_parameter(nlohmann::json* request_p, nlohmann::json* errors_p,
                           std::string json_key, nlohmann::json* valid_values_p,
                           std::string admin_type, bool required);

void validate_supplemental_parameters(nlohmann::json* request_p,
                                      nlohmann::json* errors_p,
                                      std::string* admin_type,
                                      std::string* operation,
                                      nlohmann::json* checked_parameters_p,
                                      bool traits_allowed);

#endif
