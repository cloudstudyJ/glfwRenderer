#include "core/window.hpp"
#include "core/renderer.hpp"

constexpr unsigned int WIN_WIDTH = 800;
constexpr unsigned int WIN_HEIGHT = 600;
constexpr const char* WIN_TITLE = "glfwRenderer";

int main() {
    Window window(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);

    Renderer renderer;
    renderer.targetWindow(&window);
    renderer.run();

    return 0;
}