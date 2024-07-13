/**
 * @file GLFWEventHandlers.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains basic event handlers for GLFS window events like key presses, mouse movement, etc.
 *      These handlers are used to capture and send events into ECS to be processed by appropiate systems.
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
    constexpr GLFWerrorfun error_callback = [](
        int error,
        const char* description
    ){
        jac::print_error({
            error, "GLFW error:", description});
    };

    // monitor configuration change
    constexpr GLFWmonitorfun monitor_callback = nullptr;

    //// WINDOW EVENTS ////

    // window position change
    constexpr GLFWwindowposfun window_pos_callback = nullptr;

    //// Unsupported in Wayland
    // constexpr GLFWwindowposfun window_pos_callback = [](
    //     GLFWwindow* /* window */,
    //     int xpos,
    //     int ypos
    // ){
    // };

    // window size change
    constexpr GLFWwindowsizefun window_size_callback = [](
        GLFWwindow* /* window */,
        int width,
        int height
    ){
        WindowSizeEvent event = {
            .width = static_cast<uint32>(width),
            .height = static_cast<uint32>(height)
        };

        EventRegistry::CreateUniqueEvent(
            std::move(event));
    };

    // window close request
    constexpr GLFWwindowclosefun window_close_callback = [](
        GLFWwindow* /* window */
    ){
        WindowEvent event = {
            .action = WindowEvent::Action::Close
        };

        EventRegistry::CreateEvent(
            std::move(event));
    };

    // window content needs to be redrawn
    constexpr GLFWwindowrefreshfun window_refresh_callback = [](
        GLFWwindow* /* window */
    ){
        WindowEvent event = {
            .action = WindowEvent::Action::Refresh
        };

        EventRegistry::CreateEvent(
            std::move(event));
    };

    // window gains or loses focus
    constexpr GLFWwindowfocusfun window_focus_callback = [](
        GLFWwindow* /* window */,
        int focused
    ){
        WindowEvent event = {
            .action = focused ? WindowEvent::Action::Focus
                              : WindowEvent::Action::LostFocus
        };

        EventRegistry::CreateEvent(
            std::move(event));
    };

    // window is iconified or restored
    constexpr GLFWwindowiconifyfun window_iconify_callback = nullptr;

    //// Not working properly
    // constexpr GLFWwindowiconifyfun window_iconify_callback = [](
    //     GLFWwindow* /* window */,
    //     int iconified
    // ){
    //     WindowEvent event = {
    //         .action = iconified ? WindowEvent::Action::Minimize
    //                             : WindowEvent::Action::Restore
    //     };

    //     jac::print_info({
    //         "Window iconified: ", iconified});

    //     EventRegistry::CreateEvent(
    //         std::move(event));
    // };

    // window is maximized or restored
    constexpr GLFWwindowmaximizefun window_maximize_callback = [](
        GLFWwindow* /* window */,
        int maximized
    ){
        WindowEvent event = {
            .action = maximized ? WindowEvent::Action::Maximize
                                : WindowEvent::Action::Restore
        };

        EventRegistry::CreateEvent(
            std::move(event));
    };

    // window content scale change
    constexpr GLFWwindowcontentscalefun window_content_scale_callback = nullptr;

    // framebuffer size change
    constexpr GLFWframebuffersizefun framebuffer_size_callback = [](
        GLFWwindow* /* window */,
        int width,
        int height
    ){
        FramebufferSizeEvent event = {
            .width = static_cast<uint32>(width),
            .height = static_cast<uint32>(height)
        };

        EventRegistry::CreateUniqueEvent(
            std::move(event));
    };

    //// KEYBOARD INPUT ////

    // key input
    constexpr GLFWkeyfun key_callback = [](
        GLFWwindow* /* window */,
        int key,
        int scancode,
        int action,
        int mods
    ){
        KeyboardEvent event = {
            .key = key,
            .scancode = scancode,
            .action = static_cast<KeyboardEvent::Action>(action),
            .mods = static_cast<uint8>(mods)
        };

        EventRegistry::CreateEvent(
            std::move(event));
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
        MouseButtonEvent event = {
            .button = static_cast<MouseButtonEvent::Button>(button),
            .action = static_cast<MouseButtonEvent::Action>(action)
        };

        EventRegistry::CreateEvent(
            std::move(event));
    };
    
    // cursor position change
    constexpr GLFWcursorposfun cursor_pos_callback = [](
        GLFWwindow* /* window */,
        double xpos,
        double ypos
    ){
        static double last_xpos = xpos;
        static double last_ypos = ypos;

        MouseMoveEvent event = {
            .x = xpos,
            .y = ypos,
            .dx = xpos - last_xpos,
            .dy = ypos - last_ypos
        };

        last_xpos = xpos;
        last_ypos = ypos;

        EventRegistry::CreateUniqueEvent(
            std::move(event));
    };
    
    // cursor enters or leaves window
    constexpr GLFWcursorenterfun cursor_enter_callback = [](
        GLFWwindow* /* window */,
        int entered
    ){
        WindowEvent event = {
            .action = entered ? WindowEvent::Action::MouseEnter
                              : WindowEvent::Action::MouseLeave
        };

        EventRegistry::CreateEvent(
            std::move(event));
    };

    // scroll input
    constexpr GLFWscrollfun scroll_callback = [](
        GLFWwindow* /* window */,
        double xoffset,
        double yoffset
    ){
        MouseScrollEvent event = {
            .x = xoffset,
            .y = yoffset
        };

        EventRegistry::CreateUniqueEvent(
            std::move(event));
    };

    // file drop input
    constexpr GLFWdropfun drop_callback = nullptr;

    //// JOYSTICK INPUT ////

    // joystick connection/disconnection
    constexpr GLFWjoystickfun joystick_callback = nullptr;

} // namespace GLFWEventHandlers

} // namespace Events
