#include <glad.c>

#include "engine.h"

using namespace Engine;

extern SDL_Window* Engine::window = nullptr;
extern SDL_GLContext Engine::context = NULL;
extern Engine::Scene* Engine::active_scene = nullptr;

bool Engine::initialize(IVec2 window_size, const char* title, void (*start)(), void (*update)(), void (*exit)()) {
    // initialize and configure
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError();
        return false;
    }

    SDL_GL_LoadLibrary(NULL);

    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // window creation
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_size.x, window_size.y, SDL_WINDOW_OPENGL);

    if (window == NULL)
    {
        std::cout << "SDL window could not initialize! SDL_Error: " << SDL_GetError();
        return false;
    }

    
    context = SDL_GL_CreateContext(window);

    if (context == NULL)
    {
        std::cout << "Failed to create OpenGL context";
        return false;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        std::cout << "Failed to initialize GLAD";
        return false;
    }

    // Setting blending parameters
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    start();

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        Time::update_time();
        active_scene->update();
        update();
        Engine::render();
        Input::newFrame();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            Input::processInputEvent( event );
        }
    }

    exit();
    SDL_Quit();
    return true;
}

void Engine::quit() {
    SDL_DestroyWindow(window);
}

void Engine::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    active_scene->render();

    // swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    SDL_GL_SwapWindow(window);
}

void Engine::activate_scene(Scene* scene) {
    active_scene = scene;
}