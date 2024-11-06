#include "block.hpp"

Block::Block()
{
    //Default block is air block
    type = 0;
    state = 1;
}

int Block::getBlockType()
{
    return type;
}

// Block::Block(Block_Type block_type, Block_State block_state)
// {
//     type = block_type;
//     state = block_state;
// }

Block::Block(int block_type, int block_state)
{
    type = block_type;
    state = block_state;
}

bool Block::isTransparent()
{
    return (state == 1);
}