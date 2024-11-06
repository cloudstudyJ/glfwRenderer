#pragma once

#include "utilities/typeHandler.hpp"

#include <assert.h>     // assert()

template <typename T>
class Vec3 {
    public:
        Vec3() noexcept;
        Vec3(const Vec3<T>&) noexcept;
        Vec3(Vec3<T>&&) noexcept;
        ~Vec3() noexcept;

        template <typename U>
        Vec3(const Vec3<U>&) noexcept;
        template <typename U>
        Vec3(Vec3<U>&&) noexcept;
        template <typename U>
        Vec3(const U&) noexcept;
        template <typename U1, typename U2>
        Vec3(const U1&, const U2&) noexcept;
        template <typename U1, typename U2, typename U3>
        Vec3(const U1&, const U2&, const U3&) noexcept;

        Vec3<T>& operator=(const Vec3<T>&) noexcept;
        Vec3<T>& operator=(Vec3<T>&&) noexcept;

        template <typename U>
        Vec3<T>& operator=(const Vec3<U>&) noexcept;
        template <typename U>
        Vec3<T>& operator=(Vec3<U>&&) noexcept;

        template <typename U>
        Vec3<T>& operator()(const U&) noexcept;
        template <typename U1, typename U2>
        Vec3<T>& operator()(const U1&, const U2&) noexcept;
        template <typename U1, typename U2, typename U3>
        Vec3<T>& operator()(const U1&, const U2&, const U3&) noexcept;

        T& operator[](const unsigned int& idx);
        const T& operator[](const unsigned int& idx) const;

        // vector calc functions

    public:
        union { T x{ }, r; };
        union { T y{ }, g; };
        union { T z{ }, b; };
};

template <typename T> Vec3<T>::Vec3() noexcept { }
template <typename T> Vec3<T>::Vec3(const Vec3<T>& other) noexcept { *this = other; }
template <typename T> Vec3<T>::Vec3(Vec3<T>&& other) noexcept { *this = move(other); }
template <typename T> Vec3<T>::~Vec3() noexcept { }

template <typename T> template <typename U>
Vec3<T>::Vec3(const U& _x) noexcept { (*this)(_x); }
template <typename T> template <typename U1, typename U2>
Vec3<T>::Vec3(const U1& _x, const U2& _y) noexcept { (*this)(_x, _y); }
template <typename T> template <typename U1, typename U2, typename U3>
Vec3<T>::Vec3(const U1& _x, const U2& _y, const U3& _z) noexcept { (*this)(_x, _y, _z); }
template <typename T> template <typename U>
Vec3<T>::Vec3(const Vec3<U>& other) noexcept { *this = other; }
template <typename T> template <typename U>
Vec3<T>::Vec3(Vec3<U>&& other) noexcept { *this = move(other); }

template <typename T> Vec3<T>& Vec3<T>::operator=(const Vec3<T>& other) noexcept {
    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
}
template <typename T> Vec3<T>& Vec3<T>::operator=(Vec3<T>&& other) noexcept {
    x = other.x;
    y = other.y;
    z = other.z;

    other.x = { };
    other.y = { };
    other.z = { };

    return *this;
}

template <typename T> template <typename U>
Vec3<T>& Vec3<T>::operator=(const Vec3<U>& other) noexcept {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);

    return *this;
}
template <typename T> template <typename U>
Vec3<T>& Vec3<T>::operator=(Vec3<U>&& other) noexcept {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);

    other.x = { };
    other.y = { };
    other.z = { };

    return *this;
}

template <typename T> template <typename U>
Vec3<T>& Vec3<T>::operator()(const U& _x) noexcept {
    x = _x;
    y = { };
    z = { };

    return *this;
}
template <typename T> template <typename U1, typename U2>
Vec3<T>& Vec3<T>::operator()(const U1& _x, const U2& _y) noexcept {
    x = static_cast<T>(_x);
    y = static_cast<T>(_y);
    z = { };

    return *this;
}
template <typename T> template <typename U1, typename U2, typename U3>
Vec3<T>& Vec3<T>::operator()(const U1& _x, const U2& _y, const U3& _z) noexcept {
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