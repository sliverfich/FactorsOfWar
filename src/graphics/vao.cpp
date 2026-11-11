#pragma once

#ifndef FOW_VAO_CPP
#define FOW_VAO_CPP
#include "vao.h"

void VAO::gen() {
	glGenVertexArrays(1, &handle);
}

void VAO::bind() {
	glBindVertexArray(handle);
}

void VAO::attr(GLuint slot, GLint dataPoints, GLsizei dataUnitSize, const void* posInDataUnit, GLenum dataPointType, GLboolean normalized) {
	glVertexAttribPointer(slot, dataPoints, dataPointType, normalized, dataUnitSize, posInDataUnit);
	glEnableVertexAttribArray(slot);
}

#endif