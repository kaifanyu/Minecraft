#include <map>
#include "block.hpp"


Block::Block(){
    printf("EMPTY");
}

Block::Block(Block_Type type){

    init_vertex_vector();
    switch (type)
    {
        case DIRT:
            append_normal_vector();    
            append_texture_vector(DIRT);
            attribute_count = 8;
            break;
        
        default:
            break;
    }

}

void Block::init_vertex_vector() {   
    
    vertices = {
        //vertex position     //normal vector       //texture
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,   0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 1.0,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   1.0, 1.0,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 1.0,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,   0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 1.0,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,   1.0, 1.0,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 1.0,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 1.0,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,   1.0, 1.0,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 1.0,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,   0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,   0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,   1.0, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,   1.0, 1.0,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,   1.0, 1.0,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,   0.0f, 1.0,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,   0.0f, 0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   1.0, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   1.0, 1.0,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   1.0, 1.0,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 1.0,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,   0.0f, 0.0f,
    };
}


void Block::append_normal_vector()
{

}


void Block::append_texture_vector(Block_Type type)
{
}