#include "camera.h"

using namespace Engine;
using namespace Engine::GameObjects;

glm::mat4 Engine::Camera::matrix() {
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	double v_x = (double)viewport[2];
	double v_y = (double)viewport[3];

	Transform* transform = object->get_component<Transform>();

	glm::mat4 proj = glm::ortho(-v_x / 2., v_x / 2., -v_y / 2., v_y / 2., std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
	proj = glm::scale(proj, glm::vec3(transform->scale.x, transform->scale.y, 1.));
	proj = glm::rotate(proj, (float)transform->rotation, glm::vec3(0., 0., 1.));
	proj = glm::translate(proj, glm::vec3(-transform->position.x, -transform->position.y, 0));

	return proj;
}

Vec2 Camera::screen_to_worldspace(IVec2 screen_pos) {
	IVec2 window_size;
	SDL_GetWindowSize (Engine::window, &window_size.x, &window_size.y);
	window_size /= 2;
	screen_pos -= window_size;
	Vec2 screen_UV = Vec2((double)screen_pos.x / (double)window_size.x, (double)screen_pos.y / (double)window_size.y);
	glm::vec4 vec = glm::inverse(matrix()) * glm::vec4(screen_UV.x, -screen_UV.y, 1.0, 1.0);
	return Vec2(vec.x, vec.y);
}