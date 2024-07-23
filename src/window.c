#include "include/window.h"
#include <stdio.h>

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

void SL_API SL_APIENTRY slInitWindow(slWindow *window) {
    if (window == NULL) {
        window->status = SL_ERROR_INVALID_ARGUMENT;
        return;
    }

    if (SL_INIT) {
        window->status = SL_ERROR_NOT_INIT;
        return;
    }

    window->window = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);
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

    if (SL_INIT) {
        window->status = SL_ERROR_NOT_INIT;
        return window->status;
    }

    // if (window->render) {
    //     window->render(window);
    // }

    glfwSwapBuffers(window->window);

    window->status = SL_SUCCESS;
    return SL_SUCCESS;
}