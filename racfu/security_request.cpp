#include "security_request.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <new>

#include "irrseq00.hpp"
#ifdef __TOS_390__
#include <unistd.h>
#else
#include "zoslib.h"
#endif

namespace RACFu {
SecurityRequest::SecurityRequest() { p_result_ = nullptr; }

SecurityRequest::SecurityRequest(racfu_result_t* p_result) {
  p_result_ = p_result;
  // Free dynamically allocated memory from previous requests.
  if (p_result->raw_request != nullptr) {
    Logger::getInstance().debugFree(p_result->raw_request);
    std::free(p_result->raw_request);
    Logger::getInstance().debug("Done");
  }
  if (p_result->raw_result != nullptr) {
    Logger::getInstance().debugFree(p_result->raw_result);
    std::free(p_result->raw_result);
    Logger::getInstance().debug("Done");
  }
  if (p_result->result_json != nullptr) {
    Logger::getInstance().debugFree(p_result->result_json);
    std::free(p_result->result_json);
    Logger::getInstance().debug("Done");
  }
  p_result_->raw_request        = nullptr;
  p_result_->raw_request_length = 0;
  p_result_->raw_result         = nullptr;
  p_result_->raw_result_length  = 0;
  p_result_->result_json        = nullptr;
}

/*************************************************************************/
/* Request Getters                                                       */
/*************************************************************************/
const std::string& SecurityRequest::getAdminType() const { return admin_type_; }

const std::string& SecurityRequest::getOperation() const { return operation_; }

const std::string& SecurityRequest::getProfileName() const {
  return profile_name_;
}

const std::string& SecurityRequest::getClassName() const { return class_name_; }

const std::string& SecurityRequest::getGroup() const { return group_; }

const std::string& SecurityRequest::getVolume() const { return volume_; }
const std::string& SecurityRequest::getGeneric() const { return generic_; }

const char* SecurityRequest::getSurrogateUserID() const {
  return surrogate_userid_;
}

const nlohmann::json& SecurityRequest::getTraits() const { return traits_; }

uint8_t SecurityRequest::getFunctionCode() const { return function_code_; }

int SecurityRequest::getIRRSMO00Options() const { return irrsmo00_options_; }

/*************************************************************************/
/* Result Getters & Setters                                              */
/*************************************************************************/
void SecurityRequest::setRawRequestPointer(char* p_raw_request) {
  p_result_->raw_request = p_raw_request;
}

char* SecurityRequest::getRawRequestPointer() const {
  return p_result_->raw_request;
}

void SecurityRequest::setRawRequestLength(int raw_request_length) {
  p_result_->raw_request_length = raw_request_length;
}

int SecurityRequest::getRawRequestLength() const {
  return p_result_->raw_request_length;
}

void SecurityRequest::setRawResultPointer(char* p_raw_result) {
  p_result_->raw_result = p_raw_result;
}

char* SecurityRequest::getRawResultPointer() const {
  return p_result_->raw_result;
}

void SecurityRequest::setRawResultLength(int raw_result_length) {
  p_result_->raw_result_length = raw_result_length;
}

int SecurityRequest::getRawResultLength() const {
  return p_result_->raw_result_length;
}

void SecurityRequest::setSAFReturnCode(int saf_return_code) {
  return_codes_.saf_return_code = saf_return_code;
}

int SecurityRequest::getSAFReturnCode() const {
  return return_codes_.saf_return_code;
}

void SecurityRequest::setRACFReturnCode(int racf_return_code) {
  return_codes_.racf_return_code = racf_return_code;
}

int SecurityRequest::getRACFReturnCode() const {
  return return_codes_.racf_return_code;
}

void SecurityRequest::setRACFReasonCode(int racf_reason_code) {
  return_codes_.racf_reason_code = racf_reason_code;
}

int SecurityRequest::getRACFReasonCode() const {
  return return_codes_.racf_reason_code;
}

void SecurityRequest::setRACFuReturnCode(int racfu_return_code) {
  return_codes_.racfu_return_code = racfu_return_code;
}

void SecurityRequest::setErrors(const std::vector<std::string>& errors) {
  errors_ = errors;
}

void SecurityRequest::setIntermediateResultJSON(
    nlohmann::json intermediate_result_json) {
  intermediate_result_json_ = intermediate_result_json;
}

const nlohmann::json& SecurityRequest::getIntermediateResultJSON() const {
  return intermediate_result_json_;
}

/*************************************************************************/
/* Load Request & Build Result                                           */
/*************************************************************************/
void SecurityRequest::load(const nlohmann::json& request) {
  admin_type_ = request["admin_type"].get<std::string>();
  operation_  = request["operation"].get<std::string>();

  if (request.contains("traits")) {
    traits_ = request["traits"].get<nlohmann::json>();
  }

  if (admin_type_ == "user") {
    function_code_ = USER_EXTRACT_FUNCTION_CODE;
    profile_name_  = request["userid"].get<std::string>();
  } else if (admin_type_ == "group") {
    function_code_ = GROUP_EXTRACT_FUNCTION_CODE;
    profile_name_  = request["group"].get<std::string>();
  } else if (admin_type_ == "group-connection") {
    function_code_ = GROUP_CONNECTION_EXTRACT_FUNCTION_CODE;
    if (operation_ == "extract") {
      profile_name_ = request["userid"].get<std::string>() + "." +
                      request["group"].get<std::string>();
    } else {
      profile_name_ = request["userid"].get<std::string>();
      group_        = request["group"].get<std::string>();
    }
  } else if (admin_type_ == "resource") {
    function_code_ = RESOURCE_EXTRACT_FUNCTION_CODE;
    profile_name_  = request["resource"].get<std::string>();
    class_name_    = request["class"].get<std::string>();
  } else if (admin_type_ == "data-set") {
    function_code_ = DATA_SET_EXTRACT_FUNCTION_CODE;
    profile_name_  = request["data_set"].get<std::string>();
  } else if (admin_type_ == "racf-options") {
    function_code_ = RACF_OPTIONS_EXTRACT_FUNCTION_CODE;
  } else if (admin_type_ == "permission") {
    if (request.contains("data_set")) {
      profile_name_ = request["data_set"].get<std::string>();
      class_name_   = "DATASET";
    } else {
      profile_name_ = request["resource"].get<std::string>();
      class_name_   = request["class"].get<std::string>();
    }
    if (request.contains("group")) {
      traits_["base:authid"] = request["group"].get<std::string>();
    } else {
      traits_["base:authid"] = request["userid"].get<std::string>();
    }
  }

  // set to 15 to enable precheck
  if (operation_ == "add") {
    irrsmo00_options_ = 15;
  } else if (operation_ == "alter") {
    if (admin_type_ != "group-connection" and admin_type_ != "racf-options" and
        admin_type_ != "permission") {
      irrsmo00_options_ = 15;
    }
  }

  if (request.contains("volume")) {
    volume_ = request["volume"].get<std::string>();
  }

  if (request.contains("generic")) {
    if (request["generic"].get<bool>() == true) {
      generic_ = "yes";
    } else {
      generic_ = "no";
    }
  }

  if (request.contains("run_as_userid")) {
    std::string surrogate_userid_string = request.get<std::string>();
    Logger::getInstance().debug("Running under the authority of user: " +
                                surrogate_userid_string);
    const int userid_length = surrogate_userid_string.length();
    strncpy(surrogate_userid_, surrogate_userid_string.c_str(), userid_length);
    __a2e_l(surrogate_userid_, userid_length);
  }
}

void SecurityRequest::buildResult() {
  Logger::getInstance().debug("Building result JSON ...");
  // Build Result JSON starting with Return Codes
  nlohmann::json result_json = {
      {"return_codes",
       {{"saf_return_code", return_codes_.saf_return_code},
        {"racf_return_code", return_codes_.racf_return_code},
        {"racf_reason_code", return_codes_.racf_reason_code},
        {"racfu_return_code", return_codes_.racfu_return_code}}}
  };

  // Convert '-1' to 'nullptr'
  if (return_codes_.saf_return_code == -1) {
    result_json["return_codes"]["saf_return_code"] = nullptr;
  }
  if (return_codes_.racf_return_code == -1) {
    result_json["return_codes"]["racf_return_code"] = nullptr;
  }
  if (return_codes_.racf_reason_code == -1) {
    result_json["return_codes"]["racf_reason_code"] = nullptr;
  }
  if (return_codes_.racf_return_code == -1) {
    result_json["return_codes"]["racf_return_code"] = nullptr;
  }
  if (return_codes_.racfu_return_code == -1) {
    result_json["return_codes"]["racfu_return_code"] = nullptr;
  }

  if (!errors_.empty()) {
    result_json["errors"] = errors_;
  }

  if (intermediate_result_json_ != nullptr and errors_.empty()) {
    if (!intermediate_result_json_.empty()) {
      result_json.merge_patch(intermediate_result_json_);
    }
  }

  // Convert profile JSON to C string.
  std::string result_json_string = result_json.dump();
  Logger::getInstance().debug("Result JSON:", result_json_string);
  try {
    auto result_json_unique_ptr =
        std::make_unique<char[]>(result_json_string.size() + 1);
    Logger::getInstance().debugAllocate(result_json_unique_ptr.get(), 64,
                                        result_json_string.size() + 1);
    std::memset(result_json_unique_ptr.get(), 0, result_json_string.size() + 1);
    std::strcpy(result_json_unique_ptr.get(), result_json_string.c_str());
    p_result_->result_json = result_json_unique_ptr.get();
    result_json_unique_ptr.release();
    Logger::getInstance().debug("Done");
  } catch (const std::bad_alloc& ex) {
    std::perror(
        "Warn - Unable to allocate space for the result JSON string.\n");
  }
}
}  // namespace RACFu
