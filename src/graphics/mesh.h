#pragma once

#ifndef FOW_MESH_H
#define FOW_MESH_H
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "vao.h"
#include "vbo.h"
#include "ebo.h"

enum class MeshType {
	PLANE,
	CUBE,
	PYRAMID
};

namespace Shape {
	inline const std::vector<glm::vec3> PLANE_VERTICES{
		// Corner positions
		glm::vec3(-1.0f, 0.0f, 1.0f), // LF, 1
		glm::vec3(1.0f, 0.0f, 1.0f), // RF, 2
		glm::vec3(1.0f,  0.0f, -1.0f), // RB, 3
		glm::vec3(-1.0f,  0.0f, -1.0f), // LB, 4
	};

	inline const std::vector<uint32_t> PLANE_INDICES {
		// top
		1, 2, 3,  // LF, RF, RB
		1, 3, 4,  // LF, RB, LB

	};

	inline const std::vector<glm::vec3> CUBE_VERTICES {
		// Corner positions
		glm::vec3(-1.0f, -1.0f, -1.0f), //glm::vec3 LDB, 0
		glm::vec3(1.0f, -1.0f, -1.0f), //glm::vec3 RDB, 3
		glm::vec3(1.0f,  1.0f, -1.0f), //glm::vec3 RUB, 6
		glm::vec3(-1.0f,  1.0f, -1.0f), //glm::vec3 LUB, 9
		glm::vec3(-1.0f, -1.0f,  1.0f), //glm::vec3 LDF, 12
		glm::vec3(1.0f, -1.0f,  1.0f), //glm::vec3 RDF, 15
		glm::vec3(1.0f,  1.0f,  1.0f), //glm::vec3 RUF, 18
		glm::vec3(-1.0f,  1.0f,  1.0f), //glm::vec3 LUF, 21
	};

	inline const std::vector<uint32_t> CUBE_INDICES{
		// Side indices
		// back
			5, 2, 11,
			5, 11, 8,
			// front
			14, 17, 20,
			14, 20, 23,
			// left
			0, 12, 21,
			0, 21, 9,
			// right
			15, 3, 6,
			15, 6, 18,
			// down
			1, 4, 16,
			1, 16, 13,
			// up
			22, 19, 7,
			22, 7, 10
	};
};



// CPU Side
typedef struct Mesh {
	VAO vao;
	VBO vbo;
	EBO ebo;
	short shape;
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;
	std::vector<uint32_t> bounds;
	

	Mesh();
	Mesh(MeshType);
	void gen();
	void bind(GLenum target = GL_ARRAY_BUFFER, GLenum target2 = GL_ELEMENT_ARRAY_BUFFER);
	void color(glm::vec4 color);
	std::vector<Vertex> load2Dvertices(std::vector<glm::vec3> positions, glm::vec4 color);
	std::vector<Vertex> load3Dvertices(std::vector<glm::vec3> positions, glm::vec4 color);
	void uv(glm::vec2 uv);
	void buffer();
	void attrib(); // Edit

	void draw(GLenum mode = GL_TRIANGLES);

} Mesh;

#endif
