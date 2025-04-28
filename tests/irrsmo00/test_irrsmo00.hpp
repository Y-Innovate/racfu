#ifndef __RACFU_TEST_ADD_H_
#define __RACFU_TEST_ADD_H_

#define IRRSMO00_REQUEST_SAMPLES "./tests/irrsmo00/request_samples/"
#define IRRSMO00_RESULT_SAMPLES "./tests/irrsmo00/result_samples/"

/*************************************************************************/
/* Request Samples                                                       */
/*************************************************************************/
// User
#define TEST_ADD_USER_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "user/test_add_user_request.json"
#define TEST_ADD_USER_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "user/test_add_user_request.xml"
#define TEST_ALTER_USER_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "user/test_alter_user_request.json"
#define TEST_ALTER_USER_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "user/test_alter_user_request.xml"
#define TEST_ALTER_USER_CSDATA_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "user/test_alter_user_csdata_request.json"
#define TEST_ALTER_USER_CSDATA_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "user/test_alter_user_csdata_request.xml"
#define TEST_ADD_USER_PARAMETER_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "user/test_add_user_parameter_errors_request.json"
#define TEST_ADD_USER_TRAIT_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "user/test_add_user_trait_errors_request.json"
#define TEST_ALTER_USER_TRAITS_NOT_JSON_ERROR_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                 \
  "user/test_alter_user_traits_not_json_error_request.json"
#define TEST_DELETE_USER_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "user/test_delete_user_request.json"
#define TEST_DELETE_USER_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "user/test_delete_user_request.xml"
#define TEST_DELETE_USER_WITH_TRAITS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "user/test_delete_user_with_traits_request.json"
#define TEST_ALTER_USER_REQUEST_PSEUDO_BOOLEAN_JSON \
  IRRSMO00_REQUEST_SAMPLES "user/test_alter_user_request_pseudo_boolean.json"
#define TEST_ALTER_USER_REQUEST_PSEUDO_BOOLEAN_XML \
  IRRSMO00_REQUEST_SAMPLES "user/test_alter_user_request_pseudo_boolean.xml"

// Group
#define TEST_ADD_GROUP_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "group/test_add_group_request.json"
#define TEST_ADD_GROUP_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "group/test_add_group_request.xml"
#define TEST_ALTER_GROUP_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "group/test_alter_group_request.json"
#define TEST_ALTER_GROUP_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "group/test_alter_group_request.xml"
#define TEST_ALTER_GROUP_CSDATA_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "group/test_alter_group_csdata_request.json"
#define TEST_ALTER_GROUP_CSDATA_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "group/test_alter_group_csdata_request.xml"
#define TEST_ADD_GROUP_PARAMETER_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                           \
  "group/"                                           \
  "test_add_group_parameter_errors_request.json"
#define TEST_ADD_GROUP_TRAIT_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "group/test_add_group_trait_errors_request.json"
#define TEST_DELETE_GROUP_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "group/test_delete_group_request.json"
#define TEST_DELETE_GROUP_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "group/test_delete_group_request.xml"

// Group Connection
#define TEST_ALTER_GROUP_CONNECTION_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                       \
  "group_connection/test_alter_group_connection_request.json"
#define TEST_ALTER_GROUP_CONNECTION_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES                      \
  "group_connection/test_alter_group_connection_request.xml"
#define TEST_ALTER_GROUP_CONNECTION_PARAMETER_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                        \
  "group_connection/test_alter_group_connection_parameter_errors_request.json"
#define TEST_ALTER_GROUP_CONNECTION_TRAIT_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                    \
  "group_connection/test_alter_group_connection_trait_errors_request.json"
#define TEST_DELETE_GROUP_CONNECTION_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                        \
  "group_connection/test_delete_group_connection_request.json"
#define TEST_DELETE_GROUP_CONNECTION_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES                       \
  "group_connection/test_delete_group_connection_request.xml"

