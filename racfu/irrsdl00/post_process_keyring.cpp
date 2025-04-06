#include "post_process_keyring.hpp"

nlohmann::json post_process_keyring(
    keyring_extract_parms_results_t *keyring_results) {
  nlohmann::json profile;
  profile["profile"] = nlohmann::json::object();

  // Repeat Group Variables
  std::vector<nlohmann::json> repeat_group_rings;
  int repeat_group_rings_count;

  repeat_group_rings_count = keyring_results->result_buffer->ring_count;
  char *work = keyring_results->result_buffer->ring_info;

  //for (int i = 0; i < repeat_group_rings_count; i++) {
  //  repeat_group_rings.push_back(nlohmann::json::object());
  //}

  profile["profile"]["keyrings"] = repeat_group_rings;

  return profile;
}
