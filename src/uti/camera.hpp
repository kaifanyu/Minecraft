#pragma once

#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>


class Camera{
    public:

        //camera default settings
        vec3 cameraPos;
        vec3 cameraFront = {0.0f, 0.0f, -1.0f};
        vec3 cameraUp = {0.0f, 1.0f, 0.0f};
        vec3 cameraTarget;

        
        //mouse default settings
        bool firstMouse = true;
        float yaw = -90.0f;     //left / right direction. Starting at -90 to face straight?
        float pitch = 0.0f;     //up / down
        float lastX = 8000.0f / 2.0;
        float lastY = 600.0f / 2.0;
        float fov = 45.0f;

        float deltaTime = 0.0f;
        float lastFrame = 0.0f;


        Camera(vec3 cameraPosIn); //constructor for cameraPos;
        void get_view_matrix(mat4 &M_view);
        void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
        // void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};