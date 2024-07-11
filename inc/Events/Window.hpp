/**
 * @file Window.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains components related to window events e.g. resizing, closing, lost focus etc.
 */
#pragma once

#include "jac/type_defs.hpp"

#include "utils/defs.hpp"

namespace Events
{

ECS_COMPONENT
struct WindowEvent
{
    enum struct Action : uint8
    {
        Close = 0u,
        Refresh,
        
        Focus,
        LostFocus,

        // Minimize,
        Maximize,
        Restore,

        MouseEnter,
        MouseLeave
    };

    Action action;
};

ECS_COMPONENT
struct WindowSizeEvent
{
    uint32 width;
    uint32 height;
};

ECS_COMPONENT
struct FramebufferSizeEvent
{
    uint32 width;
    uint32 height;
};

} // namespace Events
