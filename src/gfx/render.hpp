#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include <vector>

class Render{
    public:
        GLuint VBO; //Vertex Buffer Object
        GLuint VAO; //Vertex Array Object
        std::vector<GLfloat> object;    //object with vertices / positions
        int object_count;   //how many seperate objects we create -> how many VAO / VBO to bind?

        // Render();   //empty constructor. Create triangle on default
        Render(const std::vector<GLfloat>& object, const int attribute_count); //constructor
        ~Render();  //destructor
        void draw();

    private:
        //Constructor calls init 
        void init(const std::vector<GLfloat>& object, const int attribute_count);
};