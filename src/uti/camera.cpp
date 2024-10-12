#include "camera.hpp"
#include <iostream>
#include <GLFW/glfw3.h>

Camera::Camera()
{
    vec3 cameraPosIn = {0.0f, 0.0f, 0.0f};
    
    firstMouse = true;

    yaw = Default_Yaw;
    pitch = Default_Pitch;
    fov = Default_Fov;
    sensitivity = Default_Senstivity;

    //init camera values
    glm_vec3_copy(cameraPosIn, cameraPos); 
    glm_vec3_copy(vec3{0.0f, 0.0f, -1.0f}, cameraFront);
    glm_vec3_copy(vec3{0.0f, 1.0f, 0.0f}, cameraUp);   
    printf("Created Camera \n");
}

Camera::Camera(vec3 cameraPosIn)
{
    firstMouse = true;

    yaw = Default_Yaw;
    pitch = Default_Pitch;
    fov = Default_Fov;
    sensitivity = Default_Senstivity;

    //init camera values
    glm_vec3_copy(cameraPosIn, cameraPos); 
    glm_vec3_copy(vec3{0.0f, 0.0f, -1.0f}, cameraFront);
    glm_vec3_copy(vec3{0.0f, 1.0f, 0.0f}, cameraUp);
}

void Camera::get_view_matrix(mat4 &M_view)
{   
    vec3 temp;
    glm_vec3_add(cameraPos, cameraFront, temp); //cameraPos + cameraFront
    glm_lookat(cameraPos, temp, cameraUp, M_view);  //modify M_view
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
        case UP:
            //move vertically up
            glm_vec3_scale(cameraUp, movementSpeed, temp);  //add mulitply camera up by movementspeed aka increase cameraUp
            glm_vec3_add(cameraPos, temp, cameraPos);   //add camera up to camera position
            break;
        case DOWN:
            glm_vec3_scale(cameraUp, movementSpeed, temp);  //add mulitply camera up by movementspeed aka increase cameraUp
            glm_vec3_sub(cameraPos, temp, cameraPos);   //add camera up to camera position
            break;
        default:
            break;
    }
}

void Camera::process_mouse_camera(const float xoffset, const float yoffset)
{
    
    //if pitch is out of bounds, don't flip screen
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    
    yaw += xoffset; //change x axis
    pitch += yoffset; //change y axis
    vec3 front;
    front[0] = cos(glm_rad(yaw)) * cos(glm_rad(pitch)); //x
    front[1] = sin(glm_rad(pitch));
    front[2] = sin(glm_rad(yaw)) * cos(glm_rad(pitch));

    glm_normalize(front);
    glm_vec3_copy(front, cameraFront);
}

void Camera::process_scroll_camera(const float xoffset, const float yoffset)
{
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}