#pragma once

#include "components/component.hpp"
#include "math/vec2.hpp"

#include <deque>
using std::deque;

class Image;

class Texture: public Component {
        Texture() = delete;
        Texture(const Texture&) = delete;
        Texture(Texture&&) noexcept = delete;

        Texture& operator=(const Texture&) = delete;
        Texture& operator=(Texture&&) noexcept = delete;

    public:
        Texture(const Image&);
        virtual ~Texture() noexcept;

        void use() const;
        void setCoords(const deque<Vec2<float>>& coords) noexcept;

        unsigned int get() const noexcept;

        static unsigned short componentID() noexcept;

    private:
        unsigned int mVBO{ };
        unsigned int mTexture{ };

        deque<Vec2<float>> mCoords;
};