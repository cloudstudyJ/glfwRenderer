#pragma once

#include "math/vec2.hpp"
#include "math/vec3.hpp"

#include <deque>
using std::deque;

struct Mesh {
    unsigned int vao{ };
    unsigned int vbo{ };
    unsigned int ebo{ };
    unsigned int tex{ };

    deque<Vec3<float>> vertices;
    deque<Vec3<float>> normals;
    deque<Vec2<float>> texCoords;
    deque<Vec3<unsigned int>> faces;
};