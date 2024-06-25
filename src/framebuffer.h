#include <GL/gl.h>

#ifndef BUFFER_H
#define BUFFER_H

typedef struct framebuffer {
    unsigned int id;
    unsigned int texture;
    unsigned int x0;
    unsigned int y0;
    unsigned int w;
    unsigned int h;
    unsigned int m;
} framebuffer_t;

framebuffer_t* BUFFER_init(int buffer_id, int w, int h);
void BUFFER_destroy(GLuint id);
void BUFFER_free(framebuffer_t* framebuffer);

#endif
