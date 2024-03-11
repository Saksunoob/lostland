#include "scene.h"

using namespace Engine;


void Scene::render() {
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