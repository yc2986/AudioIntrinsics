#pragma once

#include "AudioType.h"

#include <bitset>
#include <string>
#include <unordered_map>

namespace intrinsics {

inline size_t audioChannelCount(audio_channel_mask_t mask) {
    const std::bitset<32u> bs(mask);
    return bs.count();
}

inline size_t audioChannelCount(const audio_attribute_t &attribute) {
    return audioChannelCount(attribute.channelmask);
}

inline std::string audioChannelMaskToString(audio_channel_mask_t mask) {
    static const std::unordered_map<audio_channel_mask_t, std::string> kMap= {
        // output
        { AUDIO_CHANNEL_OUT_MONO, "mono out" },
        { AUDIO_CHANNEL_OUT_STEREO, "stereo out" },
        { AUDIO_CHANNEL_OUT_2POINT1, "2.1 out" },
        { AUDIO_CHANNEL_OUT_2POINT0POINT2, "2.0.2 out" },
        { AUDIO_CHANNEL_OUT_2POINT1POINT2, "2.1.2 out" },
        { AUDIO_CHANNEL_OUT_3POINT0POINT2, "3.0.2 out" },
        { AUDIO_CHANNEL_OUT_3POINT1POINT2, "3.1.2 out" },
        { AUDIO_CHANNEL_OUT_QUAD, "4.0 out" },
        { AUDIO_CHANNEL_OUT_QUAD_BACK, "4.0 back out" },
        { AUDIO_CHANNEL_OUT_QUAD_SIDE, "4.0 side out" },
        { AUDIO_CHANNEL_OUT_SURROUND, "4.0 surround out" },
        { AUDIO_CHANNEL_OUT_PENTA, "5.0 out" },
        { AUDIO_CHANNEL_OUT_5POINT1, "5.1 out" },
        { AUDIO_CHANNEL_OUT_5POINT1_BACK, "5.1 back out" },
        { AUDIO_CHANNEL_OUT_5POINT1_SIDE, "5.1 side out" },
        { AUDIO_CHANNEL_OUT_5POINT1POINT2, "5.1.2 out" },
        { AUDIO_CHANNEL_OUT_5POINT1POINT4, "5.1.4 out" },
        { AUDIO_CHANNEL_OUT_6POINT1, "6.1 out" },
        { AUDIO_CHANNEL_OUT_7POINT1, "7.1 out" },
        { AUDIO_CHANNEL_OUT_7POINT1POINT2, "7.1.2 out" },
        { AUDIO_CHANNEL_OUT_7POINT1POINT4, "7.1.4 out" },
        // input
        { AUDIO_CHANNEL_IN_MONO, "mono in" },
        { AUDIO_CHANNEL_IN_STEREO, "stereo in" },
        { AUDIO_CHANNEL_IN_FRONT_BACK, "front/back in" },
        { AUDIO_CHANNEL_IN_2POINT0POINT2, "2.0.2 in" },
        { AUDIO_CHANNEL_IN_2POINT1POINT2, "2.1.2 in" },
        { AUDIO_CHANNEL_IN_3POINT0POINT2, "3.0.2 in" },
        { AUDIO_CHANNEL_IN_3POINT1POINT2, "3.1.2 in" },
        { AUDIO_CHANNEL_IN_5POINT1, "5.1 in" },
    };
    return (kMap.find(mask) == kMap.end() ? "" : kMap.at(mask));
}

inline constexpr size_t audioBytesPerSample(audio_format_t format) {
    switch (format) {
        case AUDIO_FORMAT_PCM_8_BIT: {
            return sizeof(int8_t);
        }
        case AUDIO_FORMAT_PCM_16_BIT: {
            return sizeof(int16_t);
        }
        case AUDIO_FORMAT_PCM_24_BIT_PACKED: {
            return (sizeof(int32_t) - sizeof(int8_t));
        }
        case AUDIO_FORMAT_PCM_8_24_BIT: // [[fallthrough]];
        case AUDIO_FORMAT_PCM_32_BIT: {
            return sizeof(int32_t);
        }
        case AUDIO_FORMAT_PCM_FLOAT: {
            return sizeof(float);
        }
        default: {
            return 0u;
        }
    }
}

inline size_t audioBytesPerSample(const audio_attribute_t &attribute) {
    return audioBytesPerSample(attribute.format);
}

inline std::string audioFormatToString(audio_format_t format) {
    static const std::unordered_map<audio_format_t, std::string> kMap= {
        { AUDIO_FORMAT_PCM_8_BIT, "8-bit fixed" },
        { AUDIO_FORMAT_PCM_16_BIT, "16-bit fixed" },
        { AUDIO_FORMAT_PCM_8_24_BIT, "8-24-bit fixed" },
        { AUDIO_FORMAT_PCM_24_BIT_PACKED, "packed 24-bit fixed" },
        { AUDIO_FORMAT_PCM_32_BIT, "32-bit fixed" },
        { AUDIO_FORMAT_PCM_FLOAT, "32-bit floating" },
    };
    return (kMap.find(format) == kMap.end() ? "" : kMap.at(format));
}

inline size_t audioBytesPerFrame(audio_channel_mask_t mask, audio_format_t format) {
    return audioChannelCount(mask) * audioBytesPerSample(format);
}

inline size_t audioBytesPerFrame(const audio_attribute_t &attribute) {
    return audioBytesPerFrame(attribute.channelmask, attribute.format);
}

inline size_t audioFramesFromAttribute(const audio_attribute_t &attribute) {
    return attribute.framecount;
}

inline size_t audioSamplesFromAttribute(const audio_attribute_t &attribute) {
    return (audioFramesFromAttribute(attribute) * audioChannelCount(attribute.channelmask));
}

inline size_t audioBytesFromAttribute(const audio_attribute_t &attribute) {
    return (audioSamplesFromAttribute(attribute) * audioBytesPerSample(attribute.format));
}

inline audio_attribute_t makeAttribute(uint32_t rate, size_t frames,
                                       audio_format_t format, audio_channel_mask_t mask) {
    return {
        .samplerate = rate,
        .framecount = frames,
        .format = format,
        .channelmask = mask
    };
}

}  // namespace intrinsics
