#include "world.hpp"

//Initialize the camera
World::World(): camera()
{
    renderDistance = 1;
    //create the renderer
    std::cout << "Created world with inital render distance: " << renderDistance << endl;

    block_map[Direction::FRONT] = {
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
    };

    block_map[Direction::BACK] = {
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 1.0,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 1.0,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 1.0,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
    };

    block_map[Direction::LEFT] = {
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 1.0,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 1.0,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 1.0,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
    };

    block_map[Direction::RIGHT] = {
            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 1.0,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 1.0,
            0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 1.0,
            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
    };
    block_map[Direction::TOP] = {
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   1.0, 0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   1.0, 1.0,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   1.0, 1.0,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 1.0,
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f,
    };
    block_map[Direction::BOTTOM] = {
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
    };
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


/*
render world will render all values stored in chunk vector array inside world, while calcualting based on player positon 
which chunks to 'remove' and which new chunks to render in

Everything rendered will be saved locally for next time

*/
void World::render_world()
{
    printf("Rendering World using these chunks: \n");
    //Render in the camera
    mat4 M_view, M_projection;
    camera.get_view_matrix(M_view); //Updates M_View
    glm_perspective(glm_rad(camera.fov), (float)800.0/(float)600.f, 0.1f, 80.0f, M_projection);

    block_renderer.get_shader().use();  //Activate shader
    block_renderer.get_shader().setMat4("view", M_view); //Set M_view
    block_renderer.get_shader().setMat4("projection", M_projection);    //Set M_Projection
    block_renderer.get_shader().setVec3("viewPos", camera.cameraPos);   //set camera position

    for(auto& chunk: world_chunks)
    {
        chunk.renderChunk(&block_renderer, block_map);
        break;
    }

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