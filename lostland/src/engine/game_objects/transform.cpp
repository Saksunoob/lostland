#include "transform.h"

using namespace Engine::GameObjects;

glm::mat4 Transform::matrix() {
	glm::mat4 trans = glm::mat4(1.0f);

	trans = glm::translate(trans, glm::vec3(position.x, position.y, 0.));

	trans = glm::rotate(trans, (float)rotation, glm::vec3(0.0, 0.0, -1.0));

	trans = glm::scale(trans, glm::vec3(scale.x, scale.y, 1.0));

	return trans;
}