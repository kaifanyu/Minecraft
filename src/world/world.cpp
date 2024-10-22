#include "world.hpp"

//Initialize the camera
World::World(): camera()
{
    renderDistance = 1;
    //create the renderer
    std::cout << "Created world with inital render distance: " << renderDistance << endl;
}


/*
init_world will create a starting chunk around the player in a 5x5 area. 
1) Randomly selects a biome
2) Based on biome, generate chunks verticies around the player

Each world will have a vector of chunks vertices. These chunks will be spaced out and represent the 'center' of the chunks.
Init_world will create a default 3x3 grid surrounding the player 


Each chunk will have its verticies after calculating for the faces to render. It will store every face that needs to be rendered as well 
as a 3d array of each block type.
For example:

verticies = [(-1, -1, 3)]
blocks[0][0][0] = Air
*/
void World::init_world()
{
    block_renderer.init_renderer(); //initalize the renderer

    Biome_type biome_type = DESERT;
    //Rules for desert biomes. For example, generating sand
    //Create a chunk covered with 'sand' blocks

    for(int x = -renderDistance; x <= renderDistance; x++)
    {
        for(int z = -renderDistance; z <= renderDistance; z++)
        {
            printf("Generating chunk for biome Desert. X: %d Z: %d\n", x, z);
            //load chunk with offset
            generateChunk(biome_type, x, z);
        }
    }
}



void World::render_world()
{
    for(auto& chunk: world_chunks)
    {
        render_chunk(chunk);
        break;
    }
}


void World::render_chunk(Chunk &chunk)
{
    // int x, y, z;
    vector<GLfloat> chunk_vertices;
    chunk_vertices = blockMesh.getFace(Direction::LEFT);

    vector<GLfloat> right_v;
    right_v = blockMesh.getFace(Direction::RIGHT);


    chunk_vertices.insert(chunk_vertices.end(), right_v.begin(), right_v.end());
    


    block_renderer.set_render(chunk_vertices);
    block_renderer.render(camera);

}


void World::generateChunk(Biome_type Biome_type, int x_pos, int z_pos)
{
    Chunk newChunk;
    newChunk.initChunk(camera, x_pos, z_pos);
    world_chunks.push_back(newChunk);
}


Camera& World::getCamera()
{
    return camera;
}