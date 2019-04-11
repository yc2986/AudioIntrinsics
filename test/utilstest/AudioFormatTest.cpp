#include <gtest/gtest.h>

#include "AudioIntrinsics.h"

#include <vector>

using namespace intrinsics;
using namespace std;
using namespace testing;

namespace format {

struct AudioFormatTestParam {
    audio_format_t format;
    size_t bytes;
};

class AudioFormatTest : public TestWithParam<AudioFormatTestParam> {};

TEST_P(AudioFormatTest, ParameterizedFormatSize) {
    auto param = GetParam();
    EXPECT_EQ(param.bytes, audioBytesPerSample(param.format))
            << "format: " << audioFormatToString(param.format) << "\n"
            << "expected bytes: " << param.bytes;
}

inline auto AudioFormatTestCase() {
    return vector<AudioFormatTestParam> {
        { AUDIO_FORMAT_PCM_8_BIT, 1u },
        { AUDIO_FORMAT_PCM_16_BIT, 2u },
        { AUDIO_FORMAT_PCM_8_24_BIT, 4u },
        { AUDIO_FORMAT_PCM_24_BIT_PACKED, 3u },
        { AUDIO_FORMAT_PCM_32_BIT, 4u },
        { AUDIO_FORMAT_PCM_FLOAT, 4u },
    };
}

INSTANTIATE_TEST_CASE_P(AudioFormatToNumberOfBytes,
                        AudioFormatTest,
                        ValuesIn(AudioFormatTestCase()));

}  // namespace
