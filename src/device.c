#include "include/core.h"
#include "include/device.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef SL_USE_WINDOWS
#include <windows.h>

static void enumerateGPUs(slPhysicalDevice *devices, int *deviceCount) {
    DISPLAY_DEVICE displayDevice;
    displayDevice.cb = sizeof(displayDevice);
    int index = 0;
    int gpuIndex = 0;

    while (EnumDisplayDevices(NULL, index, &displayDevice, 0)) {
        if (displayDevice.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE) {
            devices[*deviceCount].type = SL_DEVICE_TYPE_GPU;
            devices[*deviceCount].name = strdup(displayDevice.DeviceString);
            (*deviceCount)++;
        }
        index++;
    }    
}

static void enumerateCPUs(slPhysicalDevice *devices, int *deviceCount) {
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    devices[*deviceCount].type = SL_DEVICE_TYPE_CPU;
    devices[*deviceCount].name = "CPU";
    (*deviceCount)++;
}

SL_STATUS SL_API SL_APIENTRY slEnumeratePhysicalDevices(slPhysicalDevice *devices, int *deviceCount) {
    if (!devices || !deviceCount) {
        return SL_ERROR_INVALID_ARGUMENT;
    }

    *deviceCount = 0;

    enumerateCPUs(devices, deviceCount);
    enumerateGPUs(devices, deviceCount);

    return SL_SUCCESS;
}
#endif