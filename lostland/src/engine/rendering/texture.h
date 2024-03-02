#pragma once

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

class Texture {
	unsigned int texture;

	public:
		int width, height;
		Texture(const char* path);
		void use();
};