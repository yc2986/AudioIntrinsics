#include <gtest/gtest.h>

#include "AudioIntrinsics.h"

#include <vector>

using namespace intrinsics;
using namespace std;
using namespace testing;

namespace mask {

struct AudioChannelMaskTestParam {
    audio_channel_mask_t mask;
    size_t channels;
};

class AudioChannelMaskTest : public TestWithParam<AudioChannelMaskTestParam> {};

TEST_P(AudioChannelMaskTest, ParameterizedChannelCount) {
    auto param = GetParam();
    EXPECT_EQ(param.channels, audioChannelCount(param.mask))
            << "channel mask: " << audioChannelMaskToString(param.mask) << "\n"
            << "expected channel: " << param.channels;
}

inline auto AudioChannelOutMaskTestCase() {
    return vector<AudioChannelMaskTestParam> {
        { AUDIO_CHANNEL_OUT_MONO, 1u },
        { AUDIO_CHANNEL_OUT_STEREO, 2u },
        { AUDIO_CHANNEL_OUT_2POINT1, 3u },
        { AUDIO_CHANNEL_OUT_2POINT0POINT2, 4u },
        { AUDIO_CHANNEL_OUT_2POINT1POINT2, 5u },
        { AUDIO_CHANNEL_OUT_3POINT0POINT2, 5u },
        { AUDIO_CHANNEL_OUT_3POINT1POINT2, 6u },
        { AUDIO_CHANNEL_OUT_QUAD, 4u },
        { AUDIO_CHANNEL_OUT_QUAD_BACK, 4u },
        { AUDIO_CHANNEL_OUT_QUAD_SIDE, 4u },
        { AUDIO_CHANNEL_OUT_SURROUND, 4u },
        { AUDIO_CHANNEL_OUT_PENTA, 5u },
        { AUDIO_CHANNEL_OUT_5POINT1, 6u },
        { AUDIO_CHANNEL_OUT_5POINT1_BACK, 6u },
        { AUDIO_CHANNEL_OUT_5POINT1_SIDE, 6u },
        { AUDIO_CHANNEL_OUT_5POINT1POINT2, 8u },
        { AUDIO_CHANNEL_OUT_5POINT1POINT4, 10u },
        { AUDIO_CHANNEL_OUT_6POINT1, 7u },
        { AUDIO_CHANNEL_OUT_7POINT1, 8u },
        { AUDIO_CHANNEL_OUT_7POINT1POINT2, 10u },
        { AUDIO_CHANNEL_OUT_7POINT1POINT4, 12u },
    };
}

inline auto AudioChannelInMaskTestCase() {
    return vector<AudioChannelMaskTestParam> {
        { AUDIO_CHANNEL_IN_MONO, 1u },
        { AUDIO_CHANNEL_IN_STEREO, 2u },
        { AUDIO_CHANNEL_IN_FRONT_BACK, 2u },
        { AUDIO_CHANNEL_IN_2POINT0POINT2, 4u },
        { AUDIO_CHANNEL_IN_2POINT1POINT2, 5u },
        { AUDIO_CHANNEL_IN_3POINT0POINT2, 5u },
        { AUDIO_CHANNEL_IN_3POINT1POINT2, 6u },
        { AUDIO_CHANNEL_IN_5POINT1, 6u },
    };
}

INSTANTIATE_TEST_CASE_P(AudioChannelOutMaskToChannelCount,
                        AudioChannelMaskTest,
                        ValuesIn(AudioChannelOutMaskTestCase()));

INSTANTIATE_TEST_CASE_P(AudioChannelInMaskToChannelCount,
                        AudioChannelMaskTest,
                        ValuesIn(AudioChannelInMaskTestCase()));

}  // namespace mask
