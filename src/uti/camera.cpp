#include "camera.hpp"
#include <iostream>
#include <GLFW/glfw3.h>

Camera::Camera(vec3 camearPosIn)
{
    glm_vec3_copy(camearPosIn, cameraPos);  
}

void Camera::get_view_matrix(mat4 &M_view)
{   
    glm_vec3_add(cameraPos, cameraFront, cameraTarget); //cameraPos + cameraFront
    glm_lookat(cameraPos, cameraTarget, cameraUp, M_view);  //modify M_view
}


void Camera::mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{

}