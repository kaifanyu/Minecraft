#include "mesh.hpp"

std::vector<Vertex> Mesh::default_faces[6];  // Definition

Mesh::Mesh()
{
    init_default_faces();
}

void Mesh::init_default_faces()
{

    //ORDER: FRONT BACK LEFT RIGHT TOP BOTTOM
    default_faces[0] = {
        Vertex{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}},
        Vertex{{ 0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f}},
        Vertex{{ 0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}},
        Vertex{{ 0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}},
        Vertex{{-0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f}},
        Vertex{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}}
    };
    default_faces[1] = {
        Vertex{{-0.5f, -0.5f,  0.5f}, {0.0f,  0.0f,  1.0f}, {0.0f, 0.0f}},
        Vertex{{0.5f, -0.5f,  0.5f},  {0.0f,  0.0f,  1.0f}, {1.0, 0.0f}},
        Vertex{{0.5f,  0.5f,  0.5f},  {0.0f,  0.0f,  1.0f}, {1.0, 1.0}},
        Vertex{{0.5f,  0.5f,  0.5f},  {0.0f,  0.0f,  1.0f}, {1.0, 1.0}},
        Vertex{{-0.5f,  0.5f,  0.5f}, {0.0f,  0.0f,  1.0f}, {0.0f, 1.0}},
        Vertex{{-0.5f, -0.5f,  0.5f}, {0.0f,  0.0f,  1.0f}, {0.0f, 0.0f}},
    };    
    default_faces[2] = {
            Vertex{{-0.5f,  0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f},   {0.0f, 0.0f}},
            Vertex{{-0.5f,  0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f},   {1.0, 0.0f}},
            Vertex{{-0.5f, -0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f},   {1.0, 1.0}},
            Vertex{{-0.5f, -0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f},   {1.0, 1.0}},
            Vertex{{-0.5f, -0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f},   {0.0f, 1.0}},
            Vertex{{-0.5f,  0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f},   {0.0f, 0.0f}},
    };    
    default_faces[3] = {
            Vertex{{0.5f,  0.5f,  0.5f},  {1.0f,  0.0f,  0.0f},   {0.0f, 0.0f}},
            Vertex{{0.5f,  0.5f, -0.5f},  {1.0f,  0.0f,  0.0f},   {1.0, 0.0f}},
            Vertex{{0.5f, -0.5f, -0.5f},  {1.0f,  0.0f,  0.0f},   {1.0, 1.0}},
            Vertex{{0.5f, -0.5f, -0.5f},  {1.0f,  0.0f,  0.0f},   {1.0, 1.0}},
            Vertex{{0.5f, -0.5f,  0.5f},  {1.0f,  0.0f,  0.0f},   {0.0f, 1.0}},
            Vertex{{0.5f,  0.5f,  0.5f},  {1.0f,  0.0f,  0.0f},   {0.0f, 0.0f}},
    };    
    default_faces[4] = {
            Vertex{{-0.5f,  0.5f, -0.5f},  {0.0f,  1.0f,  0.0f},   {0.0f, 0.0f}},
            Vertex{{0.5f,  0.5f, -0.5f},  {0.0f,  1.0f,  0.0f},   {1.0, 0.0f}},
            Vertex{{0.5f,  0.5f,  0.5f},  {0.0f,  1.0f,  0.0f},   {1.0, 1.0}},
            Vertex{{0.5f,  0.5f,  0.5f},  {0.0f,  1.0f,  0.0f},   {1.0, 1.0}},
            Vertex{{-0.5f,  0.5f,  0.5f},  {0.0f,  1.0f,  0.0f},   {0.0f, 1.0}},
            Vertex{{-0.5f,  0.5f, -0.5f},  {0.0f,  1.0f,  0.0f},   {0.0f, 0.0f}},
    };    
    default_faces[5] = {
            Vertex{{-0.5f, -0.5f, -0.5f},  {0.0f,  0.0f, -1.0f},   {0.0f, 0.0f}},
            Vertex{{0.5f, -0.5f, -0.5f},  {0.0f,  0.0f, -1.0f},   {1.0f, 0.0f}},
            Vertex{{0.5f,  0.5f, -0.5f},  {0.0f,  0.0f, -1.0f},   {1.0f, 1.0f}},
            Vertex{{0.5f,  0.5f, -0.5f},  {0.0f,  0.0f, -1.0f},   {1.0f, 1.0f}},
            Vertex{{-0.5f,  0.5f, -0.5f},  {0.0f,  0.0f, -1.0f},   {0.0f, 1.0f}},
            Vertex{{-0.5f, -0.5f, -0.5f},  {0.0f,  0.0f, -1.0f},   {0.0f, 0.0f}},
    };
}

std::vector<GLfloat> Mesh::getFace(Direction direction)
{
    std::vector<Vertex> faceVertices = default_faces[static_cast<int>(direction)];
    std::vector<GLfloat> floatVector(faceVertices.size() * 8);  // Pre-allocate exact size

    GLfloat* dataPtr = floatVector.data();  // Get a raw pointer to the underlying data

    for (const auto& vertex : faceVertices)
    {
        // Use memcpy to copy vec3 and vec2 data
        std::memcpy(dataPtr, vertex.position, 3 * sizeof(GLfloat));
        dataPtr += 3;
        std::memcpy(dataPtr, vertex.normal, 3 * sizeof(GLfloat));
        dataPtr += 3;
        std::memcpy(dataPtr, vertex.texCoords, 2 * sizeof(GLfloat));
        dataPtr += 2;
    }

    return floatVector;
}



void Mesh::update_position(float xOffset, float yOffset, float zOffset)
{
    vec3 offset = {xOffset, yOffset, zOffset};

    for(auto& vertex : vertices)
    {
        glm_vec3_add(offset, vertex.position, vertex.position);
    }
}


// Optionally, print the vertices (for debugging)
void Mesh::printVertices() const 
{
    for (const auto& vertex : vertices) {
        printf("Position: (%f, %f, %f)\n", vertex.position[0], vertex.position[1], vertex.position[2]);
    }
}