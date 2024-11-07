#pragma once

class Shader {
    Shader(const Shader&) = delete;
    Shader(Shader&&) noexcept = delete;

    Shader& operator=(const Shader&) = delete;
    Shader& operator=(Shader&&) noexcept = delete;

    public:
        Shader();
        ~Shader() noexcept;

        void load(const char*);

        void compile();
        void use() const noexcept;

        unsigned int get() const noexcept;

    private:
        unsigned int make(const char*, const unsigned int&);

    private:
        unsigned int mVertex{ };
        // geometry, tessellation
        unsigned int mFragment{ };

        unsigned int mHandle{ };
};