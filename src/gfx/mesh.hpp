#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include <vector>
#include <iostream>
#include "../world/direction.hpp"
#include "../world/block.hpp"

struct Vertex {
    vec3 position;
    vec3 normal;
    vec2 texCoords;
};




class Mesh {

    public:
        Mesh();
        void addVertex(vec3 offset);
        void update_position(vec3 offset, Vertex vertexPointer);
        void printVertices() const;

        void addFace(vec3 offset, int blocktype, int direction);

        std::vector<Vertex> getVertices() const;
        Vertex addOffset(vec3 offset, Vertex vertices);
        // std::vector<Vertex> getFace(Direction direction);
        static std::vector<Vertex> default_faces[6];
    private:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indicies; //optional??

        void init_default_faces();
};