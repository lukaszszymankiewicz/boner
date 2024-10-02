#include "window.h"
#include "texture.h"

#ifndef BUFFER_H
#define BUFFER_H

int BUFFER_pixel_coef(game_window_t *window, int w, int h);
texture_t* BUFFER_init(game_window_t* window, int w, int h);
void BUFFER_destroy(int id);
void BUFFER_free(texture_t* framebuffer);

#endif
