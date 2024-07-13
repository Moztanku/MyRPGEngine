#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <entt/entity/registry.hpp>

#include "jac/main.hpp"
#include "jac/print.hpp"

#include "Renderer/Window.hpp"
#include "Renderer/Renderer.hpp"
#include "Events/EventRegistry.hpp"

/**
 * @brief Get the delta time between frames
 * @return double Time passed since the last frame in seconds
 */
inline auto get_delta_time() -> double
{
    static double last_frame = glfwGetTime();

    const double current_frame = glfwGetTime();
    const double delta_time = current_frame - last_frame;
    last_frame = current_frame;

    return delta_time;
}

/**
 * @brief Starting point of the engine, this function is called by the main function defined in jac/main.hpp
 * @param arg Command line arguments that can be accessed via arg["arg_name"]
 * @param env Environment variables that can be accessed via env["env_name"]
 */
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
    Renderer::Renderer renderer{window};

    while (window.isAlive())
    {
        const double delta_s = get_delta_time();

        // for (auto& system : Systems::getSystems())
        // {
        //     system.update();
        // }

        renderer.update(delta_s);
        renderer.render();
        
        window.update();
        Events::EventRegistry::CleanUp();
    }

    return 0;
}
