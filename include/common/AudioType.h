#pragma once

#include "AudioAliase.h"

#include <cstddef>
#include <cstdint>

namespace intrinsics {

/* enumeration */
enum : uint32_t {
    AUDIO_FORMAT_INVALID = 0xFFFFFFFFu,
    AUDIO_FORMAT_DEFAULT = 0,
    /* main format */
    AUDIO_FORMAT_PCM = 0x00000000u,

    /* sub format */
    AUDIO_FORMAT_PCM_SUB_8_BIT = 0x1u,
    AUDIO_FORMAT_PCM_SUB_16_BIT = 0x2u,
    AUDIO_FORMAT_PCM_SUB_8_24_BIT = 0x3u,
    AUDIO_FORMAT_PCM_SUB_24_BIT_PACKED = 0x4u,
    AUDIO_FORMAT_PCM_SUB_32_BIT = 0x5u,
    AUDIO_FORMAT_PCM_SUB_FLOAT = 0x6u,

    /* aliase */
    AUDIO_FORMAT_PCM_8_BIT = AUDIO_FORMAT_PCM | AUDIO_FORMAT_PCM_SUB_8_BIT,
    AUDIO_FORMAT_PCM_16_BIT = AUDIO_FORMAT_PCM | AUDIO_FORMAT_PCM_SUB_16_BIT,
    AUDIO_FORMAT_PCM_8_24_BIT = AUDIO_FORMAT_PCM | AUDIO_FORMAT_PCM_SUB_8_24_BIT,
    AUDIO_FORMAT_PCM_24_BIT_PACKED = AUDIO_FORMAT_PCM | AUDIO_FORMAT_PCM_SUB_24_BIT_PACKED,
    AUDIO_FORMAT_PCM_32_BIT = AUDIO_FORMAT_PCM | AUDIO_FORMAT_PCM_SUB_32_BIT,
    AUDIO_FORMAT_PCM_FLOAT = AUDIO_FORMAT_PCM | AUDIO_FORMAT_PCM_SUB_FLOAT,
};

enum : uint32_t {
    AUDIO_CHANNEL_NONE = 0x0u,

    /* individual output channel */
    AUDIO_CHANNEL_OUT_FRONT_LEFT = 0x1u,
    AUDIO_CHANNEL_OUT_FRONT_RIGHT = 0x2u,
    AUDIO_CHANNEL_OUT_FRONT_CENTER = 0x4u,
    AUDIO_CHANNEL_OUT_LOW_FREQUENCY = 0x8u,
    AUDIO_CHANNEL_OUT_BACK_LEFT = 0x10u,
    AUDIO_CHANNEL_OUT_BACK_RIGHT = 0x20u,
    AUDIO_CHANNEL_OUT_FRONT_LEFT_OF_CENTER = 0x40u,
    AUDIO_CHANNEL_OUT_FRONT_RIGHT_OF_CENTER = 0x80u,
    AUDIO_CHANNEL_OUT_BACK_CENTER = 0x100u,
    AUDIO_CHANNEL_OUT_SIDE_LEFT = 0x200u,
    AUDIO_CHANNEL_OUT_SIDE_RIGHT = 0x400u,
    AUDIO_CHANNEL_OUT_TOP_CENTER = 0x800u,
    AUDIO_CHANNEL_OUT_TOP_FRONT_LEFT = 0x1000u,
    AUDIO_CHANNEL_OUT_TOP_FRONT_CENTER = 0x2000u,
    AUDIO_CHANNEL_OUT_TOP_FRONT_RIGHT = 0x4000u,
    AUDIO_CHANNEL_OUT_TOP_BACK_LEFT = 0x8000u,
    AUDIO_CHANNEL_OUT_TOP_BACK_CENTER = 0x10000u,
    AUDIO_CHANNEL_OUT_TOP_BACK_RIGHT = 0x20000u,
    AUDIO_CHANNEL_OUT_TOP_SIDE_LEFT = 0x40000u,
    AUDIO_CHANNEL_OUT_TOP_SIDE_RIGHT = 0x80000u,

