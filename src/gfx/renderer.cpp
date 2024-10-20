#include "renderer.hpp"

#include "render.hpp"
#include "shader.hpp"
#include "texture.hpp"


Renderer::Renderer()
{
    glm_vec3_copy(vec3{1.2f, 1.0f, 2.0f}, light_pos);   //set starting position for light 
    glm_vec3_copy(vec3{1.0f, 1.0f, 1.0f}, light_color);   //set starting position for light
};

void Renderer::init_renderer()
{
    block_shader.setShader(ASSETS_DIR "shaders/cube.vs", ASSETS_DIR "shaders/cube.fs");
    block_texture.setTexture(ASSETS_DIR "images/cat.jpg");
}


Render Renderer::get_render()
{
    return block_render;
}

Shader Renderer::get_shader()
{
    return block_shader;
}

Texture Renderer::get_texture()
{
    return block_texture;
}


void Renderer::render_block_face(mat4 &M_model, Camera &camera, Block &block, Direction direction) 
{
    block_texture.bind(block_shader.getID());    //bind texture to shader 

    block_shader.use();
    block_shader.setVec3("lightColor", light_color);

    block_shader.setMat4("model", M_model);

    mat4 M_view;
    camera.get_view_matrix(M_view);

    mat4 M_projection;
    glm_perspective(glm_rad(camera.fov), (float)800/(float)600, 0.1f, 80.0f, M_projection);    //M_projection
    
    block_shader.setMat4("view", M_view);
    block_shader.setMat4("projection", M_projection);
    block_shader.setVec3("viewPos", camera.cameraPos);

    block_render.draw();
}