#include "racfu_error.hpp"

#include <algorithm>

namespace RACFu {
RACFuError::RACFuError(const std::vector<std::string>& errors)
    : errors_(errors) {
  std::for_each(errors_.begin(), errors_.end(),
                [](std::string& error) { error = "racfu: " + error; });
}

RACFuError::RACFuError(const std::string& error)
    : errors_({"racfu: " + error}) {}

const std::vector<std::string>& RACFuError::getErrors() const {
  return errors_;
}

}  // namespace RACFu