    /* output channel mask */
    AUDIO_CHANNEL_OUT_MONO = AUDIO_CHANNEL_OUT_FRONT_CENTER,
    AUDIO_CHANNEL_OUT_STEREO = AUDIO_CHANNEL_OUT_FRONT_LEFT |
                               AUDIO_CHANNEL_OUT_FRONT_RIGHT,
    AUDIO_CHANNEL_OUT_2POINT1 = AUDIO_CHANNEL_OUT_STEREO |
                                AUDIO_CHANNEL_OUT_LOW_FREQUENCY,
    AUDIO_CHANNEL_OUT_2POINT0POINT2 = AUDIO_CHANNEL_OUT_STEREO |
                                      AUDIO_CHANNEL_OUT_TOP_SIDE_LEFT |
                                      AUDIO_CHANNEL_OUT_TOP_SIDE_RIGHT,
    AUDIO_CHANNEL_OUT_2POINT1POINT2 = AUDIO_CHANNEL_OUT_2POINT0POINT2 |
                                      AUDIO_CHANNEL_OUT_LOW_FREQUENCY,
    AUDIO_CHANNEL_OUT_3POINT0POINT2 = AUDIO_CHANNEL_OUT_2POINT0POINT2 |
                                      AUDIO_CHANNEL_OUT_FRONT_CENTER,
    AUDIO_CHANNEL_OUT_3POINT1POINT2 = AUDIO_CHANNEL_OUT_3POINT0POINT2 |
                                      AUDIO_CHANNEL_OUT_LOW_FREQUENCY,
    AUDIO_CHANNEL_OUT_QUAD = AUDIO_CHANNEL_OUT_STEREO |
                             AUDIO_CHANNEL_OUT_BACK_LEFT |
                             AUDIO_CHANNEL_OUT_BACK_RIGHT,
    AUDIO_CHANNEL_OUT_QUAD_BACK = AUDIO_CHANNEL_OUT_QUAD,
    AUDIO_CHANNEL_OUT_QUAD_SIDE = AUDIO_CHANNEL_OUT_STEREO |
                             AUDIO_CHANNEL_OUT_SIDE_LEFT |
                             AUDIO_CHANNEL_OUT_SIDE_RIGHT,
    AUDIO_CHANNEL_OUT_SURROUND = AUDIO_CHANNEL_OUT_STEREO |
                                 AUDIO_CHANNEL_OUT_FRONT_CENTER |
                                 AUDIO_CHANNEL_OUT_BACK_CENTER,
    AUDIO_CHANNEL_OUT_PENTA = AUDIO_CHANNEL_OUT_QUAD |
                              AUDIO_CHANNEL_OUT_FRONT_CENTER,
    AUDIO_CHANNEL_OUT_5POINT1 = AUDIO_CHANNEL_OUT_STEREO |
                                AUDIO_CHANNEL_OUT_FRONT_CENTER |
                                AUDIO_CHANNEL_OUT_LOW_FREQUENCY |
                                AUDIO_CHANNEL_OUT_BACK_LEFT |
                                AUDIO_CHANNEL_OUT_BACK_RIGHT,
    AUDIO_CHANNEL_OUT_5POINT1_BACK = AUDIO_CHANNEL_OUT_5POINT1,
    AUDIO_CHANNEL_OUT_5POINT1_SIDE = AUDIO_CHANNEL_OUT_STEREO |
                                     AUDIO_CHANNEL_OUT_FRONT_CENTER |
                                     AUDIO_CHANNEL_OUT_LOW_FREQUENCY |
                                     AUDIO_CHANNEL_OUT_SIDE_LEFT |
                                     AUDIO_CHANNEL_OUT_SIDE_RIGHT,
    AUDIO_CHANNEL_OUT_5POINT1POINT2 = AUDIO_CHANNEL_OUT_5POINT1_SIDE |
                                      AUDIO_CHANNEL_OUT_TOP_SIDE_LEFT |
                                      AUDIO_CHANNEL_OUT_TOP_SIDE_RIGHT,
    AUDIO_CHANNEL_OUT_5POINT1POINT4 = AUDIO_CHANNEL_OUT_5POINT1_SIDE |
                                      AUDIO_CHANNEL_OUT_TOP_FRONT_LEFT |
                                      AUDIO_CHANNEL_OUT_TOP_FRONT_RIGHT |
                                      AUDIO_CHANNEL_OUT_TOP_BACK_LEFT |
                                      AUDIO_CHANNEL_OUT_TOP_BACK_RIGHT,
    AUDIO_CHANNEL_OUT_6POINT1 = AUDIO_CHANNEL_OUT_5POINT1 |
                                AUDIO_CHANNEL_OUT_BACK_CENTER,
    AUDIO_CHANNEL_OUT_7POINT1 = AUDIO_CHANNEL_OUT_5POINT1 |
                                AUDIO_CHANNEL_OUT_SIDE_LEFT |
                                AUDIO_CHANNEL_OUT_SIDE_RIGHT,
    AUDIO_CHANNEL_OUT_7POINT1POINT2 = AUDIO_CHANNEL_OUT_7POINT1 |
                                      AUDIO_CHANNEL_OUT_TOP_SIDE_LEFT |
                                      AUDIO_CHANNEL_OUT_TOP_SIDE_RIGHT,
    AUDIO_CHANNEL_OUT_7POINT1POINT4 = AUDIO_CHANNEL_OUT_7POINT1 |
                                      AUDIO_CHANNEL_OUT_TOP_FRONT_LEFT |
                                      AUDIO_CHANNEL_OUT_TOP_FRONT_RIGHT |
                                      AUDIO_CHANNEL_OUT_TOP_BACK_LEFT |
                                      AUDIO_CHANNEL_OUT_TOP_BACK_RIGHT,

