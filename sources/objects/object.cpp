#include "objects/object.hpp"
#include "components/component.hpp"

Object::Object() { }
Object::~Object() noexcept {
    for (const auto& it: mComponents) {
        delete it.second;

        mComponents.erase(it.first);
    }
}

unsigned int Object::id() const noexcept { return mID; }

void Object::addComponent(Component* component) noexcept { mComponents.emplace(component->id(), component); }
unordered_map<unsigned short, Component*>& Object::getComponents() noexcept { return mComponents; }