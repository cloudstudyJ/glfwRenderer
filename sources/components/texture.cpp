#include "components/texture.hpp"

#include "glew/glew.h"
#include "glfw/glfw3.h"

Texture::Texture(const char* file)
    : Component{componentID()} {
    // load texture from resource manager
}
Texture::~Texture() noexcept {
    glDeleteBuffers(1, &mVBO);
    glDeleteTextures(1, &mTexture);
}

void Texture::use() const { glBindTexture(GL_TEXTURE_2D, mTexture); }

unsigned int Texture::get() const noexcept { return mTexture; }

unsigned short Texture::componentID() noexcept {
    static const unsigned short id = 8;

    return id;
}