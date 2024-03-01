#include "transform.h"

glm::mat4 Transform::matrix() {
	glm::mat4 trans = glm::mat4(1.0f);

	trans = glm::translate(trans, glm::vec3(position.x, position.y, position.z));

	trans = glm::rotate(trans, rotation.x, glm::vec3(1.0, 0.0, 0.0));
	trans = glm::rotate(trans, rotation.y, glm::vec3(0.0, 1.0, 0.0));
	trans = glm::rotate(trans, rotation.z, glm::vec3(0.0, 0.0, 1.0));

	trans = glm::scale(trans, glm::vec3(scale.x, scale.y, scale.z));

	return trans;
}