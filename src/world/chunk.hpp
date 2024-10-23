#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "../gfx/renderer.hpp"
#include "../gfx/mesh.hpp"

#include <unordered_map>

struct Chunk_Vertex {
    int x_pos;
    int y_pos;
    int z_pos;
};

class Chunk
{
    public:
        Chunk();
        void initChunk(Camera &camera, int x_offset, int z_offset); 
        void renderChunk();    
        std::vector<Vertex> getVertices() const;    
        void print();
        static const int CHUNK_SIZE_X = 3;
        static const int CHUNK_SIZE_Y = 3;
        static const int CHUNK_SIZE_Z = 3;
    private:

        std::vector<Chunk_Vertex> chunk_vertices;
        Mesh block_mesh; 

        //Matrix of block
        Block blocks[CHUNK_SIZE_X][CHUNK_SIZE_Y][CHUNK_SIZE_Z]; //x y z size
};