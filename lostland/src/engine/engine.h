#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <vector>

#include "shader.h"

class Engine {
	unsigned int window_width;
	unsigned int window_height;
	const char* window_title;

	public:
		Engine(unsigned int width, unsigned int height, const char* title);
		bool run();
	private:
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void processInput(GLFWwindow* window);
};


