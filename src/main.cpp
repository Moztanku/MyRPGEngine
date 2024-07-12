#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <entt/entity/registry.hpp>

#include "jac/main.hpp"
#include "jac/print.hpp"

#include "Renderer/Window.hpp"
#include "Events/EventRegistry.hpp"

auto run(jac::Arguments& /* arg */, jac::Arguments& /* env */) -> int
{
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
    // Renderer::Renderer renderer{window};

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

    return 0;
}
