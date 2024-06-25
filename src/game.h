#include <SDL2/SDL.h>

#ifndef GAME_H
#define GAME_H

typedef struct game {
  int       loop;
  int       frame;
  int       frame_ticks;
  SDL_Event event;
} game_t;

void GAME_run();

#endif
