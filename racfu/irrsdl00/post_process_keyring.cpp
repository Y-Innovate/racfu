#include "post_process_keyring.hpp"

nlohmann::json post_process_keyring(
    keyring_extract_parms_results_t *keyring_results) {
  nlohmann::json profile;
  profile["profile"] = nlohmann::json::object();

  int nLen;
  char cRACFUserId[9];
  char cRingName[238];
  char cLabel[256];

  std::vector<nlohmann::json> repeat_group_rings;
  int repeat_group_rings_count;

  std::vector<nlohmann::json> repeat_group_certs;
  int repeat_group_certs_count;

  repeat_group_rings_count = ((ring_result_t*) ((cddlx_get_ring_t*) keyring_results->result_buffer)->cddlx_ring_res_ptr)->ring_count;
  char *work = ((ring_result_t*) ((cddlx_get_ring_t*) keyring_results->result_buffer)->cddlx_ring_res_ptr)->ring_info;

  for (int i = 0; i < repeat_group_rings_count; i++) {
    repeat_group_rings.push_back(nlohmann::json::object());

    memset(&cRACFUserId[0], 0, 9);
    nLen = *work;
    work++;
    strncpy(&cRACFUserId[0], work, nLen);
    __e2a_l(&cRACFUserId[0], nLen);
    repeat_group_rings[i]["ring_owner"] = cRACFUserId;
    work += nLen;

    memset(&cRingName[0], 0, 238);
    nLen = *work;
    work++;
    strncpy(&cRingName[0], work, nLen);
    __e2a_l(&cRingName[0], nLen);
    repeat_group_rings[i]["ring_name"] = cRingName;

    repeat_group_certs_count = *((int*) work);
    work += 4;

    for (int j = 0; j < repeat_group_certs_count; j++) {
      repeat_group_certs.push_back(nlohmann::json::object());

      memset(&cLabel[0], 0, 256);
      nLen = *work;
      work++;
      strncpy(&cLabel[0], work, nLen);
      __e2a_l(&cLabel[0], nLen);
      repeat_group_certs[j]["label"] = cLabel;
      work += nLen;

      memset(&cRACFUserId[0], 0, 9);
      nLen = *work;
      work++;
      strncpy(&cRACFUserId[0], work, nLen);
      __e2a_l(&cRACFUserId[0], nLen);
      repeat_group_certs[j]["owner"] = cRACFUserId;
      work += nLen;
    }

    repeat_group_rings[i]["certificates"] = repeat_group_certs;
  }

  profile["profile"]["keyrings"] = repeat_group_rings;

  return profile;
}
