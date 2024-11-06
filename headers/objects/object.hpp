#pragma once

#include <unordered_map>
using std::unordered_map;

class Component;

class Object {
    Object(const Object&) = delete;
    Object(Object&&) noexcept = delete;

    Object& operator=(const Object&) = delete;
    Object& operator=(Object&&) noexcept = delete;

    public:
        virtual ~Object() noexcept;

        void addComponent(Component*) noexcept;
        template <typename T> void removeComponent() noexcept;

        unsigned int id() const noexcept;

        template <typename T> T* getComponent() noexcept;
        unordered_map<unsigned short, Component*>& getComponents() noexcept;

    protected:
        Object();

    private:
        unsigned int mID{ };

        // <ComponentID, Component*>
        unordered_map<unsigned short, Component*> mComponents;
};

template <typename T> void Object::removeComponent() noexcept {
    auto& it = mComponents.find(T::componentID());

    if (it != mComponents.end()) {
        delete it.second;

        mComponents.erase(it);
    }
}
template <typename T> T* Object::getComponent() noexcept {
    const auto& it = mComponents.find(T::componentID());

    return (it == mComponents.end()) ? nullptr : static_cast<T*>(it.second);
}