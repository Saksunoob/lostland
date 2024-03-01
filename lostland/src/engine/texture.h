#pragma once

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

class Texture {
	unsigned int texture;

	public:
		Texture(const char* path);
		void use();
};