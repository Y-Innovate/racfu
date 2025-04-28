#include "security_admin.hpp"

#include <stdexcept>

#define _POSIX_C_SOURCE 200112L
#include <arpa/inet.h>

#include "irrsmo00.hpp"
#include "irrsmo00_error.hpp"
#include "profile_extractor.hpp"
#include "profile_post_processor.hpp"
#include "racfu_error.hpp"
#include "xml_generator.hpp"
#include "xml_parser.hpp"

namespace RACFu {
SecurityAdmin::SecurityAdmin(racfu_result_t *p_result, bool debug) {
  Logger::getInstance().setDebug(debug);
  request_ = SecurityRequest(p_result);
}

void SecurityAdmin::makeRequest(const char *p_request_json_string) {
  nlohmann::json request_json;

  try {
    // Parse Request JSON
    try {
      request_json = nlohmann::json::parse(p_request_json_string);
    } catch (const nlohmann::json::parse_error &ex) {
      request_.setRACFuReturnCode(8);
      throw RACFuError(std::string("Syntax error in request JSON at byte ") +
                       std::to_string(ex.byte));
    }

    Logger::getInstance().debug("Validating parameters ...");
    try {
      RACFU_SCHEMA_VALIDATOR.validate(request_json);
    } catch (const std::exception &ex) {
      request_.setRACFuReturnCode(8);
      throw RACFuError(
          "The provided request JSON does not contain a valid request");
    }
    Logger::getInstance().debug("Done");

    // Load Request
    request_.load(request_json);

    // Make Request To Corresponding Callable Service
    if (request_.getOperation() == "extract") {
      Logger::getInstance().debug("Entering IRRSEQ00 path");
      SecurityAdmin::doExtract();
    } else {
      Logger::getInstance().debug("Entering IRRSMO00 path");
      SecurityAdmin::doAddAlterDelete();
    }
  } catch (const RACFuError &ex) {
    request_.setErrors(ex.getErrors());
  } catch (const IRRSMO00Error &ex) {
    request_.setErrors(ex.getErrors());
  } catch (const std::exception &ex) {
    request_.setRACFuReturnCode(8);
    request_.setErrors({ex.what()});
  }
  request_.buildResult();
}

void SecurityAdmin::doExtract() {
  // Extract Profile
  ProfileExtractor extractor;
  extractor.extract(request_);

  ProfilePostProcessor post_processor;
  if (request_.getAdminType() != "racf-options") {
    // Post Process Generic Extract Result
    post_processor.postProcessGeneric(request_);
  } else {
    // Post Process RACF Options Extract Result
    post_processor.postProcessRACFOptions(request_);
  }

  Logger::getInstance().debug("Profile extract result has been post-processed");
}

void SecurityAdmin::doAddAlterDelete() {
  IRRSMO00 irrsmo00;

  // Check if profile exists already for some alter operations
  const std::string &operation    = request_.getOperation();
  const std::string &admin_type   = request_.getAdminType();
  const std::string &profile_name = request_.getProfileName();
  const std::string &class_name   = request_.getClassName();
  if ((operation == "alter") and
      ((admin_type == "group") or (admin_type == "user") or
       (admin_type == "data-set") or (admin_type == "resource"))) {
    Logger::getInstance().debug("Verifying that profile existis for alter ...");
    if (!irrsmo00.does_profile_exist(request_)) {
      request_.setRACFuReturnCode(8);
      if (class_name.empty()) {
        throw RACFuError("unable to alter '" + profile_name +
                         "' because the profile does not exist");
      } else {
        throw RACFuError("unable to alter '" + profile_name + "' in the '" +
                         class_name +
                         "' class because the profile does not exist");
      }
    }

    // Since the profile exists check was successful,
    // we can clean up the preserved result information.
    Logger::getInstance().debugFree(request_.getRawRequestPointer());
    std::free(request_.getRawRequestPointer());
    Logger::getInstance().debug("Done");
    request_.setRawRequestPointer(nullptr);
    request_.setRawRequestLength(0);
    Logger::getInstance().debugFree(request_.getRawResultPointer());
    std::free(request_.getRawResultPointer());
    Logger::getInstance().debug("Done");
    request_.setRawResultPointer(nullptr);
    request_.setRawResultLength(0);

    Logger::getInstance().debug("Done");
  }

  // Build Request
  XMLGenerator generator;
  generator.buildXMLString(request_);
  Logger::getInstance().debug("Calling IRRSMO00 ...");
  irrsmo00.call_irrsmo00(request_, false);
  Logger::getInstance().debug("Done");

  // Parse Result
  XMLParser parser;
  request_.setIntermediateResultJSON(parser.buildJSONString(request_));

  // Post-Process Result
  irrsmo00.post_process_smo_json(request_);

  Logger::getInstance().debug("Done");
}
}  // namespace RACFu
