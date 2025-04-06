#ifndef __RACFU_POST_PROCESS_H_
#define __RACFU_POST_PROCESS_H_

#include <nlohmann/json.hpp>

#include "extract_seq.hpp"

nlohmann::json post_process_generic(
    generic_extract_parms_results_t *generic_result_buffer,
    const char *admin_type);

nlohmann::json post_process_setropts(
    setropts_extract_results_t *setropts_result_buffer);

void process_setropts_field(char *field_data_destination,
                            char *field_data_source, int field_length);

void process_generic_field(nlohmann::json &json_field,
                           generic_field_descriptor_t *field, char *field_key,
                           char *profile_address, const char racfu_field_type);

char get_setropts_field_type(char *field_key);

std::string post_process_field_key(char *field_key, const char *admin_type,
                                   const char *segment,
                                   const char *raw_field_key);

void post_process_key(char *destination_key, const char *source_key,
                      int length);

void copy_and_encode_string(char *destination_string, const char *source_string,
                            int length);

void convert_to_lowercase(char *string, int length);

void trim_trailing_spaces(char *string, int length);

#endif
