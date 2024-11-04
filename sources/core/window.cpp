#include "core/window.hpp"

#include "glew/glew.h"
#include "glfw/glfw3.h"

#include <iostream>
using std::cout;
using std::endl;

Window::Window(const unsigned int& w, const unsigned int& h, const char* title)
    : mWidth{w}, mHeight{h}, mTitle{title} {
    if (!glfwInit())
        cout << "[ERROR]: GLFW INIT" << endl;

    else {
        glfwSetErrorCallback( [](int errCode, const char* desc) { cout << "[ERROR " << errCode << "]: " << desc << endl; } );

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

        mHandle = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(mHandle);

        if (glewInit()) {
            cout << "[ERROR]: GLEW INIT" << endl;

            glfwTerminate();
        }

        else
            glViewport(0, 0, mWidth, mHeight);
    }
}
Window::~Window() noexcept { glfwTerminate(); }

GLFWwindow* Window::handle() const noexcept { return mHandle; }