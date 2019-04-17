#include "AudioIntrinsics.h"

#include <gtest/gtest.h>

#include <functional>
#include <vector>

using namespace intrinsics;
using namespace std;
using namespace testing;

namespace attribute {

using attribute_handler_t = size_t(*)(const audio_attribute_t&);

struct AudioAttributeTestParam {
    function<size_t(const audio_attribute_t&)> handler;
    audio_attribute_t attribute;
    size_t size;
};

class AudioAttributeTest : public TestWithParam<AudioAttributeTestParam> {};

TEST_P(AudioAttributeTest, ParameterizedAttributeCalculation) {
    auto param = GetParam();
    EXPECT_EQ(param.size, param.handler(param.attribute))
            << "attribute info:" << "\n"
            << "    samplerate: " << param.attribute.samplerate << "\n"
            << "    framecount: " << param.attribute.framecount << "\n"
            << "    format: " << audioFormatToString(param.attribute.format) << "\n"
            << "    channelMask: " << audioChannelMaskToString(param.attribute.channelmask);
}

inline auto audioAttributeChannelCountCase() {
    auto handler = static_cast<attribute_handler_t>(&audioChannelCount);
    return vector<AudioAttributeTestParam> {
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_MONO), 1u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_STEREO), 2u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_2POINT1), 3u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_2POINT0POINT2), 4u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_2POINT1POINT2), 5u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_3POINT0POINT2), 5u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_3POINT1POINT2), 6u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_QUAD), 4u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_QUAD_BACK), 4u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_QUAD_SIDE), 4u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_SURROUND), 4u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_PENTA), 5u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_5POINT1), 6u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_5POINT1_BACK), 6u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_5POINT1_SIDE), 6u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_5POINT1POINT2), 8u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_5POINT1POINT4), 10u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_6POINT1), 7u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_7POINT1), 8u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_7POINT1POINT2), 10u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_OUT_7POINT1POINT4), 12u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_IN_MONO), 1u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_IN_STEREO), 2u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_IN_FRONT_BACK), 2u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_IN_2POINT0POINT2), 4u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_IN_2POINT1POINT2), 5u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_IN_3POINT0POINT2), 5u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_IN_3POINT1POINT2), 6u },
        { handler, makeAttribute(0u, 0u, 0u, AUDIO_CHANNEL_IN_5POINT1), 6u },
    };
}

inline auto audioAttributeSampleSizeCase() {
    auto handler = static_cast<attribute_handler_t>(&audioBytesPerSample);
    return vector<AudioAttributeTestParam> {
        { handler, makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_BIT, 0u), 1u },
        { handler, makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_16_BIT, 0u), 2u },
        { handler, makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_24_BIT, 0u), 4u },
        { handler, makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_24_BIT_PACKED, 0u), 3u },
        { handler, makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_32_BIT, 0u), 4u },
        { handler, makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_FLOAT, 0u), 4u },
    };
}

inline auto audioAttributeFrameSizeCase() {
    auto handler = static_cast<attribute_handler_t>(&audioBytesPerFrame);
    return vector<AudioAttributeTestParam> {
        // 8-bit fixed
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_BIT, AUDIO_CHANNEL_OUT_MONO), 1u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_BIT, AUDIO_CHANNEL_OUT_STEREO), 2u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_BIT, AUDIO_CHANNEL_OUT_5POINT1), 6u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_BIT, AUDIO_CHANNEL_OUT_7POINT1), 8u },
        // 16-bit fixed
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_MONO), 2u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO), 4u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_5POINT1), 12u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_7POINT1), 16u },
        // 8 24-bit fixed
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_24_BIT, AUDIO_CHANNEL_OUT_MONO), 4u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_24_BIT, AUDIO_CHANNEL_OUT_STEREO), 8u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_24_BIT, AUDIO_CHANNEL_OUT_5POINT1), 24u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_8_24_BIT, AUDIO_CHANNEL_OUT_7POINT1), 32u },
        // 24-bit packed fixed
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_24_BIT_PACKED, AUDIO_CHANNEL_OUT_MONO), 3u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_24_BIT_PACKED, AUDIO_CHANNEL_OUT_STEREO), 6u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_24_BIT_PACKED, AUDIO_CHANNEL_OUT_5POINT1), 18u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_24_BIT_PACKED, AUDIO_CHANNEL_OUT_7POINT1), 24u },
        // 32-bit fixed
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_32_BIT, AUDIO_CHANNEL_OUT_MONO), 4u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_32_BIT, AUDIO_CHANNEL_OUT_STEREO), 8u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_32_BIT, AUDIO_CHANNEL_OUT_5POINT1), 24u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_32_BIT, AUDIO_CHANNEL_OUT_7POINT1), 32u },
        // 32-bit float
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_FLOAT, AUDIO_CHANNEL_OUT_MONO), 4u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_FLOAT, AUDIO_CHANNEL_OUT_STEREO), 8u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_FLOAT, AUDIO_CHANNEL_OUT_5POINT1), 24u },
        { handler,
            makeAttribute(0u, 0u, AUDIO_FORMAT_PCM_FLOAT, AUDIO_CHANNEL_OUT_7POINT1), 32u },
    };
}


