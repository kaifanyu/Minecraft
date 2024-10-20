#pragma once

enum class Direction{
    FRONT = 0,
    BACK = 1,
    LEFT = 2,
    RIGHT = 3,
    TOP = 4,
    BOTTOM = 5,
};

struct DirectionOffset{
    int xOffset;
    int yOffset;
    int zOffset;
};

const DirectionOffset directionOffsets[6] = {
    {  0,  1,  0 },  // TOP
    {  0, -1,  0 },   // BOTTOM
    { -1,  0,  0 },  // LEFT
    {  1,  0,  0 },  // RIGHT
    {  0,  0, -1 },  // FRONT
    {  0,  0,  1 }  // BACK
};
