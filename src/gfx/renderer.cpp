#include "renderer.hpp"



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

void Renderer::set_render(std::vector<Vertex> &vertices)
{
    block_render.setRender(vertices, 8); //8 attribute count. Should change later
}



void Renderer::render(Camera& camera)    //render loop
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // background color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    block_shader.use();
    block_texture.bind(block_shader.getID());
    camera.get_view_matrix(M_view);
    glm_perspective(glm_rad(camera.fov), (float)800.0/(float)600.f, 0.1f, 80.0f, M_projection);
    
    block_shader.setMat4("view", M_view);
    block_shader.setMat4("projection", M_projection);
    block_shader.setVec3("viewPos", camera.cameraPos);   //set camera position

    block_render.draw();
}



//Getter functions
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

