#include "game_object.h"

using namespace Engine::GameObjects;

void GameObject::add_child(GameObject* child) {
    children.push_back(child);
}
void GameObject::remove_child(GameObject* child) {
    auto index = std::find(children.begin(), children.end(), child);
    if (index != children.end()) {
        children.erase(index);
    }
}
GameObject::~GameObject() {
    for (GameObject* child : children) {
        child->parent = nullptr;
        delete child;
    }
    for (int i = 0; i < components.size(); i++) {
        delete[] components[i];
    }
    if (parent != nullptr) {
        parent->remove_child(this);
    }
}

void GameObject::update() {
    for (Component* it : components) {
        it->update();
    }
    for (GameObject* child : children) {
        child->update();
    }
}

void GameObject::render() {
    for (Component* it : components) {
        it->render();
    }
    for (GameObject* child : children) {
        child->render();
    }
    
}