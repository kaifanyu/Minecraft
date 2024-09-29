#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "../uti/camera.hpp"

class Window{
    public:
    
        GLFWwindow* window;
        char* name;
        int SCR_WIDTH;
        int SCR_HEIGHT;

        bool firstMouse = true;
        float yaw;     //left / right direction. Starting at -90 to face straight?
        float pitch;     //up / down
        float fov;
        float lastX;
        float lastY;

        Window(const int &SCR_WIDTH, const int &SCR_HEIGHT);
        bool init();

        void setCallbacks();
        void processInput(Camera camera, const int& deltaTime);

    private:
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
        static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
        static void mouse_callback(GLFWwindow *window, double xpos, double ypos);
};