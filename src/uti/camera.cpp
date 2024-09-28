#include "camera.hpp"
#include <iostream>
#include <GLFW/glfw3.h>

Camera::Camera(vec3 camearPosIn)
{
    firstMouse = true;

    yaw = Default_Yaw;
    pitch = Default_Pitch;
    fov = Default_Fov;
    sensitivity = Default_Senstivity;

    //init camera values
    glm_vec3_copy(camearPosIn, cameraPos); 
    glm_vec3_copy(vec3{0.0f, 0.0f, -1.0f}, cameraFront);
    glm_vec3_copy(vec3{0.0f, 1.0f, 0.0f}, cameraUp);
}

void Camera::get_view_matrix(mat4 &M_view)
{   
    glm_vec3_add(cameraPos, cameraFront, cameraTarget); //cameraPos + cameraFront
    glm_lookat(cameraPos, cameraTarget, cameraUp, M_view);  //modify M_view
}

void Camera::process_keyboard(Camera_Movement direction, float deltaTime)
{
    vec3 temp;
    movementSpeed = Default_movementSpeedScalar * deltaTime;
    switch (direction)
    {
    case FORWARD:
        glm_vec3_scale(cameraFront, movementSpeed, temp);
        glm_vec3_add(cameraPos, temp, cameraPos);
        break;
    case BACKWARD:
        glm_vec3_scale(cameraFront, movementSpeed, temp);
        glm_vec3_sub(cameraPos, temp, cameraPos);
        break;
    case LEFT:
        glm_cross(cameraFront, cameraUp, temp);
        glm_normalize(temp);
        glm_vec3_scale(temp, movementSpeed, temp);
        glm_vec3_sub(cameraPos, temp, cameraPos);
        break;
    case RIGHT:
        glm_cross(cameraFront, cameraUp, temp);  //get the 'right' direction by crossing front and up
        glm_normalize(temp); //normalize temp
        glm_vec3_scale(temp, movementSpeed, temp); //scale temp by cameraSpeed basically 'incrementing' temp 
        glm_vec3_add(cameraPos, temp, cameraPos); //add 'right' direction to
        break;
    default:
        break;
    }
}

void Camera::mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
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