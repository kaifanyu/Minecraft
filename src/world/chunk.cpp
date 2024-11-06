#include "chunk.hpp"

Chunk::Chunk()
{
    x_offset = 0;
    z_offset = 0;
}


void Chunk::initChunk(Camera &camera, int world_x_offset, int world_z_offset) {
    x_offset = world_x_offset;
    z_offset = world_z_offset;
    std::cout << "xoffset: " << world_x_offset;
    std::cout << " zoffset: " << world_z_offset << std::endl;

    vec3 offset; // Temporary vec3 to store the world offset
    for (int x = 0; x < CHUNK_SIZE_X; x++) {
        for (int y = -CHUNK_SIZE_Y; y < 0; y++) {
            for (int z = 0; z < CHUNK_SIZE_Z; z++) {
                Block newBlock(1, 0);

                // Calculate the actual world position of each block in the chunk
                glm_vec3_copy(vec3{(float)x + x_offset, (float)y, (float)z + z_offset}, offset);

                BlockManager temp;
                temp.block = newBlock;
                temp.block_vertices = {offset[0], offset[1], offset[2]};
                manager.push_back(temp);
            }
        }
    }

    check();
}

void Chunk::check() {
    for (auto t : manager) {
        float x = t.block_vertices.x_pos;
        float y = t.block_vertices.y_pos;
        float z = t.block_vertices.z_pos;

        vec3 offset = {x, y, z};

        // Check for visible faces on chunk boundaries:
        if (z == z_offset + CHUNK_SIZE_Z - 1) {
            block_mesh.addFace(offset, 1, 0); // front
        }
        if (z == z_offset) {
            block_mesh.addFace(offset, 1, 1); // back
        }

        if (x == x_offset + CHUNK_SIZE_X - 1) {
            block_mesh.addFace(offset, 1, 3); // right
        }
        if (x == x_offset) {
            block_mesh.addFace(offset, 1, 2); // left
        }
        
        if (y == -CHUNK_SIZE_Y) {
            block_mesh.addFace(offset, 1, 5); // bottom
        }
        if (y == -1) {
            // block_mesh.addFace(offset, 1, 4); // top
        }
    }
}



bool Chunk::isAir(int x, int y, int z) {
    return false;
}

/*
world generates 9 chunks
each chunk generates 3x3x3 blocks
each block has 1.type 2.transparency


I want to only render blocks where the face is visible, and that means where the face is 




*/





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