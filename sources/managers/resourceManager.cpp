#include "managers/resourceManager.hpp"
#include "managers/fileManager.hpp"
#include "resources/image.hpp"
#include "components/texture.hpp"

#include <iostream>
using std::cout;
using std::endl;

unordered_map<string, Texture*> ResourceManager::mTextureCaches;

void ResourceManager::loadTexture(const char* file) {
    Image img = FileManager::readImage(file);
    Texture* texture = new Texture(img);

    mTextureCaches.emplace(FileManager::getFileName(file), texture);
}

void ResourceManager::clear() noexcept {
    for (auto& it: mTextureCaches) {
        delete it.second;

        mTextureCaches.erase(it.first);
    }
}