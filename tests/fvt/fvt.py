import getpass
import json
import os

from racfu import racfu

# This user shouldn't exist
if "RACFU_FVT_USERID" not in os.environ:
  print(
    "The 'RACFU_FVT_USERID' environment variable must be set "
    + "to a z/OS userid that does NOT exist on the system.")
  exit(1)

# This request may fail, but regardless, it demonstrates that 
# we can make a request to IRRSEQ00 and get a result back.
extract_request = {
  "admin_type": "user",
  "operation": "extract",
  "userid": getpass.getuser()
}

# This request will fail, but it demonstrates that
# we can make a request to IRRSMO00 and get a result back.
delete_request = {
  "admin_type": "user",
  "operation": "delete",
  "userid": os.environ["RACFU_FVT_USERID"],
}

print("Extract Test (IRRSEQ00):")
result = racfu(extract_request)
print(json.dumps(result.result, indent=2))

print("Delete Test (IRRSMO00):")
result = racfu(delete_request)
print(json.dumps(result.result, indent=2))

print("Debug Test (IRRSMO00):")
result = racfu(delete_request, debug=True)
print(json.dumps(result.result, indent=2))