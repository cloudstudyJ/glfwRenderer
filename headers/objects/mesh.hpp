#pragma once

#include "math/vec2.hpp"
#include "math/vec3.hpp"

#include <deque>
using std::deque;

class Texture;

struct Mesh {
    unsigned int vao{ };
    unsigned int vbo{ };
    unsigned int ebo{ };

    deque<Vec3<float>> vertices;
    deque<Vec3<float>> normals;
    deque<Vec3<unsigned int>> faces;
    deque<Texture*> textures;
};