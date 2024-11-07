#pragma once

#include "utilities/typeHandler.hpp"

class Math {
    // Numeric Constants
    public:
        template <typename T, typename = enableIF<isFloat<T>>>
        inline static constexpr T EPSILON = (isSame<T, float>) ? 1.0E-06f : 1.0E-15;

    // Base Functions
    public:
        template <typename T, typename = enableIF<isArithmetic<T>>>
        inline static constexpr T abs(const T&) noexcept;

        template <typename T, typename = enableIF<isArithmetic<T>>>
        inline static constexpr bool isZero(const T&) noexcept;
};

template <typename T, typename>
inline constexpr T Math::abs(const T& val) noexcept {
    if constexpr (isFloat<T>) {
        using iType = IF<isSame<T, float>, unsigned int, unsigned long long>;

        union {
            T     f;
            iType i;
        } conv;

        conv.f  = val;
        conv.i &= (isSame<T, float>) ? 0x7FFF'FFFFU : 0x7FFF'FFFF'FFFF'FFFFULL;

        return conv.f;
    }
    else if (isSignedInteger<T>)
        return (val < 0) ? -val : val;

    // unsigned integers
    return val;
}
template <typename T, typename>
inline constexpr bool Math::isZero(const T& val) noexcept {
    // check absolute error
    if constexpr (isFloat<T>)
        return (Math::abs(val) <= EPSILON<T>);

    return (val == 0);
}