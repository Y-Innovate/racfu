#ifndef __RACFU_KEY_MAP_PERMISSION_H_
#define __RACFU_KEY_MAP_PERMISSION_H_

#include <stdbool.h>

#include "key_map_structs.hpp"

const trait_key_mapping_t PERMISSION_BASE_SEGMENT_MAP[]{
    {
     "base:access",   "access",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:authid",       "id",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:model_profile_class",   "fclass",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:model_profile", "fprofile",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:model_profile_generic", "fgeneric",
     TRAIT_TYPE_BOOLEAN, {true, false, false, false},
     },
    {
     "base:model_profile_volume",  "fvolume",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:reset",    "reset",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_partner_lu_name", "whenappc",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_console", "whencons",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_jes",  "whenjes",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_program", "whenprog",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_servauth", "whenserv",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_sms",  "whensms",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_db2_role", "whensqlr",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_service",  "whensrv",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_system",  "whensys",
     TRAIT_TYPE_STRING, {true, false, false, false},
     },
    {
     "base:when_terminal", "whenterm",
     TRAIT_TYPE_STRING, {true, false, false, false},
     }
};

const segment_key_mapping_t PERMISSION_SEGMENT_KEY_MAP[] = {
    {"base", field_count(PERMISSION_BASE_SEGMENT_MAP),
     PERMISSION_BASE_SEGMENT_MAP}
};

#endif
