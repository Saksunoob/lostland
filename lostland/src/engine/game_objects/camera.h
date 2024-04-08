#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

#include "../core/game_object.h"
#include "transform.h"

using namespace Engine::GameObjects;

namespace Engine {
	namespace GameObjects {
		class Camera : public Component {
		public:
			Camera() {};
			glm::mat4 matrix();

			Vec2 screen_to_worldspace(IVec2 screen_pos);
		};
	}
}
