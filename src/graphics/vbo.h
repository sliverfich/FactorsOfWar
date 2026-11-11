#pragma once

#ifndef FOW_VBO_H
#define FOW_VBO_H
#include <vector>
#include <GL/glew.h>
#include "../graphics/vertex.h"

typedef struct VBO {
	GLuint handle;
	std::vector<Vertex> vertices;

	void gen();
	void bind(GLenum target = GL_ARRAY_BUFFER);


} VBO;

#endif