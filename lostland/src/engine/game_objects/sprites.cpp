#include "sprites.h"

using namespace Engine::GameObjects;

Shader SpriteRenderer::shader = Shader((unsigned int)NULL);
unsigned int SpriteRenderer::VAO = NULL;

void SpriteRenderer::initialize() {
    float vertices[5 * 4] = {
        // positions         // texCoords
         0.5f,  0.5f, 0.0f,  1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f    // top left
    };
    unsigned int indices[6] = {
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    Shader shaderProgram("src/engine/rendering/shaders/sprite");

    static unsigned int VBO, EBO;

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

    SpriteRenderer::shader = shaderProgram;

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

SpriteRenderer::SpriteRenderer() : texture(Texture("")) {
    if (SpriteRenderer::shader.ID == NULL) { // Initialize shader
        initialize();
    }
};
SpriteRenderer::SpriteRenderer(Texture texture) : texture(texture) {
    if (SpriteRenderer::shader.ID == NULL) { // Initialize shader
        initialize();
    }
};

void SpriteRenderer::render() {
    shader.use();

    texture.use();
    Transform modified_transform = *object->get_component<Transform>();

    modified_transform.scale.x *= texture.width;
    modified_transform.scale.y *= texture.height;
    shader.setMatrix4f("transform", modified_transform.matrix());

    Camera* camera = Engine::active_scene->active_camera;
    shader.setMatrix4f("projection", camera->matrix());

    // Bind array
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // Unbind array
    glBindVertexArray(0);
}

Shader TileMapRenderer::shader = Shader((unsigned int)NULL);

void TileMapRenderer::initialize() {
    Shader shaderProgram("src/engine/rendering/shaders/tile_map");

    shaderProgram.use();
    shaderProgram.setInt("atlas", 0);
    shaderProgram.setInt("tiles", 1);

    TileMapRenderer::shader = shaderProgram;
}

TileMapRenderer::TileMapRenderer(Texture atlas, unsigned int width, unsigned int height, unsigned int cell_width, unsigned int cell_height) :
    SpriteRenderer(atlas), width(width), height(height), cell_width(cell_width), cell_height(cell_height), tiles(std::vector<unsigned int>(width* height, 0).data()) 
{
    __super::initialize();
    if (TileMapRenderer::shader.ID == NULL) { // Initialize shader
        initialize();
    }
}

void TileMapRenderer::render() {
    shader.use();

    texture.use();
    Transform modified_transform = *object->get_component<Transform>();

    // Set tiles texture

    unsigned int tiles_texture;

    glActiveTexture(GL_TEXTURE1);
    glGenTextures(1, &tiles_texture);
    glBindTexture(GL_TEXTURE_2D, tiles_texture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R32UI, width, height, 0, GL_RED_INTEGER, GL_UNSIGNED_INT, tiles);

    glBindTexture(GL_TEXTURE_2D, tiles_texture);


    modified_transform.scale.x *= cell_width * width;
    modified_transform.scale.y *= cell_height * height;
    shader.setMatrix4f("transform", modified_transform.matrix());

    Camera* camera = Engine::active_scene->active_camera;
    shader.setMatrix4f("projection", camera->matrix());

    shader.setUVec2("atlas_size", glm::uvec2(texture.width/cell_width, texture.height/cell_height));

    // Bind array
    glBindVertexArray(__super::VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // Unbind array
    glBindVertexArray(0);
    // Delete texture
    glDeleteTextures(1, &tiles_texture);
}