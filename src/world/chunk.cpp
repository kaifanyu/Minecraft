#include "chunk.hpp"

#define STB_PERLIN_IMPLEMENTATION
#include "stb_perlin.h"


Chunk::Chunk()
{
    x_offset = 0;
    z_offset = 0;

    frequency = 0.1f;
    amplitude = CHUNK_SIZE_Y;

    
}


void Chunk::initChunk(Camera &camera, int world_x_offset, int world_z_offset) {
    x_offset = world_x_offset;
    z_offset = world_z_offset;

    std::cout << "xoffset: " << world_x_offset;
    std::cout << " zoffset: " << world_z_offset << std::endl;

    // Initialize the 3D block array
    blocks.resize(CHUNK_SIZE_X);
    for (int x = 0; x < CHUNK_SIZE_X; x++) {
        blocks[x].resize(CHUNK_SIZE_Y);
        for (int y = 0; y < CHUNK_SIZE_Y; y++) {
            blocks[x][y].resize(CHUNK_SIZE_Z);
        }
    }

    for (int x = 0; x < CHUNK_SIZE_X; x++) {
        for (int z = 0; z < CHUNK_SIZE_Z; z++) {
            float blockx = (float)x + x_offset;
            float blockz = (float)z + z_offset;

            float noiseValue = stb_perlin_noise3(blockx * frequency, 0.0f, blockz * frequency, 0, 0, 0) * amplitude;

            int height = (int)(noiseValue + (float)CHUNK_SIZE_Y / 2); // Adjust height to fit in the array
            height = (int)glm_clamp((float)height, 0.0f, (float)(CHUNK_SIZE_Y - 1));

            for (int y = 0; y <= height; y++) {
                Block newBlock(1, 0); // Solid block
                blocks[x][y][z] = newBlock;
            }
            // Fill the rest with air blocks
            for (int y = height + 1; y < CHUNK_SIZE_Y; y++) {
                Block airBlock(0, 0); // Air block
                blocks[x][y][z] = airBlock;
            }
        }
    }

    check();
}

void Chunk::check() {
    for (int x = 0; x < CHUNK_SIZE_X; x++) {
        for (int y = 0; y < CHUNK_SIZE_Y; y++) {
            for (int z = 0; z < CHUNK_SIZE_Z; z++) {
                Block currentBlock = blocks[x][y][z];
                if (currentBlock.getBlockType() == 0) continue; // Skip air blocks

                vec3 offset = {(float)x + x_offset, (float)y, (float)z + z_offset};

                // Left face (-X)
                if (x == 0 || blocks[x - 1][y][z].getBlockType() == 0) {
                    block_mesh.addFace(offset, currentBlock.getBlockType(), 2); // Left face
                }
                // Right face (+X)
                if (x == CHUNK_SIZE_X - 1 || blocks[x + 1][y][z].getBlockType() == 0) {
                    block_mesh.addFace(offset, currentBlock.getBlockType(), 3); // Right face
                }
                // Bottom face (-Y)
                if (y == 0 || blocks[x][y - 1][z].getBlockType() == 0) {
                    block_mesh.addFace(offset, currentBlock.getBlockType(), 5); // Bottom face
                }
                // Top face (+Y)
                if (y == CHUNK_SIZE_Y - 1 || blocks[x][y + 1][z].getBlockType() == 0) {
                    block_mesh.addFace(offset, currentBlock.getBlockType(), 4); // Top face
                }
                // Back face (-Z)
                if (z == 0 || blocks[x][y][z - 1].getBlockType() == 0) {
                    block_mesh.addFace(offset, currentBlock.getBlockType(), 1); // Back face
                }
                // Front face (+Z)
                if (z == CHUNK_SIZE_Z - 1 || blocks[x][y][z + 1].getBlockType() == 0) {
                    block_mesh.addFace(offset, currentBlock.getBlockType(), 0); // Front face
                }
            }
        }
    }
}



bool Chunk::isAir(int x, int y, int z) {
    return false;
}



void Chunk::print()
{
    std::cout << "printing all vertices: " << endl;
    // block_mesh.printVertices();
}

std::vector<Vertex> Chunk::getVertices() const
{
    //maybe check from here?
    return block_mesh.getVertices();
}


void Chunk::renderChunk()
{
    std::cout << "printing chunk: \n";
    block_mesh.printVertices();
}