#pragma once

#ifndef FOW_ENGINE_CPP
#define FOW_ENGINE_CPP
#include "engine.h"

static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // Resize viewport to actual framebuffer size (handles HiDPI)
    glViewport(0, 0, width, height);

    // Update stored aspect ratio if Engine is the window user pointer
    Engine* e = static_cast<Engine*>(glfwGetWindowUserPointer(window));
    if (e && height != 0) {
        e->settings.aspect = static_cast<float>(width) / static_cast<float>(height);
		e->camera.init();
    }
}

Engine::Engine() : input(Input{}), settings(Settings{}), clock(Clock{}), camera(Camera((float)WINDOW_WIDTH / (float)WINDOW_HEIGHT )) {
	camera.init();
}

int Engine::init() {
	if (!glfwInit()) return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	monitor = glfwGetPrimaryMonitor();

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "FOW", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	
	if (monitor)
	{
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);
		if (mode)
		{
			// Calculate top-left coordinates for centering
			int xpos = (mode->width - WINDOW_WIDTH) / 2;
			int ypos = (mode->height - WINDOW_HEIGHT) / 2;
			glfwSetWindowPos(window, xpos, ypos);
		}
	}

	glfwMakeContextCurrent(window);

	// Ensure callbacks and user pointer are set so framebuffer callback can update aspect
	glfwSetWindowUserPointer(window, this);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Set viewport to actual framebuffer size (important on HiDPI displays)
	int fbw = 0, fbh = 0;
	glfwGetFramebufferSize(window, &fbw, &fbh);
	if (fbw == 0 || fbh == 0) {
	    // fall back to window size if framebuffer query fails
	    glfwGetWindowSize(window, &fbw, &fbh);
	}
	glViewport(0, 0, fbw, fbh);
	// Update aspect to match framebuffer
	if (fbh != 0) settings.aspect = static_cast<float>(fbw) / static_cast<float>(fbh);


	glEnable(GL_DEPTH_TEST);


	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW init failed\n";
		return -1;
	}
	//stbi_set_flip_vertically_on_load(true);

	// Create shader and get sources
	Shader basicDarkShader;
	basicDarkShader.addSource(loadShaderSource("assets/basicDark.vert"), GL_VERTEX_SHADER);
	basicDarkShader.addSource(loadShaderSource("assets/basicDark.frag"), GL_FRAGMENT_SHADER);
	basicDarkShader.link();
	shaders["basicDark"] = std::move(basicDarkShader);

	Shader basicLightShader;
	basicLightShader.addSource(loadShaderSource("assets/basicLight.vert"), GL_VERTEX_SHADER);
	basicLightShader.addSource(loadShaderSource("assets/basicLight.frag"), GL_FRAGMENT_SHADER);
	basicLightShader.link();
	shaders["basicLight"] = std::move(basicLightShader);

	clock.reset();

	input.init(window);

	world = World();

	return 1;
}

int Engine::run() {
	Model playerModel;
	playerModel.init();
	playerModel.createNode();
	world.models.push_back(playerModel);

	// Gets the location of a variable within the currently bound OpenGL shader program
	GLint lightPosition = glGetUniformLocation(shaders["basicLight"].program, "lightPos");
	GLint lightColor = glGetUniformLocation(shaders["basicLight"].program, "lightColor");

	GLint basicDarkModel = glGetUniformLocation(shaders["basicDark"].program, "model");
	GLint basicDarkView = glGetUniformLocation(shaders["basicDark"].program, "view");
	GLint basicDarkProjection = glGetUniformLocation(shaders["basicDark"].program, "projection");

	GLint basicLightModel = glGetUniformLocation(shaders["basicLight"].program, "model");
	GLint basicLightView = glGetUniformLocation(shaders["basicLight"].program, "view");
	GLint basicLightProjection = glGetUniformLocation(shaders["basicLight"].program, "projection");

	


	while (!glfwWindowShouldClose(window)) {
		//INPUT
		clock.update();
		if (clock.isNewFrame(settings.FPS)) {
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			input.process(window, &settings);

			// UPDATE
			// Build matrices , Create fresh identity matrices each frame
			glm::mat4 modelBlock = glm::mat4(1.0f);
			modelBlock = glm::translate(modelBlock, Direction::Right);
			modelBlock = glm::translate(playerModel.translation, Direction::Right);

			// Convert yaw + pitch to direction vector
			camera.update(&input);

			camera.lightPos = camera.position;
			//RENDER
				/*
				shaders["basicDark"].use();
				glUniformMatrix4fv(basicDarkView, 1, GL_FALSE, glm::value_ptr(camera.view));
				glUniformMatrix4fv(basicDarkProjection, 1, GL_FALSE, glm::value_ptr(projection));
				*/

			shaders["basicLight"].use();

			// Updates/specifies the value of a variable within the currently bound OpenGL shader program
			// Uniform: Modifies a uniform variable (a global shader variable that stays constant for all vertices/fragments during a single draw call).
			// 3: Expects 3 components per element (e.g., X, Y, Z or R, G, B).
			// f: GLfloat
			// v: Stands for vector (or pointer), meaning it accepts a pointer to an array of floats rather than separate individual scalar arguments (unlike glUniform3f

			glUniform3fv(lightPosition, 1, &camera.lightPos[0]);
			glUniform3f(lightColor, 1.0f, 1.0f, 1.0f);

			// Render Models
			for (Model model : world.models) {
				// 1. Update the SAME uniform slot with this specific model's matrix
				glUniformMatrix4fv(basicLightModel, 1, GL_FALSE, &model.translation[0][0]);
				model.render();
			}
			
			// Render View
			glUniformMatrix4fv(basicLightView, 1, GL_FALSE, glm::value_ptr(camera.view));

			// Render Projection
			glUniformMatrix4fv(basicLightProjection, 1, GL_FALSE, glm::value_ptr(camera.projection));



			glfwSwapBuffers(window);
			clock.save();
		}
		glfwPollEvents();
	}
	return 1;
}

void Engine::end() {
	glfwTerminate();
}
#endif