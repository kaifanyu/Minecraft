#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include <vector>
#include "../world/direction.hpp"

struct Vertex {
    vec3 position;
    vec3 normal;
    vec2 texCoords;
};




class Mesh {

    public:
        Mesh();
        void update_position(float xOffset, float yOffset, float zOffset);
        void printVertices() const;
        std::vector<GLfloat> getFace(Direction direction);
    private:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indicies; //optional??

        static std::vector<Vertex> default_faces[6];
        void init_default_faces();
};