#include "components/texture.hpp"
#include "resources/image.hpp"

#include "glew/glew.h"
#include "glfw/glfw3.h"

#include <iostream>
using std::cout;
using std::endl;

Texture::Texture(const Image& img)
    : Component{componentID()} {
    if (img) {
        glGenBuffers(1, &mVBO);
        glGenTextures(1, &mTexture);
        glBindTexture(GL_TEXTURE_2D, mTexture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int channel =
            (img.channels() == 3) ? GL_RGB :
            (img.channels() == 1) ? GL_RED : GL_RGBA
        ;

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width(), img.height(), 0, channel, GL_UNSIGNED_BYTE, img.data());
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
        cout << "[ERROR]: FAILED TO MAKE TEXTURE. NO IMG DATA" << endl;
}
Texture::~Texture() noexcept {
    glDeleteBuffers(1, &mVBO);
    glDeleteTextures(1, &mTexture);
}

void Texture::use() const { glBindTexture(GL_TEXTURE_2D, mTexture); }
void Texture::setCoords(const deque<Vec2<float>>& coords) noexcept {
    if (!mCoords.empty())
        mCoords.clear();

    mCoords.resize(coords.size());

    for (const auto& coord: coords)
        mCoords.emplace_back(coord);

    mCoords.shrink_to_fit();

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mCoords.size() * sizeof(Vec2<float>), &mCoords[0], GL_STATIC_DRAW);

    // texture uniform?
    /* glVertexAttribPointer(10, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2<float>), (void*)0);
    glEnableVertexAttribArray(10); */
}

unsigned int Texture::get() const noexcept { return mTexture; }

unsigned short Texture::componentID() noexcept {
    static const unsigned short id = 8;

    return id;
}