# Starlight
A new high-performance, multi-threaded rendering API written in C. (VERY VERY EARLY WIP)

NOTE: As of now, I'm working only on Windows and Linux. All help with darwin is accepted and appreciated.

## Example Usage
```c
#include <starlight.h>
#include <stdio.h>

int main() {
    // Initialization
    if (slInit() != SL_ERROR_INIT) {
        printf("Failed to initialize Starlight.");
        return 1;
    }

    // Creating a window config
    SL_CONFIG windowConfig;
    windowConfig.sConfigType = SL_CONFIG_WINDOW;
    windowConfig.pWindowTitle = "Starlight Example"
    windowConfig.pWindowWidth = 800;
    windowConfig.pWindowHeight = 600;
    windowConfig.pWindowFlags = NULL;

    // Create a window
    slWindow window;
    slLinkWindowConfig(&window, windowConfig);
    slInitWindow(&window);
    slRenderWindow(&window);

    while (!slWindowShouldClose(window)) {
        // Render code here
    }

    slDestroyWindow(&window);
    slTerminate();
}
```
