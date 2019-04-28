#pragma once

#include "Error.h"

#include <type_traits>
#include <variant>

namespace intrinsics {

template <class T, class = std::enable_if_t<!std::is_same_v<T, Error>>>
class Return : private std::variant<T, Error> {

public:
    constexpr Return(const T &other) noexcept
            : std::variant<T, Error>(other) {}
    constexpr Return(T &&other) noexcept
            : std::variant<T, Error>(other) {}
    constexpr Return(const Error &err) noexcept
            : std::variant<T, Error>(err) {}
    virtual ~Return() = default;

    constexpr operator bool() const { return !std::holds_alternative<Error>(*this); }

    constexpr T& get() { return std::get<T>(*this); }
    constexpr const T& get() const { return std::get<T>(*this); }
    constexpr const Error& error() const { return std::get<Error>(*this); }

};

}  // namespace intrinsics
