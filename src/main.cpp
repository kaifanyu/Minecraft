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
        -0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f, -0.5f,  0.5f, 
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 

        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 

         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  

        -0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f, -0.5f,  0.5f,  
        -0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, 
    };
  
    // Create Shader
    Shader colorShader(ASSETS_DIR "shaders/color.vs", ASSETS_DIR "shaders/color.fs");
    Shader cubeShader(ASSETS_DIR "shaders/lightShader.vs", ASSETS_DIR "shaders/lightShader.fs");

    // Create Render
    Render render(vertices);
    Render cube(vertices);
    // Render loop
    while (!glfwWindowShouldClose(window.window)) {
        //get current Time
        updateDeltaTime();

        // checks input
        window.processInput(&camera, deltaTime);
        
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // background color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // render 
        colorShader.use();
        colorShader.setVec3("objectColor", {1.0f, 0.5f, 0.31f});
        colorShader.setVec3("lightColor", { 1.0f, 1.0f, 1.0f});


        //Set up for colorShader
        mat4 M_view, M_projection;    
        camera.get_view_matrix(M_view); //M_View
        glm_perspective(glm_rad(camera.fov), (float)SCR_WIDTH/(float)SCR_HEIGHT, 0.1f, 80.0f, M_projection);    //M_projection

        //Set up M_Model
        mat4 M_model;
        glm_mat4_identity(M_model);
        colorShader.setMat4("model", M_model);
        colorShader.setMat4("view", M_view);
        colorShader.setMat4("projection", M_projection);

        render.draw(); //draw render


        cubeShader.use();
        mat4 cube_model;

        glm_mat4_identity(cube_model);
        glm_translate(cube_model, lightPos);
        glm_scale_uni(cube_model, 0.2f);
        cubeShader.setMat4("model", cube_model);
        cubeShader.setMat4("view", M_view);
        cubeShader.setMat4("projection", M_projection);

        cube.draw();


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