#pragma once

#include "utilities/typeHandler.hpp"

template <typename T>
class Vec3 {
    public:
        Vec3();
        Vec3(const Vec3<T>&);
        Vec3(Vec3<T>&&) noexcept;
        ~Vec3() noexcept;

        Vec3<T>& operator=(const Vec3<T>&);
        Vec3<T>& operator=(Vec3<T>&&) noexcept;

        // vector calc functions

    public:
        union { T x{ }, r; };
        union { T y{ }, g; };
        union { T z{ }, b; };
};

template <typename T> Vec3<T>::Vec3() { }
template <typename T> Vec3<T>::Vec3(const Vec3<T>& other) { *this = other; }
template <typename T> Vec3<T>::Vec3(Vec3<T>&& other) noexcept { *this = move(other); }
template <typename T> Vec3<T>::~Vec3() noexcept { }

template <typename T> Vec3<T>& Vec3<T>::operator=(const Vec3<T>& other) {
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