#include "block.hpp"

Block::Block()
{
    block_type = AIR;
}

Block::Block(Block_Type type)
{
    block_type = type;
}

Block_Type Block::getBlockType()
{
    return block_type;
}

void Block::setBlockType(Block_Type type)
{
    block_type = type;
}



std::vector<float> Block::getVertices(Direction direction)
{
    std::vector<float> verticies;
    
    switch (direction)
    {
        case Direction::FRONT:

            verticies = {
                -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
                0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 0.0f,
                0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
                0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
                -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 1.0f,
                -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
            };

            return verticies;
            break;
        case Direction::BACK:
            verticies = {
                -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
                0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 0.0f,
                0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 1.0,
                0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 1.0,
                -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 1.0,
                -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
            };

            return verticies;
            break;
        case Direction::LEFT:
            verticies = {
                -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 0.0f,
                -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 1.0,
                -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 1.0,
                -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 1.0,
                -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
            };

            return verticies;
            break;

        case Direction::RIGHT:
            verticies = {
                0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
                0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 0.0f,
                0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 1.0,
                0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 1.0,
                0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 1.0,
                0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
            };
            return verticies;
            break;
        case Direction::TOP:
            verticies = {
                -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f,
                0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   1.0, 0.0f,
                0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   1.0, 1.0,
                0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   1.0, 1.0,
                -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 1.0,
                -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f,
            };
            return verticies;
            break;
        case Direction::BOTTOM:
            verticies = {
                -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,   0.0f, 0.0f,
                0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,   1.0, 0.0f,
                0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,   1.0, 1.0,
                0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,   1.0, 1.0,
                -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,   0.0f, 1.0,
                -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,   0.0f, 0.0f,
            };
            return verticies;
            break;
        default:
            verticies = {
                -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
                0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 0.0f,
                0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
                0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
                -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 1.0f,
                -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
            };
            return verticies;
            break;
    }
}

int Block::getAttributes(){
    //based on block type, return # of attribute counts. i.e. if we need normal vector
    switch (block_type)
    {
        case DIRT:
            return 8;
            break;
        
        default:
            return 8;
            break;
    }
}