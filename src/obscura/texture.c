/* GL texture replated code */

#include <assert.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL2/SDL_image.h>

#include <stdlib.h>

#include "texture.h"


int TEXTURE_MODE                = GL_RGB;

// a lot of defaults, but I dont care
texture_t* TEX_read_texture(
    const char *filepath,
    int         sprite
) {
    assert(filepath);
    assert(sprite>=0);

    SDL_Surface  *surface = NULL;
    texture_t    *texture = NULL;
    GLuint        gl_id;

    surface                = IMG_Load(filepath);
    texture                = (texture_t*)malloc(sizeof(texture_t));
    
    assert(surface);

    glGenTextures(1, &gl_id);
    glBindTexture(GL_TEXTURE_2D, gl_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if(surface && surface->format->BytesPerPixel == 4) {
        TEXTURE_MODE = GL_RGBA; 
    }

    // surface can be NULL, check must be done beforehand
    if (surface) {
        glTexImage2D(
            GL_TEXTURE_2D, 0, TEXTURE_MODE,
            surface->w, surface->h,
            0, TEXTURE_MODE, GL_UNSIGNED_BYTE, surface->pixels
        );
    }

    texture->surface = surface;
    texture->gl_id   = gl_id;
    texture->width   = surface->w;
    texture->height  = surface->h;
    texture->sprite  = sprite;

    glBindTexture(GL_TEXTURE_2D, 0);

    return texture;
}

void TEX_free(
    texture_t* texture
) {
    if (texture && texture->surface) {
        SDL_FreeSurface(texture->surface);
        texture->surface    = NULL;
        GLuint TextureID    = texture->gl_id;
        glDeleteTextures(1, &TextureID);
        free(texture);
        texture = NULL;
    }
}
