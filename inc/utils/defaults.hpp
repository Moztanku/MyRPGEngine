/**
 * @file defaults.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains default settings for the project
 */
#pragma once

#include <string>

namespace utils
{

namespace defaults
{
    // OpenGL settings
    constexpr int opengl_major_version = 4;
    constexpr int opengl_minor_version = 6;
    constexpr int opengl_profile = 0; // 0 = core, 1 = compatibility, 2 = any

    // Window settings
    constexpr uint window_width = 1080;
    constexpr uint window_height = 720;
    constexpr std::string window_title = "Engine Demo";
};

} // namespace utils
