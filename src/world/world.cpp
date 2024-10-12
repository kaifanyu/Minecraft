#include "world.hpp"

World::World() {
    //create the renderer
}



void World::init_world(){
    //create the world by creating the dirt_chunk
    Chunk dirt_chunk;
    dirt_chunk.initChunk(camera);

    
}