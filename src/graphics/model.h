#pragma once

#ifndef FOW_MODEL_H
#define FOW_MODEL_H
#include <vector>
#include "mesh.h"
#include "material.h"
#include "node.h"

// CPU Side
typedef struct Model {
	std::vector<Mesh> meshes;
	std::vector<Node> nodes;
	std::vector<glm::vec3> skeleton; // fix type

	glm::mat4 translation = glm::mat4(1.0f);
	glm::mat4 rotation = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);
	glm::mat4 reflection = glm::mat4(1.0f);

	Model();

	void init();
	void createNode();
	void render();

} Model;

#endif