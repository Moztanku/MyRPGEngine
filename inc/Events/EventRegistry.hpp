/**
 * @file EventRegistry.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains class that manages all events and their components, it is
 * an abstraction for the entt registry.
 */
#pragma once

#include <entt/entt.hpp>

namespace Events
{

class EventRegistry
{
    public:
    private:
        static entt::registry m_registry;
}; // class EventRegistry

entt::registry EventRegistry::m_registry{};

} // namespace Events
