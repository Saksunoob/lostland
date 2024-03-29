#pragma once

#include "game_object.h"
#include "../rendering/texture.h"
#include "../rendering/shader.h"

using namespace Engine::Rendering;

namespace Engine
{
    namespace GameObjects {
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

