#ifndef __RACFU_KEY_MAP_STRUCTS_H_
#define __RACFU_KEY_MAP_STRUCTS_H_

#include <stdbool.h>

// Trait Types
#define TRAIT_TYPE_BAD -1
#define TRAIT_TYPE_NULL 0
#define TRAIT_TYPE_BOOLEAN 1
#define TRAIT_TYPE_STRING 2
#define TRAIT_TYPE_UINT 3
#define TRAIT_TYPE_REPEAT 4
#define TRAIT_TYPE_PSEUDO_BOOLEAN 5

// Operators
#define OPERATOR_BAD -1
#define OPERATOR_ANY 0
#define OPERATOR_SET 1
#define OPERATOR_ADD 2
#define OPERATOR_REMOVE 3
#define OPERATOR_DELETE 4

typedef struct {
  const bool set_allowed;     // Set a value
  const bool add_allowed;     // Append a value to an existing "list" value
  const bool remove_allowed;  // Remove a value from an existing "list" value
  const bool delete_allowed;  // Delete a value
} operators_allowed_t;

typedef struct {
  const char racfu_key[256];   // RACFu Key (i.e., 'omvs:default_shell')
  const char racf_key[8 + 1];  // RACF Key (i.e., 'program')
  const char trait_type;       // Data Type (i.e., TRAIT_TYPE_BOOLEAN)
  const operators_allowed_t operators_allowed;
  // 'operators_allowed' describes 'alter' operations allowed only since
  // IRRSMO00 always uses 'alter' for both 'add' and 'alter' requests.
} trait_key_mapping_t;

typedef struct {
  const char segment[8 + 1];          // The name of the segment.
  const int size;                     // The number of fields in the segment.
  const trait_key_mapping_t *traits;  // A pointer to the array of trait key
} segment_key_mapping_t;              // mappings for this segment.

typedef struct {
  const char profile_type[16 + 1];  // The type of profile (i.e., 'user')
  const int size;                   // The number of segments in the profile.
  const segment_key_mapping_t *segments;
} key_mapping_t;

#define field_count(segment) sizeof(segment) / sizeof(trait_key_mapping_t)
#define segment_count(profile) sizeof(profile) / sizeof(segment_key_mapping_t)

#endif
