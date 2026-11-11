#pragma once

#ifndef FOW_EBO_CPP
#define FOW_EBO_CPP
#include "ebo.h"

void EBO::gen() {
    glGenBuffers(1, &handle);
}

void EBO::bind(GLenum target) {
    glBindBuffer(target, handle);
}
#endif