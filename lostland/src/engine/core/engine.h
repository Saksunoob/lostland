#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "input.h"
#include "scene.h"

namespace Engine {
	static GLFWwindow* window;
	static Scene* active_scene;

	bool initialize(unsigned int width, unsigned int height, const char* title, void (*start)(), void (*update)(), void (*exit)());
	void quit();
	static void render();
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void activate_scene(Scene* scene);
}


