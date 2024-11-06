#pragma once

class Window;
class World;

class Renderer {
    Renderer(const Renderer&) = delete;
    Renderer(Renderer&&) noexcept = delete;

    Renderer& operator=(const Renderer&) = delete;
    Renderer& operator=(Renderer&&) noexcept = delete;

    public:
        Renderer();
        ~Renderer() noexcept;

        void targetWindow(Window*) noexcept;
        void targetWorld(World*) noexcept;

        void run() noexcept;

    private:
        Window* mTargetWindow{ };
        World* mTargetWorld{ };
};