#include "AudioIntrinsics.h"

#include <gtest/gtest.h>

#include <string>
#include <sstream>

using namespace intrinsics;
using namespace std;
using namespace testing;

namespace status {

TEST(ErrorCode, CodeStringify) {
    EXPECT_EQ("no permission"s, string(codeToString(NO_PERMISSION)));
    EXPECT_EQ("no memory"s, string(codeToString(NO_MEMORY)));
    EXPECT_EQ("no access"s, string(codeToString(NO_ACCESS)));
    EXPECT_EQ("bad value"s, string(codeToString(BAD_VALUE)));
    EXPECT_EQ("invalid operation"s, string(codeToString(INVALID_OPERATION)));
    EXPECT_EQ("generic error"s, string(codeToString(GENERIC_ERROR)));
    EXPECT_EQ("unknown error"s, string(codeToString(static_cast<error_code_t>(1))));
}

TEST(ErrorCode, ErrorStringify) {
    EXPECT_EQ("no permission"s, string(codeToString(NoPermissionError)));
    EXPECT_EQ("no memory"s, string(codeToString(NoMemoryError)));
    EXPECT_EQ("no access"s, string(codeToString(NoAccessError)));
    EXPECT_EQ("bad value"s, string(codeToString(BadValueError)));
    EXPECT_EQ("invalid operation"s, string(codeToString(InvalidOperationError)));
    EXPECT_EQ("generic error"s, string(codeToString(GenericError)));
}

TEST(ErrorCode, ErrorFactory) {
    EXPECT_EQ(NoPermissionError, makeError(NO_PERMISSION, "foo"));
    EXPECT_EQ(NoMemoryError, makeError(NO_MEMORY, "foo"));
    EXPECT_EQ(NoAccessError, makeError(NO_ACCESS, "foo"));
    EXPECT_EQ(BadValueError, makeError(BAD_VALUE, "foo"));
    EXPECT_EQ(InvalidOperationError, makeError(INVALID_OPERATION, "foo"));
    EXPECT_EQ(GenericError, makeError(GENERIC_ERROR, "foo"));
}

TEST(ErrorCode, StreamOperator) {
    stringstream ss;
    ss << makeError(NO_PERMISSION, "bad permission");
    EXPECT_EQ("error code: no permission, message: bad permission",
              ss.str());
}

}  // namespace status
