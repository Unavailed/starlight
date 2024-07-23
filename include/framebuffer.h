#pragma once

#include "vendor/GLFW/glfw3.h"
#include "window.h"
#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE unsigned char

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    BYTE* buffer;
    int width;
    int height;
    SL_STATUS status;
} slFramebuffer;

SL_STATUS SL_API SL_APIENTRY slInitFramebuffer(slFramebuffer *fb, int width, int height);
SL_STATUS SL_API SL_APIENTRY slclearFramebuffer(slFramebuffer *fb);
SL_STATUS SL_API SL_APIENTRY slFBDrawPixel(slFramebuffer *fb, int x, int y, BYTE r, BYTE g, BYTE b, BYTE a);
void SL_API SL_APIENTRY slRenderFramebuffer(slWindow *window, slFramebuffer fb);

#ifdef __cplusplus
}
#endif 