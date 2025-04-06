#include "post_process_keyring.hpp"

nlohmann::json post_process_keyring(
    keyring_extract_parms_results_t *keyring_result_buffer) {
  nlohmann::json profile;
  profile["profile"]    = nlohmann::json::object();

  return profile;
}
