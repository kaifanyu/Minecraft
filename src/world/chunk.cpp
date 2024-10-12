#include "chunk.hpp"

Chunk::Chunk()
{

}



void Chunk::initChunk(Camera &camera)
{
    //i`nit a 16 x 16 blocks
    Block dirtBlock(DIRT); //create a dirt block

    //render the dirtblock. Call renderer class next
    Renderer renderer;

    //Create model view for position
    mat4 M_model;
    vec3 blockPos = {0.0f, 0.0f, -3.0f};  //want block to be here?

    glm_mat4_identity(M_model); //init the model to identity matrix so we can do calculations
    glm_translate(M_model, blockPos);   //translate the model to blockPos

    renderer.render_block_face(M_model, camera, dirtBlock, Direction::FRONT);
    renderer.render_block_face(M_model, camera, dirtBlock, Direction::BACK);
    renderer.render_block_face(M_model, camera, dirtBlock, Direction::TOP);
    renderer.render_block_face(M_model, camera, dirtBlock, Direction::BOTTOM);
    renderer.render_block_face(M_model, camera, dirtBlock, Direction::LEFT);
    renderer.render_block_face(M_model, camera, dirtBlock, Direction::RIGHT);

}



void Chunk::generateChunk()
{
    //for loop to deteremine x, y, z coords for each chunk.

    //TEMP
    mat4 M_model;
    vec3 blockPos = {0.0f, 0.0f, -3.0f};  //want block to be here?

    glm_mat4_identity(M_model); //init the model to identity matrix so we can do calculations
    glm_translate(M_model, blockPos);   //translate the model to blockPos

    //using M_model, we now render the block
    render_block(M_model, DIRT);
}

void Chunk::render_block(mat4 M_model, Block_Type blockType)
{
    //check which sides of the block needs to be rendered
    
}

