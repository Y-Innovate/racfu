#include "logger.hpp"

#include <string.h>

#include <csignal>
#include <iostream>
#include <string>

#ifdef __TOS_390__
#include <unistd.h>
#else
#include "zoslib.h"
#endif

std::string Logger::cast_hex_string(const char* input, int buffer_len) {
  // Cast data to hex so that small strings and buffers of hex values can be
  // printed to represent EBCDIC data
  std::string output = "";
  char buff[HEX_CHAR_SIZE - 1];
  int running_pad_len = 0;

  if (input == nullptr) {
    return "NULL";
  }

  if (buffer_len == 0) {
    buffer_len = strlen(input);
  }

  for (int i = 0; i < buffer_len; i++) {
    std::snprintf(buff, HEX_CHAR_SIZE - 1, "0x%02x",
                  (unsigned char)*(input + i));
    output += buff;
    if (i < (buffer_len - 1)) {
      output += ", ";
      if (((i + 2) * HEX_CHAR_SIZE + running_pad_len) % MAX_LINE_LENGTH <
          ((i + 1) * HEX_CHAR_SIZE + running_pad_len) % MAX_LINE_LENGTH) {
        size_t pad =
            MAX_LINE_LENGTH -
            ((i + 1) * HEX_CHAR_SIZE + running_pad_len) % MAX_LINE_LENGTH;
        output += std::string(pad, ' ');
        running_pad_len += pad;
      }
    }
  }

  return output;
}

void Logger::debug(const std::string& message, const std::string& body) const {
  if (!debug_mode) {
    return;
  }
  std::string racfu_header = "racfu:";
  if (isatty(fileno(stdout))) {
    racfu_header = ANSI_YELLOW + racfu_header + ANSI_RESET;
  }
  std::cout << racfu_header << " " << message << "\n";
  if (body != "") {
    for (size_t i = 0; i < body.length(); i += MAX_LINE_LENGTH) {
      std::cout << body.substr(i, MAX_LINE_LENGTH) << "\n";
    }
  }
}
