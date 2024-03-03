#include <glad.c>

#include "engine.h"

bool Engine::initialize(unsigned int width, unsigned int height, const char* title) {
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
}

bool Engine::run()
{
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, Engine::framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    Texture texture("src/engine/rendering/missiexture.png");
    Transform transform;
    transform.position.x = 100.;
    transform.scale = Vec2(50., 50.);

    Sprite sprite1(transform, texture);

    texture = Texture("src/engine/tree.jpg");
    transform.position.x = -100.;
    transform.scale = Vec2(0.1, 0.1);
    Sprite sprite2(transform, texture);

    Camera camera;
    Input input;

    while (!glfwWindowShouldClose(window))
    {
        input.processInput(window);

        if (input.get_key_pressed(KEY_D)) {
            sprite1.transform.position.x += 0.1f;
        }
        if (input.get_key_pressed(KEY_A)) {
            sprite1.transform.position.x -= 0.1f;
        }
        if (input.get_key_pressed(KEY_W)) {
            sprite1.transform.position.y += 0.1f;
        }
        if (input.get_key_pressed(KEY_S)) {
            sprite1.transform.position.y -= 0.1f;
        }

        if (input.get_key_pressed(KEY_E)) {
            sprite1.transform.rotation += 0.001f;
        }
        if (input.get_key_pressed(KEY_Q)) {
            sprite1.transform.rotation -= 0.001f;
        }

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        sprite1.render(camera);
        sprite2.render(camera);

        // swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glff terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return true;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void Engine::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}