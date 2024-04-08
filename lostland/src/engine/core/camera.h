#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

#include "vectors.h"

namespace Engine {
	class Camera {
	public:
		Vec2 pos;
		float rot, zoom;
		Camera() : pos(Vec2(0)), rot(0), zoom(1) {};
		glm::mat4 matrix();
	};
}
