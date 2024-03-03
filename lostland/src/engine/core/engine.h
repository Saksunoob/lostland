#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../rendering/shader.h"
#include "../rendering/texture.h"
#include "../game_objects/transform.h"
#include "input.h"
#include "../game_objects/game_object.h"

namespace Engine {
	static GLFWwindow* window;

	bool initialize(unsigned int width, unsigned int height, const char* title);
	bool run();
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}


