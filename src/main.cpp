#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <entt/entity/registry.hpp>

#include "jac/main.hpp"
#include "jac/print.hpp"

#include "Renderer/Window.hpp"

#include <entt/entt.hpp>
#include <atomic>

// struct Event
// {
//     glm::vec2 position;
//     glm::vec2 velocity;

//     Event& operator=(const Event& other){
//         position = other.position;
//         velocity = other.velocity;

//         handled = other.handled.load();

//         return *this;
//     };

//     std::atomic<bool> handled = {false};
// };

// void handleEvent(Event& event)
// {
//     if (event.handled.load())
//         return;
//     else
//         event.handled.store(true);

//     jac::print_info(
//         jac::make_message(
//             "Event received at: (", event.position.x, ", ", event.position.y, ")"));
// }

// struct EventHandler
// {
//     void on(Event& event)
//     {
//         jac::print_info(
//             jac::make_message(
//                 "Event received at: (", event.position.x, ", ", event.position.y, ")"));
//     }
// };

struct Event
{
    virtual auto to_string() const -> std::string = 0;

    virtual ~Event() = default;
};

struct InputEvent : public Event
{
    auto to_string() const -> std::string override
    {
        return "InputEvent";
    }
};

struct SystemEvent : public Event
{
    auto to_string() const -> std::string override
    {
        return "SystemEvent";
    }
};

struct CoreEvent : public Event
{
    auto to_string() const -> std::string override
    {
        return "CoreEvent";
    }
};

auto generic_event_handler(const Event& event) -> void
{
    jac::print_info(event.to_string());
}

auto run(jac::Arguments& /* arg */, jac::Arguments& /* env */) -> int
{
    /*
        START:

            Create a window & Initialize everything

            LOOP:
                Poll input from window
                Process input into events

                for event in events:
                    bool handled = handle_event(event)
                    if handled:
                        remove event from events

                for system in systems:
                    system.update()

                renderer.render()   // Parallelize this

            Cleanup
    */

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
        window.update();
    }

    // entt::dispatcher dispatcher{};

    // dispatcher.sink<Event>().connect<&generic_event_handler>();
    // dispatcher.sink<Event>().connect<&EventHandler::on>(EventHandler{});
    // dispatcher.sink<Event>().connect<&handleEvent>();

    // dispatcher.trigger(
    //     Event{{1.0f, 2.0f}, {3.0f, 4.0f}}
    // );

    // dispatcher.enqueue<Event>(
    //     Event{{1.0f, 2.0f}, {3.0f, 4.0f}}
    // );

    // dispatcher.update();

    return 0;
}