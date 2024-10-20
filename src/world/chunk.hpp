#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "../gfx/renderer.hpp"
#include <unordered_map>

class Chunk
{
    public:
        Chunk();
        void initChunk(Camera &camera, int x_offset, int z_offset); 
        std::vector<std::tuple<int, int, int>> getVertices();

    private:
        static const int CHUNK_SIZE_X = 3;
        static const int CHUNK_SIZE_Y = 3;
        static const int CHUNK_SIZE_Z = 3;

        std::vector<std::tuple<int, int, int>> vertices;

        //Matrix of block
        Block blocks[CHUNK_SIZE_X][CHUNK_SIZE_Y][CHUNK_SIZE_Z]; //x y z size
};