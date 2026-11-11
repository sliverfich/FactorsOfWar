#pragma once

#ifndef FOW_ENGINE_H
#define FOW_ENGINE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "stb_image.h"
#include "../graphics/shader.h"
#include "clock.h"
#include "../graphics/model.h"
#include "../world/world.h"

#include "../input/input.h"
#include "../graphics/camera.h"
#include "../config/settings.h"
#include "util.h"

#include "../graphics/vao.h"
#include "../graphics/ebo.h"


typedef struct Engine {
	GLFWwindow* window; // input, event handling, timing, fullscreen, resizing, cursor capture
	GLFWmonitor* monitor;
	Input input; // Global
	Settings settings; // Global
	Clock clock;
	Camera camera;
	World world;
	

	std::unordered_map<std::string, Shader> shaders = {};

	Engine();
	int init();
	int run();
	void end();

} Engine;

#endif
