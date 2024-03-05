#include <glad.c>

#include "engine.h"

using namespace Engine;

bool Engine::initialize(unsigned int width, unsigned int height, const char* title, void (*start)(), void (*update)(), void (*exit)()) {
    // initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // window creation
    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, Engine::framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    // Setting blending parameters
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    Input::init();

    start();

    while (!glfwWindowShouldClose(window)) {
        Input::processInput(window);
        Time::update_time();
        update();
        Engine::render();
    }

    exit();
    glfwTerminate();
    return true;
}

void Engine::quit() {
    glfwSetWindowShouldClose(window, 1);
}

void Engine::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    active_scene->render();

    // swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Engine::activate_scene(Scene* scene) {
    active_scene = scene;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void Engine::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}