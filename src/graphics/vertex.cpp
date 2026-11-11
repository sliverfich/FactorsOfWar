#pragma once

#ifndef FOW_VERTEX_CPP
#define FOW_VERTEX_CPP
#include "vertex.h"

Vertex::Vertex(glm::vec3 position, glm::vec4 color, glm::vec3 normal)
    : position(position)
    , color(color)
    , normal(normal)
    , uv(glm::vec2(0.0f, 0.0f))
{
}

#endif