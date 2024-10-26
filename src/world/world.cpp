#include "world.hpp"

//Initialize the camera
World::World(): camera()
{
    renderDistance = 1;
    final_VAO = {};
    //create the renderer
    std::cout << "Created world with inital render distance: " << renderDistance << endl;
}


/*
init_world will create a starting chunk around the player in a 5x5 area. 
1) Randomly selects a biome
2) Based on biome, generate chunks verticies around the player

Each world will have a vector of chunks vertices. These chunks will be spaced out and represent the 'center' of the chunks.
Init_world will create a default 3x3 grid surrounding the player 


Each chunk will have its verticies after calculating for the faces to render. It will store every face that needs to be rendered as well 
as a 3d array of each block type.
For example:

verticies = [(-1, -1, 3)]
blocks[0][0][0] = Air
*/
void World::init_world()
{
    block_renderer.init_renderer(); //initalize the renderer

    Biome_type biome_type = DESERT;
    //Rules for desert biomes. For example, generating sand
    //Create a chunk covered with 'sand' blocks

    for(int x = -renderDistance; x <= renderDistance; x++)
    {
        for(int z = -renderDistance; z <= renderDistance; z++)
        {
            printf("Generating chunk for biome Desert. X: %d Z: %d\n", x, z);
            //load chunk with offset
            generateChunk(biome_type, x*3, z*3);
        }
    }
}



void World::render_world()
{
    for(auto& chunk: world_chunks)
    {
        render_chunk(chunk);
    }

    block_renderer.set_render(final_VAO);
    block_renderer.render(camera);

    //render in the axis
    render_axis();
}

void World::render_axis()
{
    float axis[] = {
        -10.0f, 0.0f, 0.0f,  // Origin
        10.0f, 0.0f, 0.0f,  // Along X-axis

        // Y-axis (green)
        0.0f, -10.0f, 0.0f,  // Origin
        0.0f, 10.0f, 0.0f,  // Along Y-axis

        // Z-axis (blue)
        0.0f, 0.0f, -10.0f,  // Origin
        0.0f, 0.0f, 10.0f   // Along Z-axis
    };

    Shader axisShader;
    axisShader.setShader(ASSETS_DIR "shaders/axis.vs", ASSETS_DIR "shaders/axis.fs");

    unsigned int axisVAO, axisVBO;
    glGenVertexArrays(1, &axisVAO);
    glGenBuffers(1, &axisVBO);

    // Bind the VAO
    glBindVertexArray(axisVAO);

    // Bind and set the VBO
    glBindBuffer(GL_ARRAY_BUFFER, axisVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(axis), axis, GL_STATIC_DRAW);

    // Specify the vertex attributes (position)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    mat4 model, view, projection;
    glm_mat4_identity(model);
    camera.get_view_matrix(view);
    glm_perspective(glm_rad(camera.fov), (float)800.0f / (float)600.0f, 0.1f, 100.0f, projection);

    axisShader.use();
    axisShader.setMat4("model", model);
    axisShader.setMat4("view", view);
    axisShader.setMat4("projection", projection);

    // Render X-axis (red)
    axisShader.setVec3("color", vec3{1.0f, 0.0f, 0.0f});  // Red
    glBindVertexArray(axisVAO);
    glDrawArrays(GL_LINES, 0, 2);  // First 2 vertices for X-axis

    // Render Y-axis (green)
    axisShader.setVec3("color", vec3{0.0f, 1.0f, 0.0f});  // Green
    glDrawArrays(GL_LINES, 2, 2);  // Next 2 vertices for Y-axis

    // Render Z-axis (blue)
    axisShader.setVec3("color", vec3{0.0f, 0.0f, 1.0f});  // Blue
    glDrawArrays(GL_LINES, 4, 2);  // Last 2 vertices for Z-axis

    // Unbind VAO
    glBindVertexArray(0);
}

void World::render_chunk(Chunk &chunk)
{
    vector<Vertex> temp;
    for(auto& chunk : world_chunks)
    {
        temp = chunk.getVertices();

        final_VAO.insert(final_VAO.end(),temp.begin(), temp.end());
    }


}


void World::generateChunk(Biome_type Biome_type, int x_pos, int z_pos)
{
    std::cout << "Generating Chunk at: x:" << x_pos << " z: " << z_pos << endl;
    Chunk newChunk;
    newChunk.initChunk(camera, x_pos, z_pos);
    world_chunks.push_back(newChunk);
}


Camera& World::getCamera()
{
    return camera;
}