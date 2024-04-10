#pragma once

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

namespace Engine {
	namespace Rendering {
		class Texture {
		public:
			unsigned int texture;
			int width, height;
			Texture(const char* path);
			void use(unsigned texture_slot);
		};
	}
}
