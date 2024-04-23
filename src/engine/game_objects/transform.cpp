#include "transform.h"

using namespace Engine::GameObjects;

Transform::Transform() : 
	global_position(0.0, 0.0),
	global_rotation(0.0),
	global_scale(1.0, 1.0),
	position(0.0, 0.0),
	rotation(0.0),
	scale(1.0, 1.0),
	z_index(0) 
{}

void Transform::update() {
	Transform* parent = object->parent->get_component<Transform>();
	Transform* default_transform = new Transform();
	if (parent == nullptr) {
		parent = default_transform;
	}
	double sin_r = sin(parent->global_rotation);
	double cos_r = cos(parent->global_rotation);
	global_position = parent->global_position + parent->global_scale * Vec2(position.x * cos_r - position.y * sin_r, position.x * sin_r + position.y * cos_r);
	global_scale = parent->global_scale * scale;
	global_rotation = parent->global_rotation + rotation;

	delete default_transform;
}

glm::mat4 Transform::matrix() {
	update();
	glm::mat4 trans = glm::mat4(1.0f);

	trans = glm::translate(trans, glm::vec3(global_position.x, global_position.y, z_index));
	trans = glm::rotate(trans, (float)global_rotation, glm::vec3(0.0, 0.0, -1.0));
	trans = glm::scale(trans, glm::vec3(global_scale.x, global_scale.y, 1.0));

	return trans;
}