#include "mesh.hpp"

std::vector<Vertex> Mesh::default_faces[6];  // Definition

Mesh::Mesh()
{
    vertices = {};
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


std::vector<Vertex> Mesh::getVertices() const
{
    return vertices;
}

void Mesh::addVertex(vec3 offset)
{
    // Iterate over the 6 faces of the cube (default_faces is an array of 6 vectors)
    for (int i = 0; i < 6; i++)
    {
        // Iterate over the vertices in each face
        for (size_t j = 0; j < default_faces[i].size(); j++)
        {
            // Update the position of each vertex with the offset
            update_position(offset, default_faces[i][j]);
        }

        // Insert the updated vertices into the main vertices vector
        vertices.insert(vertices.end(), default_faces[i].begin(), default_faces[i].end());
    }
}

void Mesh::update_position(vec3 offset, Vertex& vertexPointer)
{
    // Update the vertex position by adding the offset
    glm_vec3_add(vertexPointer.position, offset, vertexPointer.position);
}


// std::vector<GLfloat> Mesh::getFace(Direction direction)
// {
//     std::vector<Vertex> faceVertices = default_faces[static_cast<int>(direction)];
//     std::vector<GLfloat> floatVector(faceVertices.size() * 8);  // Pre-allocate exact size

//     GLfloat* dataPtr = floatVector.data();  // Get a raw pointer to the underlying data

//     for (const auto& vertex : faceVertices)
//     {
//         // Use memcpy to copy vec3 and vec2 data
//         std::memcpy(dataPtr, vertex.position, 3 * sizeof(GLfloat));
//         dataPtr += 3;
//         std::memcpy(dataPtr, vertex.normal, 3 * sizeof(GLfloat));
//         dataPtr += 3;
//         std::memcpy(dataPtr, vertex.texCoords, 2 * sizeof(GLfloat));
//         dataPtr += 2;
//     }

//     return floatVector;
// }



// Optionally, print the vertices (for debugging)
void Mesh::printVertices() const 
{

    for (size_t i = 0; i < vertices.size(); ++i) {
        const Vertex& vertex = vertices[i];
        
        // Print vertex index
        std::cout << "Vertex " << i + 1 << ":\n";

        // Print position
        std::cout << "  Position: (" 
                  << vertex.position[0] << ", "
                  << vertex.position[1] << ", "
                  << vertex.position[2] << ")\n";

        // Print normal
        std::cout << "  Normal: (" 
                  << vertex.normal[0] << ", "
                  << vertex.normal[1] << ", "
                  << vertex.normal[2] << ")\n";

        // Print texture coordinates
        std::cout << "  Texture Coordinates: (" 
                  << vertex.texCoords[0] << ", "
                  << vertex.texCoords[1] << ")\n";

        std::cout << std::endl;
    }
}