#pragma once

#ifndef FOW_WORLD_H
#define FOW_WORLD_H
#include <vector>
#include "../graphics/model.h"


// CPU Side
typedef struct World {
	std::vector<Model> models;

	World();

	void init();

} World;

#endif
