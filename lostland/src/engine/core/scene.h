#pragma once

#include <vector>
#include "../game_objects/game_object.h"
#include "../game_objects/transform.h"
#include <algorithm>

using namespace Engine::GameObjects;

namespace Engine {
	class Scene {
	private:
		std::vector<GameObject*> game_objects;
	public:
		Camera* active_camera = nullptr;
		void render();
		void update();
		void instatiate(GameObject* game_object);
		void remove(GameObject* game_object);
		void activate_camera(Camera* camera);
	};
}