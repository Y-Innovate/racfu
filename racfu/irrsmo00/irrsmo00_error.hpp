#ifndef __IRRSMO00_ERROR_H_
#define __IRRSMO00_ERROR_H_

#include <iostream>
#include <exception>
#include <vector>

namespace RACFu {
class IRRSMO00Error : public std::exception {
 private:
  std::vector<std::string> errors_;

 public:
  explicit IRRSMO00Error(const std::vector<std::string>& errors);
  explicit IRRSMO00Error(const std::string& error);
  const std::vector<std::string>& getErrors() const;
};
}  // namespace RACFu

#endif
