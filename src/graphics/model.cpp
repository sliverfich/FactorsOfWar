#pragma once

#ifndef FOW_MODEL_CPP
#define FOW_MODEL_CPP
#include "model.h"

Model::Model() {

}

void Model::init() {
	Mesh block;
	block.bind();
	block.vertices = block.load3Dvertices(Shape::CUBE_VERTICES, Color::Red);

	block.indices = Shape::CUBE_INDICES;

	block.buffer();
	block.attrib();
	meshes.push_back(block);
}

void Model::createNode() {
	Node newNode;
	newNode.setMesh(&meshes[0]);
	nodes.push_back(newNode);
}

void Model::render() {
	for (Node node : nodes) {
		node.mesh->draw();
	}
}

#endif