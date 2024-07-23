#include "include/framebuffer.h"

slFramebuffer SL_API SL_APIENTRY slDefineFramebuffer() {
    slFramebuffer fb;
    fb.status = SL_SUCCESS;
    return fb;
}

SL_STATUS SL_API SL_APIENTRY slInitFramebuffer(slFramebuffer *fb, int width, int height) {
    fb->width = width;
    fb->height = height;
    fb->buffer = (unsigned char*)malloc(fb->width * fb->height * 3);
    if (!fb->buffer) {
        fprintf(stderr, "Failed to allocate framebuffer.\n");
        fb->status = SL_ERROR_OUT_OF_MEMORY;
        return SL_ERROR_OUT_OF_MEMORY;
    }

    fb->status = SL_SUCCESS;
    return SL_SUCCESS;
}

SL_STATUS SL_API SL_APIENTRY slclearFramebuffer(slFramebuffer *fb) {
    memset(fb->buffer, 0, fb->width * fb->height * 3);
    if (!fb->buffer) {
        fprintf(stderr, "Failed to allocate framebuffer.\n");
        fb->status = SL_ERROR_OUT_OF_MEMORY;
        return SL_ERROR_OUT_OF_MEMORY;
    } 

    fb->status = SL_SUCCESS;
    return SL_SUCCESS;
}

SL_STATUS SL_API SL_APIENTRY slFBDrawPixel(slFramebuffer *fb, int x, int y, BYTE r, BYTE g, BYTE b, BYTE a) {
    int WIDTH = fb->width;
    int HEIGHT = fb->height;
    unsigned char* framebuffer = fb->buffer;
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return SL_ERROR_INVALID_ARGUMENT;
    int index = (y * WIDTH + x) * 3;
    framebuffer[index] = r;
    framebuffer[index + 1] = g;
    framebuffer[index + 2] = b;
    framebuffer[index + 3] = a;
    fb->status = SL_SUCCESS;
    return SL_SUCCESS;
}

#if defined(SL_USE_WINDOWS)
void SL_API SL_APIENTRY slRenderFramebuffer(slWindow *window, slFramebuffer fb) {
    HWND hWnd = glfwGetWin32Window(window->window);
    HDC hDC = GetDC(hWnd);

    // TO-DO: ACTUALLY IMPLEMENT IT.

    int width = fb.width;
    int height = fb.height;
    unsigned char* framebuffer = fb.buffer;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            SetPixel(hDC, x, y, RGB(framebuffer[index], framebuffer[index + 1], framebuffer[index + 2]));
        }
    }

    ReleaseDC(hWnd, hDC);
}
#endif