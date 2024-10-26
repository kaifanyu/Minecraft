#include "world/world.hpp"
#include "gfx/window.hpp"

#include <iostream>
#include <vector>

float deltaTime = 0.0f;
float lastFrame = 0.0f;

void updateDeltaTime();


int main() {

    World world;    //Create the world object
    Window window(&world.getCamera());  //create window with world.camera object

    if (!window.init())
        return -1;  // If window initialization failed, exit

    world.init_world(); //init the world
    // Enable face culling
    glEnable(GL_CULL_FACE);
    // Specify which faces to cull (GL_BACK culls the back faces)
    glCullFace(GL_BACK);
    // Set the winding order (default is GL_CCW, counter-clockwise)

    // Render loop
    while (!glfwWindowShouldClose(window.window)) {
        //get current Time
        updateDeltaTime();

        world.render_world();
        window.processInput(world.getCamera(), deltaTime);

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