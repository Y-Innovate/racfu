#include "parameter_validation.hpp"

#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

#include "errors.hpp"

void validate_parameters(nlohmann::json* request_p, nlohmann::json* errors_p,
                         std::string* operation_p, std::string* admin_type_p,
                         std::string* profile_name_p, std::string* auth_id_p,
                         std::string* class_name_p) {
  // Obtain JSON Parameter information and Validate as appropriate
  nlohmann::json checked_parameters = nlohmann::json::array();

  // Json arrays of valid values for different parameters
  nlohmann::json yes_or_no{"yes", "no"};
  nlohmann::json yes_no_or_force{"yes", "no", "force"};
  nlohmann::json valid_operations{"add", "alter", "extract", "delete"};
  nlohmann::json valid_racf_options_operations{"alter", "extract"};
  nlohmann::json valid_no_add_operations{"alter", "extract", "delete"};
  nlohmann::json valid_extract_admin_types{
      "user",     "group",    "group-connection",
      "resource", "data-set", "racf-options",
      "keyring"};
  nlohmann::json valid_non_extract_admin_types{
      "user",     "group",        "group-connection", "resource",
      "data-set", "racf-options", "permission"};
  nlohmann::json no_validation = nlohmann::json::object();

  // Validate parameters that are always necessary first
  if (validate_parameter(request_p, errors_p, "operation", &valid_operations,
                         *admin_type_p, true) == 0) {
    *admin_type_p = (*request_p)["admin_type"].get<std::string>();
  }
  if (validate_parameter(request_p, errors_p, "admin_type",
                         &valid_non_extract_admin_types, *admin_type_p,
                         true) == 0) {
    *operation_p = (*request_p)["operation"].get<std::string>();
  }
  if (!(errors_p)->empty()) {
    // Not enough information to validate other parameters
    return;
  }
  checked_parameters.push_back("operation");
  if (*operation_p == "extract") {
    // Call will go to IRRSEQ00 or IRRSDL00 for EXTRACT operations
    validate_parameter(request_p, errors_p, "admin_type",
                       &valid_extract_admin_types, *admin_type_p, true);
    if (*admin_type_p != "racf-options") {
      if (validate_parameter(request_p, errors_p, "profile_name",
                             &no_validation, *admin_type_p, true) == 0) {
        *profile_name_p = (*request_p)["profile_name"].get<std::string>();
      }
      checked_parameters.push_back("profile_name");
      if (*admin_type_p == "resource") {
        if (validate_parameter(request_p, errors_p, "class_name",
                               &no_validation, *admin_type_p, true) == 0) {
          *class_name_p = (*request_p)["class_name"].get<std::string>();
        }
        checked_parameters.push_back("class_name");
      }
    }
    validate_supplemental_parameters(request_p, errors_p, admin_type_p,
                                     operation_p, &checked_parameters, false);
    return;
  }
  // Call will go to IRRSMO00 for NON-EXTRACT operations
  // Each operation has required or allowed parameters, these checks are made in
  // order to validate that every required parameter is specified and optional
  // parameters are only used for supported operations and admin types
  bool traits_allowed = true;
  validate_parameter(request_p, errors_p, "run", &yes_or_no, (*admin_type_p),
                     false);
  checked_parameters.push_back("run");
  if (*admin_type_p == "racf-options") {
    // SETROPTS only requires 'admin_type' and 'operation' and allows 'run'
    // SETROPTS only supports 'alter' and 'extract' operations
    validate_parameter(request_p, errors_p, "operation",
                       &valid_racf_options_operations, *admin_type_p, true);
    validate_supplemental_parameters(request_p, errors_p, admin_type_p,
                                     operation_p, &checked_parameters,
                                     traits_allowed);
    return;
  }
  traits_allowed = !(*operation_p == "delete");
  if (validate_parameter(request_p, errors_p, "profile_name", &no_validation,
                         *admin_type_p, true) == 0) {
    *profile_name_p = (*request_p)["profile_name"].get<std::string>();
  }
  checked_parameters.push_back("profile_name");
  if ((*admin_type_p == "user") || (*admin_type_p == "group")) {
    // USER and GROUP also allow 'override' and require 'profile_name'
    validate_supplemental_parameters(request_p, errors_p, admin_type_p,
                                     operation_p, &checked_parameters,
                                     traits_allowed);
    return;
  }
  if (*admin_type_p == "group-connection") {
    // GROUP-CONNECTION also requires 'goup' but no other admin types do
    // GROUP-CONNECTION only supports 'alter', 'delete' and 'extract' operations
    validate_parameter(request_p, errors_p, "operation",
                       &valid_no_add_operations, *admin_type_p, true);
    if (validate_parameter(request_p, errors_p, "group", &no_validation,
                           *admin_type_p, true) == 0) {
      checked_parameters.push_back("group");
    }
    validate_supplemental_parameters(request_p, errors_p, admin_type_p,
                                     operation_p, &checked_parameters,
                                     traits_allowed);
    return;
  }
  if (*admin_type_p == "permission") {
    // PERMISSION also requires 'auth_id' but no other admin types do
    // PERMISSION only supports 'alter', 'delete' and 'extract' operations
    validate_parameter(request_p, errors_p, "operation",
                       &valid_no_add_operations, *admin_type_p, true);
    if (validate_parameter(request_p, errors_p, "auth_id", &no_validation,
                           *admin_type_p, true) == 0) {
      checked_parameters.push_back("auth_id");
    }
  }

  if ((*admin_type_p == "resource") || (*admin_type_p == "permission")) {
    // RESOURCE and PERMISSION also require 'class_name' but DATA-SET does not
    if (validate_parameter(request_p, errors_p, "class_name", &no_validation,
                           *admin_type_p, true) == 0) {
      *class_name_p = (*request_p)["class_name"].get<std::string>();
    } else {
      validate_supplemental_parameters(request_p, errors_p, admin_type_p,
                                       operation_p, &checked_parameters,
                                       traits_allowed);
      return;
    }
    checked_parameters.push_back("class_name");
    if ((*admin_type_p == "resource") || (*class_name_p != "dataset")) {
      // RESOURCE and PERMISSION (for non DATASET class) do not support any
      // additional parameters
      validate_supplemental_parameters(request_p, errors_p, admin_type_p,
                                       operation_p, &checked_parameters,
                                       traits_allowed);
      return;
    }
  }
  if ((*admin_type_p == "data-set") || (*admin_type_p == "permission")) {
    // DATA-SET and PERMISSION (for DATASET class) allow for 'volume' and
    // 'generic' parameters
    validate_parameter(request_p, errors_p, "volume", &no_validation,
                       *admin_type_p, false);
    checked_parameters.push_back("volume");
    validate_parameter(request_p, errors_p, "generic", &yes_or_no,
                       *admin_type_p, false);
    checked_parameters.push_back("generic");
    validate_supplemental_parameters(request_p, errors_p, admin_type_p,
                                     operation_p, &checked_parameters,
                                     traits_allowed);
  }
}

