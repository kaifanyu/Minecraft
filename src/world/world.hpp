#pragma once

#include "../uti/camera.hpp"
#include "chunk.hpp"

#include <unordered_map>
#include <tuple>

/*
The world class will contain everything you need to create a world

Objects per world:
Camera
*/
enum Biome_type{
    DESERT,
    RAINFOREST,
};


class World{

    public:
        World();  
        void init_world();
        void render_world();
        Camera& getCamera();

        void generateChunk(Biome_type Biome_type, int x_pos, int z_pos);
    private:
        Camera camera;  //Player Camera
        Renderer block_renderer; //Block Renderer for chunks
        
        std::vector<Chunk> world_chunks;
        std::unordered_map<Direction, std::vector<GLfloat>> block_map;
        int renderDistance;
};