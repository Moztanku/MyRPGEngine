#include "Renderer/Window.hpp"

#include "jac/print.hpp"

#include "utils/defaults.hpp"
#include "Events/GLFWEventHandlers.hpp"

namespace
{

auto init_glfw() -> bool
{
    namespace def = utils::defaults;

    if (!glfwInit())
    {
        int ec = glfwGetError(nullptr);

        jac::print_error({
            "Failed to initialize GLFW, error code:", ec});

        return false;
    }

    glfwWindowHint(
        GLFW_CONTEXT_VERSION_MAJOR,
        def::opengl_major_version
    );

    glfwWindowHint(
        GLFW_CONTEXT_VERSION_MINOR,
        def::opengl_minor_version
    );

    #ifdef __APPLE__
    glfwWindowHint(
        GLFW_OPENGL_FORWARD_COMPAT,
        GL_TRUE
    );
    #endif

    glfwWindowHint(
        GLFW_OPENGL_PROFILE,
        def::opengl_profile == 0 ? GLFW_OPENGL_CORE_PROFILE :
        def::opengl_profile == 1 ? GLFW_OPENGL_COMPAT_PROFILE :
            GLFW_OPENGL_ANY_PROFILE
    );

    return true;
}

auto set_event_callbacks(GLFWwindow* window) -> void
{
    using namespace Events::GLFWEventHandlers;

    glfwSetErrorCallback    (error_callback);
    glfwSetMonitorCallback  (monitor_callback);

    glfwSetWindowPosCallback            (window, window_pos_callback);
    glfwSetWindowSizeCallback           (window, window_size_callback);
    glfwSetWindowCloseCallback          (window, window_close_callback);
    glfwSetWindowRefreshCallback        (window, window_refresh_callback);
    glfwSetWindowFocusCallback          (window, window_focus_callback);
    glfwSetWindowIconifyCallback        (window, window_iconify_callback);
    glfwSetWindowMaximizeCallback       (window, window_maximize_callback);
    glfwSetWindowContentScaleCallback   (window, window_content_scale_callback);
    glfwSetFramebufferSizeCallback      (window, framebuffer_size_callback);

    glfwSetKeyCallback          (window, key_callback);
    glfwSetCharCallback         (window, char_callback);
    glfwSetCharModsCallback     (window, char_mods_callback);
    glfwSetMouseButtonCallback  (window, mouse_button_callback);
    glfwSetCursorPosCallback    (window, cursor_pos_callback);
    glfwSetCursorEnterCallback  (window, cursor_enter_callback);
    glfwSetScrollCallback       (window, scroll_callback);
    glfwSetDropCallback         (window, drop_callback);
    glfwSetJoystickCallback     (joystick_callback);
}

} // namespace

namespace Renderer
{

Window::Window() : Window(Settings{})
{
}

Window::Window(const Settings& settings)
{
    if (init_glfw() == false)
        return;

    m_Window.reset(
        glfwCreateWindow(
            settings.width,
            settings.height,
            settings.title.c_str(),
            nullptr,
            nullptr
        ));

    if (m_Window == nullptr)
    {
        int ec = glfwGetError(nullptr);

        jac::print_error({
            "Failed to create window, error code:", ec});

        return;
    }

    glfwMakeContextCurrent(m_Window.get());
    set_event_callbacks(m_Window.get());

    m_alive = true;
}

auto Window::update() -> void
{
    if (m_alive == false)
        return;

    glfwSwapBuffers(m_Window.get());
    glfwPollEvents();

    handleWindowEvents();
}

auto Window::isAlive() const -> bool
{
    return m_alive;
}

auto Window::handleWindowEvents() -> void
{
    using Events::EventRegistry;
    using Events::WindowEvent;
    using Events::WindowSizeEvent;
    using Events::FramebufferSizeEvent;
    using Action = Events::WindowEvent::Action;

    for (auto [event, window] : EventRegistry::GetEvents<WindowEvent>())
    {
        switch (window.action){
            case Action::Close:
                m_alive = false;
                break;
            case Action::Refresh:
            case Action::Focus:
            case Action::LostFocus:
            case Action::Maximize:
            // case Action::Minimize:
            case Action::Restore:
            case Action::MouseEnter:
            case Action::MouseLeave:
            default:
                break;
        }
        
        event.handled = true;
    }

    for (auto [event, size] : EventRegistry::GetEvents<WindowSizeEvent>())
    {
        event.handled = true;
    }

    for (auto [event, size] : EventRegistry::GetEvents<FramebufferSizeEvent>())
    {
        event.handled = true;
    }

    for (auto [event, key] : EventRegistry::GetEvents<Events::KeyboardEvent>())
    {
        if (key.key == GLFW_KEY_ESCAPE && key.action == Events::KeyboardEvent::Action::Press)
        {
            m_alive = false;
            event.handled = true;
        }
    }
}

} // namespace Renderer
