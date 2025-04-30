#include "tests/irrsdl00/test_irrsdl00.hpp"

#include <arpa/inet.h>
#include <sys/stat.h>

#include <cstring>

#include "tests/unit_test_utilities.hpp"

/*************************************************************************/
/* Keyring                                                               */
/*************************************************************************/
void test_generate_extract_keyring_request() {
  test_extract_request_irrsdl00_generation(TEST_EXTRACT_KEYRING_REQUEST_JSON,
                                           TEST_EXTRACT_KEYRING_REQUEST_RAW,
                                           false);
}

void test_parse_extract_keyring_result() {
  test_parse_extract_irrsdl00_result(TEST_EXTRACT_KEYRING_REQUEST_JSON,
                                     TEST_EXTRACT_KEYRING_RESULT_JSON,
                                     TEST_EXTRACT_KEYRING_RESULT_RAW, false);
}

void test_parse_extract_keyring_result_keyring_not_found() {
  test_parse_extract_irrsdl00_result_keyring_not_found(
      TEST_EXTRACT_KEYRING_REQUEST_KEYRING_NOT_FOUND_JSON,
      TEST_EXTRACT_KEYRING_RESULT_KEYRING_NOT_FOUND_JSON, false);
}

void test_parse_extract_keyring_result_required_parameter_missing() {
  test_validation_errors(
      TEST_EXTRACT_KEYRING_REQUEST_REQUIRED_PARAMETER_MISSING_JSON,
      TEST_PARAMETER_VALIDATION_ERROR_RESULT_JSON, false);
}
