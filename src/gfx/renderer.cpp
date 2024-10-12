#include "renderer.hpp"

#include "render.hpp"
#include "shader.hpp"
#include "texture.hpp"


Renderer::Renderer()
{
    glm_vec3_copy(vec3{1.2f, 1.0f, 2.0f}, light_pos);   //set starting position for light 
    glm_vec3_copy(vec3{1.0f, 1.0f, 1.0f}, light_color);   //set starting position for light 
};

void Renderer::render_block(mat4 &M_model, Camera &camera, Block &block) const
{
    printf("Rendering BlocK");
    
    Render block_render(block.vertices, block.attribute_count);
    Shader block_shader(ASSETS_DIR "shaders/cube.vs", ASSETS_DIR "shaders/cube.fs");
    Texture block_texture(ASSETS_DIR "images/cat.jpg");

    block_texture.bind(block_shader.ID);    //bind texture to shader 

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

    glm_mat4_print(M_model, stdout);
    block_render.draw();
}