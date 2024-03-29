#pragma once

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>
#include <vector>
#include "../game_objects/transform.h"

namespace Engine {
	namespace Rendering {
		class Texture {
			unsigned int texture;

		public:
			int width, height;
			Texture(const char* path);
			void use();
		};
	}
}
