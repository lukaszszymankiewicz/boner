#include <SDL2/SDL.h>

#ifndef TEX_H
#define TEX_H

#define DEFAULT_TEXTURE_UNIT 0

typedef struct texture {
    int          gl_id;
    int          sprite;
    SDL_Surface *surface;
    int          width;
    int          height;
} texture_t;

texture_t* TEX_read_texture(const char *filepath, int sprite);

void TEX_free(texture_t* texture);

#endif
