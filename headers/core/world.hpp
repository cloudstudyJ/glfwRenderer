#pragma once

#include <string>
using std::string;

class World {
    World() = delete;
    World(const World&) = delete;
    World(World&&) noexcept = delete;

    World& operator=(const World&) = delete;
    World& operator=(World&&) noexcept = delete;

    public:
        World(const string&);
        ~World() noexcept;

        void name(const string&) noexcept;

        string name() const noexcept;

    private:
        string mName;
};