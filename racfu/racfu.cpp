#include "racfu.h"

#define _POSIX_C_SOURCE 200112L
#include <arpa/inet.h>

#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

#include "errors.hpp"
#include "extract_seq.hpp"
#include "extract_sdl.hpp"
#include "irrsmo00.hpp"
#include "logger.hpp"
#include "messages.h"
#include "parameter_validation.hpp"
#include "post_process.hpp"
#include "post_process_keyring.hpp"
#include "xml_generator.hpp"
#include "xml_parser.hpp"

void do_extract(const char *admin_type, const char *profile_name,
                const char *auth_id, const char *class_name,
                racfu_result_t *result, racfu_return_codes_t *return_codes_p,
                Logger *logger_p);

void do_add_alter_delete(const char *admin_type, const char *profile_name,
                         const char *class_name, const char *operation,
                         const char *surrogate_userid, bool check_first,
                         nlohmann::json *full_request_json_p,
                         racfu_result_t *results,
                         racfu_return_codes_t *return_codes_p,
                         Logger *logger_p);

void build_result(const char *operation, char *raw_result,
                  int raw_result_length, char *raw_request,
                  int raw_request_length,
                  nlohmann::json *intermediate_result_json_p,
                  racfu_result_t *result, racfu_return_codes_t *return_codes_p,
                  Logger *logger_p);

void racfu(racfu_result_t *result, const char *request_json, bool debug) {
  Logger logger = Logger(debug);
  nlohmann::json request, errors;
  std::string operation = "", admin_type = "", profile_name = "",
              auth_id = "", class_name = "";
  racfu_return_codes_t return_codes = {-1, -1, -1, -1};
  const char *profile_name_ptr      = NULL;
  const char *auth_id_ptr           = NULL;
  const char *class_name_ptr        = NULL;
  const char *surrogate_userid      = NULL;
  try {
    request = nlohmann::json::parse(request_json);
  } catch (nlohmann::json::parse_error &ex) {
    update_error_json(&errors, SYNTAX_ERROR,
                      nlohmann::json{
                          {"byte", ex.byte}
    });
    return_codes.racfu_return_code = 8;
    build_result(operation.c_str(), nullptr, 0, nullptr, 0, &errors, result,
                 &return_codes, &logger);
    return;
  }
  logger.debug(MSG_VALIDATING_PARAMETERS);
  validate_parameters(&request, &errors, &operation, &admin_type, &profile_name,
                      &auth_id, &class_name);
  if (!profile_name.empty()) {
    profile_name_ptr = profile_name.c_str();
  }
  if (!auth_id.empty()) {
    auth_id_ptr = auth_id.c_str();
  }
  if (!class_name.empty()) {
    class_name_ptr = class_name.c_str();
  }
  if (!errors.empty()) {
    return_codes.racfu_return_code = 8;
    build_result(operation.c_str(), nullptr, 0, nullptr, 0, &errors, result,
                 &return_codes, &logger);
    return;
  }
  logger.debug(MSG_DONE);

  operation  = request["operation"].get<std::string>();
  admin_type = request["admin_type"].get<std::string>();
  if (request.contains("profile_name")) {
    profile_name = request["profile_name"].get<std::string>().c_str();
  }
  if (request.contains("auth_id")) {
    auth_id = request["auth_id"].get<std::string>().c_str();
  }
  if (request.contains("class_name")) {
    class_name = request["class_name"].get<std::string>().c_str();
  }
  // Extract
  if (operation == "extract") {
    logger.debug(MSG_SEQ_PATH);
    do_extract(admin_type.c_str(), profile_name_ptr, auth_id_ptr, class_name_ptr,
               result, &return_codes, &logger);
    // Add/Alter/Delete
  } else {
    if (request.contains("run_as_userid")) {
      surrogate_userid = request["run_as_userid"].get<std::string>().c_str();
    }
    logger.debug(MSG_SMO_PATH);
    bool check_first =
        ((operation == "alter") &&
         ((admin_type == "group") || (admin_type == "user") ||
          (admin_type == "data-set") || (admin_type == "resource")));
    do_add_alter_delete(admin_type.c_str(), profile_name_ptr, class_name_ptr,
                        operation.c_str(), surrogate_userid, check_first,
                        &request, result, &return_codes, &logger);
  }
}

