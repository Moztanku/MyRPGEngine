#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <entt/entity/registry.hpp>

#include "jac/main.hpp"
#include "jac/print.hpp"

#include "Renderer/Window.hpp"
#include "Events/EventRegistry.hpp"

struct Component
{
    static auto on_construct(entt::registry& /* registry */, entt::entity entity) -> void
    {
        jac::print_info({"Entity created: ", static_cast<int>(entity)});
    }
};

auto run(jac::Arguments& /* arg */, jac::Arguments& /* env */) -> int
{

    // entt::registry registry{};
    // registry.on_construct<Component>().connect<&Component::on_construct>();

    // auto entity = registry.create();
    // registry.emplace<Component>(entity);

    // registry.create<Component>();
    // /*
    //     START:

    //         Create a window & Initialize everything

    //         LOOP:
    //             Poll input from window
    //             Process input into events

    //             for event in events:
    //                 bool handled = handle_event(event)
    //                 if handled:
    //                     remove event from events

    //             for system in systems:
    //                 system.update()

    //             renderer.render()   // Parallelize this

    //         Cleanup
    // */

    Renderer::Window window{};
    // // Renderer::Renderer renderer{window};

    while (window.isAlive())
    {
        // for (auto& event : Events::getEvents())
        // {
        //     bool handled = handle_event(event);
        //     if (handled)
        //         Events::removeEvent(event);
        // }

        // for (auto& system : Systems::getSystems())
        // {
        //     system.update();
        // }

        // renderer.render();
        
        Events::EventRegistry::CleanUp();
        window.update();
    }

    // // entt::dispatcher dispatcher{};

    // // dispatcher.sink<Event>().connect<&generic_event_handler>();
    // // dispatcher.sink<Event>().connect<&EventHandler::on>(EventHandler{});
    // // dispatcher.sink<Event>().connect<&handleEvent>();

    // // dispatcher.trigger(
    // //     Event{{1.0f, 2.0f}, {3.0f, 4.0f}}
    // // );

    // // dispatcher.enqueue<Event>(
    // //     Event{{1.0f, 2.0f}, {3.0f, 4.0f}}
    // // );

    // // dispatcher.update();

    return 0;
}
