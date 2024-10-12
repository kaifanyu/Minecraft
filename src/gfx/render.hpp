#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

class Render{
    public:
        Render(const std::vector<GLfloat>& object, const int attribute_count); //constructor
        ~Render();  //destructor
        void draw();

    private:
        GLuint VBO;
        GLuint VAO;
        std::vector<GLfloat> object;    //object with vertices / positions
        int object_count;   //how many seperate objects we create -> how many VAO / VBO to bind?
  
        //Constructor calls init 
        void init(const std::vector<GLfloat>& object, const int attribute_count);
};