#pragma once

#include "../core.h"
#include "../rendering/texture.h"
#include "../rendering/shader.h"
#include "transform.h"
#include "camera.h"

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
            unsigned int* tiles;
            bool tiles_changed;
            Texture tiles_texture;

            void update_tiles_texture();
        public:
            IVec2 grid_size;
            IVec2 cell_size;

            void setTiles(unsigned int* new_tiles);
            void setTile(unsigned int index, unsigned int value);

            TileMapRenderer(Texture atlas, IVec2 grid_size, IVec2 cell_size);

            void render();
        };
    }
}

