#include "include/window.h"

slWindow SL_API SL_APIENTRY slDefineWindow(void) {
    slWindow window = {0};
    window.status = SL_SUCCESS;
    return window;
}

void SL_API SL_APIENTRY slLinkWindowConfig(slWindow *window, SL_CONFIG config) {
    if (window == NULL || config.sConfigType != SL_CONFIG_WINDOW) {
        window->status = SL_ERROR_INVALID_ARGUMENT;
        return;
    }

    window->width = config.pWindowWidth;
    window->height = config.pWindowHeight;
    window->title = config.pWindowTitle;
    window->monitor = config.pWindowMonitor;
    window->status = SL_SUCCESS;
}

void SL_API SL_APIENTRY slLinkWindowGLFW(slWindow *window, GLFWwindow* glfwWindow) {
    if (window == NULL || glfwWindow == NULL) {
        window->status = SL_ERROR_INVALID_ARGUMENT;
        return;
    }

    window->window = glfwWindow;
    GLFWvidmode return_struct;
    glfwGetVideoMode(&return_struct);
    window->width = return_struct.width;
    window->height = return_struct.height;
    window->title = "LINKED_WITH_GLFW_NULL";
    window->status = SL_SUCCESS;
}

void SL_API SL_APIENTRY slInitWindow(slWindow *window) {
    if (window == NULL) {
        window->status = SL_ERROR_INVALID_ARGUMENT;
        return;
    }

    if (!SL_INIT) {
        window->status = SL_ERROR_NOT_INIT;
        return;
    }

    if (window->title == "LINKED_WITH_GLFW_NULL") {
        glfwMakeContextCurrent(window->window);
        return;
    }

    window->window = glfwCreateWindow(window->width, window->height, window->title, window->monitor, NULL);
    if (window->window == NULL) {
        window->status = SL_ERROR_WINDOW;
        return;
    }
    glfwMakeContextCurrent(window->window);

    window->status = SL_SUCCESS;
}

SL_STATUS SL_API SL_APIENTRY slRenderWindow(slWindow *window) {
    if (window == NULL || window->window == NULL) {
        window->status = SL_ERROR_INVALID_ARGUMENT;
        return window->status;
    }

    if (!SL_INIT) {
        window->status = SL_ERROR_NOT_INIT;
        return window->status;
    }

    glClear(GL_COLOR_BUFFER_BIT);

    // if (window->render) {
    //     window->render(window);
    // }

    glfwSwapBuffers(window->window);
    glfwPollEvents();

    window->status = SL_SUCCESS;
    return SL_SUCCESS;
}