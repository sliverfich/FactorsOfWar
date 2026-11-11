#pragma once

#ifndef FOW_SHADER_CPP
#define FOW_SHADER_CPP
#include "shader.h"
#include <iostream>

// Loads a GLSL file into const char*
std::string loadShaderSource(const char* filepath) {
    std::ifstream file(filepath);

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

Shader::Shader() {
    program = glCreateProgram();
}
Shader::~Shader() {
    std::cout << "Destroying shader: " << program << '\n';
    if (program != 0)
        glDeleteProgram(program);
}

Shader::Shader(Shader&& other) noexcept
{
    program = other.program;
    other.program = 0;
}

Shader& Shader::operator=(Shader&& other) noexcept
{
    if (this != &other)
    {
        if (program != 0)
            glDeleteProgram(program);

        program = other.program;
        other.program = 0;
    }

    return *this;
}

void Shader::addSource(std::string source, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    shaders.push_back(shader);

    const char* sourceCode = source.c_str();

    glShaderSource(shader, 1, &sourceCode, NULL);
    glCompileShader(shader);

    // Check compile status and print log
    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint logLen = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
        std::vector<char> infoLog(logLen + 1);
        glGetShaderInfoLog(shader, logLen, NULL, infoLog.data());
        std::cerr << "Shader compile error (" << shaderType << "):\n" << infoLog.data() << std::endl;
    }

    glAttachShader(program, shader);
}
void Shader::link() {
    glLinkProgram(program);

    // Check link status and print log
    GLint success = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        GLint logLen = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLen);
        std::vector<char> infoLog(logLen + 1);
        glGetProgramInfoLog(program, logLen, NULL, infoLog.data());
        std::cerr << "Program link error:\n" << infoLog.data() << std::endl;
    }

    for (auto& item : shaders) {
        glDeleteShader(item);
    }
}
void Shader::use() {
    glUseProgram(program);
}
#endif