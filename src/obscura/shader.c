/* Gl shader related code. Mostly basic stuff, please see some basic tutorial to
 * get around. */

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shader.h"

#define SHADER_CHECK_MODE        "rb"
#define SHADER_READ_MODE         "r"
#define ALLOWED_UNIFORM_NAME_LEN  16
#define ALLOWED_ATTRIB_NAME_LEN   16
#define UNUSED_SHADER_PROGRAM_ID  -1

int max_buffer_len              = 512;

int SHADER_check_compile_status(
    GLuint shader_id
) {
    GLint status;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &status);
    
    if (status == GL_FALSE) {
        char buffer[max_buffer_len];
        glGetShaderInfoLog(shader_id, max_buffer_len, NULL, buffer);
        printf("Shader compilation error: %s", buffer);
        return 0;
    }
    return 1;
}

int SHADER_check_program_link_status(
    GLuint program 
) {
    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);

    if (linked == GL_FALSE) {
        char buffer[max_buffer_len];
        glGetProgramInfoLog(program, max_buffer_len, NULL, buffer);
        printf("Program link error: %s \n", buffer);
        return 0;
    }
    return 1;
}

char* SHADER_read_file(
   const char* path
) {
    FILE *fp;
    long  size = 0;
    char* shader;
    
    fp = fopen(path, SHADER_CHECK_MODE);

    if(fp == NULL) {
        printf("COULD NOT OPEN SHADER FROM PATH: %s!\n", path);
        return "";
    }

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp) + 1;
    fclose(fp);

    fp = fopen(path, SHADER_READ_MODE);
    shader = memset(malloc(size), '\0', size);
    fread(shader, 1, size-1, fp);
    fclose(fp);

    return shader;
}

int SHADER_compile(
    const char *path,
    GLenum      type
) {
    char* src   = SHADER_read_file(path); 
    GLuint id   = glCreateShader(type);
    
    glShaderSource(id, 1, (const GLchar**)&src, NULL);
    glCompileShader(id);

    if (!SHADER_check_compile_status(id)) {
        printf("Shader %s failed to compiled!\n", path);
        return -1; 
    }
    free(src);
    return (int)id;
}

int SHADER_type_size(
    GLenum type
) {
    switch (type)
    {
        case GL_FLOAT_VEC2:
            return 2 * sizeof(GL_FLOAT);
        case GL_FLOAT_VEC3:
            return 3 * sizeof(GL_FLOAT);
        case GL_FLOAT_VEC4:
            return 4 * sizeof(GL_FLOAT);
        case GL_SAMPLER_2D:
            return 1 * sizeof(GLuint);
        case GL_FLOAT_MAT2:
            return 4 * sizeof(GL_FLOAT);
        case GL_FLOAT:
            return 1 * sizeof(GL_FLOAT);
        default:
            return -1;
    }
}

shader_program_t* SHADER_init(
    const char* vertex_shader_path,
    const char* fragment_shader_path,
    const char* geometry_shader_path
) {
    GLint i;
    GLint n_uniforms, n_attribs;

    GLenum  type; 
    GLchar  name[ALLOWED_UNIFORM_NAME_LEN];
    GLsizei length;

    shader_program_t* shader_program = NULL;
    shader_program                   = (shader_program_t*)malloc(sizeof(shader_program_t));

    int vertex_shader_id = SHADER_compile(vertex_shader_path, GL_VERTEX_SHADER);
    if (vertex_shader_id == -1) { return NULL; }

    int fragment_shader_id = SHADER_compile(fragment_shader_path, GL_FRAGMENT_SHADER);
    if (fragment_shader_id == -1) { return NULL; }
    
    // geometry TBD
    // glAttachShader(program_id, geometry_shader_id);

    // link 
    GLuint program_id = glCreateProgram();

    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);
    glLinkProgram(program_id);
    if (SHADER_check_program_link_status(program_id) == 0) { return NULL; }
    
    //cleanup
    glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);

    glDetachShader(program_id, vertex_shader_id);
    glDetachShader(program_id, fragment_shader_id);

    // put everything in place
    shader_program->vertex_shader_id   = vertex_shader_id;
    shader_program->fragment_shader_id = fragment_shader_id;                   
    shader_program->geometry_shader_id = UNUSED_SHADER_PROGRAM_ID;
    shader_program->program            = program_id;

    // get uniforms
    glGetProgramiv(program_id, GL_ACTIVE_UNIFORMS, &n_uniforms);
    shader_program->n_uniforms = (int)n_uniforms;

    for (i=0; i<(int)n_uniforms; i++) {
        shader_program->uniforms[i] = NULL;
        shader_program->uniforms[i] = (uniform_t*)malloc(sizeof(uniform_t));

        int loc;
        glGetActiveUniform(program_id, (GLuint)i, ALLOWED_UNIFORM_NAME_LEN, &length, NULL, &type, name);
        shader_program->uniforms[i]->name = NULL;
        shader_program->uniforms[i]->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
        strcpy(shader_program->uniforms[i]->name, name);

        loc                                = glGetUniformLocation(program_id, name);
        shader_program->uniforms[i]->loc   = loc;
        shader_program->uniforms[i]->type  = type;
        shader_program->uniforms[i]->size  = SHADER_type_size(type);
    }
    
    // create VBO
    glGenBuffers(1, &shader_program->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, shader_program->vbo);

    // create VAO 
    glGenVertexArrays(1, &shader_program->vao);
    glBindVertexArray(shader_program->vao);

    // get attribs
    n_attribs = (GLuint)0;
    glGetProgramiv(program_id, GL_ACTIVE_ATTRIBUTES, &n_attribs);
    
    int    locs[n_attribs]; 
    int    vec_sizes[n_attribs]; 
    int    stride = 0;

    for (i=0; i<n_attribs; i++) {
        GLenum type; int loc; 

        glGetActiveAttrib(program_id, (GLuint)i, ALLOWED_ATTRIB_NAME_LEN, NULL, NULL, &type, name);
        loc      = (int)glGetAttribLocation(program_id, name);
        locs[i]  = loc;

        vec_sizes[i]  = SHADER_type_size(type) / sizeof(GL_FLOAT);
        stride       += vec_sizes[i];
    }

    int    atrb_size = 0;

    for (i=0; i<n_attribs; i++) {
        glEnableVertexAttribArray(locs[i]);
        glVertexAttribPointer(
            locs[i],
            vec_sizes[i],
            GL_FLOAT,
            GL_FALSE,
            stride*sizeof(float),
            (void*)(atrb_size*sizeof(float))
        );

        atrb_size += vec_sizes[i];
    }

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return shader_program;
}

void SHADER_free(
    shader_program_t *shader
) {
    for (int i=0; i<shader->n_uniforms; i++) {
        free(shader->uniforms[i]->name);
        shader->uniforms[i]->name = NULL;
        
        free(shader->uniforms[i]);
        shader->uniforms[i] = NULL;
    }

    glDeleteProgram(shader->program);
    free(shader);
    shader = NULL;
}
