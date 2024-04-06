#include "camera.h"

glm::mat4 Engine::GameObjects::Camera::matrix() {
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	double v_x = (double)viewport[2];
	double v_y = (double)viewport[3];

	glm::mat4 proj = glm::ortho(-v_x / 2., v_x / 2., -v_y / 2., v_y / 2., 0., 100.);
	proj = glm::scale(proj, glm::vec3(zoom, zoom, 1.));
	proj = glm::translate(proj, glm::vec3(-pos.x, -pos.y, 0.));

	return proj;
}