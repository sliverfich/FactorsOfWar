#pragma once

#ifndef FOW_MOUSE_CPP
#define FOW_MOUSE_CPP
#include "mouse.h"
#include <iostream>

bool Mouse::active = false;
bool Mouse::inWindow = false;
double Mouse::lastX = 0.0;
double Mouse::lastY = 0.0;
double Mouse::x = 0.0;
double Mouse::y = 0.0;
float Mouse::xOffset = 0.0;
float Mouse::yOffset = 0.0;
bool Mouse::leftPressed = false;
bool Mouse::rightPressed = false;


Mouse::Mouse() {

}



void Mouse::init(GLFWwindow* window) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    
    glfwSetCursorEnterCallback(window, cursorEnterCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetScrollCallback(window, scrollCallback);
}

void Mouse::update(float sensitivity) {
    if (active) {
        xOffset = x - lastX;
        yOffset = lastY - y; // reversed (y goes down on screen)

        lastX = x;
        lastY = y;

        xOffset *= sensitivity;
        yOffset *= sensitivity;
    }
}

void Mouse::reset() {
    lastX = x;
    lastY = y;

    xOffset = 0;
    yOffset = 0;
}

void Mouse::cursorEnterCallback(GLFWwindow* window, int entered) {
    inWindow = entered;
}

void Mouse::cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    x = xpos;
    y = ypos;
}

void Mouse::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    leftPressed = (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS);
    rightPressed = (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS);
}

void Mouse::scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {

}

#endif