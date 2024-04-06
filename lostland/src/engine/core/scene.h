#pragma once

#include "../game_objects/camera.h"

using namespace Engine::GameObjects;

namespace Engine {
	namespace GameObjects {
		class GameObject;
	}

	class Scene {
	private:
		GameObject* root;
	public:
		Camera* active_camera = nullptr;

		Scene();
		void render();
		void update();
		GameObject* instatiate(GameObject* parent = nullptr);
		void activate_camera(Camera* camera);
	};
}