#include "core/renderer.hpp"
#include "core/window.hpp"

#include "glew/glew.h"
#include "glfw/glfw3.h"

#include <iostream>
using std::cout;
using std::endl;

Renderer::Renderer() { }
Renderer::~Renderer() noexcept { }

void Renderer::targetWindow(Window* window) noexcept { mTargetWindow = window; }
void Renderer::targetWorld(World* world) noexcept { mTargetWorld = world; }

void Renderer::run() noexcept {
    if (mTargetWindow == nullptr) {
        cout << "[ERROR]: NO TARGET WINDOW TO RENDER" << endl;

        return;
    }

    while (!glfwWindowShouldClose(mTargetWindow->handle())) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        // draw here

        glfwSwapBuffers(mTargetWindow->handle());
    }
}