// RACF Options
#define TEST_ALTER_RACF_OPTIONS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "racf_options/test_alter_racf_options_request.json"
#define TEST_ALTER_RACF_OPTIONS_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "racf_options/test_alter_racf_options_request.xml"
#define TEST_ALTER_RACF_OPTIONS_PARAMETER_ERRORS_REQUEST_JSON      \
  IRRSMO00_REQUEST_SAMPLES                                         \
  "racf_options/test_alter_racf_options_parameter_errors_request." \
  "json"
#define TEST_ALTER_RACF_OPTIONS_TRAIT_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                \
  "racf_options/test_alter_racf_options_trait_errors_request.json"

// Data-Set
#define TEST_ADD_DATA_SET_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "data_set/test_add_data_set_request.json"
#define TEST_ADD_DATA_SET_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "data_set/test_add_data_set_request.xml"
#define TEST_ALTER_DATA_SET_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "data_set/test_alter_data_set_request.json"
#define TEST_ALTER_DATA_SET_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "data_set/test_alter_data_set_request.xml"
#define TEST_ALTER_DATA_SET_CSDATA_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "data_set/test_alter_data_set_csdata_request.json"
#define TEST_ALTER_DATA_SET_CSDATA_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "data_set/test_alter_data_set_csdata_request.xml"
#define TEST_ADD_DATA_SET_PARAMETER_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                              \
  "data_set/test_add_data_set_parameter_errors_request.json"
#define TEST_ADD_DATA_SET_TRAIT_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                          \
  "data_set/test_add_data_set_trait_errors_request.json"
#define TEST_DELETE_DATA_SET_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "data_set/test_delete_data_set_request.json"
#define TEST_DELETE_DATA_SET_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "data_set/test_delete_data_set_request.xml"

// Resource
#define TEST_ADD_RESOURCE_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "resource/test_add_resource_request.json"
#define TEST_ADD_RESOURCE_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "resource/test_add_resource_request.xml"
#define TEST_ALTER_RESOURCE_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "resource/test_alter_resource_request.json"
#define TEST_ALTER_RESOURCE_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "resource/test_alter_resource_request.xml"
#define TEST_ALTER_RESOURCE_CSDATA_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "resource/test_alter_resource_csdata_request.json"
#define TEST_ALTER_RESOURCE_CSDATA_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "resource/test_alter_resource_csdata_request.xml"
#define TEST_ADD_RESOURCE_PARAMETER_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                              \
  "resource/test_add_resource_parameter_errors_request.json"
#define TEST_ADD_RESOURCE_TRAIT_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                          \
  "resource/test_add_resource_trait_errors_request.json"
#define TEST_DELETE_RESOURCE_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES "resource/test_delete_resource_request.json"
#define TEST_DELETE_RESOURCE_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES "resource/test_delete_resource_request.xml"

// Permission
#define TEST_ALTER_PERMISSION_DATA_SET_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                          \
  "permission/test_alter_permission_data_set_request.json"
#define TEST_ALTER_PERMISSION_DATA_SET_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES                         \
  "permission/test_alter_permission_data_set_request.xml"
#define TEST_ALTER_PERMISSION_DATA_SET_WITH_CLASS_PARAMETER_ERROR_REQEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                                    \
  "permission/"                                                               \
  "test_alter_permission_data_set_with_class_parameter_error_request.json"
#define TEST_ALTER_PERMISSION_RESOURCE_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                          \
  "permission/test_alter_permission_resource_request.json"
#define TEST_ALTER_PERMISSION_RESOURCE_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES                         \
  "permission/test_alter_permission_resource_request.xml"
#define TEST_ALTER_PERMISSION_DATA_SET_PARAMETER_ERRORS_REQUEST_JSON    \
  IRRSMO00_REQUEST_SAMPLES                                              \
  "permission/test_alter_permission_data_set_parameter_errors_request." \
  "json"
#define TEST_ALTER_PERMISSION_DATA_SET_WITH_CLASS_PARAMETER_ERROR_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                                     \
  "permission/"                                                                \
  "test_alter_permission_data_set_with_class_parameter_error_request."         \
  "json"
