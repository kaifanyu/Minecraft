#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "../gfx/renderer.hpp"
#include "../gfx/mesh.hpp"

#include <unordered_map>

struct Chunk_Position{
    int x_pos;
    int y_pos;
    int z_pos;
};


class Chunk
{
    public:
        Chunk();
        void initChunk(Camera &camera, int x_offset, int z_offset); 
        std::vector<std::tuple<int, int, int>> getVertices();
        void populate_faces();
        void printVertices();
    private:
        static const int CHUNK_SIZE_X = 3;
        static const int CHUNK_SIZE_Y = 3;
        static const int CHUNK_SIZE_Z = 3;

        std::vector<std::tuple<int, int, int>> vertices;
        vector<GLfloat> vao_vertices;
        Mesh block_mesh;        
        //Matrix of block
        Block blocks[CHUNK_SIZE_X][CHUNK_SIZE_Y][CHUNK_SIZE_Z]; //x y z size
};