#pragma once

#include "transform.h"
#include "../rendering/texture.h"
#include "../rendering/shader.h"

using namespace Engine::Rendering;

namespace Engine {
    namespace GameObjects {
        class GameObject {
        public:
            Transform transform;
            Shader shader;
            GameObject(Transform transform, Shader shader) : transform(transform), shader(shader) {};
            virtual void render(Camera camera) {};
        };

        class Sprite : public GameObject {
            static const float vertices[5 * 4];
            static const unsigned int indices[6];
            static unsigned int VBO, VAO, EBO;
            static Shader SPRITE_SHADER;

        public:
            Texture texture;
            Sprite(Transform transform, Texture texture) : GameObject(transform, SPRITE_SHADER), texture(texture) {
                if (VBO == NULL || VAO == NULL || EBO == NULL) {
                    Shader shaderProgram("src/engine/rendering/shaders/sprite");

                    glGenVertexArrays(1, &VAO);
                    glGenBuffers(1, &VBO);
                    glGenBuffers(1, &EBO);
                    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
                    glBindVertexArray(VAO);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
                    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

                    // position attribute
                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
                    glEnableVertexAttribArray(0);

                    // texture coord attribute
                    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
                    glEnableVertexAttribArray(1);

                    shaderProgram.use();
                    shaderProgram.setInt("texture_image", 0);

                    SPRITE_SHADER = shaderProgram;
                    shader = SPRITE_SHADER;

                    glBindBuffer(GL_ARRAY_BUFFER, 0);
                    glBindVertexArray(0);
                }
            }
            void render(Camera camera) override;
        };
    }
}
