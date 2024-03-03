#include "game_object.h"

using namespace Engine::GameObjects;

const float Sprite::vertices[5 * 4] = {
    // positions         // texCoords
     0.5f,  0.5f, 0.0f,  1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,  0.0f, 1.0f    // top left
};
const unsigned int Sprite::indices[6] = {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

unsigned int Sprite::VBO = NULL;
unsigned int Sprite::VAO = NULL;
unsigned int Sprite::EBO = NULL;
Shader Sprite::SPRITE_SHADER = Shader((unsigned int)0);

void Sprite::render(Camera *camera) {
    shader.use();

    texture.use();
    Transform modified_transform = transform;
    
    modified_transform.scale.x *= texture.width;
    modified_transform.scale.y *= texture.height;
    shader.setMatrix4f("transform", modified_transform.matrix());
    shader.setMatrix4f("projection", camera->matrix());

    // Bind array
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // Unbind array
    glBindVertexArray(0);
}