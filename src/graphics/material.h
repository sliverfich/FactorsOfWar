#pragma once

#ifndef FOW_MATERIAL_H
#define FOW_MATERIAL_H
#include <vector>
#include <glm/glm.hpp>
#include "shader.h"

// Fix
typedef struct Material {
	Shader* shader;
	//Texture albedo;
	//Normal Map
	//Metallic
	//Roughness
	//Emissive
	//std::vector<glm::vec3> UniformValues;

	Material();

} Material;

#endif
