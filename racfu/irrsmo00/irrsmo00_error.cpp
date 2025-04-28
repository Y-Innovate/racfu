#include "irrsmo00_error.hpp"

#include <algorithm>

namespace RACFu {
IRRSMO00Error::IRRSMO00Error(const std::vector<std::string>& errors)
    : errors_(errors) {
  std::for_each(errors_.begin(), errors_.end(),
                [](std::string& error) { error = "irrsmo00: " + error; });
}

IRRSMO00Error::IRRSMO00Error(const std::string& error)
    : errors_({"irrsmo00: " + error}) {}

const std::vector<std::string>& IRRSMO00Error::getErrors() const {
  return errors_;
}

}  // namespace RACFu
