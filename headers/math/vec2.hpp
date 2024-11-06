#pragma once

#include "utilities/typeHandler.hpp"

template <typename T>
class Vec2 {
    public:
        Vec2();
        Vec2(const Vec2<T>&);
        Vec2(Vec2<T>&&) noexcept;
        ~Vec2() noexcept;

        Vec2<T>& operator=(const Vec2<T>&);
        Vec2<T>& operator=(Vec2<T>&&) noexcept;

        // vector calc functions

    public:
        union { T x{ }, s; };
        union { T y{ }, t; };
};

template <typename T> Vec2<T>::Vec2() { }
template <typename T> Vec2<T>::Vec2(const Vec2<T>& other) { *this = other; }
template <typename T> Vec2<T>::Vec2(Vec2<T>&& other) noexcept { *this = move(other); }
template <typename T> Vec2<T>::~Vec2() noexcept { }

template <typename T> Vec2<T>& Vec2<T>::operator=(const Vec2<T>& other) {
    x = other.x;
    y = other.y;

    return *this;
}
template <typename T> Vec2<T>& Vec2<T>::operator=(Vec2<T>&& other) noexcept {
    x = other.x;
    y = other.y;

    other.x = { };
    other.y = { };

    return *this;
}