#include "block.hpp"

Block::Block()
{
    //Default block is air block
    id = 0;
    state = 1;
}


Block::Block(Block_Type block_type, Block_State block_state)
{
    id = block_type;
    state = block_state;
}


// Block_Type Block::getBlockType()
// {
//     return id;
// }

// void Block::setBlockType(Block_Type type)
// {
//     block_type = type;
// }



// std::vector<float> Block::getVertices(Direction direction)
// {
//     std::vector<float> verticies;
    
//     switch (direction)
//     {
//         case Direction::FRONT:

//             verticies = {
//                 -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
//                 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 0.0f,
//                 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
//                 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
//                 -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 1.0f,
//                 -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
//             };

//             return verticies;
//             break;
//         case Direction::BACK:
//             verticies = {
//                 -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
//                 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 0.0f,
//                 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 1.0,
//                 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 1.0,
//                 -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 1.0,
//                 -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
//             };

//             return verticies;
//             break;
//         case Direction::LEFT:
//             verticies = {
//                 -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
//                 -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 0.0f,
//                 -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 1.0,
//                 -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 1.0,
//                 -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 1.0,
//                 -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
//             };

//             return verticies;
//             break;

//         case Direction::RIGHT:
//             verticies = {
//                 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
//                 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 0.0f,
//                 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 1.0,
//                 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 1.0,
//                 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 1.0,
//                 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
//             };
//             return verticies;
//             break;
//         case Direction::TOP:
//             verticies = {
//                 -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f,
//                 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   1.0, 0.0f,
//                 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   1.0, 1.0,
//                 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   1.0, 1.0,
//                 -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 1.0,
//                 -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f,
//             };
//             return verticies;
//             break;
//         case Direction::BOTTOM:
//             verticies = {
//                 -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,   0.0f, 0.0f,
//                 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,   1.0, 0.0f,
//                 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,   1.0, 1.0,
//                 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,   1.0, 1.0,
//                 -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,   0.0f, 1.0,
//                 -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,   0.0f, 0.0f,
//             };
//             return verticies;
//             break;
//         default:
//             verticies = {
//                 -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
//                 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 0.0f,
//                 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
//                 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
//                 -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 1.0f,
//                 -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
//             };
//             return verticies;
//             break;
//     }
// }

// int Block::getAttributes(){
//     //based on block type, return # of attribute counts. i.e. if we need normal vector
//     switch (block_type)
//     {
//         case DIRT:
//             return 8;
//             break;
        
//         default:
//             return 8;
//             break;
//     }
// }