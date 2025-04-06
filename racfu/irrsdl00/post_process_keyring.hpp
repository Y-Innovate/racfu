#ifndef __RACFU_POST_PROCESS_KEYRING_H_
#define __RACFU_POST_PROCESS_KEYRING_H_

#include <nlohmann/json.hpp>

#include "extract_sdl.hpp"

nlohmann::json post_process_keyring(
    keyring_extract_parms_results_t *keyring_result_buffer);

#endif
