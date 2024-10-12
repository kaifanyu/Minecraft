#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "../gfx/renderer.hpp"

class Chunk
{
    public:
        Chunk();
        void initChunk(Camera &camera);

};