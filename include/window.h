#include "vendor/GLFW/glfw3.h"
#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    GLFWwindow*  window;
    int          width;
    int          height;
    const char*  title;
    GLFWmonitor* monitor;

    SL_STATUS   status;
    
    // void (*update)(struct slWindow *);    // Updates Window.
    // void (*destroy)(struct slWindow *);   // Destroys Window.
    // void (*render)(struct slWindow *);    // Renders Window.
    // void (*resize)(struct slWindow *);    // Resizes Window.
    // void (*input)(struct slWindow *);     // Inputs Window.
    // void (*scroll)(struct slWindow *);    // Scrolls Window.
    // void (*key)(struct slWindow *);       // Keys Window.
    // void (*mouse)(struct slWindow *);     // Mouse Window.
    // void (*drop)(struct slWindow *);      // Drops Window.
    // void (*file)(struct slWindow *);      // File Window.
    // void (*close)(struct slWindow *);     // Closes Window.
    // void (*init)(struct slWindow *);      // Initializes window.
    // void (*terminate)(struct slWindow *); // Terminates window.
    // void (*pollEvents)(struct slWindow *); // Polls events.
    // void (*waitEvents)(struct slWindow *); // Waits for events.
    // void (*waitEventsTimeout)(struct slWindow *); // Waits for events with timeout.
} slWindow;

/**
 * @brief Defines an uninitialized window.
 * @return uninitialized Starlight window.
 */
slWindow SL_API SL_APIENTRY slDefineWindow(void);

/**
 * @brief Links window with config.
 * @param window The window linked to.
 * @param config The config to be linked.
 */
void SL_API SL_APIENTRY slLinkWindowConfig(slWindow *window, SL_CONFIG config);

/**
 * @brief Links window with GLFW window.
 * 
 * @param window Starlight window
 * @param glfwWindow GLFW window.
 */
void SL_API SL_APIENTRY slLinkWindowGLFW(slWindow *window, GLFWwindow* glfwWindow);

/**
 * @brief Initializes starlight window.
 * @param window The window being initialized.
 */
void SL_API SL_APIENTRY slInitWindow(slWindow *window);

/**
 * @brief Renders the given window.
 * 
 * @param window The window to be rendered.
 */
SL_STATUS SL_API SL_APIENTRY slRenderWindow(slWindow *window);

#ifdef __cplusplus
}
#endif