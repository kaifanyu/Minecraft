#pragma once

#include "../uti/camera.hpp"
#include "chunk.hpp"

class World{
    public:
        Camera camera;

        World();
        void init_world();
};