void do_extract(const char *admin_type, const char *profile_name,
                const char *auth_id, const char *class_name,
                racfu_result_t *racfu_result, racfu_return_codes_t *return_codes_p,
                Logger *logger_p) {
  char *raw_result  = NULL;
  char *raw_request = NULL;
  int raw_result_length, raw_request_length;
  uint8_t function_code;
  nlohmann::json profile_json;

  // Validate 'admin_type'
  if (strcmp(admin_type, "user") == 0) {
    function_code = USER_EXTRACT_FUNCTION_CODE;
  } else if (strcmp(admin_type, "group") == 0) {
    function_code = GROUP_EXTRACT_FUNCTION_CODE;
  } else if (strcmp(admin_type, "group-connection") == 0) {
    function_code = GROUP_CONNECTION_EXTRACT_FUNCTION_CODE;
  } else if (strcmp(admin_type, "resource") == 0) {
    function_code = RESOURCE_EXTRACT_FUNCTION_CODE;
  } else if (strcmp(admin_type, "data-set") == 0) {
    function_code = DATA_SET_EXTRACT_FUNCTION_CODE;
  } else if (strcmp(admin_type, "racf-options") == 0) {
    function_code = SETROPTS_EXTRACT_FUNCTION_CODE;
  } else if (strcmp(admin_type, "keyring") == 0) {
    function_code = KEYRING_EXTRACT_FUNCTION_CODE;
  } else {
    return_codes_p->racfu_return_code = 8;
  }

  // Do extract if function code is good.
  if (return_codes_p->racfu_return_code == -1) {
    if (function_code != KEYRING_EXTRACT_FUNCTION_CODE) {
      raw_result = extract_seq(profile_name, class_name, function_code, &raw_request,
                               &raw_request_length, return_codes_p, logger_p);
    } else {
      raw_result = extract_sdl(profile_name, auth_id, function_code, &raw_request,
                               &raw_request_length, return_codes_p, logger_p);
    }
    if (raw_result == NULL) {
      return_codes_p->racfu_return_code = 4;
    } else {
      return_codes_p->racfu_return_code = 0;
    }
  }

  // Build Failure Result
  if (raw_result == NULL) {
    if (strcmp(admin_type, "racf-options") != 0) {
      update_error_json(&profile_json["errors"], EXTRACT_FAILED,
                        nlohmann::json{
                            {  "admin_type",   std::string(admin_type)},
                            {"profile_name", std::string(profile_name)}
      });
    } else {
      update_error_json(&profile_json["errors"], EXTRACT_FAILED_RACF_OPTIONS,
                        nlohmann::json{
                            {"admin_type", std::string(admin_type)}
      });
    }
    build_result("extract", nullptr, 0, raw_request, raw_request_length,
                 &profile_json, racfu_result, return_codes_p, logger_p);
    return;
  }

  // Post Process Generic Result
  if (strcmp(admin_type, "racf-options") != 0) {
    if (strcmp(admin_type, "keyring") != 0) {
      generic_extract_parms_results_t *generic_result_buffer =
          reinterpret_cast<generic_extract_parms_results_t *>(raw_result);
      raw_result_length = ntohl(generic_result_buffer->result_buffer_length);
      logger_p->debug(MSG_RESULT_SEQ_GENERIC,
                      logger_p->cast_hex_string(raw_result, raw_result_length));
      profile_json = post_process_generic(generic_result_buffer, admin_type);
    } else {
      keyring_extract_parms_results_t *keyring_results =
          reinterpret_cast<keyring_extract_parms_results_t *>(raw_result);
      raw_result_length = ntohl(keyring_results->result_buffer_length);
      logger_p->debug(MSG_RESULT_SDL_KEYRING,
                      logger_p->cast_hex_string((char*) keyring_results->result_buffer, raw_result_length));
      profile_json = post_process_keyring(keyring_results);
    }
    // Post Process Setropts Result
  } else {
    setropts_extract_results_t *setropts_result_buffer =
        reinterpret_cast<setropts_extract_results_t *>(raw_result);
    raw_result_length = ntohl(setropts_result_buffer->result_buffer_length);
    logger_p->debug(MSG_RESULT_SEQ_SETROPTS,
                    logger_p->cast_hex_string(raw_result, raw_result_length));
    profile_json = post_process_setropts(setropts_result_buffer);
  }

  logger_p->debug(MSG_SEQ_POST_PROCESS);

  // Build Success Result
  build_result("extract", raw_result, raw_result_length, raw_request,
               raw_request_length, &profile_json, racfu_result, return_codes_p,
               logger_p);

  return;
}

