#include "AudioIntrinsics.h"

#include <gtest/gtest.h>

using namespace intrinsics;
using namespace std;
using namespace testing;

namespace memory {

struct AudioBufferSizeTestParam {
    audio_attribute_t attribute;
    size_t frames;
    size_t samples;
    size_t bytes;
};

class AudioBufferSizeTest : public TestWithParam<AudioBufferSizeTestParam> {};

TEST_P(AudioBufferSizeTest, ParameterizedSize) {
    auto param = GetParam();
    AudioBuffer buffer(param.attribute);
    EXPECT_EQ(param.frames, buffer.getTotalFrames());
    EXPECT_EQ(param.samples, buffer.getTotalSamples());
    EXPECT_EQ(param.bytes, buffer.getTotalBytes());
}

inline auto audioMemoryBufferSizeTestCase() {
    return vector<AudioBufferSizeTestParam> {
        // framecount variation
        { makeAttribute(48000u, 128u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                128u, 256u, 512u },
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                256u, 512u, 1024u },
        { makeAttribute(48000u, 384u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                384u, 768u, 1536u },
        { makeAttribute(48000u, 512u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                512u, 1024u, 2048u },
        { makeAttribute(48000u, 640u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                640u, 1280u, 2560u },
        { makeAttribute(48000u, 768u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                768u, 1536u, 3072u },
        { makeAttribute(48000u, 896u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                896u, 1792u, 3584u },
        { makeAttribute(48000u, 1024u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                1024u, 2048u, 4096u },
        // channel mask variation
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_MONO),
                256u, 256u, 512u },
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                256u, 512u, 1024u },
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_5POINT1),
                256u, 1536u, 3072u },
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_7POINT1),
                256u, 2048u, 4096u },
        // format variation
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_8_BIT, AUDIO_CHANNEL_OUT_STEREO),
                256u, 512u, 512u },
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO),
                256u, 512u, 1024u },
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_8_24_BIT, AUDIO_CHANNEL_OUT_STEREO),
                256u, 512u, 2048u },
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_24_BIT_PACKED, AUDIO_CHANNEL_OUT_STEREO),
                256u, 512u, 1536u },
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_32_BIT, AUDIO_CHANNEL_OUT_STEREO),
                256u, 512u, 2048u },
        { makeAttribute(48000u, 256u, AUDIO_FORMAT_PCM_FLOAT, AUDIO_CHANNEL_OUT_STEREO),
                256u, 512u, 2048u },
    };
}

INSTANTIATE_TEST_CASE_P(AudioBufferTripleSize,
                        AudioBufferSizeTest,
                        ValuesIn(audioMemoryBufferSizeTestCase()));

}  // namespace memory