    /* individual input channel */
    AUDIO_CHANNEL_IN_LEFT                   = 0x4u,
    AUDIO_CHANNEL_IN_RIGHT                  = 0x8u,
    AUDIO_CHANNEL_IN_FRONT                  = 0x10u,
    AUDIO_CHANNEL_IN_BACK                   = 0x20u,
    AUDIO_CHANNEL_IN_BACK_LEFT              = 0x10000u,
    AUDIO_CHANNEL_IN_BACK_RIGHT             = 0x20000u,
    AUDIO_CHANNEL_IN_CENTER                 = 0x40000u,
    AUDIO_CHANNEL_IN_LOW_FREQUENCY          = 0x100000u,
    AUDIO_CHANNEL_IN_TOP_LEFT               = 0x200000u,
    AUDIO_CHANNEL_IN_TOP_RIGHT              = 0x400000u,

    /* input channel mask */
    AUDIO_CHANNEL_IN_MONO          = AUDIO_CHANNEL_IN_FRONT,
    AUDIO_CHANNEL_IN_STEREO        = AUDIO_CHANNEL_IN_LEFT | AUDIO_CHANNEL_IN_RIGHT,
    AUDIO_CHANNEL_IN_FRONT_BACK    = AUDIO_CHANNEL_IN_FRONT | AUDIO_CHANNEL_IN_BACK,
    AUDIO_CHANNEL_IN_2POINT0POINT2 = AUDIO_CHANNEL_IN_LEFT |
                                     AUDIO_CHANNEL_IN_RIGHT |
                                     AUDIO_CHANNEL_IN_TOP_LEFT |
                                     AUDIO_CHANNEL_IN_TOP_RIGHT,
    AUDIO_CHANNEL_IN_2POINT1POINT2 = AUDIO_CHANNEL_IN_LEFT |
                                     AUDIO_CHANNEL_IN_RIGHT |
                                     AUDIO_CHANNEL_IN_TOP_LEFT |
                                     AUDIO_CHANNEL_IN_TOP_RIGHT |
                                     AUDIO_CHANNEL_IN_LOW_FREQUENCY,
    AUDIO_CHANNEL_IN_3POINT0POINT2 = AUDIO_CHANNEL_IN_LEFT |
                                     AUDIO_CHANNEL_IN_CENTER |
                                     AUDIO_CHANNEL_IN_RIGHT |
                                     AUDIO_CHANNEL_IN_TOP_LEFT |
                                     AUDIO_CHANNEL_IN_TOP_RIGHT,
    AUDIO_CHANNEL_IN_3POINT1POINT2 = AUDIO_CHANNEL_IN_LEFT |
                                     AUDIO_CHANNEL_IN_CENTER |
                                     AUDIO_CHANNEL_IN_RIGHT |
                                     AUDIO_CHANNEL_IN_TOP_LEFT |
                                     AUDIO_CHANNEL_IN_TOP_RIGHT |
                                     AUDIO_CHANNEL_IN_LOW_FREQUENCY,
    AUDIO_CHANNEL_IN_5POINT1       = AUDIO_CHANNEL_IN_LEFT |
                                     AUDIO_CHANNEL_IN_CENTER |
                                     AUDIO_CHANNEL_IN_RIGHT |
                                     AUDIO_CHANNEL_IN_BACK_LEFT |
                                     AUDIO_CHANNEL_IN_BACK_RIGHT |
                                     AUDIO_CHANNEL_IN_LOW_FREQUENCY,
};

// defined structure
struct audio_attribute_t {
    uint32_t samplerate;
    size_t framecount;
    audio_format_t format;
    audio_channel_mask_t channelmask;
};

}  // namespace intrinsics
