#include "window.hpp"
#include "../uti/camera.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>


Window::Window()
{
    SCR_WIDTH = 600;
    SCR_HEIGHT = 800;
    window = nullptr;
    name = "Walmart Minecraft";

    bool firstMouse = true;
    float yaw = -90.0f;     //left / right direction. Starting at -90 to face straight?
    float pitch = 0.0f;     //up / down
    float fov = 45.0f;
    float lastX = SCR_WIDTH / 2.0f;
    float lastY = SCR_HEIGHT / 2.0f;
}


Window::Window(Camera* camera_in)
{
    camera = camera_in;
    SCR_WIDTH = 600;
    SCR_HEIGHT = 800;
    window = nullptr;
    name = "Walmart Minecraft";

    bool firstMouse = true;
    float yaw = -90.0f;     //left / right direction. Starting at -90 to face straight?
    float pitch = 0.0f;     //up / down
    float fov = 45.0f;
    float lastX = (float)SCR_WIDTH / 2.0f;
    float lastY = (float)SCR_HEIGHT / 2.0f;

    printf("Created window\n");
}




bool Window::init()
{
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return false;
    }
    // Request OpenGL 4.2 with the Core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, name, NULL, NULL);

    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return false;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Load OpenGL functions with GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return false;
    }
    
    glfwSetWindowUserPointer(window, this);  // Set the pointer to the current Window instance

    setCallbacks();
    
    // configure global opengl state
    glEnable(GL_DEPTH_TEST);

    return true;
}

void Window::setCallbacks()
{
    // whenever the window changes in size, gflw calls this function and fills in proper arguments
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // mouse cursor movement
    glfwSetCursorPosCallback(window, mouse_callback);
    // mouse scroll movement
    glfwSetScrollCallback(window, scroll_callback);
    // capture mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::processInput(Camera& camera, const float &deltaTime)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.process_keyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.process_keyboard(BACKWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.process_keyboard(LEFT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.process_keyboard(RIGHT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.process_keyboard(UP, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        camera.process_keyboard(DOWN, deltaTime);
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);    
}

void Window::mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
{
    // Create a pointer to current window object 
    Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));

    float xpos = static_cast<float>(xposIn);    //convert double to float
    float ypos = static_cast<float>(yposIn);

    if(win->firstMouse)  //init mouse
    {
        win->lastX = xpos;
        win->lastY = ypos;
        win->firstMouse = false;
    }

    float xoffset = xpos - win->lastX;
    float yoffset = win->lastY - ypos;   //y go from bottom to top
    
    float sens = 0.05f;
    xoffset *= sens;
    yoffset *= sens;
    
    win->lastX = xpos;
    win->lastY = ypos;

    win->camera->process_mouse_camera(xoffset, yoffset);
}

void Window::scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));   //create window pointer that points to current Window
    // Use camera pointer to call the function from main's Camera object
    win->camera->process_scroll_camera(static_cast<float>(xoffset), static_cast<float>(yoffset));
}