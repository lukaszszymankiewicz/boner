#include <SDL2/SDL.h>

#ifndef TEX_H
#define TEX_H

#define DEFAULT_TEXTURE_UNIT 0

typedef struct texture {
    SDL_Surface *surface;
    int          gl_id;    // gl id
    int          sprite;   // game id
    int          texture;  // gl tex id
    int          width;
    int          height;
    int          x0;
    int          y0;
    int          m;
} texture_t;

texture_t* TEX_read_texture(const char *filepath, int sprite);

void TEX_free(texture_t* texture);

#endif
