#pragma once

class Image {
    Image() = delete;
    Image(const Image&) = delete;

    Image& operator=(const Image&) = delete;

    public:
        Image(const unsigned int&, const unsigned int&, const unsigned char&, unsigned char*);
        Image(Image&&) noexcept;
        ~Image() noexcept;

        Image& operator=(Image&&) noexcept;

        explicit operator bool() const noexcept;

        unsigned int width() const noexcept;
        unsigned int height() const noexcept;
        unsigned char channels() const noexcept;

        [[nodiscard]] const unsigned char* const data() const noexcept;

    private:
        unsigned int mWidth{ };
        unsigned int mHeight{ };
        unsigned char mChannels{ };

        unsigned char* mData{ };
};