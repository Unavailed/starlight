#pragma once
#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    SL_DEVICE_TYPE_UNKNOWN     = 0,
    SL_DEVICE_TYPE_CPU         = 1,
    SL_DEVICE_TYPE_GPU         = 2,
} SL_DEVICE_TYPE;

typedef struct {
    SL_DEVICE_TYPE type;
    const char* name;
} slPhysicalDevice;

// typedef struct {
//     // ... Yet to be added.
// } slLogicalDevice;

SL_STATUS SL_API SL_APIENTRY slEnumeratePhysicalDevices(slPhysicalDevice *devices, int *deviceCount);

#ifdef __cplusplus
}
#endif