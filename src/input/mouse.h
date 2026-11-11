#pragma once

#ifndef FOW_MOUSE_H
#define FOW_MOUSE_H
#include "../engine/util.h"
#include "../config/settings.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct Mouse {
    static bool active;
    static bool inWindow;
    static bool leftPressed;
    static bool rightPressed;
    static double lastX, lastY;
    static double x, y;
    static float xOffset, yOffset;
    

    Mouse();

    void init(GLFWwindow*);
    void update(float);
    
    static void reset();
    static void cursorEnterCallback(GLFWwindow*, int);
    static void cursorPosCallback(GLFWwindow*, double, double);
    static void mouseButtonCallback(GLFWwindow*, int, int, int);
    static void scrollCallback(GLFWwindow*, double, double);

} Mouse;

#endif
