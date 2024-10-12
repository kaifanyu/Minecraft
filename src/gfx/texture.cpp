#include "texture.hpp"
#include <glad/glad.h> //TODO: Remove excess includes
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


Texture::Texture()
{
    texture_ID = 0;
}


Texture::Texture(const char* path)
{
    glGenTextures(1, &texture_ID);    //Generate 1 texture
    glBindTexture(GL_TEXTURE_2D, texture_ID);

    // Set texture wrapping and filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    load_image(path);
}

void Texture::bind(unsigned int program) const
{
    // bind textures according to texture_id
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_ID);
    glUniform1i(glGetUniformLocation(program, "textureAtlas"), 0);
}


void Texture::load_image(const char* path)
{
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded textures on the y-axis.
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0); // load image

    if(data)
    {
        GLenum format;
        if (nrChannels == 1)
            format = GL_RED;  // handle grayscale images
        else if (nrChannels == 3)
            format = GL_RGB;  // standard RGB
        else if (nrChannels == 4)
            format = GL_RGBA; // RGBA with transparency
        // Now create the texture
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } 
    else 
    {
        printf("Failed to load texture\n");
    }

    stbi_image_free(data);  // free image
}
