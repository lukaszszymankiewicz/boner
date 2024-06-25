/* rendering things to screen code. Mostly hard gl functions. */

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>

#include <stdio.h>

#include "./data/library.h"

#include "render.h"

void RENDER_set_uniform(
    int      uniform_id,
    int      type,
    array_t *uniform
) {
    float* v = uniform->values;

    switch (type)
    {
        case GL_FLOAT:
            glUniform1f(uniform_id, v[0]);
            break;
        case GL_FLOAT_VEC2:
            glUniform2f(uniform_id, v[0], v[1]);
            break;
        case GL_FLOAT_VEC3:
            glUniform3f(uniform_id, v[0], v[1], v[2]);
            break;
        case GL_FLOAT_VEC4:
            glUniform4f(uniform_id, v[0], v[1], v[2], v[3]);
            break;
        case GL_SAMPLER_2D:
            glUniform1i(uniform_id, (int)v[0]);
            break;
        case GL_FLOAT_MAT2:
            glUniformMatrix2fv(uniform_id, 1, GL_FALSE, &v[0]);
            break;
        default:
            printf("    unknown uniform! \n");
            break;
    }
}

int RENDER_uniform_n(
    int         shader
) {
    return shader_library[shader]->n_uniforms;
}

int RENDER_get_uniform_index(
    int         shader,
    const char* uniform
) {
    int n_uniforms = RENDER_uniform_n(shader);

    for (int u=0; u<n_uniforms; u++) { 
        const char *name = shader_library[shader]->uniforms[u]->name;

        if (strcmp(name, uniform) == 0) {
            return u;
        }
    }
    return -1;
}

int RENDER_get_uniform_size(
    int shader,
    int uniform
) {
    return shader_library[shader]->uniforms[uniform]->size;
}

void RENDER_set_uniforms(
    int      shader,
    array_t *uniforms[]
) {
    for (int u=0; u<shader_library[shader]->n_uniforms; u++) { 
        int   uniform_id = shader_library[shader]->uniforms[u]->loc;
        int   type       = shader_library[shader]->uniforms[u]->type;

        RENDER_set_uniform(uniform_id, type, uniforms[u]);
    }
}

void RENDER_clear_buffer(
    int   buffer
) {
    glBindFramebuffer(GL_FRAMEBUFFER, buffer);
    glClearColor(
        135.0 / 256.0,
        206.0 / 256.0,
        235.0 / 256.0,
        1.0f
    );
    glClear(GL_COLOR_BUFFER_BIT);
}

void RENDER_set_viewport(
    int            buffer,
    int            buffer_w,
    int            buffer_h
) { 
    glBindFramebuffer(GL_FRAMEBUFFER, buffer);
    glViewport(0, 0, buffer_w, buffer_h);    
}

GLint RENDER_set_gl_mode(
    int mode
) { 
    switch (mode)
    {
        case RENDER_MODE_TEXTURE:
            return GL_TRIANGLES;
            break;
        default:
            printf("    unknown render mode! \n");
            return 0;
            break;
    }

    return 0;
}

void RENDER_shader(
    int            shader,
    int            texture,
    float         *vertices,
    int            n_vertices,
    array_t       *uniforms[MAX_SHADER_UNIFORMS],
    int            count,
    int            mode
) { 
    glUseProgram(shader_library[shader]->program);

    glBindVertexArray(shader_library[shader]->vao);
    glBindBuffer(GL_ARRAY_BUFFER, shader_library[shader]->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*n_vertices, vertices, GL_STATIC_DRAW);
    RENDER_set_uniforms(shader, uniforms);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawArrays(RENDER_set_gl_mode(mode), 0, count);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
