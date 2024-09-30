#ifndef SHADER_H
#define SHADER_H

#define MAX_SHADER_UNIFORMS  8

enum SHADER_IDX {
    SHADER_TEXTURE,
    SHADER_ALL
};

typedef struct uniform {
    int   loc;
    int   type;
    int   size;
    char *name;
} uniform_t;

typedef struct shader_program_blueprint {
    int   id;
    const char *vertex_shader_path;
    const char *fragment_shader_path;
    const char *geomentry_shader_path;
} shader_program_blueprint_t;

typedef struct shader_program {
    int           program;
    int           vertex_shader_id;
    int           fragment_shader_id;
    int           geometry_shader_id;
    int           n_uniforms;
    uniform_t    *uniforms[MAX_SHADER_UNIFORMS];
    unsigned int  vao;
    unsigned int  vbo;
} shader_program_t;

shader_program_t* SHADER_init(
    const char* vertex_shader_path,
    const char* fragment_shader_path,
    const char* geometry_shader_path
);

shader_program_t *shader_library[SHADER_ALL];

void SHADER_free(shader_program_t *shader);
void SHADER_create_library();
void SHADER_free_library();

#endif
