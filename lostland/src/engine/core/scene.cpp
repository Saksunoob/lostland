#include "scene.h"

using namespace Engine;

static bool comapre_z_index(GameObject* a, GameObject* b)
{
	return a->transform.z_index < b->transform.z_index;
}
void Scene::render() {
	std::sort(game_objects.begin(), game_objects.end(), comapre_z_index);
	for (int i = 0; i < game_objects.size(); i++) {
		game_objects[i]->render(active_camera);
	}
}
void Scene::instatiate(GameObject* game_object) {
	game_objects.push_back(game_object);
}
void Scene::remove(GameObject *game_object) {
	auto iterator = std::find(game_objects.begin(), game_objects.end(), game_object);
	if (iterator != game_objects.end()) {
		game_objects.erase(iterator);
	}
}
void Scene::activate_camera(Camera* camera) {
	active_camera = camera;
}