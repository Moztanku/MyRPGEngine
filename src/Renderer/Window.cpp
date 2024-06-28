#include "Renderer/Window.hpp"

#include "jac/print.hpp"

#include "utils/defaults.hpp"

namespace
{

auto init_glfw() -> bool
{
    using def = utils::defaults;

    if (!glfwInit())
    {
        int ec = glfwGetError(nullptr);

        jac::print_error(
            jac::make_message("Failed to initialize GLFW, error code: ", ec)
        );

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

    glfwWindowHint(
        GLFW_OPENGL_PROFILE,
        def::opengl_profile == 0 ? GLFW_OPENGL_CORE_PROFILE :
        def::opengl_profile == 1 ? GLFW_OPENGL_COMPAT_PROFILE :
            GLFW_OPENGL_ANY_PROFILE
    );

    return true;
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

        jac::print_error(
            jac::make_message("Failed to create window, error code: ", ec)
        );

        return;
    }

    glfwMakeContextCurrent(m_Window.get());
    glfwSetFramebufferSizeCallback(m_Window.get(), [](GLFWwindow* /* window */, int width, int height)
    {
        glViewport(0, 0, width, height);
    });
}

} // namespace Renderer