cmake_minimum_required (VERSION 3.0)
project (GraphicsAPI)

set(GA_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

set(GRAPHICSUSEGL true CACHE BOOL "Uses OpenGL if set true, otherwise uses Vulkan")

if(GRAPHICSUSEGL)
add_definitions(-DGA_GL)
else()
add_definitions(-DGA_VULKAN)
endif()

add_subdirectory (core)
add_subdirectory (shapes)
add_subdirectory (window)
add_subdirectory (tests)