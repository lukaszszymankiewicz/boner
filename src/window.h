#include <SDL2/SDL.h>

#include "global.h"

#ifndef WINDOW_H
#define WINDOW_H

#define SCREEN_FPS                   20                 
#define SCREEN_TICKS_PER_FRAME       1000 / SCREEN_FPS 

// base screen size - it is aligned with the physical size, but those values are
// used as base for pixel-perfect rendering
#define SCREEN_HEIGHT                240                
#define SCREEN_WIDTH                 320               

enum buffers     { DEFAULT_FRAMEBUFFER, FIRST_BUFFER, BUFFER_ALL};

typedef struct game_window {
    SDL_Window    *screen;
    SDL_GLContext  gl_context;
    int            camera_x;
    int            camera_y;
    float          width;
    float          height;
} game_window_t;

void WINDOW_init();
void WINDOW_update();
void WINDOW_free();

#endif
