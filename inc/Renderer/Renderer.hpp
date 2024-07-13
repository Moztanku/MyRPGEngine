/**
 * @file Renderer.hpp
 * @author Moztanku (mostankpl@gmail.com)
 */
#pragma once

#include <glad/gl.h>

#include "jac/print.hpp"

#include "Renderer/Window.hpp"

#include "Renderer/GPU/Shader.hpp"
#include "Renderer/GPU/Texture.hpp"
#include "Renderer/GPU/VertexArray.hpp"
#include "Renderer/GPU/VertexBuffer.hpp"
#include "Renderer/GPU/IndexBuffer.hpp"
#include "Renderer/GPU/VertexBufferLayout.hpp"

namespace Renderer
{

class Renderer
{
    public:
        /**
         * @brief Construct a new Renderer object
         * @param window Reference to the window object, used to get the window context, it can be kept as a reference
         *      since the window context should always outlive the renderer.
         */
        Renderer(Window& window) : m_Window(window)
        {
            if (!gladLoaderLoadGL())
            {
                jac::print_error("Failed to load OpenGL functions");
                std::exit(EXIT_FAILURE);
            }

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            m_Shader = new GPU::Shader(
                "res/shaders/sample_shader.vert",
                "res/shaders/sample_shader.frag");

            m_Texture = new GPU::Texture("res/tilesets/32x32.png");
        }

        ~Renderer()
        {
            delete m_Shader;
        }

        /**
         * @brief Updates the renderer, should be called once per frame to process events such as scene change.
         * @param delta_ms Time passed since the last frame in milliseconds.
         */
        auto update(double /* delta_s */) -> void
        {
            // TODO: Implement
        }

        /**
         * @brief Renders the scene to the window. Should be called once per frame and before the window is updated.
         */
        auto render() -> void
        {
            // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            // glClear(GL_COLOR_BUFFER_BIT);

            

            // TODO: Implement
        }
    private:
        [[maybe_unused]]
        Window& m_Window;

        // Remove later
        GPU::Shader* m_Shader;
        GPU::Texture* m_Texture;
};

} // namespace Renderer