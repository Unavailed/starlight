cmake_minimum_required(VERSION 3.5.0)
project(starlight VERSION 0.1.0 LANGUAGES C)

set(glfw3_ROOT "${CMAKE_SOURCE_DIR}/vendor/GLFW")

include_directories(".")

if (WIN32)
    set(GLFW_LIB_DIR "${GLFW_ROOT}/lib-win32")
    set(GLFW_LIB_NAME "glfw3.lib")
elseif (UNIX)
    set(GLFW_LIB_DIR "${GLFW_ROOT}/lib-unix")
    set(GLFW_LIB_NAME "libglfw3.a")
endif()

link_directories("${GLFW_LIB_DIR}")
add_library(glfw3 STATIC IMPORTED)
set_target_properties(glfw3 PROPERTIES IMPORTED_LOCATION "${GLFW_LIB_DIR}/${GLFW_LIB_NAME}")

add_library(starlight src/core/core.c src/core/window.c)

target_link_libraries(starlight glfw3)

target_compile_definitions(starlight PRIVATE STARLIGHT_STATIC)

set_target_properties(starlight PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/win32"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/win32"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/win32"
)