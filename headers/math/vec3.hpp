#pragma once

#include "utilities/typeHandler.hpp"
#include "math/math.hpp"

#include <assert.h>     // assert()

template <typename T>
class Vec3 {
    public:
        inline Vec3() noexcept;
        inline Vec3(const Vec3<T>&) noexcept;
        inline Vec3(Vec3<T>&&) noexcept;
        inline ~Vec3() noexcept;

        template <typename U>
        inline Vec3(const Vec3<U>&) noexcept;
        template <typename U>
        inline Vec3(Vec3<U>&&) noexcept;
        template <typename U>
        inline Vec3(const U&) noexcept;
        template <typename U1, typename U2>
        inline Vec3(const U1&, const U2&) noexcept;
        template <typename U1, typename U2, typename U3>
        inline Vec3(const U1&, const U2&, const U3&) noexcept;

        inline Vec3<T>& operator=(const Vec3<T>&) noexcept;
        inline Vec3<T>& operator=(Vec3<T>&&) noexcept;

        template <typename U>
        inline Vec3<T>& operator=(const Vec3<U>&) noexcept;
        template <typename U>
        inline Vec3<T>& operator=(Vec3<U>&&) noexcept;

        template <typename U>
        inline Vec3<T>& operator()(const U&) noexcept;
        template <typename U1, typename U2>
        inline Vec3<T>& operator()(const U1&, const U2&) noexcept;
        template <typename U1, typename U2, typename U3>
        inline Vec3<T>& operator()(const U1&, const U2&, const U3&) noexcept;

        T& operator[](const unsigned int& idx);
        const T& operator[](const unsigned int& idx) const;

        template <typename U> inline Vec3<T>& operator+=(const Vec3<U>&) noexcept;
        template <typename U> inline Vec3<T>& operator-=(const Vec3<U>&) noexcept;
        template <typename U> inline Vec3<T>& operator*=(const U&) noexcept;
        template <typename U> Vec3<T>& operator/=(const U&);

        template <typename U> inline Vec3<T> operator+(const Vec3<U>&) const noexcept;
        template <typename U> inline Vec3<T> operator-(const Vec3<U>&) const noexcept;
        template <typename U> inline Vec3<T> operator*(const U&) const noexcept;
        template <typename U> Vec3<T> operator/(const U&) const;

        template <typename U> inline T dot(const Vec3<U>&) const noexcept;
        template <typename U> inline Vec3<T> cross(const Vec3<U>&) const noexcept;

        template <typename U> static inline T dot(const Vec3<T>&, const Vec3<U>&) noexcept;
        template <typename U> static inline Vec3<T> cross(const Vec3<T>&, const Vec3<U>&) noexcept;

    public:
        union { T x{ }, r; };
        union { T y{ }, g; };
        union { T z{ }, b; };
};

template <typename T> inline Vec3<T>::Vec3() noexcept { }
template <typename T> inline Vec3<T>::Vec3(const Vec3<T>& other) noexcept { *this = other; }
template <typename T> inline Vec3<T>::Vec3(Vec3<T>&& other) noexcept { *this = move(other); }
template <typename T> inline Vec3<T>::~Vec3() noexcept { }

template <typename T> template <typename U>
inline Vec3<T>::Vec3(const U& _x) noexcept { (*this)(_x); }
template <typename T> template <typename U1, typename U2>
inline Vec3<T>::Vec3(const U1& _x, const U2& _y) noexcept { (*this)(_x, _y); }
template <typename T> template <typename U1, typename U2, typename U3>
inline Vec3<T>::Vec3(const U1& _x, const U2& _y, const U3& _z) noexcept { (*this)(_x, _y, _z); }
template <typename T> template <typename U>
inline Vec3<T>::Vec3(const Vec3<U>& other) noexcept { *this = other; }
template <typename T> template <typename U>
inline Vec3<T>::Vec3(Vec3<U>&& other) noexcept { *this = move(other); }

template <typename T> inline Vec3<T>& Vec3<T>::operator=(const Vec3<T>& other) noexcept {
    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
}
template <typename T> inline Vec3<T>& Vec3<T>::operator=(Vec3<T>&& other) noexcept {
    x = other.x;
    y = other.y;
    z = other.z;

    other.x = { };
    other.y = { };
    other.z = { };

    return *this;
}

