#pragma once

#include "game_object.h"
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
            Texture texture;
            SpriteRenderer() : texture(Texture("")) {
                if (SpriteRenderer::shader.ID == NULL) { // Initialize shader
                    initialize();
                }
            };
            SpriteRenderer(Texture texture) : texture(texture) {
                if (SpriteRenderer::shader.ID == NULL) { // Initialize shader
                    initialize();
                }
            };

            void render(Camera* camera);
        };

        class TileMapRenderer : public SpriteRenderer {
            static Shader shader;
            static void initialize();
        public:
            unsigned int width, height;
            unsigned int cell_width, cell_height;
            unsigned int* tiles;

            TileMapRenderer(Texture atlas, unsigned int width, unsigned int height, unsigned int cell_width, unsigned int cell_height) : 
                SpriteRenderer(atlas), width(width), height(height), cell_width(cell_width), cell_height(cell_height), tiles(std::vector<unsigned int>(width* height, 0).data())
            {
                __super::initialize();
                if (TileMapRenderer::shader.ID == NULL) { // Initialize shader
                    initialize();
                }
            };

            void render(Camera* camera);
        };
    }
}

