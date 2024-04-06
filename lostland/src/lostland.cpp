#include "lostland.h"

using namespace Engine;

int main(void)
{
    Engine::initialize(IVec2(800, 600), "LostLand", start, update, exit);
    return 0;
}

Camera* camera;
Scene* main_scene;

void start() {
    main_scene = new Scene;
    camera = new Camera;
    main_scene->activate_camera(camera);
    Engine::activate_scene(main_scene);

    GameObject* object = main_scene->instatiate();
    Transform* transform = object->attach(Transform());
    Map* map = object->attach(Map(Texture("src/squares.png")));
    Player* player = object->attach(Player());

    map->generateChunk(IVec2(0, 0));
    map->generateChunk(IVec2(1, 0));
    map->generateChunk(IVec2(-1, 0));
    map->generateChunk(IVec2(0, 1));
    map->generateChunk(IVec2(0, -1));
}

void update() {
    std::cout << std::fixed << std::setprecision(2) << "\rFPS: " << 1. / Time::delta_time;
}

void exit() {
    delete main_scene;
    delete camera;
}