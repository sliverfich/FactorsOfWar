#pragma once

#ifndef FOW_INPUT_CPP
#define FOW_INPUT_CPP
#include "input.h"

Input::Input() : keyboard(Keyboard{}), mouse(Mouse{}) {
	
}

void Input::init(GLFWwindow* window) {
	keyboard.init(window);
	mouse.init(window);
}

void Input::keyEvent() {

}

void Input::process(GLFWwindow* window, Settings* settings) {
	//keyboard.update();
	mouse.update(settings->sensitivity);
	// TASK set polling and callback keys between here and keyboard
	// 
	// 
	// Holding keys, movement, polling / REQUIRED FOR MULTIPLE FRAMES
	if (keyboard.keys[GLFW_KEY_ESCAPE]) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		Mouse::active = false;
		Keyboard::reset();
		Mouse::reset();
	}
	
	if (Mouse::leftPressed && !Mouse::active) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		Keyboard::reset();
		Mouse::reset();
		Mouse::active = true;
	}
}


#endif