#include <glad.c>

#include "engine.h"

Engine::Engine(unsigned int width, unsigned int height, const char* title) {
    // initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // window creation
    window = glfwCreateWindow(width, height, title, NULL, NULL);
}

bool Engine::run()
{
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

    Shader shaderProgram("src/engine/shaders/vertex_shader.glsl", "src/engine/shaders/fragment_shader.glsl");

    float vertices[] = {
        // positions         // texCoords
         0.5f,  0.5f, 0.0f,  1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,  0.0f, 1.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,  1.0f, 0.0f    // top left
    };
    unsigned int indices[] = {
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    Texture texture("src/engine/missing_texture.png");


    shaderProgram.use();
    shaderProgram.setInt("texture_image", 0);

    Transform transform;
    transform.position.x += 0.;
    transform.position.z = -0.2;
    //transform.rotation.z += 3.14159265358979323846/4.;
    transform.scale.x = 500.;
    transform.scale.y = 250.;

    Camera camera;
    camera.x += 100;
    camera.zoom = 0.5;

    shaderProgram.setMatrix4f("transform", transform.matrix());
    shaderProgram.setMatrix4f("projection", camera.matrix());


    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        texture.use();
        shaderProgram.use();

        // Bind array
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // Unbind array
        glBindVertexArray(0);

        // swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // de-allocate all resources once they've outlived their purpose:
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glff terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return true;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void Engine::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void Engine::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}