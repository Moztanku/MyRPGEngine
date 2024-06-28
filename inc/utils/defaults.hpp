/**
 * @file defaults.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains default settings for the project
 */
#pragma once

#include <string>

namespace utils
{

struct defaults
{
    // OpenGL settings
    static constexpr int opengl_major_version = 4;
    static constexpr int opengl_minor_version = 6;
    static constexpr int opengl_profile = 0; // 0 = core, 1 = compatibility, 2 = any

    // Window settings
    static constexpr uint window_width = 1080;
    static constexpr uint window_height = 720;
    static constexpr std::string window_title = "Engine Demo";
};

} // namespace utils