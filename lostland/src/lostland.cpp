#include "lostland.h"

using namespace Engine;

int main(void)
{
    Engine::initialize(800, 600, "LostLand", start, update, exit);
    return 0;
}

Camera* camera;
Scene* main_scene;
GameObject object;

void start() {
    main_scene = new Scene;
    camera = new Camera;
    main_scene->activate_camera(camera);
    Engine::activate_scene(main_scene);

    Transform transform;
    Player player;

    
    

    object = GameObject();
    object.attach(transform);
    object.attach(Map(Texture("src/squares.png")));
    object.attach(player);

    Map* map = object.get_component<Map>();
    map->generateChunk(IVec2(0, 0));
    map->generateChunk(IVec2(1, 0));
    map->generateChunk(IVec2(-1, 0));
    map->generateChunk(IVec2(0, 1));
    map->generateChunk(IVec2(0, -1));

    if (object.get_component<Transform>() == NULL) {
        std::cout << "Somthing went wrong" << std::endl;
    }

    main_scene->instatiate(&object);

    
}

void update() {
    std::cout << std::fixed << std::setprecision(2) << "\rFPS: " << 1. / Time::delta_time;
}

void exit() {
    delete main_scene;
    delete camera;
}