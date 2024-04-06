#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../core.h"

namespace Engine {
	namespace GameObjects {
		class Transform : public Component {
			glm::mat4 global_transform;
		public:
			Vec2 position, scale;
			int z_index;
			double rotation;

			Transform();

			void update();
			glm::mat4 matrix();
			glm::mat4 local_matrix();
		};
	}
}

