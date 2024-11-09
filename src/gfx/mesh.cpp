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
            Vertex{{-0.5f, -0.5f,  0.5f}, {0.0f,  0.0f,  1.0f}, {0.0f, 0.0f}},
            Vertex{{0.5f, -0.5f,  0.5f},  {0.0f,  0.0f,  1.0f}, {1.0, 0.0f}},
            Vertex{{0.5f,  0.5f,  0.5f},  {0.0f,  0.0f,  1.0f}, {1.0, 1.0}},
            Vertex{{0.5f,  0.5f,  0.5f},  {0.0f,  0.0f,  1.0f}, {1.0, 1.0}},
            Vertex{{-0.5f,  0.5f,  0.5f}, {0.0f,  0.0f,  1.0f}, {0.0f, 1.0}},
            Vertex{{-0.5f, -0.5f,  0.5f}, {0.0f,  0.0f,  1.0f}, {0.0f, 0.0f}},
    };
    default_faces[1] = {
            Vertex{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}},
            Vertex{{ 0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f}},
            Vertex{{ 0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}},
            Vertex{{ 0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}},
            Vertex{{-0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f}},
            Vertex{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}}
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
            Vertex{{ -0.5f, -0.5f, 0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}},
            Vertex{{ 0.5f, -0.5f, 0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f}},
            Vertex{{ 0.5f,  -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}},
            Vertex{{ 0.5f,  -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}},
            Vertex{{-0.5f,  -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f}},
            Vertex{{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}}
    };

}


std::vector<Vertex> Mesh::getVertices() const
{
    return vertices;
}

void Mesh::addFace(vec3 offset, int block_type, int direction)
{
    std::vector<Vertex> temp_vertex = default_faces[direction];
    float val = (float)block_type * (16.0f / 256.0f);
    vec2 top = {(16.0f / 256.0f), 0};
    for(auto& t : temp_vertex)
    {
        glm_vec3_add(offset, t.position, t.position);
        //change texture
        glm_vec2_scale(t.texCoords, val, t.texCoords);

        if(direction == 4)
        {
            //get the 2nd image
            glm_vec2_add(t.texCoords, top, t.texCoords);
        }
    }
    vertices.insert(vertices.end(), temp_vertex.begin(), temp_vertex.end());
}

//change texture
void Mesh::addVertex(vec3 offset)
{
    // std::cout << "\nAdding offset Vertex: ";
    // glm_vec3_print(offset, stdout);
    // Iterate over the 6 faces of the cube (default_faces is an array of 6 vectors)
    for (int i = 0; i < 6; i++)
    {
        std::vector<Vertex> temp_vertex;
        for(const auto face_vertex : default_faces[i])
        {
            Vertex temp = addOffset(offset, face_vertex);
            temp_vertex.push_back(temp);
        }
        // Insert the updated vertices into the main vertices vector
        vertices.insert(vertices.end(), temp_vertex.begin(), temp_vertex.end());
    }
}


Vertex Mesh::addOffset(vec3 offset, Vertex vertices)
{
    glm_vec3_add(vertices.position, offset, vertices.position);
    return vertices;
}


void Mesh::update_position(vec3 offset, Vertex vertexPointer)
{
    // Update the vertex position by adding the offset
    glm_vec3_add(vertexPointer.position, offset, vertexPointer.position);
}



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