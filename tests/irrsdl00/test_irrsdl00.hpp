#ifndef __RACFU_TEST_IRRSDL00_H_
#define __RACFU_TEST_IRRSDL00_H_

#define IRRSDL00_REQUEST_SAMPLES "./tests/irrsdl00/request_samples/"
#define IRRSDL00_RESULT_SAMPLES "./tests/irrsdl00/result_samples/"

/*************************************************************************/
/* Request Samples                                                       */
/*************************************************************************/
// Keyring
#define TEST_EXTRACT_KEYRING_REQUEST_JSON \
  IRRSDL00_REQUEST_SAMPLES "keyring/test_extract_keyring_request.json"
#define TEST_EXTRACT_KEYRING_REQUEST_RAW \
  IRRSDL00_REQUEST_SAMPLES "keyring/test_extract_keyring_request.bin"
#define TEST_EXTRACT_KEYRING_REQUEST_KEYRING_NOT_FOUND_JSON \
  IRRSDL00_REQUEST_SAMPLES                                  \
      "keyring/test_extract_keyring_request_keyring_not_found.json"
#define TEST_EXTRACT_KEYRING_REQUEST_REQUIRED_PARAMETER_MISSING_JSON \
  IRRSDL00_REQUEST_SAMPLES                                           \
  "keyring/test_extract_keyring_request_required_parameter_missing.json"

/*************************************************************************/
/* Result Samples                                                        */
/*************************************************************************/
// Keyring
#define TEST_EXTRACT_KEYRING_RESULT_JSON \
  IRRSDL00_RESULT_SAMPLES "keyring/test_extract_keyring_result.json"
#define TEST_EXTRACT_KEYRING_RESULT_RAW \
  IRRSDL00_RESULT_SAMPLES "keyring/test_extract_keyring_result.bin"
#define TEST_EXTRACT_KEYRING_RESULT_KEYRING_NOT_FOUND_JSON \
  IRRSDL00_RESULT_SAMPLES                                  \
      "keyring/test_extract_keyring_result_keyring_not_found.json"
#define TEST_EXTRACT_KEYRING_RESULT_KEYRING_NOT_FOUND_RAW \
  IRRSDL00_RESULT_SAMPLES                                 \
      "keyring/test_extract_keyring_result_keyring_not_found.bin"

/*************************************************************************/
/* Prototypes                                                            */
/*************************************************************************/
// Keyring
void test_generate_extract_keyring_request();
void test_parse_extract_keyring_result();
void test_parse_extract_keyring_result_keyring_not_found();
void test_parse_extract_keyring_result_required_parameter_missing();

#endif
