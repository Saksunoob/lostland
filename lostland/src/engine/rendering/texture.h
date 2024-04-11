#pragma once

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

#include "../core/vectors.h"

namespace Engine {
	namespace Rendering {
		struct Texture {
			unsigned int texture;
			IVec2 size;
			Texture(const char* path);
			void use(unsigned texture_slot);
		};
		struct TextureAtlas : public Texture {
			IVec2 cell_size;
			TextureAtlas(IVec2 cell_size, Texture texture);
		};
	}
}
