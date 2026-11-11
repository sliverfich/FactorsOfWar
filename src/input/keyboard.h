#pragma once

#ifndef FOW_KEYBOARD_H
#define FOW_KEYBOARD_H
#define GLFW_INCLUDE_NONE
#include "../config/settings.h"
#include <GLFW/glfw3.h>

typedef struct Keyboard {
    static bool active;
    static bool keys[GLFW_KEY_LAST];

    Keyboard();

    static void init(GLFWwindow*);
    static void reset();
    static void keyCallback(GLFWwindow*, int, int, int, int);
    static void charCallback(GLFWwindow*, unsigned int);

} Keyboard;

#endif
