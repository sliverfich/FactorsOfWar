#pragma once

#ifndef FOW_NODE_H
#define FOW_NODE_H
#include "../engine/util.h"
#include "mesh.h"
#include "material.h"

// CPU Side
typedef struct Node {
	Mesh* mesh;
	Material* material;

	glm::mat4 translation = glm::mat4(1.0f);
	glm::mat4 rotation = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);
	glm::mat4 reflection = glm::mat4(1.0f);
	

	Node();

	void init();
	void setMesh(Mesh*);

} Node;

#endif