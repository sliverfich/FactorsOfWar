#pragma once

#ifndef FOW_UTIL_H
#define FOW_UTIL_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Color {
    constexpr glm::vec4 Red = { 1.0f, 0.0f, 0.0f, 1.0f };
    constexpr glm::vec4 Green = { 0.0f, 1.0f, 0.0f, 1.0f };
    constexpr glm::vec4 Blue = { 0.0f, 0.0f, 1.0f, 1.0f };

    constexpr glm::vec4 Black = { 0.0f, 0.0f, 0.0f, 1.0f };
    constexpr glm::vec4 White = { 1.0f, 1.0f, 1.0f, 1.0f };
    constexpr glm::vec4 Gray = { 0.5f, 0.5f, 0.5f, 1.0f };

    constexpr glm::vec4 Yellow = { 1.0f, 1.0f, 0.0f, 1.0f };
    constexpr glm::vec4 Cyan = { 0.0f, 1.0f, 1.0f, 1.0f };
    constexpr glm::vec4 Magenta = { 1.0f, 0.0f, 1.0f, 1.0f };

    constexpr glm::vec4 Orange = { 1.0f, 0.7f, 0.0f, 1.0f };

    
}

namespace Direction {
    constexpr glm::vec3 Left = { -1.0f, 0.0f, 0.0f };
    constexpr glm::vec3 Right = { 1.0f, 0.0f, 0.0f };

    constexpr glm::vec3 Up = { 0.0f, 1.0f, 0.0f };
    constexpr glm::vec3 Down = { 0.0f, -1.0f, 0.0f };

    constexpr glm::vec3 Forward = { 0.0f, 0.0f, -1.0f };
    constexpr glm::vec3 Backward = { 0.0f, 0.0f, 1.0f };
}

#endif
