/**
 * @file Event.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains base event component
 */
#pragma once

#include "utils/defs.hpp"

namespace Events {

ECS_COMPONENT
struct Event
{
    bool handled{false};
};

} // namespace Events
