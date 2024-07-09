/**
 * @file Mouse.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains components related to mouse input
 */
#pragma once

#include "jac/type_defs.hpp"

#include "utils/defs.hpp"

namespace Events
{

ECS_COMPONENT
struct MouseMoveInput
{
    float x;
    float y;

    float dx;
    float dy;
};

ECS_COMPONENT
struct MouseButtonInput
{
    enum struct Action : uint8
    {
        Press,
        Release
    };

    enum struct Button : uint8
    {
        Left,
        Right,
        Middle,
        Button4,
        Button5,
        Button6,
        Button7,
        Button8
    };

    Button button;
    Action action;
};

ECS_COMPONENT
struct MouseScrollInput
{
    float x;
    float y;
};

} // namespace Events
