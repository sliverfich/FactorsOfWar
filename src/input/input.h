#pragma once

#ifndef FOW_INPUT_H
#define FOW_INPUT_H
#include "keyboard.h"
#include "mouse.h"
#include "../config/settings.h"
enum class InputModes {
    UI,
    WALKING,
    DRIVING,
    FLYING
};

typedef struct InputMode {
    InputModes index;



} InputMode;

typedef struct Input {
    

    static InputMode mode;
    Keyboard keyboard;
    Mouse mouse;

    Input();

    void init(GLFWwindow*);
    void keyEvent();
    void process(GLFWwindow*, Settings*);

} Input;


#endif
