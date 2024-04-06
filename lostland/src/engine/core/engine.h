#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "vectors.h"
#include "input.h"
#include "time.h"
#include "scene.h"

namespace Engine {
	extern GLFWwindow* window;
	extern Scene* active_scene;

	bool initialize(IVec2 window_size, const char* title, void (*start)(), void (*update)(), void (*exit)());
	void quit();
	static void render();
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void activate_scene(Scene* scene);
}


