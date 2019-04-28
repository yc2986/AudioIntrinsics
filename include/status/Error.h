#pragma once

#include <errno.h>

#include <iostream>
#include <string>
#include <cstdint>

namespace intrinsics {

enum error_code_t : int32_t {
    NO_PERMISSION = -EPERM,
    NO_MEMORY = -ENOMEM,
    NO_ACCESS = -EACCES,
    BAD_VALUE = -EINVAL,
    INVALID_OPERATION = -ENOSYS,
    GENERIC_ERROR = INT32_MIN,
};

struct Error {

    const error_code_t code;
    const std::string message;

    bool operator==(const Error &err) const {
        return (code == err.code);
    }

};

// helpers
inline constexpr const char* codeToString(const error_code_t &err) {
    switch (err) {
        case NO_PERMISSION: {
            return "no permission";
            break;
        }
        case NO_MEMORY: {
            return "no memory";
            break;
        }
        case NO_ACCESS: {
            return "no access";
            break;
        }
        case BAD_VALUE: {
            return "bad value";
            break;
        }
        case INVALID_OPERATION: {
            return "invalid operation";
            break;
        }
        case GENERIC_ERROR: {
            return "generic error";
            break;
        }
        default: {
            return "unknown error";
            break;
        }
    }
}

inline constexpr const char* codeToString(const Error &err) {
    return codeToString(err.code);
}

inline Error makeError(const int32_t code, const char *message = nullptr) {
    return Error {
        .code = static_cast<error_code_t>(code),
        .message = (message == nullptr ? "" : message)
    };
}

inline std::ostream& operator<<(std::ostream &os, const Error &obj) {
    os << "error code: " << codeToString(obj.code)
       << ", message: " << obj.message;
    return os;
}

// error literal with no message
const Error NoPermissionError = makeError(NO_PERMISSION);
const Error NoMemoryError = makeError(NO_MEMORY);
const Error NoAccessError = makeError(NO_ACCESS);
const Error BadValueError = makeError(BAD_VALUE);
const Error InvalidOperationError = makeError(INVALID_OPERATION);
const Error GenericError = makeError(GENERIC_ERROR);

}  // namespace intrinsics
