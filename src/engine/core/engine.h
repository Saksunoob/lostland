#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>


#include "vectors.h"
#include "input.h"
#include "time.h"
#include "scene.h"

namespace Engine {
	extern SDL_Window* window;
	extern SDL_GLContext context;
	extern Scene* active_scene;

	bool initialize(IVec2 window_size, const char* title, void (*start)(), void (*update)(), void (*exit)());
	void quit();
	static void render();
	void activate_scene(Scene* scene);
}


