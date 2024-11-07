#pragma once

#include "objects/model.hpp"

class Triangle: public Model {
    Triangle() = delete;
    Triangle(const Triangle&) = delete;
    Triangle(Triangle&&) noexcept = delete;

    Triangle& operator=(const Triangle&) = delete;
    Triangle& operator=(Triangle&&) noexcept = delete;

    public:
        Triangle(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&);
        virtual ~Triangle() noexcept;

    private:
        static unsigned int mTriangleCounter;
};