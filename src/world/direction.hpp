#pragma once

enum class Direction{
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
    FRONT,
    BACK,
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
