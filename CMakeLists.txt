cmake_minimum_required(VERSION 3.29)

project(MyRPGEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")

## Directories

set(VENDOR_DIR ${CMAKE_SOURCE_DIR}/vendor)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/inc)

## External dependencies
# - GLAD
# - STB_image
# - JacekLib

add_subdirectory(${VENDOR_DIR})

## OpenGL libraries

set(OpenGL_Packages
    OpenGL
    glfw3
    glm)

foreach(package ${OpenGL_Packages})
    find_package(${package} REQUIRED)

    if (NOT ${package}_FOUND)
        message(FATAL_ERROR "Package ${package} not found")
    endif()
endforeach()

## Sources

file(GLOB_RECURSE SOURCES ${SRC_DIR}/**.cpp)

## Engine

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE
    GL glfw JacekLib GLAD STB_image)