void do_add_alter_delete(const char *admin_type, const char *profile_name,
                         const char *class_name, const char *operation,
                         const char *surrogate_userid, bool check_first,
                         nlohmann::json *full_request_json_p,
                         racfu_result_t *racfu_result,
                         racfu_return_codes_t *return_codes_p,
                         Logger *logger_p) {
  char running_userid[8] = {0};
  char *xml_response_string, *xml_request_string;
  int irrsmo00_options, saf_rc, racf_rc, racf_rsn, racfu_rc;
  unsigned int result_buffer_size, request_length;

  nlohmann::json intermediate_result_json, errors{};
  XmlParser *parser       = new XmlParser();
  XmlGenerator *generator = new XmlGenerator();

  irrsmo00_options        = 13;
  result_buffer_size      = 10000;
  saf_rc                  = 0;
  racf_rc                 = 0;
  racf_rsn                = 0;
  racfu_rc                = 0;

  xml_request_string      = generator->build_xml_string(
      admin_type, full_request_json_p, &errors, running_userid,
      &irrsmo00_options, &request_length, logger_p);

  if (!errors.empty()) {
    return_codes_p->racfu_return_code = 8;
    build_result(operation, nullptr, 0, xml_request_string, request_length,
                 &errors, racfu_result, return_codes_p, logger_p);
    return;
  }

  if (check_first) {
    logger_p->debug(MSG_SMO_VALIDATE_EXIST);
    if (!does_profile_exist(std::string(admin_type), std::string(profile_name),
                            class_name, running_userid)) {
      if (class_name == NULL) {
        update_error_json(&errors, BAD_ALTER_TARGET,
                          nlohmann::json{
                              {"name", std::string(profile_name)}
        });
      } else {
        update_error_json(&errors, BAD_ALTER_TARGET_CLASS,
                          nlohmann::json{
                              { "name", std::string(profile_name)},
                              {"class",   std::string(class_name)}
        });
      }
    }
    if (!errors.empty()) {
      return_codes_p->racfu_return_code = 8;
      build_result(operation, nullptr, 0, xml_request_string, request_length,
                   &errors, racfu_result, return_codes_p, logger_p);
      return;
    }
    logger_p->debug(MSG_DONE);
  }

  logger_p->debug(MSG_CALLING_SMO);

  xml_response_string =
      call_irrsmo00(xml_request_string, running_userid, &result_buffer_size,
                    irrsmo00_options, &saf_rc, &racf_rc, &racf_rsn);

  logger_p->debug(MSG_DONE);

  return_codes_p->saf_return_code  = saf_rc;
  return_codes_p->racf_return_code = racf_rc;
  return_codes_p->racf_reason_code = racf_rsn;

  intermediate_result_json =
      parser->build_json_string(xml_response_string, &racfu_rc, logger_p);

  logger_p->debug(MSG_SMO_POST_PROCESS);
  logger_p->debug(intermediate_result_json.dump());
  // Maintain any RC 4's from parsing xml or post-processing json
  racfu_rc =
      racfu_rc | post_process_smo_json(&intermediate_result_json, profile_name,
                                       admin_type, class_name);
  logger_p->debug(MSG_DONE);

  return_codes_p->racfu_return_code = racfu_rc;

  delete generator;
  delete parser;
  // free xml_response_string;
  // free json_res_string;
  // free xml_request_string;

  // Build Success Result
  build_result(operation, xml_response_string, result_buffer_size,
               xml_request_string, request_length, &intermediate_result_json,
               racfu_result, return_codes_p, logger_p);
  // TODO: Make sure this isn't leaking memory?
  return;
}

void build_result(const char *operation, char *raw_result,
                  int raw_result_length, char *raw_request,
                  int raw_request_length,
                  nlohmann::json *intermediate_result_json_p,
                  racfu_result_t *racfu_result,
                  racfu_return_codes_t *return_codes_p, Logger *logger_p) {
  logger_p->debug(MSG_BUILD_RESULT);

  // Build Result JSON starting with Return Codes
  nlohmann::json result_json = {
      {"return_codes",
       {{"saf_return_code", return_codes_p->saf_return_code},
        {"racf_return_code", return_codes_p->racf_return_code},
        {"racf_reason_code", return_codes_p->racf_reason_code},
        {"racfu_return_code", return_codes_p->racfu_return_code}}}
  };

  // Convert '-1' to 'nullptr'
  if (return_codes_p->saf_return_code == -1) {
    result_json["return_codes"]["saf_return_code"] = nullptr;
  }
  if (return_codes_p->racf_return_code == -1) {
    result_json["return_codes"]["racf_return_code"] = nullptr;
  }
  if (return_codes_p->racf_reason_code == -1) {
    result_json["return_codes"]["racf_reason_code"] = nullptr;
  }
  if (return_codes_p->racf_return_code == -1) {
    result_json["return_codes"]["racf_return_code"] = nullptr;
  }
  if (return_codes_p->racfu_return_code == -1) {
    result_json["return_codes"]["racfu_return_code"] = nullptr;
  }

  if (intermediate_result_json_p->contains("errors")) {
    result_json.merge_patch(
        format_error_json(&((*intermediate_result_json_p)["errors"])));
  } else {
    if ((intermediate_result_json_p->empty()) &&
        (std::string(operation) == "extract")) {
      result_json["profile"] = nullptr;
    } else if (!intermediate_result_json_p->empty()) {
      result_json.merge_patch(*intermediate_result_json_p);
    }
  }

  // Convert profile JSON to C string.
  std::string result_json_cpp_string = result_json.dump();
  char *result_json_string           = static_cast<char *>(
      malloc(sizeof(char) * (result_json_cpp_string.size() + 1)));
  std::strcpy(result_json_string, result_json_cpp_string.c_str());

  // Build RACFu Result Structure
  racfu_result->raw_result         = raw_result;
  racfu_result->raw_result_length  = raw_result_length;
  racfu_result->raw_request        = raw_request;
  racfu_result->raw_request_length = raw_request_length;
  racfu_result->result_json        = result_json_string;

  logger_p->debug(MSG_DONE);

  return;
}
