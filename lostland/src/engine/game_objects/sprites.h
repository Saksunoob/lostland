#pragma once

#include "../core.h"
#include "../rendering/texture.h"
#include "../rendering/shader.h"
#include "transform.h"

using namespace Engine::Rendering;

namespace Engine
{
    namespace GameObjects {
        class SpriteRenderer : public Component {
            static Shader shader;
        protected:
            static unsigned int VAO;
            static void initialize();
        public:
            Rendering::Texture texture;
            SpriteRenderer();
            SpriteRenderer(Texture texture);

            void render();
        };

        class TileMapRenderer : public SpriteRenderer {
            static Shader shader;
            static void initialize();
        public:
            unsigned int width, height;
            unsigned int cell_width, cell_height;
            unsigned int* tiles;

            TileMapRenderer(Texture atlas, unsigned int width, unsigned int height, unsigned int cell_width, unsigned int cell_height);

            void render();
        };
    }
}