inline auto audioAttributeFrameCountCase() {
    auto handler = static_cast<attribute_handler_t>(&audioFramesFromAttribute);
    return vector<AudioAttributeTestParam> {
        { handler, makeAttribute(0u, 128u, 0u, 0u), 128u },
        { handler, makeAttribute(0u, 256u, 0u, 0u), 256u },
        { handler, makeAttribute(0u, 384u, 0u, 0u), 384u },
        { handler, makeAttribute(0u, 512u, 0u, 0u), 512u },
        { handler, makeAttribute(0u, 640u, 0u, 0u), 640u },
        { handler, makeAttribute(0u, 768u, 0u, 0u), 768u },
        { handler, makeAttribute(0u, 896u, 0u, 0u), 896u },
        { handler, makeAttribute(0u, 1024u, 0u, 0u), 1024u },
    };
}

inline auto audioAttributeSampleCountCase() {
    auto handler = static_cast<attribute_handler_t>(&audioSamplesFromAttribute);
    return vector<AudioAttributeTestParam> {
        // 256 frames
        { handler, makeAttribute(0u, 256u, 0u, AUDIO_CHANNEL_OUT_MONO), 256u },
        { handler, makeAttribute(0u, 256u, 0u, AUDIO_CHANNEL_OUT_STEREO), 512u },
        { handler, makeAttribute(0u, 256u, 0u, AUDIO_CHANNEL_OUT_5POINT1), 1536u },
        { handler, makeAttribute(0u, 256u, 0u, AUDIO_CHANNEL_OUT_7POINT1), 2048u },
        // 512 frames
        { handler, makeAttribute(0u, 512u, 0u, AUDIO_CHANNEL_OUT_MONO), 512u },
        { handler, makeAttribute(0u, 512u, 0u, AUDIO_CHANNEL_OUT_STEREO), 1024u },
        { handler, makeAttribute(0u, 512u, 0u, AUDIO_CHANNEL_OUT_5POINT1), 3072u },
        { handler, makeAttribute(0u, 512u, 0u, AUDIO_CHANNEL_OUT_7POINT1), 4096u },
    };
}

inline auto audioAttributeByteCountCase() {
    auto handler = static_cast<attribute_handler_t>(&audioBytesFromAttribute);
    return vector<AudioAttributeTestParam> {
        // 256 frames
        { handler,
            makeAttribute(0u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_MONO), 512u },
        { handler,
            makeAttribute(0u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO), 1024u },
        { handler,
            makeAttribute(0u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_5POINT1), 3072u },
        { handler,
            makeAttribute(0u, 256u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_7POINT1), 4096u },
        // 512 frames
        { handler,
            makeAttribute(0u, 512u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_MONO), 1024u },
        { handler,
            makeAttribute(0u, 512u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_STEREO), 2048u },
        { handler,
            makeAttribute(0u, 512u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_5POINT1), 6144u },
        { handler,
            makeAttribute(0u, 512u, AUDIO_FORMAT_PCM_16_BIT, AUDIO_CHANNEL_OUT_7POINT1), 8192u },
    };
}

INSTANTIATE_TEST_CASE_P(AudioAttributeChannelCount,
                        AudioAttributeTest,
                        ValuesIn(audioAttributeChannelCountCase()));

INSTANTIATE_TEST_CASE_P(AudioAttributeSampleSize,
                        AudioAttributeTest,
                        ValuesIn(audioAttributeSampleSizeCase()));

INSTANTIATE_TEST_CASE_P(AudioAttributeFrameSize,
                        AudioAttributeTest,
                        ValuesIn(audioAttributeFrameSizeCase()));

INSTANTIATE_TEST_CASE_P(AudioAttributeFrameCount,
                        AudioAttributeTest,
                        ValuesIn(audioAttributeFrameCountCase()));

INSTANTIATE_TEST_CASE_P(AudioAttribuitSampleCount,
                        AudioAttributeTest,
                        ValuesIn(audioAttributeSampleCountCase()));

INSTANTIATE_TEST_CASE_P(AudioAttribuitByteCount,
                        AudioAttributeTest,
                        ValuesIn(audioAttributeByteCountCase()));

}  // namespace attribute
