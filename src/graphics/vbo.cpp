#pragma once

#ifndef FOW_VBO_CPP
#define FOW_VBO_CPP
#include "vbo.h"

void VBO::gen() {
	glGenBuffers(1, &handle);
}

void VBO::bind(GLenum target) {
	glBindBuffer(target, handle);
}

#endif