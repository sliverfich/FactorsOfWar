#pragma once

#ifndef FOW_CAMERA_CPP
#define FOW_CAMERA_CPP
#include "camera.h"

Camera::Camera(float aspect) : aspect(aspect) {

}

void Camera::init() {
	glm::mat4 perspective = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 200.0f);
	glm::mat4 orthographic = glm::ortho(
		-1.0f, 1.0f,   // left, right
		-1.0f, 1.0f,   // bottom, top
		0.1f, 100.0f     // near, far
	);
	projection = perspective;
}

void Camera::update(Input* input) {
	yaw += input->mouse.xOffset;
	pitch += input->mouse.yOffset;
	if (pitch > 89.0f) pitch = 89.0f;
	if (pitch < -89.0f) pitch = -89.0f;


	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
	right = glm::normalize(glm::cross(front, up));


	position += front * float(input->keyboard.keys[GLFW_KEY_W]);
	position += -front * float(input->keyboard.keys[GLFW_KEY_S]);
	position += right * float(input->keyboard.keys[GLFW_KEY_D]);
	position += -right * float(input->keyboard.keys[GLFW_KEY_A]);

	view = glm::lookAt(position, position + front, up);
}

#endif