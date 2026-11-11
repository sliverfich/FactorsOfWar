#pragma once

#ifndef FOW_CLOCK_CPP
#define FOW_CLOCK_CPP
#include "clock.h"

Clock::Clock() : previousTime(0), currentTime(0) {

}

void Clock::reset() {
	this->currentTime = glfwGetTime();
	this->previousTime = this->currentTime;
	this->currentTime = glfwGetTime();
	this->previousTime = this->currentTime;
}

void Clock::update() {
	this->currentTime = glfwGetTime();
}

void Clock::save() {
	this->previousTime = this->currentTime;
}

bool Clock::isNewFrame(double FPS) {
	return (currentTime - previousTime >= (1 / FPS));
}

#endif