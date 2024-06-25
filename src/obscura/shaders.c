#include <stdlib.h>
#include <stdio.h>

#include "shader.h"

typedef struct shader_program_blueprint {
    int   id;
    const char *vertex_shader_path;
    const char *fragment_shader_path;
    const char *geomentry_shader_path;
} shader_program_blueprint_t;

shader_program_t* shader_library[SHADER_ALL] = { NULL };

shader_program_blueprint_t shader_texture = {
    SHADER_TEXTURE,
    "./src/obscura/shaders/tex_vertex.glsl",
    "./src/obscura/shaders/tex_fragment.glsl",
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
        printf("[SHADER (%s) read\n", blueprint->vertex_shader_path);
    }

    shader_library[blueprint->id] = shader;
};

void LIB_create_shaders_library(
) {
    LIB_read_shader_blueprint(&shader_texture);
};

void LIB_free_shaders_library(
) {
    SHADER_free(shader_library[SHADER_TEXTURE]);
}