uint8_t validate_parameter(nlohmann::json* request_p, nlohmann::json* errors_p,
                           std::string json_key, nlohmann::json* valid_values_p,
                           std::string admin_type, bool required) {
  if (!request_p->contains(json_key) && required && admin_type.empty()) {
    // Required Parameter for ALL Admin Types
    update_error_json(errors_p, REQUIRED_PARAMETER,
                      nlohmann::json{
                          {"parameter", json_key}
    });
    return REQUIRED_PARAMETER;
  }
  if (!request_p->contains(json_key) && required) {
    // Required Parameter for passed Admin Type
    update_error_json(errors_p, MISSING_PARAMETER,
                      nlohmann::json{
                          { "parameter",   json_key},
                          {"admin_type", admin_type}
    });
    return MISSING_PARAMETER;
  }
  if (!request_p->contains(json_key)) {
    // Parameter is not required and not present
    return 0;
  }
  if (!(*request_p)[json_key].is_string()) {
    // Parameter needs to be a string
    update_error_json(errors_p, BAD_PARAMETER_DATA_TYPE,
                      nlohmann::json{
                          {"parameter", json_key},
                          {"data_type", "string"}
    });
    return BAD_PARAMETER_DATA_TYPE;
  }
  std::string val = (*request_p)[json_key].get<std::string>();
  std::transform(val.begin(), val.end(), val.begin(), ::tolower);
  if (val.empty()) {
    // Parameter key is present but value is an empty string
    update_error_json(errors_p, BAD_PARAMETER_VALUE,
                      nlohmann::json{
                          {      "parameter", json_key},
                          {"parameter_value",      val}
    });
    return BAD_PARAMETER_VALUE;
  }
  if (valid_values_p->empty()) {
    return 0;  // Parameter has no validation and is present
  }
  for (const auto& item : valid_values_p->items()) {
    if (val.compare(item.value()) == 0) {
      return 0;  // Parameter meets validation rules
    }
  }
  // Parameter value does not meet validation rules
  update_error_json(errors_p, BAD_PARAMETER_VALUE,
                    nlohmann::json{
                        {      "parameter", json_key},
                        {"parameter_value",      val}
  });
  return BAD_PARAMETER_VALUE;
}

void validate_supplemental_parameters(nlohmann::json* request_p,
                                      nlohmann::json* errors_p,
                                      std::string* admin_type,
                                      std::string* operation,
                                      nlohmann::json* checked_parameters_p,
                                      bool traits_allowed) {
  nlohmann::json stable_parameters{"run_as_userid", "admin_type"};
  checked_parameters_p->insert(checked_parameters_p->end(),
                               stable_parameters.begin(),
                               stable_parameters.end());

  for (const auto& item : request_p->items()) {
    if ((item.key() == "traits") && traits_allowed) {
      if (!(*request_p)["traits"].is_structured()) {
        update_error_json(errors_p, BAD_PARAMETER_DATA_TYPE,
                          nlohmann::json{
                              {"parameter", "traits"},
                              {"data_type",   "json"}
        });
      }
      continue;
    } else if (item.key() == "traits") {
      update_error_json(
          errors_p, BAD_PARAMETER_FOR_OPERATION,
          nlohmann::json{
              {"parameter",   "traits"},
              {"operation", *operation}
      });
      continue;
    }
    bool found_match = false;
    for (const auto& allowed : checked_parameters_p->items()) {
      if (item.key().compare(allowed.value()) == 0) {
        found_match = true;
        continue;
      }
    }
    if (found_match) {
      continue;
    }

    // Anything else shouldn't be here
    update_error_json(
        errors_p, BAD_PARAMETER_NAME,
        nlohmann::json{
            { "parameter",  item.key()},
            {"admin_type", *admin_type}
    });
  }
  return;
}
