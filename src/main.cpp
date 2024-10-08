#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "gfx/shader.hpp"
#include "gfx/render.hpp"
#include "gfx/texture.hpp"
#include "gfx/window.hpp"

#include "uti/camera.hpp"

#include "world/chunk.hpp"
#include "world/block.hpp"

#include <map>


#include <ft2build.h>
#include FT_FREETYPE_H


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
    vec3 starting_cameraPos = {0.0f, 0.0f, 0.0f}; //start at 3


    Camera camera(starting_cameraPos); //create camera with default cameraPos
    Window window(SCR_WIDTH, SCR_HEIGHT, &camera);  //create window with camera object

    if (!window.init())
        return -1;  // If window initialization failed, exit
    window.setCallbacks();  //set callbacks for resize, cursor inputs

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);

    Block dirtBlock(DIRT);

    // Create Shader
    Shader cubeShader(ASSETS_DIR "shaders/cube.vs", ASSETS_DIR "shaders/cube.fs");
    Texture blockTextures(ASSETS_DIR "images/cat.jpg");

    // Create Render
    Render cube_render(dirtBlock.vertices, dirtBlock.attribute_count);

    glEnable(GL_CULL_FACE);         // Enable face culling
    glCullFace(GL_BACK);            // Cull back faces (default)
    // Render loop
    while (!glfwWindowShouldClose(window.window)) {
        //get current Time
        updateDeltaTime();

        // checks input
        window.processInput(&camera, deltaTime);
        
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // background color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        vec3 lightPos = {1.2f, 1.0f, 2.0f}; //temp
        vec3 blockPos = {0.0f, 0.0f, -3.0f};  //want block to be here?

        
        blockTextures.bind(cubeShader.ID);
        // render + lightring for cubeShader
        cubeShader.use();
        cubeShader.setVec3("lightColor", { 1.0f, 1.0f, 1.0f});
        cubeShader.setVec3("lightPos", lightPos);

        //M_model tells OpenGL where the object is in the world: Move / Rotate / scale object
        mat4 M_model;   //transforms object from original space to world space. 
        glm_mat4_identity(M_model); //init the model to identity matrix so we can do calculations
        glm_translate(M_model, blockPos);   //translate the model to blockPos

        //M_view represents camera's position and direction. Defines how world looks from view of camera
        mat4 M_view;
        camera.get_view_matrix(M_view); //get the view_matrix by 
        
        //M_projection defines how the 3D world is projected onto the 2D screen. Define FOV, aspect ratio, how far / close objects should appear
        mat4 M_projection;    
        glm_perspective(glm_rad(camera.fov), (float)SCR_WIDTH/(float)SCR_HEIGHT, 0.1f, 80.0f, M_projection);    //M_projection
        cubeShader.setMat4("model", M_model);
        cubeShader.setMat4("view", M_view);
        cubeShader.setMat4("projection", M_projection);
        cubeShader.setVec3("viewPos", camera.cameraPos);

        cube_render.draw(); //draw render
        
        // printf("CameraPos: X:%f Y:%f Z:%f\n", camera.cameraPos[0], camera.cameraPos[1], camera.cameraPos[2]);
        // printf("CameraUp: X:%f Y:%f Z:%f\n", camera.cameraUp[0], camera.cameraUp[1], camera.cameraUp[2]);
        // printf("CameraFront: X:%f Y:%f Z:%f\n", camera.cameraFront[0], camera.cameraFront[1], camera.cameraFront[2]);
        
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