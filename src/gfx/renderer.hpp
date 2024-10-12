#pragma once

#include "render.hpp"
#include "shader.hpp"
#include "texture.hpp"

#include "../world/block.hpp"
#include "../uti/camera.hpp"


#include "cglm/cglm.h"

//This class will create the render, shader, texture
class Renderer{
    public:
        vec3 light_pos;
        vec3 light_color;
        vec3 starting_cameraPos = {0.0f, 0.0f, 0.0f}; //start at 3

        mat4 M_model;
        Shader shader;
        Texture texture;
        
        Renderer();
        void render_block_face(mat4 &M_model, Camera &camera, Block &block, Direction direction) const;

};