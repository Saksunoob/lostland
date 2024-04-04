#include "game_object.h"

using namespace Engine::GameObjects;

void GameObject::update() {
    for (auto& it : components) {
        it->update();
    }
}

void GameObject::render(Camera* camera) {
    for (auto& it : components) {
        it->render(camera);
    }
}