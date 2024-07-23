#include "include/starlight.h"
#include <stdio.h>

int main() {
    if (slInit() != 0) {
        printf("Failed to initialize Starlight.\n");
        return 1;
    }

    slPhysicalDevice devices[10];
    int deviceCount = 0;
    slEnumeratePhysicalDevices(devices, &deviceCount);

    printf("Found %d devices.\n", deviceCount);

    // Loop through the devices and print their details
    for (int i = 0; i < deviceCount; ++i) {
        const char* type = (devices[i].type == SL_DEVICE_TYPE_CPU) ? "CPU" : 
                           (devices[i].type == SL_DEVICE_TYPE_GPU) ? "GPU" : "Unknown";
        printf("Device %d: Type: %s, Name: %s\n", i, type, devices[i].name);
    }

    // Clean up dynamically allocated names
    for (int i = 0; i < deviceCount; ++i) {
        if (devices[i].type == SL_DEVICE_TYPE_GPU) {
            free((void*)devices[i].name);
        }
    }  

    return 0;
}