import json
from typing import Any

from racfu._C import call_racfu


class SecurityResult:
    def __init__(
            self,
            request: dict,
            raw_request: bytes | None,
            raw_result: bytes | None,
            result: dict[str, Any] | None
    ):
        self.request = request
        self.raw_request = raw_request
        self.raw_result = raw_result
        self.result = result


def racfu(request: dict, debug: bool = False) -> SecurityResult:
    response = call_racfu(json.dumps(request), debug=debug)
    return SecurityResult(
        request = request,
        raw_request = response["raw_request"],
        raw_result = response["raw_result"],
        result = json.loads(response['result_json'])
    )
