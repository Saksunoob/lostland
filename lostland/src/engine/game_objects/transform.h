#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"

namespace Engine {
	namespace GameObjects {
		class Vec2 {
		public:
			double x, y;
			Vec2(double x, double y) : x(x), y(y) {}
		};

		class Transform {
		public:
			Vec2 position, scale;
			double rotation;
			int z_index;
			Transform()
				: position(0.0, 0.0),
				rotation(0.0),
				scale(1.0, 1.0),
				z_index(0) {}

			glm::mat4 matrix();
		};
	}
}

