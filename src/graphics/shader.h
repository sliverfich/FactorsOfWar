#pragma once

#ifndef FOW_SHADER_H
#define FOW_SHADER_H
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <GL/glew.h>
std::string loadShaderSource(const char* filepath);

typedef struct Shader {
	std::vector<GLuint> shaders;
	GLuint program;
	Shader();
	~Shader();

	Shader(const Shader&) = delete;
	Shader& operator=(const Shader&) = delete;

	Shader(Shader&& other) noexcept;
	Shader& operator=(Shader&& other) noexcept;
	

	void link();
	void addSource(std::string source, GLenum shaderType);
	void use();

} Shader;
#endif