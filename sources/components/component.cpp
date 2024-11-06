#include "components/component.hpp"

Component::Component(const unsigned short& id)
    : mID{id} { }
Component::~Component() noexcept { }

unsigned short Component::id() const noexcept { return mID; }