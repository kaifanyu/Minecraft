#include "chunk.hpp"

Chunk::Chunk()
{
    vao_vertices = {};
    printf("Created Chunk\n");
}

std::vector<tuple<int, int, int>> Chunk::getVertices()
{
    return vertices;
}

void Chunk::printVertices()
{
    std::cout << "Start: " << endl;
    for(auto& vert : vertices)
    {
        int x, y, z;

        std::tie(x, y, z) = vert;

        std::cout << "x: " << x << " y: " << y << " z: " << z << endl;
    }
    std::cout << "Stop: " << endl;
}



//initalizes a chunk object
void Chunk::initChunk(Camera &camera, int x_offset, int z_offset)
{
    for(int x = 0; x < CHUNK_SIZE_X; x++)
    {
        for(int y = 0; y < CHUNK_SIZE_Y; y++)
        {
            for(int z = 0; z < CHUNK_SIZE_Z; z++)
            {
                //add verticies to vertices array
                vertices.push_back(std::make_tuple(x+x_offset, y, z+z_offset));
                //Add block to blocks array
                Block newBlock(Block_Type::AIR, Block_State::Opaque);
                blocks[x][y][z] = newBlock;
            }
        }
    }
}

void Chunk::populate_faces()
{
    vector<GLfloat> chunk_block;
    for (const auto& vertex : vertices)
    {
        int x, y, z;
        std::tie(x, y, z) = vertex;

        vector<GLfloat> temp;
        temp = block_mesh.getFace(Direction::LEFT);

        
        chunk_block.insert(chunk_block.end(), temp.begin(), temp.end());
    }
}