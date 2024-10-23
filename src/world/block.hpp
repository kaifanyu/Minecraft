#pragma once

#include <vector>
#include <map>
#include "direction.hpp"

enum Block_Type{
    AIR = 0,
    DIRT = 1,
    GRASS = 2,
};

enum Block_State{
    Opaque = 0,
    Transparent = 1,
};


class Block{
    public:
        Block();
        Block(Block_Type type, Block_State state);
        int getBlockType();
        void setNeighbors(int value, bool status);
        // void setBlockType();
    private:
        int id;
        int state;
        bool neighbors[6];
};