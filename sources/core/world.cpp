#include "core/world.hpp"

#include <string>
using std::string;

World::World(const string& name)
    : mName{name} { }
World::~World() noexcept { }

void World::name(const string& name) noexcept { mName = name; }

string World::name() const noexcept { return mName; }