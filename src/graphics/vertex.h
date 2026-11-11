#pragma once

#ifndef FOW_VERTEX_H
#define FOW_VERTEX_H
#include <glm/glm.hpp>
// GPU Side
typedef struct Vertex {
    glm::vec3 position;
    glm::vec4 color;
    glm::vec3 normal;
    glm::vec2 uv;

    Vertex(glm::vec3 position, glm::vec4 color, glm::vec3 normal);

} Vertex;

#endif
