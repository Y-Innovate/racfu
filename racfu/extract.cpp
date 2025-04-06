#include "extract.hpp"

#include <cstring>

void preserve_raw_request(const char *arg_area, char **raw_request,
                          const int *raw_request_length) {
  *raw_request = static_cast<char *>(calloc(*raw_request_length, sizeof(char)));

  if (*raw_request == NULL) {
    perror(
        "Warn - Unable to allocate space to preserve the "
        "raw request for profile extract.\n");
    return;
  }

  memcpy(*raw_request, arg_area, *raw_request_length);
}
