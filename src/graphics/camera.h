#pragma once

#ifndef FOW_CAMERA_H
#define FOW_CAMERA_H
#include "../engine/util.h"
#include "../input/input.h"

typedef struct Camera {
    float aspect = 1.75f;
    float yaw = -90.0f; // start facing -Z
    float pitch = 0.0f;

    glm::vec3 position = glm::vec3(0.0f, 0.0f, 4.0f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 200.0f);
    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 lightPos = glm::vec3(4.0f, 4.0f, 4.0f);
    glm::mat4 view;

    Camera(float);

    void init();
    void update(Input*);


} Camera;

#endif