#pragma once

#include <vector>
#include <algorithm>
#include "scene.h"

using namespace Engine;

namespace Engine {
    namespace GameObjects {
        class GameObject;

        class Component {
        public:
            GameObject* object;
            Component() : object(nullptr) {};
            virtual void attach() {};
            virtual void update() {};
            virtual void render() {};
        };
        class GameObject {
        public:
            Scene* scene;
            GameObject* parent;
            std::vector<GameObject*> children;
            std::vector<Component*> components;

            template <class T>
            T* attach(T component) {
                T* n_component = new T(component);
                components.push_back(n_component);
                components.back()->object = this;
                components.back()->attach();
                return static_cast<T*>(components.back());
            };

            template <class T>
            T* get_component() {
                for (Component* component : components) {
                    if (dynamic_cast<T*>(component)) {
                        return static_cast<T*>(component);
                    }
                }
                return nullptr;
            };

            void add_child(GameObject* child);
            void remove_child(GameObject* child);
            ~GameObject();
            void update();
            void render();
        };
    }
}