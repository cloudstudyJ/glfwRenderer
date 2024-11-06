#pragma once

namespace TypeBase {
    template <typename T> struct removeReference      { using type = T; };
    template <typename T> struct removeReference<T&>  { using type = T; };
    template <typename T> struct removeReference<T&&> { using type = T; };
}

template <typename T> using removeReference = typename TypeBase::removeReference<T>::type;


template <typename T>
[[nodiscard]] constexpr decltype(auto) move(T&& val) noexcept
{ return static_cast<removeReference<T>&&>(val); }