#pragma once

#ifndef FOW_SETTINGS_H
#define FOW_SETTINGS_H

#define WINDOW_WIDTH 2000
#define WINDOW_HEIGHT 1200

typedef struct Settings {

    double FPS = 50;
    float aspect = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;
    float sensitivity = 0.1f;
    float speed = 2.0f;

} Settings;

#endif
