#pragma once

#include <vector>
#include <unordered_map>
#include <typeinfo>
#include <memory>

#include "camera.h"

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
            std::vector<std::unique_ptr<Component>> components;
            template <class T>
            T* attach(T component) {
                components.push_back(std::make_unique<T>(std::move(component)));
                components.back()->object = this;
                components.back()->attach();
                return static_cast<T*>(components.back().get());
            };

            template <class T>
            T* get_component() {
                for (auto& it : components) {
                    if (dynamic_cast<T*>(it.get())) {
                        return static_cast<T*>(it.get());
                    }
                }
                return NULL;
            };

            void update();
            void render();
        };
    }
}