#include "core/window.hpp"
#include "core/renderer.hpp"
#include "core/shader.hpp"

constexpr unsigned int WIN_WIDTH = 800;
constexpr unsigned int WIN_HEIGHT = 600;
constexpr const char* WIN_TITLE = "glfwRenderer";

int main() {
    Window window(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);

    Shader objShader;
    objShader.load("./shaders/objShader.vert");
    objShader.load("./shaders/objShader.frag");
    objShader.compile();

    Renderer renderer;
    renderer.targetWindow(&window);
    renderer.run();

    return 0;
}