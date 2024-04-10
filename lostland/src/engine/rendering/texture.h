#pragma once

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

namespace Engine {
	namespace Rendering {
		class Texture {
			unsigned int texture;

		public:
			int width, height;
			Texture(const char* path);
			void use(unsigned texture_slot);
		};
	}
}
