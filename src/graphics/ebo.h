#pragma once

#ifndef FOW_EBO_H
#define FOW_EBO_H

#include <vector>
#include <GL/glew.h>
#include "vertex.h"

typedef struct EBO {
	GLuint handle;
	std::vector<Vertex> vertices;

	void gen();
	void bind(GLenum target = GL_ELEMENT_ARRAY_BUFFER);

} EBO;

#endif