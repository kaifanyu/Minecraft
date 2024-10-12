#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "../gfx/renderer.hpp"

class Chunk
{
    public:
        Chunk();
        void initChunk(Camera &camera);
        void generateChunk();
        void render_block(mat4 M_model, Block_Type type);
};