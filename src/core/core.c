#include "include/core.h"
#include "vendor/GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>

static SL_STATUS Status = SL_SUCCESS;

SL_STATUS SL_API SL_APIENTRY slInit(void) {
    if (!glfwInit()) {
        Status = SL_ERROR_INIT;
        return Status;
    }
    Status = SL_SUCCESS;
    SL_INIT = 1;
    return Status;
}

void SL_API SL_APIENTRY slTerminate(void) {
    glfwTerminate();
    Status = SL_SUCCESS;
}

SL_STATUS SL_API SL_APIENTRY slGetStatus(void) {
    return Status;
}