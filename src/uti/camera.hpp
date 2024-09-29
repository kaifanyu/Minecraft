#pragma once

#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

enum Camera_Movement{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float Default_Yaw = -90.0f;     //left / right direction. Starting at -90 to face straight?
const float Default_Pitch = 0.0f;     //up / down
const float Default_Fov = 45.0f;
const float Default_Senstivity = 0.5f;
const float Default_movementSpeedScalar = 2.5;

class Camera{
    public:

        //camera default settings
        vec3 cameraPos;
        vec3 cameraFront;
        vec3 cameraUp;

        //mouse default settings
        bool firstMouse;
        float yaw;
        float pitch;
        float fov;
        float sensitivity;
        float movementSpeed;

        float lastX = 8000.0f / 2.0;
        float lastY = 600.0f / 2.0;

        float deltaTime = 0.0f;
        float lastFrame = 0.0f;

        Camera(vec3 cameraPosIn); //constructor for cameraPos;
        void process_keyboard(Camera_Movement direction, float deltaTime);
        void process_mouse_camera(const float xoffset, const float yoffset);
        void process_scroll_camera(const float xoffset, const float yoffset);
        void get_view_matrix(mat4 &M_view);
};