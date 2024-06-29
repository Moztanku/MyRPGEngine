#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "jac/main.hpp"
#include "jac/print.hpp"

#include "entt/entity/registry.hpp"

#include "Renderer/Window.hpp"


auto run(jac::Arguments& /* arg */, jac::Arguments& /* env */) -> int
{
    Renderer::Window window({ 800, 600, "Hello, World!" });

    GLFWwindow& window_handle = window.getWindow();
    
    while (true)
    {
       glfwPollEvents();

        if (glfwWindowShouldClose(&window_handle))
        {
            break;
        }

        glfwSwapBuffers(&window_handle);
    };

    return 0;
}