#include "library.h"

#include "../shader.h"

shader_program_t* shader_library[SHADER_ALL] = { NULL };

shader_program_blueprint_t shader_texture = {
    SHADER_TEXTURE,
    "./src/data/shaders/tex_vertex.glsl",
    "./src/data/shaders/tex_fragment.glsl",
    "",
};

void LIB_read_shader_blueprint(
    shader_program_blueprint_t *blueprint
) {
    shader_program_t* shader = SHADER_init(
        blueprint->vertex_shader_path,
        blueprint->fragment_shader_path,
        blueprint->geomentry_shader_path
    );

    if (shader) {
        printf("SHADER ID = %d read\n", blueprint->id);
    }
    shader_library[blueprint->id] = shader;
};

void LIB_create_shaders_library(
) {
    LIB_read_shader_blueprint(&shader_texture);
};
