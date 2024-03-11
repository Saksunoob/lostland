#pragma once

#include <vector>
#include <unordered_map>
#include <typeinfo>

#include "../rendering/texture.h"
#include "../rendering/shader.h"
#include "camera.h"

using namespace Engine::Rendering;

namespace Engine {
    namespace GameObjects {
        class GameObject;

        class Component {
        public:
            GameObject* object;
            Component() {
                object = nullptr;
            }
            virtual void attach() {};
            virtual void update() {};
            virtual void render(Camera* camera) {};
        };
        class GameObject {
        public:
            std::unordered_map<std::size_t, std::unique_ptr<Component>> components;
            template <class T>
            void attach(T component) {
                std::size_t id = typeid(T).hash_code();
                components[id] = std::make_unique<T>(std::move(component));
                components[id].get()->object = this;
                components[id].get()->attach();
            };

            void update() {
                for (auto& it : components) {
                    it.second.get()->update();
                }
            }

            void render(Camera *camera) {
                for (auto& it : components) {
                    it.second.get()->render(camera);
                }
            }

            template <class T>
            T* get_component() {
                return static_cast<T*>(components[typeid(T).hash_code()].get());
            };
        };

        class SpriteRenderer : public Component {
            static Shader shader;
            static unsigned int VAO;
            static void initialize();
        public:
            Texture texture;
            SpriteRenderer();
            SpriteRenderer(Texture texture);

            void render(Camera* camera);
        };
    }
}