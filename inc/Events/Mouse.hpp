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
struct MouseButtonInput
{
    enum struct Action : uint8
    {
        Release = 0u,
        Press
    };

    enum struct Button : uint8
    {
        Left = 0u,
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
struct MouseMoveInput
{
    double x;
    double y;

    double dx;
    double dy;
};

ECS_COMPONENT
struct MouseScrollInput
{
    double x;
    double y;
};

} // namespace Events
