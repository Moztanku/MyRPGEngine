/**
 * @file EventRegistry.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains class that manages all events and their components, it is an abstraction for the entt registry.
 * Events are created with set components and only those components can be accessed outside of the class.
 */
#pragma once

#include <type_traits>

#include <entt/entt.hpp>

#include "jac/print.hpp"

#include "Events/Event.hpp"

namespace Events
{

class EventRegistry
{
    public:
        template<typename... Components>
        static auto CreateEvent(Components&&... components) -> void
        {
            if constexpr (std::disjunction_v<std::is_same<Events::Event, Components>...>)
                jac::print_error("Event component should not be passed to CreateEvent() function manually!");

            entt::entity event = m_registry.create();

            m_registry.emplace<Events::Event>(event);

            (m_registry.emplace<Components>(event, std::forward<Components>(components)), ...);
        }

        // TODO: Change this so that it doesn't return view at entities, but rather only the components.
        //       This way we can't modify the entities, only its components and this functions interface
        //       will be clearer.
        template<typename... Components>
        static auto GetEvents()
        {
            if constexpr (std::disjunction_v<std::is_same<Events::Event, Components>...>)
                jac::print_error("Event component should not be passed to GetEvents() function manually!");

            return m_registry.view<Events::Event, Components...>();
        }
    
        static auto CleanUp() -> void
        {
            auto view = m_registry.view<Events::Event>();

            view.each([&](entt::entity entity, Events::Event& event){
                if (event.handled)
                    m_registry.destroy(entity);
            });
        }

    private:
        static inline entt::registry m_registry{};
}; // class EventRegistry

} // namespace Events
