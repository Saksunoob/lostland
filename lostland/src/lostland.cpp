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
    camera_obj->attach(Transform());
    camera = camera_obj->attach(Camera());

    main_scene->activate_camera(camera);

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
    Vec2 mouse_pos = camera->screen_to_worldspace(Input::get_mouse_pos());
    std::cout << " mouse: (" << mouse_pos.x << ", " << mouse_pos.y << ")\t";
}

void exit() {
    delete main_scene;
    delete camera;
}