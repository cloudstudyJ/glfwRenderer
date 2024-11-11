#include "resources/image.hpp"
#include "utilities/typeHandler.hpp"

// already defined STB_IMAGE_IMPLEMENTATION
#include "stbi/stb_image.h"

#include <iostream>
using std::cout;
using std::endl;

Image::Image(const unsigned int& width, const unsigned int& height, const unsigned char& channels, unsigned char* data)
    : mWidth{width}, mHeight{height}, mChannels{channels}, mData{data} { }
Image::Image(Image&& other) noexcept { *this = move(other); }
Image::~Image() noexcept {
    if (mData != nullptr)
        stbi_image_free(mData);
}

Image& Image::operator=(Image&& other) noexcept {
    if (mData != nullptr)
        stbi_image_free(mData);

    mWidth = other.mWidth;
    mHeight = other.mHeight;
    mChannels = other.mChannels;
    mData = other.mData;

    other.mWidth = { };
    other.mHeight = { };
    other.mChannels = { };
    other.mData = { };

    return *this;
}

Image::operator bool() const noexcept { return (mData != nullptr); }

unsigned int Image::width() const noexcept { return mWidth; }
unsigned int Image::height() const noexcept { return mHeight; }
unsigned char Image::channels() const noexcept { return mChannels; }

[[nodiscard]] const unsigned char* const Image::data() const noexcept { return mData; }