#ifndef __RACFU_TRAITS_H_
#define __RACFU_TRAITS_H_

#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>
#include <vector>

namespace RACFu {

enum TraitType { STRING, BOOLEAN, LIST, UINT };

class Trait {
 private:
  std::string racfu_key_;
  std::string racf_key_;
  TraitType trait_type_;

 public:
  Trait(const std::string& racfu_key, const std::string& racf_key,
        TraitType trait_type);
  const std::string& getRACFuKey();
  const std::string& getRACFKey();
  const std::string& getTraitType();
};

class Traits {
 private:
  std::unordered_map<std::string, std::vector<TraitType>> traits_;

 public:
  Traits(const nlohmann::json& racfu_schema);
  const std::string& getRACFuKey(const std::string& racf_key);
  const std::string& getRACFKey(const std::string& racfu_key);
  TraitType getTraitType(const std::string& racfu_key);
};

}  // namespace RACFu

#endif
