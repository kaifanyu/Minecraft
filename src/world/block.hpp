#include <string>
#include <vector>


enum Block_Type{
    DIRT = 0,
    GRASS
};


//Block("DIRT") will generate the vertices with correct texture verticies

class Block{
    public:
        std::vector<float> vertices;
        int attribute_count;
        Block();
        Block(Block_Type type);

    private:
        void init_vertex_vector();
        void append_normal_vector();
        void append_texture_vector(Block_Type type);
};