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
    namespace handlers = Events::GLFWEventHandlers;

    glfwSetFramebufferSizeCallback(window, handlers::framebuffer_size_callback);

    glfwSetKeyCallback(window, handlers::key_callback);

    glfwSetMouseButtonCallback(window, handlers::mouse_button_callback);
    glfwSetCursorPosCallback(window, handlers::cursor_pos_callback);
}

} // namespace

namespace Renderer
{

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
}

} // namespace Renderer