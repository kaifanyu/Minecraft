#include "world/world.hpp"
#include "gfx/window.hpp"

// #include <ft2build.h>
// #include FT_FREETYPE_H

#include <iostream>
#include <vector>

float deltaTime = 0.0f;
float lastFrame = 0.0f;

void updateDeltaTime();

int main() {

    World world;    //Create the world object
    Window window(&world.camera);  //create window with world.camera object

    if (!window.init())
        return -1;  // If window initialization failed, exit
    window.setCallbacks();  //set callbacks for resize, cursor inputs

    // // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    
    // glEnable(GL_CULL_FACE);         // Enable face culling
    // glCullFace(GL_BACK);            // Cull back faces (default)
    
    world.init_world(); //init the world

    // Render loop
    while (!glfwWindowShouldClose(window.window)) {
        //get current Time
        updateDeltaTime();
        
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // background color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        world.init_world(); //init the world

        // checks input
        window.processInput(world.camera, deltaTime);

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