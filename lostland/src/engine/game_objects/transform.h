#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"

class Vec2 {
public:
	float x, y;
	Vec2(float x, float y) : x(x), y(y) {}
};

class Transform {
public:
	Vec2 position, scale;
	float rotation;
	int z_index;
	Transform()
		: position(0.0, 0.0),
		rotation(0.0),
		scale(1.0, 1.0),
		z_index(0) {}

	glm::mat4 matrix();
};
