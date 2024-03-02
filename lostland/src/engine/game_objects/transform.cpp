#include "transform.h"

glm::mat4 Transform::matrix() {
	glm::mat4 trans = glm::mat4(1.0f);

	trans = glm::translate(trans, glm::vec3(position.x, position.y, (float)z_index)); // z_index here is a temporary solution

	trans = glm::rotate(trans, rotation, glm::vec3(0.0, 0.0, -1.0));

	trans = glm::scale(trans, glm::vec3(scale.x, scale.y, 1.0));

	return trans;
}