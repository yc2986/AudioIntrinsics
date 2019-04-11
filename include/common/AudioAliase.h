#pragma once

#include <array>
#include <vector>
#include <cstddef>

namespace intrinsics {

// type aliase
/* data type */
#if __cplusplus >= 201703L && \
        (defined(__cpp_lib_byte) && (__cpp_lib_byte >= 201603)  || \
         defined(_LIBCPP_VERSION) && (_LIBCPP_VERSION >= 5000))
using byte_t = std::byte;
#else
using byte_t = uint8_t;
#endif

/* container */
template <size_t N>
using byte_array_t = std::array<byte_t, N>;
using byte_vector_t = std::vector<byte_t>;

/* enum aliase */
using audio_format_t = uint32_t;
using audio_channel_mask_t = uint32_t;

}  // namespace intrinsics
