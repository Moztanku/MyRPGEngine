/**
 * @file Window.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief Window class used to... create a window, duh
 */
#pragma once

#include <string>
#include <memory>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "jac/type_defs.hpp"

#include "utils/defaults.hpp"

namespace Renderer
{

class Window
{
    public:
        struct Settings
        {
            uint width{utils::defaults::window_width};
            uint height{utils::defaults::window_height};
            std::string title{utils::defaults::window_title};
        };

        Window();
        Window(const Settings& settings);
        ~Window() = default;

        Window(const Window&) = delete;
        Window(Window&&) = delete;
        auto operator=(const Window&) -> Window& = delete;
        auto operator=(Window&&) -> Window& = delete;

        // Just for testing, remove later
        auto getWindow() -> GLFWwindow& { return *m_Window; }
    private:
        unique_ptr<
            GLFWwindow,
            decltype(&glfwDestroyWindow)
        > m_Window = {nullptr, glfwDestroyWindow};
};

} // namespace Renderer