#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "gfx/shader.hpp"
#include "gfx/render.hpp"
#include "gfx/texture.hpp"
#include "gfx/window.hpp"

#include "uti/camera.hpp"

#include <iostream>
#include <vector>

// screen setting
const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

void updateDeltaTime();
int main() {

    //camera
    vec3 cameraPos = {0.0f, 0.0f, 3.0f};
    Camera camera(cameraPos); //create camera with default cameraPos

    Window window(SCR_WIDTH, SCR_HEIGHT, &camera);
    if (!window.init()) {
        return -1;  // If window initialization failed, exit
    }
    window.setCallbacks();

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    

    vec3 cubePositions[] = {
        {0.0f, 0.0f, 0.0f},    
        { 0.0f,  0.0f,  0.0f},
        { 2.0f,  5.0f, -15.0f},
        {-1.5f, -2.2f, -2.5f},
        {-3.8f, -2.0f, -12.3f},
        {2.4f, -0.4f, -3.5f},
        {-1.7f,  3.0f, -7.5f},
        { 1.3f, -2.0f, -2.5f},
        { 1.5f,  2.0f, -2.5f},
        { 1.5f,  0.2f, -1.5f},
        {-1.3f,  1.0f, -1.5}
    };

    // Create Shader
    Shader myShader(ASSETS_DIR "shaders/testShader.vs", ASSETS_DIR "shaders/testShader.fs");

    // Create Render
    Render render;

    // Create Texture
    Texture texture(ASSETS_DIR "images/cat.jpg");    //this will hold an vector array of Textures
    
    // Set the texture uniform
    myShader.use();

    texture.bind();
    myShader.setInt("texture1", 0);

    // Render loop
    while (!glfwWindowShouldClose(window.window)) {
        //get current Time
        updateDeltaTime();

        // checks input
        window.processInput(&camera, deltaTime);
        
        // render 
        glClearColor(1.0f, 1.0f, 1.0f, 0.5f);   //background color?
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // activate shader
        myShader.use(); //use shader

        //Set up M_View
        mat4 M_view;    
        camera.get_view_matrix(M_view);
        myShader.setMat4("M_view", M_view);

        //Set up M_projection
        mat4 M_projection;    
        glm_perspective(glm_rad(camera.fov), (float)SCR_WIDTH/(float)SCR_HEIGHT, 0.1f, 80.0f, M_projection);
        myShader.setMat4("M_projection", M_projection);

        for(int i = 1; i < 10; i++)
        {
            texture.bind();   // Bind texture1 (shiina.jpg) to texture unit 0 for other cubes

            //Set up M_Model
            mat4 M_model;
            glm_mat4_identity(M_model);   //basically 1.0f
            glm_translate(M_model, cubePositions[i]);

            // float angle = (float)glfwGetTime(); // get the time for animated rotation
            float angle = 20.0f * i;
            glm_rotate(M_model, glm_rad(angle) * (float)glfwGetTime(), vec3{1.0f, 0.0f, 0.0f}); // rotating around the x axis

            myShader.setMat4("M_model", M_model);

            render.draw();
        }

        // Swap buffers
        glfwSwapBuffers(window.window);
        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void updateDeltaTime()
{
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}