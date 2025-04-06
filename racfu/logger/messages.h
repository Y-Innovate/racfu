#ifndef __RACFU_MESSAGES_H_
#define __RACFU_MESSAGES_H_

// Common Logging Messages
#define MSG_VALIDATING_PARAMETERS "Validating parameters ..."
#define MSG_DONE "Done"
#define MSG_BUILD_RESULT "Building JSON result ..."

// IRRSEQ00 Logging Messages
#define MSG_SEQ_PATH "Entering IRRSEQ00 path"
#define MSG_CALLING_SEQ "Calling IRRSEQ00 ..."
#define MSG_REQUEST_SEQ_GENERIC "Generic extract request buffer:"
#define MSG_REQUEST_SEQ_SETROPTS "Setropts extract request buffer:"
#define MSG_RESULT_SEQ_GENERIC "Raw profile extract result:"
#define MSG_RESULT_SEQ_SETROPTS "Raw setropts extract result:"
#define MSG_SEQ_POST_PROCESS "Profile extract result has been post-processed"

// IRRSMO00 Logging Messages
#define MSG_SMO_PATH "Entering IRRSMO00 path"
#define MSG_RUN_AS_USER "Running under the authority of user: "
#define MSG_VALIDATING_TRAITS "Validating traits ..."
#define MSG_REQUEST_SMO_ASCII "Request XML:"
#define MSG_REQUEST_SMO_EBCDIC "EBCDIC encoded request XML:"
#define MSG_CALLING_SMO "Calling IRRSMO00 ..."
#define MSG_SMO_VALIDATE_EXIST "Verifying that profile exists for alter ..."
#define MSG_RESULT_SMO_EBCDIC "Raw EBCDIC encoded result XML:"
#define MSG_RESULT_SMO_ASCII "Decoded result XML:"
#define MSG_SMO_POST_PROCESS "Post-processing decoded result ..."

// IRRSDL00 Logging Messages
#define MSG_CALLING_SDL "Calling IRRSDL00 ..."
#define MSG_REQUEST_SDL_KEYRING "Keyring extract request buffer:"
#define MSG_RESULT_SDL_KEYRING "Raw profile extract result:"

#endif
