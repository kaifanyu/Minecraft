#include "render.hpp"

Render::Render()
{
    // Empty constructor
}

Render::Render(const std::vector<Vertex> &object, const int attribute_count)
{
    vertexCount = object.size();
    init(object, attribute_count);
}

Render::~Render()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Render::setRender(const std::vector<Vertex> &object, const int attribute_count)
{
    vertexCount = object.size();
    init(object, attribute_count);
}

void Render::init(const std::vector<Vertex>& object, const int attribute_count)
{
    if (object.empty()) {
        return;  // Prevent initializing with empty vertex data
    }

    glGenVertexArrays(1, &VAO);  // Generate and initialize VAO
    glGenBuffers(1, &VBO);       // Generate and initialize VBO

    glBindVertexArray(VAO);      // Bind VAO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  // Bind VBO

    // Upload vertex data to GPU
    glBufferData(GL_ARRAY_BUFFER, object.size() * sizeof(Vertex), object.data(), GL_STATIC_DRAW);

    GLsizei stride = sizeof(Vertex);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    // Normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(1);

    // Texture coordinates attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)offsetof(Vertex, texCoords));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);  // Unbind VAO
}

void Render::draw()
{
    glBindVertexArray(VAO);  // Bind VAO
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);  // Draw the vertices
    glBindVertexArray(0);  // Unbind VAO
}
