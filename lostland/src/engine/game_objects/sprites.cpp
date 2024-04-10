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

    texture.use(0);
    Transform modified_transform = *object->get_component<Transform>();

    modified_transform.scale.x *= texture.width;
    modified_transform.scale.y *= texture.height;
    shader.setMatrix4f("transform", modified_transform.matrix());

    shader.setMatrix4f("projection", Engine::active_scene->active_camera->matrix());

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

TileMapRenderer::TileMapRenderer(Texture atlas, IVec2 grid_size, IVec2 cell_size) :
    SpriteRenderer(atlas), grid_size(grid_size), cell_size(cell_size), tiles(new unsigned int[grid_size.x*grid_size.y]), tiles_changed(true), tiles_texture(Texture(""))
{
    __super::initialize();
    if (TileMapRenderer::shader.ID == NULL) { // Initialize shader
        initialize();
        update_tiles_texture();
    }
}

void TileMapRenderer::update_tiles_texture() {
    glDeleteTextures(1, &tiles_texture.texture);

    glActiveTexture(GL_TEXTURE1);
    glGenTextures(1, &tiles_texture.texture);
    glBindTexture(GL_TEXTURE_2D, tiles_texture.texture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R32UI, grid_size.x, grid_size.y, 0, GL_RED_INTEGER, GL_UNSIGNED_INT, tiles);
    tiles_changed = false;
}

void TileMapRenderer::setTiles(unsigned* new_tiles) {
    delete[] tiles;
    tiles = new_tiles;
    tiles_changed = true;
}

void TileMapRenderer::setTile(unsigned index, unsigned value) {
    tiles[index] = value;
    tiles_changed = true;
}


void TileMapRenderer::render() {

    auto StartTime = std::chrono::system_clock::now();

    shader.use();

    texture.use(0);
    Transform modified_transform = *object->get_component<Transform>();

    // Set tiles texture

    if (tiles_changed) {
        update_tiles_texture();
    }
    tiles_texture.use(1);


    modified_transform.scale.x *= grid_size.x * cell_size.x;
    modified_transform.scale.y *= grid_size.y * cell_size.y;
    shader.setMatrix4f("transform", modified_transform.matrix());

    shader.setMatrix4f("projection", Engine::active_scene->active_camera->matrix());

    shader.setUVec2("atlas_size", glm::uvec2(texture.width/cell_size.x, texture.height/cell_size.y));
    shader.setUVec2("grid_size", glm::uvec2(grid_size.x, grid_size.y));

    // Bind array
    glBindVertexArray(__super::VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // Unbind array
    glBindVertexArray(0);
}