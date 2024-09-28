#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "gfx/shader.hpp"
#include "uti/camera.hpp"

#include <iostream>
#include <cglm/cglm.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);



// screen setting
const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;
        
//camera
vec3 cameraPos = {0.0f, 0.0f, 3.0f};
vec3 cameraFront = {0.0f, 0.0f, -1.0f};
vec3 cameraUp = {0.0f, 1.0f, 0.0f};


//mouse 
bool firstMouse = true;
float yaw = -90.0f;     //left / right direction. Starting at -90 to face straight?
float pitch = 0.0f;     //up / down
float lastX = 8000.0f / 2.0;
float lastY = 600.0f / 2.0;
float fov = 45.0f;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

Camera camera(cameraPos); //create camera with default cameraPos


using namespace std;
int main() {


    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }
    // Request OpenGL 4.2 with the Core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Walmart Minecraft", NULL, NULL);
    
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Load OpenGL functions with GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }
    
    // whenever the window changes in size, gflw calls this function and fills in proper arguments
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // mouse cursor movement
    glfwSetCursorPosCallback(window, mouse_callback);
    // mouse scroll movement
    glfwSetScrollCallback(window, scroll_callback);
    // capture mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    
    // build + compile shader
    Shader myShader("../assets/shaders/testShader.vs", "../assets/shaders/testShader.fs");


    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
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



    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);  // Generate the VAO
    glGenBuffers(1, &VBO);       // Generate the VBO

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    //Texture
    unsigned int texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    // Set texture wrapping and filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char* data = stbi_load("../assets/images/cat.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);



    // Set the texture uniform
    myShader.use();
    myShader.setInt("texture1", 0);


    // Render loop
    while (!glfwWindowShouldClose(window)) {
        //get current Time
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;   
        lastFrame = currentFrame;

        // checks input
        processInput(window);
        
        // render 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // bind textures 
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);

        // activate shader
        myShader.use(); //use shader


        //Set up M_View
        mat4 M_view;    
        glm_mat4_identity(M_view);

        vec3 cameraTarget;
        glm_vec3_add(cameraPos, cameraFront, cameraTarget);
        glm_lookat(cameraPos, cameraTarget, cameraUp, M_view);
        myShader.setMat4("M_view", M_view);

        //Set up M_projection
        mat4 M_projection;    
        glm_perspective(glm_rad(fov), (float)SCR_WIDTH/(float)SCR_HEIGHT, 0.1f, 80.0f, M_projection);
        myShader.setMat4("M_projection", M_projection);

        // printf("T Direction: (%f, %f, %f)\n", cameraTarget[0], cameraTarget[1], cameraTarget[2]);
        // printf("P Direction: (%f, %f, %f)\n", cameraPos[0], cameraPos[1], cameraPos[2]);
        // printf("U Direction: (%f, %f, %f)\n", cameraUp[0], cameraUp[1], cameraUp[2]);

        //render boxes
        glBindVertexArray(VAO);

        for(int i = 1; i < 10; i++)
        {
            //Set up M_Model
            mat4 M_model;
            glm_mat4_identity(M_model);   //basically 1.0f
            glm_translate(M_model, cubePositions[i]);

            // float angle = (float)glfwGetTime(); // get the time for animated rotation
            float angle = 20.0f * i;
            glm_rotate(M_model, glm_rad(angle) * (float)glfwGetTime(), vec3{1.0f, 0.0f, 0.0f}); // rotating around the x axis

            myShader.setMat4("M_model", M_model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        // Swap buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //tells OpenGL how to map to NDC space to the corresponding width + height
    glViewport(0, 0, width, height);    
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    float cameraSpeed = static_cast<float>(2.5f * deltaTime);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        vec3 temp;
        glm_vec3_scale(cameraFront, cameraSpeed, temp);
        glm_vec3_add(cameraPos, temp, cameraPos);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        vec3 temp;
        glm_vec3_scale(cameraFront, cameraSpeed, temp);
        glm_vec3_sub(cameraPos, temp, cameraPos);
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        vec3 temp;
        glm_cross(cameraFront, cameraUp, temp);
        glm_normalize(temp);
        glm_vec3_scale(temp, cameraSpeed, temp);
        glm_vec3_sub(cameraPos, temp, cameraPos);
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        vec3 temp;
        glm_cross(cameraFront, cameraUp, temp);  //get the 'right' direction by crossing front and up
        glm_normalize(temp); //normalize temp
        glm_vec3_scale(temp, cameraSpeed, temp); //scale temp by cameraSpeed basically 'incrementing' temp 
        glm_vec3_add(cameraPos, temp, cameraPos); //add 'right' direction to
    }
}


void mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);    //convert double to float
    float ypos = static_cast<float>(yposIn);

    if(firstMouse)  //init mouse
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }


    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;   //y go from bottom to top
    
    float sens = 0.05f;
    xoffset *= sens;
    yoffset *= sens;
    
    lastX = xpos;
    lastY = ypos;

    yaw += xoffset; //change x axis
    pitch += yoffset; //change y axis

    //if pitch is out of bounds, don't flip screen
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    
    vec3 front;
    front[0] = cos(glm_rad(yaw)) * cos(glm_rad(pitch)); //x
    front[1] = sin(glm_rad(pitch));
    front[2] = sin(glm_rad(yaw)) * cos(glm_rad(pitch));

    glm_normalize(front);
    glm_vec3_copy(front, cameraFront);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}