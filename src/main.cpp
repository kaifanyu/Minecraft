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
const float SCR_WIDTH = 800.0f;
const float SCR_HEIGHT = 600.0f;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

void updateDeltaTime();
int main() {
    vec3 lightPos = {1.2f, 1.0f, 2.0f}; //temp

    // camera
    vec3 cameraPos = {0.0f, 0.0f, 3.0f};
    Camera camera(cameraPos); //create camera with default cameraPos

    // Window
    Window window(SCR_WIDTH, SCR_HEIGHT, &camera);
    if (!window.init())
        return -1;  // If window initialization failed, exit
    window.setCallbacks();

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    
  
    vector<float> vertices = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

    int attribute_count = 6;
  
    // Create Shader
    Shader cubeShader(ASSETS_DIR "shaders/cube.vs", ASSETS_DIR "shaders/cube.fs");
    Shader lightShader(ASSETS_DIR "shaders/light.vs", ASSETS_DIR "shaders/light.fs");

    // Create Render
    Render cube_render(vertices, attribute_count);
    Render light_render(vertices, attribute_count);
    // Render loop
    while (!glfwWindowShouldClose(window.window)) {
        //get current Time
        updateDeltaTime();

        // checks input
        window.processInput(&camera, deltaTime);
        
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // background color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        vec3 lightPos = {1.2f, 1.0f, 2.0f}; //temp

        // render 
        cubeShader.use();
        cubeShader.setVec3("objectColor", {1.0f, 0.3f, 0.31f});
        cubeShader.setVec3("lightColor", { 1.0f, 1.0f, 1.0f});
        cubeShader.setVec3("lightPos", lightPos);

        //Set up for cubeShader
        mat4 M_view, M_projection;    
        camera.get_view_matrix(M_view); //M_View
        glm_perspective(glm_rad(camera.fov), (float)SCR_WIDTH/(float)SCR_HEIGHT, 0.1f, 80.0f, M_projection);    //M_projection

        //Set up M_Model
        mat4 M_model;
        glm_mat4_identity(M_model);
        cubeShader.setMat4("model", M_model);
        cubeShader.setMat4("view", M_view);
        cubeShader.setMat4("projection", M_projection);
        cubeShader.setVec3("viewPos", camera.cameraPos);

        cube_render.draw(); //draw render


        lightShader.use();

        mat4 light_model;

        glm_mat4_identity(light_model);
        glm_translate(light_model, lightPos);
        glm_scale_uni(light_model, 0.2f);
        lightShader.setMat4("model", light_model);
        lightShader.setMat4("view", M_view);
        lightShader.setMat4("projection", M_projection);

        light_render.draw();


        glfwSwapBuffers(window.window); // Swap buffers
        glfwPollEvents();// Poll for and process events
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