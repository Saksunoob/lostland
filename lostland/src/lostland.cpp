#include "lostland.h"

using namespace Engine;

int main(void)
{
    Engine::initialize(800, 600, "LostLand", start, update, exit);
    return 0;
}

Sprite* missing_texture;
Sprite* tree;
Camera* camera;
Scene* main_scene;

void start() {
    glClearColor(0.1f, 0.1f, 0.5f, 1.0f); // Black by default
    main_scene = new Scene;

    Transform transform;
    transform.position.x = 100;
    transform.z_index = 1;
    transform.scale = Vec2(10., 10.);
    missing_texture = new Sprite(transform, Texture(""));
    main_scene->instatiate(missing_texture);

    transform.position.x = -100;
    transform.z_index = 0;
    transform.scale = Vec2(0.1, 0.1);
    tree = new Sprite(transform, Texture("src/tree.jpg"));
    main_scene->instatiate(tree);

    camera = new Camera;
    main_scene->activate_camera(camera);

    Engine::activate_scene(main_scene);
}

void update() {
    if (Input::get_key_pressed(Input::KEY_D)) {
        missing_texture->transform.position.x += 0.1;
    }
    if (Input::get_key_pressed(Input::KEY_A)) {
        missing_texture->transform.position.x -= 0.1;
    }
    if (Input::get_key_pressed(Input::KEY_W)) {
        missing_texture->transform.position.y += 0.1;
    }
    if (Input::get_key_pressed(Input::KEY_S)) {
        missing_texture->transform.position.y -= 0.1;
    }
}

void exit() {
    delete tree;
    delete missing_texture;
    delete camera;
    delete main_scene;
}