#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"

class Vec3 {
public:
	float x, y, z;
	Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
};

class Transform {
public:
	Vec3 position, rotation, scale;
	Transform()
		: position(0.0, 0.0, 0.0),
		rotation(0.0, 0.0, 0.0),
		scale(1.0, 1.0, 1.0) {}

	glm::mat4 matrix();
};
