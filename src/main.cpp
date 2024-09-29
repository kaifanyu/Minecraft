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

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);


// screen setting
const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

//camera
vec3 cameraPos = {0.0f, 0.0f, 3.0f};

Camera camera(cameraPos); //create camera with default cameraPos

//mouse 
bool firstMouse = true;
float yaw = -90.0f;     //left / right direction. Starting at -90 to face straight?
float pitch = 0.0f;     //up / down
float fov = 45.0f;
float lastX = 8000.0f / 2.0;
float lastY = 600.0f / 2.0;

float deltaTime = 0.0f;
float lastFrame = 0.0f;


using namespace std;
int main() {


    Window window(SCR_WIDTH, SCR_HEIGHT);
    if (!window.init())
    {
        printf("Failed to initialize window");
        return -1;
    };

    window.setCallbacks();
    // // Initialize GLFW
    // if (!glfwInit()) {
    //     return -1;
    // }
    // // Request OpenGL 4.2 with the Core profile
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // // Create a windowed mode window and its OpenGL context
    // GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Walmart Minecraft", NULL, NULL);
    
    // if (!window) {
    //     printf("Failed to create GLFW window\n");
    //     glfwTerminate();
    //     return -1;
    // }

    // // Make the window's context current
    // glfwMakeContextCurrent(window);

    // // Load OpenGL functions with GLAD
    // if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    //     printf("Failed to initialize GLAD\n");
    //     return -1;
    // }
    
    // // whenever the window changes in size, gflw calls this function and fills in proper arguments
    // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // // mouse cursor movement
    // glfwSetCursorPosCallback(window, mouse_callback);
    // // mouse scroll movement
    // glfwSetScrollCallback(window, scroll_callback);
    // // capture mouse
    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    

    std::vector<GLfloat> triangle = {
        //back square    
            // back triangle
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            //other back traingle
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        //front square
            //front triangle
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            // other front triangle
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

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
    Render render(triangle);

    // Create Texture
    Texture texture(ASSETS_DIR "images/shiina.jpg");    //this will hold an vector array of Textures
    
    // Set the texture uniform
    myShader.use();
    texture.bind(0);
    myShader.setInt("texture1", 0);


    // Render loop
    while (!glfwWindowShouldClose(window.window)) {
        //get current Time
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;   
        lastFrame = currentFrame;

        // checks input
        window.processInput(camera, deltaTime);
        
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

            texture.bind(0);   // Bind texture1 (shiina.jpg) to texture unit 0 for other cubes

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

// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
//     //tells OpenGL how to map to NDC space to the corresponding width + height
//     glViewport(0, 0, width, height);    
// }

// void processInput(GLFWwindow* window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//         camera.process_keyboard(FORWARD, deltaTime);
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//         camera.process_keyboard(BACKWARD, deltaTime);
//     if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//         camera.process_keyboard(LEFT, deltaTime);
//     if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//         camera.process_keyboard(RIGHT, deltaTime);
// }

// void mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
// {
//     float xpos = static_cast<float>(xposIn);    //convert double to float
//     float ypos = static_cast<float>(yposIn);

//     if(firstMouse)  //init mouse
//     {
//         lastX = xpos;
//         lastY = ypos;
//         firstMouse = false;
//     }

//     float xoffset = xpos - lastX;
//     float yoffset = lastY - ypos;   //y go from bottom to top
    
//     float sens = 0.05f;
//     xoffset *= sens;
//     yoffset *= sens;
    
//     lastX = xpos;
//     lastY = ypos;

//     camera.process_mouse_camera(xoffset, yoffset);
// }

// void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
// {
//     camera.process_scroll_camera(static_cast<float>(xoffset), static_cast<float>(yoffset));
// }