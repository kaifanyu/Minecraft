#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "../gfx/renderer.hpp"
#include "../gfx/mesh.hpp"

#include <unordered_map>

struct block_Vertex {
    float x_pos;
    float y_pos;
    float z_pos;
};


struct BlockManager {
    Block block;
    block_Vertex block_vertices;
};


class Chunk
{
    public:
        Chunk();
        void initChunk(Camera &camera, int x_offset, int z_offset); 
        void renderChunk();    
        void check();
        bool isAir(int x, int y, int z);
        std::vector<Vertex> getVertices() const;    
        void print();
        static const int CHUNK_SIZE_X = 4;
        static const int CHUNK_SIZE_Y = 8;
        static const int CHUNK_SIZE_Z = 4;

        int x_offset;
        int z_offset;
    private:

        // Noise parameters
        float frequency;
        float amplitude;

        Mesh block_mesh; 
        std::vector<std::vector<std::vector<Block>>> blocks; // Add this line
        // int blocks[CHUNK_SIZE_X][CHUNK_SIZE_Y][CHUNK_SIZE_Z];
        std::vector<BlockManager> manager;
};