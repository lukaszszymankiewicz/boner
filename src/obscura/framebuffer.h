#include "window.h"
#include "texture.h"

#ifndef BUFFER_H
#define BUFFER_H

texture_t* BUFFER_init(int window_w, int window_h, int w, int h);
void BUFFER_destroy(int id);
void BUFFER_free(texture_t* framebuffer);

#endif
