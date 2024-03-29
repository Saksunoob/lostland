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

    Transform transform;
    transform.scale = Vec2(50., 50.);
    Texture texture("src/.png");
    SpriteRenderer renderer(texture);
    Player player;
    

    object = GameObject();
    object.attach(transform);
    object.attach(renderer);
    object.attach(player);

    if (object.get_component<Transform>() == NULL) {
        std::cout << "Somthing went wrong" << std::endl;
    }

    main_scene->instatiate(&object);

    Engine::activate_scene(main_scene);
}

void update() {
    std::cout << std::fixed << std::setprecision(2) << "\rFPS: " << 1. / Time::delta_time;
}

void exit() {
    delete main_scene;
    delete camera;
}