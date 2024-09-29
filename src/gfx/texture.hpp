#pragma once

#include <glad/glad.h> //TODO: Remove excess includes
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include <vector>
class Texture{
    public:

        GLuint texture_ID;

        Texture(const char* path);
        void bind() const;
    private:
        void load_image(const char* path);
};