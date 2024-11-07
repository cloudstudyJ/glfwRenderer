#pragma once

#include "utilities/typeHandler.hpp"
#include "math/math.hpp"

#include <assert.h>     // assert()

template <typename T>
class Vec2 {
    public:
        inline Vec2() noexcept;
        inline Vec2(const Vec2<T>&) noexcept;
        inline Vec2(Vec2<T>&&) noexcept;
        inline ~Vec2() noexcept;

        template <typename U>
        inline Vec2(const Vec2<U>&) noexcept;
        template <typename U>
        inline Vec2(Vec2<U>&&) noexcept;
        template <typename U>
        inline Vec2(const U&) noexcept;
        template <typename U1, typename U2>
        inline Vec2(const U1&, const U2&) noexcept;

        inline Vec2<T>& operator=(const Vec2<T>&) noexcept;
        inline Vec2<T>& operator=(Vec2<T>&&) noexcept;

        template <typename U>
        inline Vec2<T>& operator=(const Vec2<U>&) noexcept;
        template <typename U>
        inline Vec2<T>& operator=(Vec2<U>&&) noexcept;

        template <typename U>
        inline Vec2<T>& operator()(const U&) noexcept;
        template <typename U1, typename U2>
        inline Vec2<T>& operator()(const U1&, const U2&) noexcept;

        T& operator[](const unsigned int& idx);
        const T& operator[](const unsigned int& idx) const;

        template <typename U> inline Vec2<T>& operator+=(const Vec2<U>&) noexcept;
        template <typename U> inline Vec2<T>& operator-=(const Vec2<U>&) noexcept;
        template <typename U> inline Vec2<T>& operator*=(const U&) noexcept;
        template <typename U> Vec2<T>& operator/=(const U&);

        template <typename U> inline Vec2<T> operator+(const Vec2<U>&) const noexcept;
        template <typename U> inline Vec2<T> operator-(const Vec2<U>&) const noexcept;
        template <typename U> inline Vec2<T> operator*(const U&) const noexcept;
        template <typename U> Vec2<T> operator/(const U&) const;

    public:
        union { T x{ }, s; };
        union { T y{ }, t; };
};

template <typename T> inline Vec2<T>::Vec2() noexcept { }
template <typename T> inline Vec2<T>::Vec2(const Vec2<T>& other) noexcept { *this = other; }
template <typename T> inline Vec2<T>::Vec2(Vec2<T>&& other) noexcept { *this = move(other); }
template <typename T> inline Vec2<T>::~Vec2() noexcept { }

template <typename T> template <typename U>
inline Vec2<T>::Vec2(const Vec2<U>& other) noexcept { *this = other; }
template <typename T> template <typename U>
inline Vec2<T>::Vec2(Vec2<U>&& other) noexcept { *this = move(other); }
template <typename T> template <typename U>
inline Vec2<T>::Vec2(const U& _x) noexcept { (*this)(_x); }
template <typename T> template <typename U1, typename U2>
inline Vec2<T>::Vec2(const U1& _x, const U2& _y) noexcept { (*this)(_x, _y); }

template <typename T> inline Vec2<T>& Vec2<T>::operator=(const Vec2<T>& other) noexcept {
    x = other.x;
    y = other.y;

    return *this;
}
template <typename T> inline Vec2<T>& Vec2<T>::operator=(Vec2<T>&& other) noexcept {
    x = other.x;
    y = other.y;

    other.x = { };
    other.y = { };

    return *this;
}

template <typename T> template <typename U>
inline Vec2<T>& Vec2<T>::operator=(const Vec2<U>& other) noexcept {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);

    return *this;
}
template <typename T> template <typename U>
inline Vec2<T>& Vec2<T>::operator=(Vec2<U>&& other) noexcept {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);

    other.x = { };
    other.y = { };

    return *this;
}

template <typename T> template <typename U>
inline Vec2<T>& Vec2<T>::operator()(const U& _x) noexcept {
    x = static_cast<T>(_x);

    return *this;
}
template <typename T> template <typename U1, typename U2>
inline Vec2<T>& Vec2<T>::operator()(const U1& _x, const U2& _y) noexcept {
    x = static_cast<T>(_x);
    y = static_cast<T>(_y);

    return *this;
}

template <typename T> T& Vec2<T>::operator[](const unsigned int& idx) {
    assert(idx < 2);

    switch (idx) {
        default:
        case 0: return x;
        case 1: return y;
    }
}
template <typename T> const T& Vec2<T>::operator[](const unsigned int& idx) const {
    assert(idx < 2);

    switch (idx) {
        default:
        case 0: return x;
        case 1: return y;
    }
}

template <typename T> template <typename U>
inline Vec2<T>& Vec2<T>::operator+=(const Vec2<U>& other) noexcept {
    x = static_cast<T>(x + other.x);
    y = static_cast<T>(y + other.y);

    return *this;
}
template <typename T> template <typename U>
inline Vec2<T>& Vec2<T>::operator-=(const Vec2<U>& other) noexcept {
    x = static_cast<T>(x - other.x);
    y = static_cast<T>(y - other.y);

    return *this;
}
template <typename T> template <typename U>
inline Vec2<T>& Vec2<T>::operator*=(const U& val) noexcept {
    x = static_cast<T>(x * val);
    y = static_cast<T>(y * val);

    return *this;
}
template <typename T> template <typename U>
Vec2<T>& Vec2<T>::operator/=(const U& val) {
    assert(!Math::isZero(val));

    x = static_cast<T>(x / val);
    y = static_cast<T>(y / val);

    return *this;
}

template <typename T> template <typename U>
inline Vec2<T> Vec2<T>::operator+(const Vec2<U>& other) const noexcept {
    return {
        static_cast<T>(x + other.x),
        static_cast<T>(y + other.y)
    };
}
template <typename T> template <typename U>
inline Vec2<T> Vec2<T>::operator-(const Vec2<U>& other) const noexcept {
    return {
        static_cast<T>(x - other.x),
        static_cast<T>(y - other.y)
    };
}
template <typename T> template <typename U>
inline Vec2<T> Vec2<T>::operator*(const U& val) const noexcept {
    return {
        static_cast<T>(x * val),
        static_cast<T>(y * val)
    };
}
template <typename T> template <typename U>
Vec2<T> Vec2<T>::operator/(const U& val) const {
    assert(!Math::isZero(val));

    return {
        static_cast<T>(x / val),
        static_cast<T>(y / val)
    };
}