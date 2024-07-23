cmake_minimum_required(VERSION 3.5.0)
project(starlight VERSION 0.1.0 LANGUAGES C)

set(GLFW_ROOT "${CMAKE_SOURCE_DIR}/vendor/GLFW")

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

# DLL
add_library( starlight_dll SHARED src/core.c src/window.c src/framebuffer.c src/device.c )
target_link_libraries(starlight_dll glfw3)
target_compile_definitions(starlight_dll PRIVATE STARLIGHT_BUILD)

# STATIC
add_library( starlight_static STATIC src/core.c src/window.c src/framebuffer.c src/device.c )
target_link_libraries(starlight_static glfw3)
target_compile_definitions(starlight_static PRIVATE STARLIGHT_STATIC)

# EXAMPLES
# add_executable( starlight_example examples/making_a_window.c )
add_executable( starlight_example examples/device.c )
target_link_libraries(starlight_example starlight_static)
target_link_libraries(starlight_example glfw3)
target_compile_definitions(starlight_example PRIVATE STARLIGHT_BUILD)

if (WIN32)
    set_target_properties(starlight_dll PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/win32"
    )
    set_target_properties(starlight_static PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/win32"
    )

    set_target_properties(starlight_example PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/win32/examples"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/win32/examples"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/win32/examples"
    )
elseif (UNIX)
    set_target_properties(starlight_dll PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/linux"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/linux"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/linux"
    )
endif()