#ifndef __RACFU_SECURITY_REQUEST_H_
#define __RACFU_SECURITY_REQUEST_H_

#include <nlohmann/json.hpp>
#include <vector>

#include "logger.hpp"
#include "racfu_result.h"

namespace RACFu {

class SecurityRequest {
 private:
  // Request
  std::string admin_type_;
  std::string operation_;
  std::string profile_name_;
  std::string class_name_;
  std::string group_;  // Only used by IRRSMO00 for group connection
  std::string volume_;
  std::string generic_;
  std::string owner_;
  std::string keyring_;
  char surrogate_userid_[8] = {0};
  nlohmann::json traits_;
  uint8_t function_code_ = 0;
  int irrsmo00_options_  = 13;
  // Result
  racfu_result_t* p_result_;
  racfu_return_codes_t return_codes_ = {-1, -1, -1, -1};
  std::vector<std::string> errors_;
  nlohmann::json intermediate_result_json_;

 public:
  SecurityRequest();
  explicit SecurityRequest(racfu_result_t* p_result);
  // Request Getters
  const std::string& getAdminType() const;
  const std::string& getOperation() const;
  const std::string& getProfileName() const;
  const std::string& getClassName() const;
  const std::string& getGroup() const;
  const std::string& getVolume() const;
  const std::string& getGeneric() const;
  const std::string& getOwner() const;
  const std::string& getKeyring() const;
  const char* getSurrogateUserID() const;
  const nlohmann::json& getTraits() const;
  uint8_t getFunctionCode() const;
  int getIRRSMO00Options() const;
  // Result Getters & Setters
  void setRawRequestPointer(char* p_raw_request);
  char* getRawRequestPointer() const;
  void setRawRequestLength(int raw_request_length);
  int getRawRequestLength() const;
  void setRawResultPointer(char* p_raw_result);
  char* getRawResultPointer() const;
  void setRawResultLength(int raw_result_length);
  int getRawResultLength() const;
  void setSAFReturnCode(int saf_return_code);
  int getSAFReturnCode() const;
  void setRACFReturnCode(int racf_return_code);
  int getRACFReturnCode() const;
  void setRACFReasonCode(int racf_reason_code);
  int getRACFReasonCode() const;
  void setRACFuReturnCode(int racfu_return_code);
  void setErrors(const std::vector<std::string>& errors);
  void setIntermediateResultJSON(nlohmann::json intermediate_result_json);
  const nlohmann::json& getIntermediateResultJSON() const;
  // Load Request & Build Result
  void load(const nlohmann::json& request);
  void buildResult();
};

}  // namespace RACFu

#endif
