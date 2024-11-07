#include "core/window.hpp"
#include "core/renderer.hpp"
#include "core/shader.hpp"
#include "core/world.hpp"

#include "math/vec2.hpp"
#include "math/vec3.hpp"
#include "math/math.hpp"
#include <iostream>

constexpr unsigned int WIN_WIDTH = 800;
constexpr unsigned int WIN_HEIGHT = 600;
constexpr const char* WIN_TITLE = "glfwRenderer";

int main() {
    /* Window window(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    World world("main");

    Shader objShader;
    objShader.load("./shaders/objShader.vert");
    objShader.load("./shaders/objShader.frag");
    objShader.compile();

    Renderer renderer;
    renderer.targetWindow(&window);
    renderer.targetWorld(&world);
    renderer.run(); */

    Vec2<float> v1;
    Vec2<float> v2;

    Vec2<double> v3 = v1;

    v1 = v2;
    v1 = move(v2);
    v2 = v3;

    v1(v3);
    v1(2.0, 1);

    return 0;
}