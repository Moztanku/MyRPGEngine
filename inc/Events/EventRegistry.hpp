/**
 * @file EventRegistry.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains class that manages all events and their components, it is an abstraction for the entt registry.
 *      Events are created with set components and only those components can be accessed outside of the class.
 */
#pragma once

#include <type_traits>

#include <entt/entt.hpp>

#include "jac/print.hpp"

#include "Events/Event.hpp"
#include "utils/helper.hpp"

namespace Events
{

class EventRegistry
{
    public:
        /**
         * @brief Create an event with the given components.
         * @param components Components to be added to the event.
         */
        template<typename... Components>
        static auto CreateEvent(Components&&... components) -> void
        {
            if constexpr (std::disjunction_v<std::is_same<Events::Event, Components>...>)
                jac::print_error("Event component should not be passed to CreateEvent() function manually!");

            entt::entity event = m_registry.create();

            m_registry.emplace<Events::Event>(event);

            (m_registry.emplace<Components>(event, std::forward<Components>(components)), ...);
        }

        /**
         * @brief Create a unique event with the given components. If an event with the given components already exists, it will replace the components with the new ones.
         *      @note If multiple events with the given components exist, only the first one will be replaced.
         * @param components Components to be added to the event.
         */
        template<typename... Components>
        static auto CreateUniqueEvent(Components&&... components) -> void
        {
            if constexpr (std::disjunction_v<std::is_same<Events::Event, Components>...>)
                jac::print_error("Event component should not be passed to CreateUniqueEvent() function manually!");

            entt::entity event = m_registry.view<Events::Event, Components...>().front();

            if (event == entt::null)
                CreateEvent(std::forward<Components>(components)...);
            else
                (m_registry.replace<Components>(event, std::forward<Components>(components)), ...);
        }

        /**
         * @brief Get all events with the given components. Result is a iterator over std::tuple<Components...>.
         * @tparam Components Components to be accessed.
         * @return An iterator over std::tuple<Components...>. @see utils/helper.hpp
         */
        template<typename... Components>
        static auto GetEvents()
        {
            if constexpr (std::disjunction_v<std::is_same<Events::Event, Components>...>)
                jac::print_error("Event component should not be passed to GetEvents() function manually!");

            auto view = m_registry.view<Events::Event, Components...>();

            return utils::custom_iterable_adaptor{view.each()};
        }
    
        /**
         * @brief Clean up all events that have been handled.
         */
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
