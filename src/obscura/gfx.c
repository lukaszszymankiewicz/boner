/* OpenGl related code, all init of gl things are here */

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>

#include "gfx.h"

// shamesly copied from Stack Overflow
void GLAPIENTRY MessageCallback(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam 
) {
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n", ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ), type, severity, message);
}

void GFX_init_sdl_with_gl(
) {
    SDL_GL_SetAttribute(OPENGL_MAJOR_VERSION, OPENGL_MAJOR_VERSION);
    SDL_GL_SetAttribute(OPENGL_MINOR_VERSION, OPENGL_MINOR_VERSION);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 1);
}

void GFX_init_glew(
) {
    glewInit();
}

void GFX_init_gl_params(
) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);
}

void GFX_init_png(
) {
    IMG_Init(IMG_INIT_PNG);
};

void GFX_init(
) {
    GFX_init_sdl_with_gl();
    GFX_init_glew();
    GFX_init_gl_params();
    GFX_init_png();
}

void GFX_free(
) {
    // lenny face
}
