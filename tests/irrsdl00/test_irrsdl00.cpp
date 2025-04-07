#include "tests/irrsdl00/test_irrsdl00.hpp"

#define _POSIX_C_SOURCE 200112L
#include <arpa/inet.h>
#include <sys/stat.h>

#include <cstring>

#include "tests/unit_test_utilities.hpp"

/*************************************************************************/
/* Keyring                                                               */
/*************************************************************************/
void test_generate_extract_keyring_request() {
  test_extract_request_generation(TEST_EXTRACT_KEYRING_REQUEST_JSON,
                                  TEST_EXTRACT_KEYRING_REQUEST_RAW, false,
                                  false);
}

void test_parse_extract_keyring_result() {
  test_parse_extract_result(TEST_EXTRACT_KEYRING_REQUEST_JSON,
                            TEST_EXTRACT_KEYRING_RESULT_JSON,
                            TEST_EXTRACT_KEYRING_RESULT_RAW, false);
}
