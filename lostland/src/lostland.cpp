#include "lostland.h"

using namespace Engine;

int main(void)
{
    Engine::initialize(IVec2(800, 600), "LostLand", start, update, exit);
    return 0;
}

Scene* main_scene;
Camera* camera;

void start() {
    main_scene = new Scene;
    Engine::activate_scene(main_scene);

    GameObject* camera_obj = main_scene->instatiate();
    Transform* transform = camera_obj->attach(Transform());
    transform->scale = Vec2(0.1, 0.1);
    Player* player = camera_obj->attach(Player());
    camera = camera_obj->attach(Camera());

    main_scene->activate_camera(camera);

    GameObject* object = main_scene->instatiate();
    transform = object->attach(Transform());
    Map* map = object->attach(Map(2, TextureAtlas(IVec2(64), Texture("src/ground_tiles.png"))));

    int range = 10;

    for (int y = -range; y < range+1; y++) {
        for (int x = -range; x < range+1; x++) {
            map->generateChunk(IVec2(x, y));
        }
    }
}

void update() {
    std::cout << std::fixed << std::setprecision(2) << "\rFPS: " << 1. / Time::delta_time;
}

void exit() {
    delete main_scene;
    delete camera;
}