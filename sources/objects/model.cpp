#include "objects/model.hpp"

Model::Model()
    : Object{} { }
Model::~Model() noexcept { }

void Model::visible(const bool& tf) noexcept { mVisible = tf; }

bool Model::isVisible() const noexcept { return mVisible; }