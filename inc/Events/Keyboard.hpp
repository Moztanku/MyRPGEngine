/**
 * @file Keyboard.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains components related to keyboard input
 */
#pragma once

#include "jac/type_defs.hpp"

#include "utils/defs.hpp"

namespace Events
{

ECS_COMPONENT
struct KeyboardInput
{
    enum struct Action : uint8
    {
        Press = 0u,
        Release,
        Repeat
    };

    enum struct Mod : uint8
    {
        Shift       = 1u << 0,
        Control     = 1u << 1,
        Alt         = 1u << 2,
        Super       = 1u << 3,
        CapsLock    = 1u << 4,
        NumLock     = 1u << 5
    };

    int key;
    int scancode;

    Action action;
    uint mods;

    bool hasMod(Mod mod) const
    {
        return (mods & static_cast<uint>(mod)) != 0;
    }
};

} // namespace Events
