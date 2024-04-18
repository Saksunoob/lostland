#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../core.h"

namespace Engine {
	namespace GameObjects {
		class Transform : public Component {
			Vec2 global_position, global_scale;
			double global_rotation;
		public:
			Vec2 position, scale;
			int z_index;
			double rotation;

			Transform();

			void update();
			glm::mat4 matrix();
		};
	}
}

