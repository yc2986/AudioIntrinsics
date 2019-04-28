#include "AudioIntrinsics.h"

#include <gtest/gtest.h>

#include <utility>

using namespace intrinsics;
using namespace std;
using namespace testing;

namespace status {

TEST(ReturnStatus, Ctor) {
    Return<int> ret = -1;
    // copy ctor
    Return<int> retCopy(ret);
    EXPECT_EQ(-1, retCopy.get());
    // move ctor
    Return<int> retMove(std::move(ret));
    EXPECT_EQ(-1, retMove.get());
    // error ctor
    Return<int> retErr(makeError(NO_PERMISSION));
    EXPECT_EQ(NoPermissionError, retErr.error());
}

TEST(ReturnStatus, IntegerSuccess) {
    Return<int> ret = 0;
    // check return
    EXPECT_TRUE(ret);
    EXPECT_EQ(0, ret.get());
    // expected usage
    if (auto rc = ret) {
        EXPECT_EQ(0, rc.get());
    } else {
        EXPECT_TRUE(false);
    }
}

TEST(ReturnStatus, IntegerError) {
    Return<int> ret = makeError(BAD_VALUE);
    // check return
    EXPECT_FALSE(ret);
    // expected usage
    if (auto rc = ret) {
        EXPECT_TRUE(false);
    } else {
        EXPECT_EQ(BadValueError, rc.error());
    }
}

}  // namespace status
