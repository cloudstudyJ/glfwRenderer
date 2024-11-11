#include "core/shader.hpp"
#include "managers/fileManager.hpp"

#include "glew/glew.h"
#include "glfw/glfw3.h"

#include <iostream>
using std::cout;
using std::endl;

Shader::Shader() { }
Shader::~Shader() noexcept {
    glDeleteShader(mVertex);
    glDeleteShader(mFragment);
    glDeleteProgram(mHandle);
}

void Shader::load(const char* file) {
    if (FileManager::getFileExtension(file) == "vert")
        mVertex = make(file, GL_VERTEX_SHADER);

    else if (FileManager::getFileExtension(file) == "frag")
        mFragment = make(file, GL_FRAGMENT_SHADER);

    // geometry, tessellation
}

void Shader::compile() {
    mHandle = glCreateProgram();

    glAttachShader(mHandle, mVertex);
    // geometry, tessellation
    glAttachShader(mHandle, mFragment);
    glLinkProgram(mHandle);

    int success{ };
    char log[2048]{ };

    glGetProgramiv(mHandle, GL_LINK_STATUS, &success);
    if (!success) {
        cout << "[ERROR]: FAILED TO COMPILE SHADER" << endl;

        glGetProgramInfoLog(mHandle, sizeof(log), nullptr, log);
        cout << log << endl;
    }
}
void Shader::use() const noexcept { glUseProgram(mHandle); }

unsigned int Shader::get() const noexcept { return mHandle; }

unsigned int Shader::make(const char* file, const unsigned int& type) {
    const char* src = FileManager::readShader(file).c_str();

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int status{ };
    char log[2048]{ };

    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status) {
        cout << "[ERROR]: FAILED TO MAKE SHADER " << std::hex << type << endl;

        glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
        cout << log << endl;

        glDeleteShader(shader);
    }

    return shader;
}