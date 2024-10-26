#include "chunk.hpp"

Chunk::Chunk()
{
    chunk_vertices = {};
}



void Chunk::initChunk(Camera &camera, int x_offset, int z_offset)
{
    vec3 offset;  // Temporary vec3 to store the world offset
    for(int x = 0; x < CHUNK_SIZE_X; x++)
    {
        for(int y = 0; y < CHUNK_SIZE_Y; y++)
        {
            for(int z = 0; z < CHUNK_SIZE_Z; z++)
            {
                // Calculate the actual world position of each block in the chunk
                glm_vec3_copy(vec3{(float)x + (float)x_offset, (float)y, (float)z + (float)z_offset}, offset);
                std::cout << "Generating block at: "; 
                glm_vec3_print(offset, stdout);
                // Pass the offset to addVertex
                block_mesh.addVertex(offset);
                // Add block to blocks array
                Block newBlock(Block_Type::AIR, Block_State::Opaque);
                blocks[x][y][z] = newBlock;
            }
        }
    }
}


void Chunk::print()
{
    block_mesh.printVertices();
}

std::vector<Vertex> Chunk::getVertices() const
{
    return block_mesh.getVertices();
}


void Chunk::renderChunk()
{
    std::cout << "printing chunk: \n";
    block_mesh.printVertices();
}