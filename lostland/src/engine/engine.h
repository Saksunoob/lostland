#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "texture.h"
#include "transform.h"

class Engine {
	GLFWwindow* window;

	public:
		Engine(unsigned int width, unsigned int height, const char* title);
		bool run();
	private:
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void processInput(GLFWwindow* window);
};


