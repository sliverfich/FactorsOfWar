#pragma once

#ifndef FOW_PLAYER_H
#define FOW_PLAYER_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "../config/settings.h"

typedef struct Player {
    Settings settings;

    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);


    void init();
    void move();


} Player;

#endif
