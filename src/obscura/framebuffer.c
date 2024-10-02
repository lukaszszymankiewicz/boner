#include <GL/glew.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "framebuffer.h"
#include "window.h"
#include "texture.h"


texture_t* BUFFER_init(
    game_window_t* window,
    int            w,
    int            h
) {
    assert(w<=window->width);
    assert(h<=window->height);
    
    // get multiplication coeficient for pixel perfect scaling
    int w_coef = (int)window->width  / w;
    int h_coef = (int)window->height / h;
    
    int m = (w_coef > h_coef) ? h_coef : w_coef;

    // buffer with size other tham physical window size must be corrected to fit
    // entire screen
    if ((w != window->width) || (h != window->height)) {
        w += ((window->width  - (m*w)) / m);
        h += ((window->height - (m*h)) / m);

        // few additional pixels to corver division inaccuracies
        w += m;
        h += m;
    } else {
        assert(m==1);
    }

    // check whether the calculation is correct
    assert((window->width  - w * m) <= m);
    assert((window->height - h * m) <= m);

    texture_t* framebuffer = NULL;
    framebuffer            = (texture_t*)malloc(sizeof(texture_t));

    GLuint id;
    glGenFramebuffers(1, &id);
    glBindFramebuffer(GL_FRAMEBUFFER, id);

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    
    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGBA,
        w, h,
        0, GL_RGBA, GL_UNSIGNED_BYTE, NULL
    );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glFramebufferTexture2D(
        GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex, 0
    );

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        printf("Framebuffer cannot be created! \n");
        return NULL;
    }
    
    framebuffer->surface    = NULL;
    framebuffer->gl_id      = id;
    framebuffer->texture    = tex;
    framebuffer->x0         = 0;
    framebuffer->y0         = 0;
    framebuffer->m          = m;
    framebuffer->width      = w;
    framebuffer->height     = h;

    glEnablei(GL_BLEND, id);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return framebuffer;
}

void BUFFER_destroy(
    int id
) {
    GLuint gl_id = (GLuint)id;
    glDeleteFramebuffers(1, &gl_id);
}

void BUFFER_free(
    texture_t* framebuffer
) {
    free(framebuffer);
    framebuffer = NULL;
}

