#pragma once

#include <string>
using std::string;

struct GLFWwindow;

class Window {
    Window() = delete;
    Window(const Window&) = delete;
    Window(Window&&) noexcept = delete;

    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&) noexcept = delete;

    public:
        Window(const unsigned int&, const unsigned int&, const char*);
        ~Window() noexcept;

        GLFWwindow* handle() const noexcept;

    private:
        unsigned int mWidth{ };
        unsigned int mHeight{ };

        string mTitle;

        GLFWwindow* mHandle{ };
};