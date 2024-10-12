#pragma once

#include <vector>

#include "direction.hpp"

enum Block_Type{
    DIRT,
    GRASS,
    AIR,
};

class Block{
    public:
        Block();
        Block(Block_Type type);

        Block_Type getBlockType();
        void setBlockType(Block_Type block_type);
        
        //return corresponding vertices to the block face
        std::vector<float> getVertices(Direction Direction);
        int getAttributes();
    private:
        Block_Type block_type;
};