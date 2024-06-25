#include <SDL2/SDL.h>

#ifndef WINDOW_H
#define WINDOW_H

#define SCREEN_FPS                   20                 
#define SCREEN_TICKS_PER_FRAME       1000 / SCREEN_FPS 

// base screen size, rendering will be scaling to this resolution
#define SCREEN_HEIGHT                240                
#define SCREEN_WIDTH                 320               
#define DEFAULT_FRAMEBUFFER          0

typedef struct game_window {
    SDL_Window    *screen;
    SDL_GLContext  gl_context;
    int            camera_x;
    int            camera_y;
    float          width;
    float          height;
} game_window_t;

game_window_t* WINDOW_init(char *name);
void WINDOW_update(game_window_t* window);
void WINDOW_free(game_window_t* window);
void WINDOW_set(game_window_t* window, int x, int y);

#endif
