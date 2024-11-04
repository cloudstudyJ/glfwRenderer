#pragma once

class Window;

class Renderer {
    Renderer(const Renderer&) = delete;
    Renderer(Renderer&&) noexcept = delete;

    Renderer& operator=(const Renderer&) = delete;
    Renderer& operator=(Renderer&&) noexcept = delete;

    public:
        Renderer();
        ~Renderer() noexcept;

        void targetWindow(Window*) noexcept;

        void run() noexcept;

    private:
        Window* mTargetWindow{ };
};