#define TEST_ALTER_PERMISSION_RESOURCE_PARAMETER_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                           \
  "permission/test_alter_permission_resource_parameter_errors_request.json"
#define TEST_ALTER_PERMISSION_RESOURCE_CLASS_SET_TO_DATASET_LOWERCASE_PARAMETER_ERROR_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                                                         \
  "permission/"                                                                                    \
  "test_alter_permission_resource_class_set_to_dataset_lowercase_parameter_"                       \
  "error_request.json"
#define TEST_ALTER_PERMISSION_RESOURCE_CLASS_SET_TO_DATASET_UPPERCASE_PARAMETER_ERROR_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                                                         \
  "permission/"                                                                                    \
  "test_alter_permission_resource_class_set_to_dataset_uppercase_parameter_"                       \
  "error_request.json"
#define TEST_ALTER_PERMISSION_RESOURCE_WITH_VOLUME_PARAMETER_ERROR_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                                      \
  "permission/"                                                                 \
  "test_alter_permission_resource_with_volume_parameter_error_request.json"
#define TEST_ALTER_PERMISSION_RESOURCE_TRAIT_ERRORS_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                                       \
  "permission/test_alter_permission_resource_trait_errors_request.json"
#define TEST_DELETE_PERMISSION_RESOURCE_REQUEST_JSON \
  IRRSMO00_REQUEST_SAMPLES                           \
  "permission/test_delete_permission_resource_request.json"
#define TEST_DELETE_PERMISSION_RESOURCE_REQUEST_XML \
  IRRSMO00_REQUEST_SAMPLES                          \
  "permission/test_delete_permission_resource_request.xml"

/*************************************************************************/
/* Result Samples                                                        */
/*************************************************************************/
// User
#define TEST_ADD_USER_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "user/test_add_user_result.json"
#define TEST_ADD_USER_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES "user/test_add_user_result.xml"
#define TEST_DELETE_USER_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "user/test_delete_user_result.json"
#define TEST_DELETE_USER_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES "user/test_delete_user_result.xml"
#define TEST_ADD_USER_RESULT_USER_ALREADY_EXISTS_JSON \
  IRRSMO00_RESULT_SAMPLES                             \
  "user/test_add_user_result_user_already_exists.json"
#define TEST_ADD_USER_RESULT_USER_ALREADY_EXISTS_XML \
  IRRSMO00_RESULT_SAMPLES                            \
  "user/test_add_user_result_user_already_exists.xml"
#define TEST_ADD_USER_TRAIT_ERRORS_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "user/test_add_user_trait_errors_result.json"
#define TEST_ADD_USER_NO_RESPONSE_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "user/test_add_user_no_response_result.json"
#define TEST_ALTER_USER_NO_RESPONSE_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "user/test_alter_user_no_response_result.json"
#define TEST_IRRSMO00_ERROR_STRUCTURE_JSON \
  IRRSMO00_RESULT_SAMPLES "user/test_irrsmo00_error_structure_result.json"
#define TEST_IRRSMO00_ERROR_STRUCTURE_XML \
  IRRSMO00_RESULT_SAMPLES "user/test_irrsmo00_error_structure_result.xml"

// Group
#define TEST_ADD_GROUP_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "group/test_add_group_result.json"
#define TEST_ADD_GROUP_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES "group/test_add_group_result.xml"
#define TEST_DELETE_GROUP_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "group/test_delete_group_result.json"
#define TEST_DELETE_GROUP_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES "group/test_delete_group_result.xml"
#define TEST_ADD_GROUP_RESULT_GROUP_ALREADY_EXISTS_JSON \
  IRRSMO00_RESULT_SAMPLES                               \
  "group/test_add_group_result_group_already_exists.json"
#define TEST_ADD_GROUP_RESULT_GROUP_ALREADY_EXISTS_XML \
  IRRSMO00_RESULT_SAMPLES                              \
  "group/test_add_group_result_group_already_exists.xml"