template <typename T> template <typename U>
inline Vec3<T>& Vec3<T>::operator=(const Vec3<U>& other) noexcept {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);

    return *this;
}
template <typename T> template <typename U>
inline Vec3<T>& Vec3<T>::operator=(Vec3<U>&& other) noexcept {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);

    other.x = { };
    other.y = { };
    other.z = { };

    return *this;
}

template <typename T> template <typename U>
inline Vec3<T>& Vec3<T>::operator()(const U& _x) noexcept {
    x = _x;

    return *this;
}
template <typename T> template <typename U1, typename U2>
inline Vec3<T>& Vec3<T>::operator()(const U1& _x, const U2& _y) noexcept {
    x = static_cast<T>(_x);
    y = static_cast<T>(_y);

    return *this;
}
template <typename T> template <typename U1, typename U2, typename U3>
inline Vec3<T>& Vec3<T>::operator()(const U1& _x, const U2& _y, const U3& _z) noexcept {
    x = static_cast<T>(_x);
    y = static_cast<T>(_y);
    z = static_cast<T>(_z);

    return *this;
}

template <typename T> T& Vec3<T>::operator[](const unsigned int& idx) {
    assert(idx < 3);

    switch (idx) {
        default:
        case 0: return x;
        case 1: return y;
        case 2: return z;
    }
}
template <typename T> const T& Vec3<T>::operator[](const unsigned int& idx) const {
    assert(idx < 3);

    switch (idx) {
        default:
        case 0: return x;
        case 1: return y;
        case 2: return z;
    }
}

template <typename T> template <typename U>
inline Vec3<T>& Vec3<T>::operator+=(const Vec3<U>& other) noexcept {
    x = static_cast<T>(x + other.x);
    y = static_cast<T>(y + other.y);
    z = static_cast<T>(z + other.z);

    return *this;
}
template <typename T> template <typename U>
inline Vec3<T>& Vec3<T>::operator-=(const Vec3<U>& other) noexcept {
    x = static_cast<T>(x - other.x);
    y = static_cast<T>(y - other.y);
    z = static_cast<T>(z - other.z);

    return *this;
}
template <typename T> template <typename U>
inline Vec3<T>& Vec3<T>::operator*=(const U& val) noexcept {
    x = static_cast<T>(x * val);
    y = static_cast<T>(y * val);
    z = static_cast<T>(z * val);

    return *this;
}
template <typename T> template <typename U>
Vec3<T>& Vec3<T>::operator/=(const U& val) {
    assert(!Math::isZero(val));

    x = static_cast<T>(x / val);
    y = static_cast<T>(y / val);
    z = static_cast<T>(z / val);

    return *this;
}

template <typename T> template <typename U>
inline Vec3<T> Vec3<T>::operator+(const Vec3<U>& other) const noexcept {
    return {
        static_cast<T>(x + other.x),
        static_cast<T>(y + other.y),
        static_cast<T>(z + other.z)
    };
}
template <typename T> template <typename U>
inline Vec3<T> Vec3<T>::operator-(const Vec3<U>& other) const noexcept {
    return {
        static_cast<T>(x - other.x),
        static_cast<T>(y - other.y),
        static_cast<T>(z - other.z)
    };
}
template <typename T> template <typename U>
inline Vec3<T> Vec3<T>::operator*(const U& val) const noexcept {
    return {
        static_cast<T>(x * val),
        static_cast<T>(y * val),
        static_cast<T>(z * val)
    };
}
template <typename T> template <typename U>
Vec3<T> Vec3<T>::operator/(const U& val) const {
    assert(!Math::isZero(val));

    return {
        static_cast<T>(x / val),
        static_cast<T>(y / val),
        static_cast<T>(z / val)
    };
}

template <typename T> template <typename U>
inline T Vec3<T>::dot(const Vec3<U>& other) const noexcept { return static_cast<T>(x * other.x + y * other.y + z * other.z); }
template <typename T> template <typename U>
inline Vec3<T> Vec3<T>::cross(const Vec3<U>& other) const noexcept {
    return {
        static_cast<T>(y * other.z - z * other.y),
        static_cast<T>(z * other.x - x * other.z),
        static_cast<T>(x * other.y - y * other.x)
    };
}

template <typename T> template <typename U>
inline T Vec3<T>::dot(const Vec3<T>& v1, const Vec3<U>& v2) noexcept { return v1.dot(v2); }
template <typename T> template <typename U>
inline Vec3<T> Vec3<T>::cross(const Vec3<T>& v1, const Vec3<U>& v2) noexcept { return v1.cross(v2); }