#include "include/starlight.h"
#include <stdio.h>

int main() {
    // Initialization
    if (slInit() != SL_SUCCESS) {
        printf("Failed to initialize Starlight.\n");
        return -1;
    }

    // Create Window config
    SL_CONFIG windowConfig;
    windowConfig.sConfigType = SL_CONFIG_WINDOW;
    windowConfig.pWindowTitle = "Starlight Example";
    windowConfig.pWindowWidth = 800;
    windowConfig.pWindowHeight = 600;
    windowConfig.pWindowMonitor = NULL;

    // Create Window
    slWindow window;
    slLinkWindowConfig(&window, windowConfig);
    slInitWindow(&window);

    // Create Framebuffer
    slFramebuffer fb = slDefineFramebuffer();
    slInitFramebuffer(&fb, window.width, window.height);
    
    // Draw to Framebuffer
    // slFBDrawPixel(&fb, 100, 100, 255, 128, 0);

    // Main Loop
    while (glfwWindowShouldClose(window.window) == 0) {
        // Render
        slRenderFramebuffer(&window, fb);
        glfwPollEvents();
    }

    // Cleanup
    free(fb.buffer);
    slTerminate();

    return 0;
}