#define TEST_ADD_GROUP_TRAIT_ERRORS_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "group/test_add_group_trait_errors_result.json"

// Group Connection
#define TEST_ALTER_GROUP_CONNECTION_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                       \
  "group_connection/test_alter_group_connection_result.json"
#define TEST_ALTER_GROUP_CONNECTION_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES                      \
  "group_connection/test_alter_group_connection_result.xml"
#define TEST_DELETE_GROUP_CONNECTION_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                        \
  "group_connection/test_delete_group_connection_result.json"
#define TEST_DELETE_GROUP_CONNECTION_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES                       \
  "group_connection/test_delete_group_connection_result.xml"
#define TEST_ALTER_GROUP_CONNECTION_TRAIT_ERRORS_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                                    \
  "group_connection/"                                        \
  "test_alter_group_connection_trait_errors_result.json"

// RACF Options
#define TEST_ALTER_RACF_OPTIONS_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "racf_options/test_alter_racf_options_result.json"
#define TEST_ALTER_RACF_OPTIONS_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES "racf_options/test_alter_racf_options_result.xml"
#define TEST_ALTER_RACF_OPTIONS_TRAIT_ERRORS_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                                \
  "racf_options/test_alter_racf_options_trait_errors_result.json"

// Data Set
#define TEST_ADD_DATA_SET_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "data_set/test_add_data_set_result.json"
#define TEST_ADD_DATA_SET_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES "data_set/test_add_data_set_result.xml"
#define TEST_DELETE_DATA_SET_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "data_set/test_delete_data_set_result.json"
#define TEST_DELETE_DATA_SET_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES "data_set/test_delete_data_set_result.xml"
#define TEST_ADD_DATA_SET_RESULT_DATA_SET_ALREADY_EXISTS_JSON \
  IRRSMO00_RESULT_SAMPLES                                     \
  "data_set/test_add_data_set_result_data_set_already_exists.json"
#define TEST_ADD_DATA_SET_RESULT_DATA_SET_ALREADY_EXISTS_XML \
  IRRSMO00_RESULT_SAMPLES                                    \
  "data_set/test_add_data_set_result_data_set_already_exists.xml"
#define TEST_ADD_DATA_SET_TRAIT_ERRORS_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                          \
  "data_set/"                                      \
  "test_add_data_set_trait_errors_result.json"

// Resource
#define TEST_ADD_RESOURCE_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "resource/test_add_resource_result.json"
#define TEST_ADD_RESOURCE_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES "resource/test_add_resource_result.xml"
#define TEST_DELETE_RESOURCE_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES "resource/test_delete_resource_result.json"
#define TEST_DELETE_RESOURCE_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES "resource/test_delete_resource_result.xml"
#define TEST_ADD_RESOURCE_RESULT_RESOURCE_ALREADY_EXISTS_JSON \
  IRRSMO00_RESULT_SAMPLES                                     \
  "resource/test_add_resource_result_resource_already_exists.json"
#define TEST_ADD_RESOURCE_RESULT_RESOURCE_ALREADY_EXISTS_XML \
  IRRSMO00_RESULT_SAMPLES                                    \
  "resource/test_add_resource_result_resource_already_exists.xml"
#define TEST_ADD_RESOURCE_TRAIT_ERRORS_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                          \
  "resource/"                                      \
  "test_add_resource_trait_errors_result.json"

// Permission
#define TEST_ALTER_PERMISSION_DATA_SET_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                          \
  "permission/test_alter_permission_data_set_result.json"
#define TEST_ALTER_PERMISSION_DATA_SET_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES                         \
  "permission/test_alter_permission_data_set_result.xml"
#define TEST_ALTER_PERMISSION_RESOURCE_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                          \
  "permission/test_alter_permission_resource_result.json"
#define TEST_ALTER_PERMISSION_RESOURCE_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES                         \
  "permission/test_alter_permission_resource_result.xml"
