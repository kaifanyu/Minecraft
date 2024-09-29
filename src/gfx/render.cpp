#include "render.hpp"
#include <glad/glad.h>  //TODO: remove unnecessary #includes
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include <vector>

Render::Render(const std::vector<GLfloat> &object)
{
    object_count = 1;
    init(object);
}

Render::~Render()
{
    glDeleteVertexArrays(object_count, &VAO);
    glDeleteBuffers(object_count, &VBO);
}

void Render::init(const std::vector<GLfloat>& object)
{
    glGenVertexArrays(object_count, &VAO);  //init VAO
    glGenBuffers(object_count, &VBO);       //init VBO

    glBindVertexArray(VAO); //activate VAO
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //activate VBO

    // put object in buffer
    glBufferData(GL_ARRAY_BUFFER, object.size() * sizeof(GLfloat), object.data(), GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

}

void Render::draw()
{
    // glBindVertexArray(VAO);  // Not sure if needed
    glDrawArrays(GL_TRIANGLES, 0, 36);  // 6 faces * 2 triangles * 3 vertcies per triangle = 36
}
