#include "game_object.h"

using namespace Engine::GameObjects;

void GameObject::update() {
    for (auto& it : components) {
        it->update();
    }
}

void GameObject::render() {
    for (auto& it : components) {
        it->render();
    }
}