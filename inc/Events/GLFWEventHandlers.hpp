/**
 * @file GLFWEventHandlers.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains basic event handlers for GLFS window events like key presses, mouse movement, etc.
 * These handlers are used to capture and send events into ECS to be processed by appropiate systems.
 */
#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Events/EventRegistry.hpp"
#include "Events/Keyboard.hpp"
#include "Events/Mouse.hpp"
#include "Events/Controller.hpp"
#include "Events/Window.hpp"

namespace Events
{

namespace GLFWEventHandlers
{

    //// GENERAL EVENTS ////

    // called when an error occurs
    constexpr GLFWerrorfun error_callback = nullptr;

    // monitor configuration change
    constexpr GLFWmonitorfun monitor_callback = nullptr;

    //// WINDOW EVENTS ////

    // window position change
    constexpr GLFWwindowposfun window_pos_callback = nullptr;

    // window size change
    constexpr GLFWwindowsizefun window_size_callback = nullptr;

    // window close request
    constexpr GLFWwindowclosefun window_close_callback = nullptr;

    // window content needs to be redrawn
    constexpr GLFWwindowrefreshfun window_refresh_callback = nullptr;

    // window gains or loses focus
    constexpr GLFWwindowfocusfun window_focus_callback = nullptr;

    // window is iconified or restored
    constexpr GLFWwindowiconifyfun window_iconify_callback = nullptr;

    // window is maximized or restored
    constexpr GLFWwindowmaximizefun window_maximize_callback = nullptr;

    // framebuffer size change
    constexpr GLFWframebuffersizefun framebuffer_size_callback = [](
        GLFWwindow* /* window */,
        int width,
        int height
    ){
        jac::print_info({
                "Framebuffer size changed to:", width, "x", height});
        
        // glViewport(0, 0, width, height); // TODO: Need to call this in the renderer with existing OpengL context
    };

    // window content scale change
    constexpr GLFWwindowcontentscalefun window_content_scale_callback = nullptr;

    //// KEYBOARD INPUT ////

    // key input
    constexpr GLFWkeyfun key_callback = [](
        GLFWwindow* /* window */,
        int key,
        int scancode,
        int action,
        int mods
    ){
        KeyboardInput input = {
            .key = key,
            .scancode = scancode,
            .action = static_cast<KeyboardInput::Action>(action),
            .mods = static_cast<uint>(mods)
        };

        EventRegistry::CreateEvent(
            std::move(input));
    };

    // Unicode character input (layout dependent as opposed to key input)
    constexpr GLFWcharfun char_callback = nullptr;

    // Unicode character with modifiers input
    constexpr GLFWcharmodsfun char_mods_callback = nullptr;

    //// MOUSE INPUT ////

    // mouse button input
    constexpr GLFWmousebuttonfun mouse_button_callback = [](
        GLFWwindow* /* window */,
        int button,
        int action,
        int /* mods */
    ){
        MouseButtonInput input = {
            .button = static_cast<MouseButtonInput::Button>(button),
            .action = static_cast<MouseButtonInput::Action>(action)
        };

        EventRegistry::CreateEvent(
            std::move(input));
    };
    
    // cursor position change
    constexpr GLFWcursorposfun cursor_pos_callback = [](
        GLFWwindow* /* window */,
        double xpos,
        double ypos
    ){
        static double last_xpos = xpos;
        static double last_ypos = ypos;

        MouseMoveInput input = {
            .x = xpos,
            .y = ypos,
            .dx = xpos - last_xpos,
            .dy = ypos - last_ypos
        };

        last_xpos = xpos;
        last_ypos = ypos;

        EventRegistry::CreateEvent(
            std::move(input));
    };
    
    // cursor enters or leaves window
    constexpr GLFWcursorenterfun cursor_enter_callback = nullptr;

    // scroll input
    constexpr GLFWscrollfun scroll_callback = [](
        GLFWwindow* /* window */,
        double xoffset,
        double yoffset
    ){
        MouseScrollInput input = {
            .x = xoffset,
            .y = yoffset
        };

        EventRegistry::CreateEvent(
            std::move(input));
    };

    // file drop input
    constexpr GLFWdropfun drop_callback = nullptr;

    //// JOYSTICK INPUT ////

    // joystick connection/disconnection
    constexpr GLFWjoystickfun joystick_callback = nullptr;

} // namespace GLFWEventHandlers

} // namespace Events
