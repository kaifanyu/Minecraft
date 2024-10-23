#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "shader.hpp"
#include "texture.hpp"
#include "mesh.hpp"

class Render{
    public:

        Render();
        Render(const std::vector<Vertex>& object, const int attribute_count); //constructor
        void setRender(const std::vector<Vertex>& object, const int attribute_count);
        ~Render();  //destructor
        void draw();

    private:
        GLuint VBO;
        GLuint VAO;
        int object_count;   //how many seperate objects we create -> how many VAO / VBO to bind?
        int vertexCount;
        //Constructor calls init 
        void init(const std::vector<Vertex>& object, const int attribute_count);
};