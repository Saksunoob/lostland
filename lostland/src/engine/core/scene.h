#pragma once

#include "camera.h"

using namespace Engine;

namespace Engine {
	namespace GameObjects {
		class GameObject;
	}

	class Scene {
	private:
		GameObjects::GameObject* root;
	public:
		Camera* active_camera = nullptr;

		Scene();
		void render();
		void update();
		GameObjects::GameObject* instatiate(GameObjects::GameObject* parent = nullptr);
		void activate_camera(Camera* camera);
	};
}