#pragma once

#ifndef FOW_TRANSFORM_H
#define FOW_TRANSFORM_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

glm::vec3 left = { -1.0f, 0.0f, 0.0f };
glm::vec3 right = { 1.0f, 0.0f, 0.0f };
glm::vec3 up = { 0.0f, 1.0f, 0.0f };
glm::vec3 down = { 0.0f, -1.0f, 0.0f };
glm::vec3 forward = { 0.0f, 0.0f, -1.0f };
glm::vec3 backward = { 0.0f, 0.0f, 1.0f };

typedef struct Transform {
    glm::mat4 model = glm::mat4(1.0f);

    void init();
    void update();


} Transform;

#endif
