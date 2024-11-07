#include "objects/model.hpp"
#include "components/texture.hpp"

#include "glew/glew.h"
#include "glfw/glfw3.h"

unsigned int Model::mModelCounter{ };

Model::Model()
    : Object{} { ++mModelCounter; }
Model::~Model() noexcept {
    for (auto& mesh: mMeshes) {
        glDeleteVertexArrays(1, &mesh.vao);
        glDeleteBuffers(1, &mesh.vbo);
        glDeleteBuffers(1, &mesh.ebo);

        for (auto& texture: mesh.textures)
            delete texture;
    }

    --mModelCounter;
}

void Model::visible(const bool& tf) noexcept { mVisible = tf; }

bool Model::isVisible() const noexcept { return mVisible; }

unsigned int Model::modelCount() noexcept { return mModelCounter; }