#include "scene.h"
#include "game_object.h"

using namespace Engine;

Scene::Scene() : root(new GameObject()) {};

void Scene::render() {
	root->render();
}
void Scene::update() {
	root->update();
}
GameObject* Scene::instatiate(GameObject* parent) {
	parent = parent == nullptr ? root : parent;

	GameObject* object = new GameObject();
	object->parent = parent;
	object->scene = this;
	parent->add_child(object);
	return object;
}
void Scene::activate_camera(Camera* camera) {
	active_camera = camera;
}