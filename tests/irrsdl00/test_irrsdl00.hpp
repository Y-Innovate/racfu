#ifndef __RACFU_TEST_EXTRACT_SDL_H_
#define __RACFU_TEST_EXTRACT_SDL_H_

#define IRRSDL00_REQUEST_SAMPLES "./tests/irrsdl00/request_samples/"
#define IRRSDL00_RESULT_SAMPLES "./tests/irrsdl00/result_samples/"

/*************************************************************************/
/* Request Samples                                                       */
/*************************************************************************/
// Resource
#define TEST_EXTRACT_KEYRING_REQUEST_JSON \
  IRRSDL00_REQUEST_SAMPLES "keyring/test_extract_keyring_request.json"
#define TEST_EXTRACT_KEYRING_REQUEST_RAW \
  IRRSDL00_REQUEST_SAMPLES "keyring/test_extract_keyring_request.bin"

/*************************************************************************/
/* Result Samples                                                        */
/*************************************************************************/
// Keyring
#define TEST_EXTRACT_KEYRING_RESULT_JSON \
  IRRSDL00_RESULT_SAMPLES "keyring/test_extract_keyring_result.json"
#define TEST_EXTRACT_KEYRING_RESULT_RAW \
  IRRSDL00_RESULT_SAMPLES "keyring/test_extract_keyring_result.bin"

/*************************************************************************/
/* Prototypes                                                            */
/*************************************************************************/
// Keyring
void test_parse_extract_keyring_result();

#endif
