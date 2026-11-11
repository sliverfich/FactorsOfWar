#pragma once

#ifndef FOW_KEYBOARD_CPP
#define FOW_KEYBOARD_CPP
#include "keyboard.h"
#include <iostream>
bool Keyboard::active = false;
bool Keyboard::keys[GLFW_KEY_LAST] = { false };

Keyboard::Keyboard() {

}

void Keyboard::init(GLFWwindow* window) {
    active = true;
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCharCallback(window, charCallback);
}

void Keyboard::reset() {
    for (int i = 0; i < GLFW_KEY_LAST; i++) {
        keys[i] = false;
    }
}

void Keyboard::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // Skip out of bounds keys
    if (key < 0 || key >= 1024) return;

    // Single press /Functional keys / Interrupts / CANT MISS INPUT
    if (key >= 32 && key < GLFW_KEY_LAST) {
        if (action == GLFW_PRESS) {
            keys[key] = true;
        }
        else if (action == GLFW_RELEASE) {
            keys[key] = false;
        }
    }
    if (keys[GLFW_KEY_ESCAPE]) {
        keys[GLFW_KEY_ESCAPE] = true;
    }
}

void Keyboard::charCallback(GLFWwindow* window, unsigned int codepoint) {
    const char* key_name = glfwGetKeyName(GLFW_KEY_W, 0);
    //show_tutorial_hint("Press %s to move forward", key_name);
}

#endif