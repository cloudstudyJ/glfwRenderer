#include "objects/predefined/triangle.hpp"

#include "glew/glew.h"
#include "glfw/glfw3.h"

unsigned int Triangle::mTriangleCounter{ };

Triangle::Triangle(const Vec3<float>& v1, const Vec3<float>& v2, const Vec3<float>& v3)
    : Model{} {
    // make mesh and fill it
    // generate buffers
    // enable buffers

    ++mTriangleCounter;
}
Triangle::~Triangle() noexcept { --mTriangleCounter; }