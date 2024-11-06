#pragma once

class Component {
    Component() = delete;
    Component(const Component&) = delete;
    Component(Component&&) noexcept = delete;

    Component& operator=(const Component&) = delete;
    Component& operator=(Component&&) noexcept = delete;

    public:
        virtual ~Component() noexcept;

        unsigned short id() const noexcept;

    protected:
        Component(const unsigned short&);

    protected:
        unsigned short mID{ };
};