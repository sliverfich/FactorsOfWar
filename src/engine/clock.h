#pragma once

#ifndef FOW_CLOCK_H
#define FOW_CLOCK_H
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

typedef struct Clock {
    double previousTime;
    double currentTime;

    Clock();

    void reset();
    void update();
    void save();

    bool isNewFrame(double);

} Clock;

#endif