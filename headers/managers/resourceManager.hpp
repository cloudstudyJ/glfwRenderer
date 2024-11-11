#pragma once

#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;

class Texture;

class ResourceManager {
    ResourceManager() = delete;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) noexcept = delete;
    ~ResourceManager() noexcept = delete;

    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager& operator=(ResourceManager&&) noexcept = delete;

    public:
        static void loadTexture(const char*);
        static void clearTextureCache() noexcept;

        static const Texture* const getTexture(const string&) noexcept;

    private:
        // Shader Cache
        static unordered_map<string, Texture*> mTextureCaches;
};