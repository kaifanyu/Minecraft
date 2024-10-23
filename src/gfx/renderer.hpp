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

        Renderer();
        void init_renderer();
        Render get_render();
        void set_render(std::vector<Vertex>& vertices);

        Shader get_shader();
        Texture get_texture();
        
        void render(Camera& camera);

    private:
        Render block_render;
        mat4 M_view, M_projection;
        Shader block_shader;
        Texture block_texture;
};