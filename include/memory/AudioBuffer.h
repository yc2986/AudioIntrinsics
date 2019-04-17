#pragma once

#include "common/Audio.h"

#include <new>
#include <stdexcept>
#include <cstdlib>

namespace intrinsics {

enum memory_alignment_t : uint32_t {
    MEMORY_ALIGNMENT_NONE = 0u,
    MEMORY_ALIGNMENT_8_BYTES = 8u,
    MEMORY_ALIGNMENT_16_BYTES = 16u,
    MEMORY_ALIGNMENT_32_BYTES = 32u,
};

class AudioBuffer {

public:
    /**
     * constructor using locally allocated memory.
     * memory lifetime will be completely managed by the AudioBuffer object
     * 
     * @param[in] attribute audio attribute indicating buffer size to allocate
     * @param[in] alignment memory alignment, default no alignment
     * 
     * @throws std::bad_alloc
     */
    AudioBuffer(const audio_attribute_t &attribute,
                memory_alignment_t alignment = MEMORY_ALIGNMENT_NONE)
            : mLocalMemory(true)
            , mBuffer(allocateMemory(alignment, audioBytesFromAttribute(attribute)))
            , mAttribute(attribute) {}
    /**
     * constructor reference externally allocated memory.
     * external caller is responsible for managing buffer lifetime.
     */
    AudioBuffer(byte_t *buffer, const audio_attribute_t &attribute)
            : mLocalMemory(false)
            , mBuffer(buffer)
            , mAttribute(attribute) {}
    virtual ~AudioBuffer() = default;

    // interface
    // reference accesser
    template <class T = byte_t>
    inline T& atSample(size_t i) {
        return *atSamplePtr<T>(i * getSampleSize());
    }
    template <class T = byte_t>
    inline const T& atSample(size_t i) const {
        return *atSamplePtr<T>(i * getSampleSize());
    }
    template <class T = byte_t>
    inline T& atFrame(size_t i) {
        return *atFramePtr<T>(i * getFrameSize());
    }
    template <class T = byte_t>
    inline const T& atFrame(size_t i) const {
        return *atFramePtr<T>(i * getFrameSize());
    }
    // pointer accesser
    template <class T = byte_t>
    inline T* atSamplePtr(size_t i) {
        if (i >= getTotalBytes()) {
            throw std::out_of_range("invalid index " + std::to_string(i));
        }
        return reinterpret_cast<T*>(mBuffer + i * getSampleSize());
    }
    template <class T = byte_t>
    inline const T* atSamplePtr(size_t i) const {
        if (i >= getTotalBytes()) {
            throw std::out_of_range("invalid index " + std::to_string(i));
        }
        return reinterpret_cast<const T*>(mBuffer + i * getSampleSize());
    }
    template <class T = byte_t>
    inline T* atFramePtr(size_t i) {
        if (i >= getTotalBytes()) {
            throw std::out_of_range("invalid index " + std::to_string(i));
        }
        return reinterpret_cast<T*>(mBuffer + i * getFrameSize());
    }
    template <class T = byte_t>
    inline const T* atFramePtr(size_t i) const {
        if (i >= getTotalBytes()) {
            throw std::out_of_range("invalid index " + std::to_string(i));
        }
        return reinterpret_cast<const T*>(mBuffer + i * getFrameSize());
    }

    // getter for channels
    inline audio_channel_mask_t getChannelMask() const { return mAttribute.channelmask; }
    inline size_t getChannelCount() const { return audioChannelCount(mAttribute); }
    // getter for format
    inline audio_format_t getSampleFormat() const { return mAttribute.format; }
    inline size_t getSampleSize() const { return audioBytesPerSample(mAttribute); }
    inline size_t getFrameSize() const { return audioBytesPerFrame(mAttribute); }
    // getter for size
    inline size_t getTotalFrames() const { return audioFramesFromAttribute(mAttribute); }
    inline size_t getTotalSamples() const { return audioSamplesFromAttribute(mAttribute); }
    inline size_t getTotalBytes() const { return audioBytesFromAttribute(mAttribute); }

private:
    // helpers
    byte_t* allocateMemory(size_t alignment, size_t size) noexcept(false) {
        byte_t *memory = nullptr;
        if (alignment == 0) {
            memory = reinterpret_cast<byte_t*>(std::malloc(size));
        } else {
            memory = reinterpret_cast<byte_t*>(std::aligned_alloc(alignment, size));
        }
        if (memory == nullptr) {
            throw std::bad_alloc{};
        }
        return memory;
    }

    const bool mLocalMemory;
    byte_t *mBuffer;
    const audio_attribute_t mAttribute;

};

} // namespace intrinsics
