#include "camera.hpp"
#include <iostream>

Camera::Camera(vec3 camearPosIn)
{
    glm_vec3_copy(cameraPos, camearPosIn);
}

// void Camera::mouse_callback(GLFWWindow* window, double xPosIn, double yPosIn)
// {

// }