#define TEST_DELETE_PERMISSION_RESOURCE_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                           \
  "permission/test_delete_permission_resource_result.json"
#define TEST_DELETE_PERMISSION_RESOURCE_RESULT_XML \
  IRRSMO00_RESULT_SAMPLES                          \
  "permission/test_delete_permission_resource_result.xml"
#define TEST_ALTER_PERMISSION_RESOURCE_TRAIT_ERRORS_RESULT_JSON \
  IRRSMO00_RESULT_SAMPLES                                       \
  "permission/test_alter_permission_resource_trait_errors_result.json"

/*************************************************************************/
/* Precheck Macros                                                       */
/*************************************************************************/
#define TEST_IRRSMO00_PRECHECK_OFF 13
#define TEST_IRRSMO00_PRECHECK_ON 15

/*************************************************************************/
/* Prototypes                                                            */
/*************************************************************************/
// User
void test_generate_add_user_request();
void test_generate_alter_user_request();
void test_generate_alter_user_csdata_request();
void test_generate_delete_user_request();
void test_parse_add_user_result();
void test_parse_delete_user_result();
void test_parse_add_user_result_user_already_exists();
void test_parse_add_user_parameter_errors();
void test_parse_add_user_trait_errors();
void test_parse_add_user_no_xml_data_error();
void test_parse_alter_user_no_xml_data_error();
void test_parse_alter_user_traits_not_json_error();
void test_parse_irrsmo00_errors_result();
void test_parse_delete_user_trait_error_result();
void test_generate_alter_user_request_pseudo_boolean();

// Group
void test_generate_add_group_request();
void test_generate_alter_group_request();
void test_generate_alter_group_csdata_request();
void test_generate_delete_group_request();
void test_parse_add_group_result();
void test_parse_delete_group_result();
void test_parse_add_group_result_group_already_exists();
void test_parse_add_group_parameter_errors();
void test_parse_add_group_trait_errors();

// Group Connection
void test_generate_alter_group_connection_request();
void test_generate_delete_group_connection_request();
void test_parse_alter_group_connection_result();
void test_parse_delete_group_connection_result();
void test_parse_alter_group_connection_parameter_errors();
void test_parse_alter_group_connection_trait_errors();

// Racf-Options
void test_generate_alter_racf_options_request();
void test_parse_alter_racf_options_result();
void test_parse_alter_racf_options_parameter_errors();
void test_parse_alter_racf_options_trait_errors();

// Data-Set
void test_generate_add_data_set_request();
void test_generate_alter_data_set_request();
void test_generate_alter_data_set_csdata_request();
void test_generate_delete_data_set_request();
void test_parse_add_data_set_result();
void test_parse_delete_data_set_result();
void test_parse_add_data_set_result_data_set_already_exists();
void test_parse_add_data_set_parameter_errors();
void test_parse_add_data_set_trait_errors();

// Resource
void test_generate_add_resource_request();
void test_generate_alter_resource_request();
void test_generate_alter_resource_csdata_request();
void test_generate_delete_resource_request();
void test_parse_add_resource_result();
void test_parse_delete_resource_result();
void test_parse_add_resource_result_resource_already_exists();
void test_parse_add_resource_parameter_errors();
void test_parse_add_resource_trait_errors();

// Permission
void test_generate_alter_permission_data_set_request();
void test_generate_alter_permission_resource_request();
void test_generate_delete_permission_resource_request();
void test_parse_alter_permission_data_set_result();
void test_parse_alter_permission_resource_result();
void test_parse_delete_permission_resource_result();
void test_parse_alter_permission_data_set_parameter_errors();
void test_parse_alter_permission_data_set_with_class_parameter_error();
void test_parse_alter_permission_resource_parameter_errors();
void test_parse_alter_permission_resource_class_set_to_data_set_lowercase_parameter_error();
void test_parse_alter_permission_resource_class_set_to_data_set_uppercase_parameter_error();
void test_parse_alter_permission_resource_with_volume_parameter_error();
void test_parse_alter_permission_trait_errors();

#endif
