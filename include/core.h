#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
    #define GLFW_EXPOSE_NATIVE_WIN32
    #include "vendor/GLFW/glfw3.h"
    #include "vendor/GLFW/glfw3native.h"
    #define SL_USE_WINDOWS
    #define SL_APIENTRY __stdcall
    #if defined(STARLIGHT_BUILD)
        #define SL_API __declspec(dllexport)
    #elif defined(STARLIGHT_STATIC)
        #define SL_API
    #else
        #define SL_API __declspec(dllimport)
    #endif
#elif defined(__linux__)
    #if defined(__WAYLAND__)
        #define GLFW_EXPOSE_NATIVE_WAYLAND
        #include "vendor/GLFW/glfw3.h"
        #include "vendor/GLFW/glfw3native.h"
    #elif defined(__X11__)
        #define GLFW_EXPOSE_NATIVE_X11
        #include "vendor/GLFW/glfw3.h"
        #include "vendor/GLFW/glfw3native.h"
    #endif 
    #define SL_USE_LINUX
    #define SL_APIENTRY
    #define SL_API __attribute__((visibility("default")))
#elif defined(__APPLE__)
    #define GLFW_EXPOSE_NATIVE_COCOA
    #include "vendor/GLFW/glfw3.h"
    #include "vendor/GLFW/glfw3native.h"
    #define SL_USE_APPLE
    #define SL_APIENTRY
    #define SL_API __attribute__((visibility("default")))
#else
    #define SL_USE_NULL
    #define SL_APIENTRY
    #define SL_API
#endif

static int SL_INIT = 0;

typedef enum {
    SL_SUCCESS = 0,
    SL_ERROR_INIT = -1,
    SL_ERROR_NOT_INIT = -1,
    SL_ERROR_WINDOW = -1,
    SL_ERROR_CONTEXT = -1,
    SL_ERROR_DEVICE = -1,
    SL_ERROR_INPUT = -1,
    SL_ERROR_RENDER = -1,
    SL_ERROR_OUT_OF_MEMORY = -1,
    SL_ERROR_INVALID_ARGUMENT = -1,
    SL_ERROR_UNKNOWN = -2
} SL_STATUS;

#define SL_CONFIG_WINDOW 0x1 // WINDOW CONFIG

typedef struct {
    int         sConfigType;
    
    // Application Information
    const char* pApplicationName;
    int         pApplicationVersion;

    // Engine Information
    const char* pEngineName;
    int         pEngineVersion;

    // Window Information
    const char* pWindowTitle;
    int         pWindowWidth;
    int         pWindowHeight;
    GLFWmonitor* pWindowMonitor;

    // Device Information
    int         pDeviceCount;
    const char* pDeviceName;
    int         pDeviceType;

    // Input Information
    int         pInputCount;
    const char* pInputName;

} SL_CONFIG;

/**
 * Initialize the Starlight library.
 * @return A status code (SL_STATUS) indicating success or failure.
 */
SL_STATUS SL_API SL_APIENTRY slInit(void);

/**
 * Terminates the Starlight library
 * @return A status code (SL_STATUS) indicating success or failure.
 */
void SL_API SL_APIENTRY slTerminate(void);

/**
 * Get's the last Starlight status.
 * @return An status code (SL_STATUS) indicating the last Starlight status.
 */
SL_STATUS SL_API SL_APIENTRY slGetStatus(void);


#ifdef __cplusplus
}
#endif