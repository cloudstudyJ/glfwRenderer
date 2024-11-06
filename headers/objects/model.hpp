#pragma once

#include "objects/object.hpp"
#include "objects/mesh.hpp"

class Model: public Object {
    Model(const Model&) = delete;
    Model(Model&&) noexcept = delete;

    Model& operator=(const Model&) = delete;
    Model& operator=(Model&&) noexcept = delete;

    public:
        Model();
        virtual ~Model() noexcept;

        void visible(const bool&) noexcept;

        bool isVisible() const noexcept;

    protected:
        bool mVisible{ true };

        deque<Mesh> mMeshes;
};