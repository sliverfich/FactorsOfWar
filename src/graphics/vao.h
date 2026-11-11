#pragma once

#ifndef FOW_VAO_H
#define FOW_VAO_H
#include <string>
#include <vector>
#include <GL/glew.h>

typedef struct VAO {
	GLuint handle;
	
	void gen();
	void bind();
	void attr(GLuint slot, GLint dataPoints, GLsizei dataChunkSize, const void* posInDataChunk, GLenum dataPointType = GL_FLOAT, GLboolean normalized = GL_FALSE);

} VAO;

#endif
