#pragma once

#include "vendor/GLFW/glfw3.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
    #define SL_APIENTRY __stdcall
    #if defined(STARLIGHT_BUILD)
        #define SL_API __declspec(dllexport)
    #else
        #define SL_API __declspec(dllimport)
    #endif
#else
    #define SL_APIENTRY
    #define SL_API __attribute__((visibility("default")))
#endif

int SL_INIT = 0;

typedef enum {
    SL_SUCCESS,
    SL_ERROR_INIT,
    SL_ERROR_NOT_INIT,
    SL_ERROR_WINDOW,
    SL_ERROR_CONTEXT,
    SL_ERROR_DEVICE,
    SL_ERROR_INPUT,
    SL_ERROR_RENDER,
    SL_ERROR_OUT_OF_MEMORY,
    SL_ERROR_INVALID_ARGUMENT,
    SL_ERROR_UNKNOWN
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
    GLFWwindow* pWindowMonitor;

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