#include "chunk.hpp"

Chunk::Chunk()
{

}



void Chunk::initChunk(Camera &camera){
    //i`nit a 16 x 16 blocks
    Block dirtBlock(DIRT); //create a dirt block

    //render the dirtblock. Call renderer class next
    Renderer renderer;

    //Create model view for position
    mat4 M_model;
    vec3 blockPos = {0.0f, 0.0f, -3.0f};  //want block to be here?

    glm_mat4_identity(M_model); //init the model to identity matrix so we can do calculations
    glm_translate(M_model, blockPos);   //translate the model to blockPos

    //render the block
    renderer.render_block(M_model, camera, dirtBlock);
    
}