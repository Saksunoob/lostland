#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

namespace Engine {
	namespace GameObjects {
		class Camera {
		public:
			float x, y, zoom;
			Camera() : x(0), y(0), zoom(1) {};
			glm::mat4 matrix();
		};
	}
}
