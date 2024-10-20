#pragma once

#include <glad/glad.h> //TODO: Remove excess includes
#include <GLFW/glfw3.h>


class Texture{
    public:

        Texture();
        void setTexture(const char* path);
        // Texture(const char* path);
        void bind(unsigned int program) const;
        GLuint getTextureID() const;
    private:
        GLuint texture_ID;
        void load_image(const char* path);
};