#pragma once

#include "../uti/camera.hpp"
#include "chunk.hpp"

class World{
    public:
        World();
        void init_world();
        Camera& getCamera();
    private:
        Camera camera;

};