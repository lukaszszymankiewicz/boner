/* Creating and managing window related code */

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>

#include "modules.h"
#include "window.h"

void WINDOW_init(
) {
    window            = NULL;
    window            = (game_window_t*)malloc(sizeof(game_window_t));
    window->screen    = NULL;
    window->camera_x  = 0;
    window->camera_y  = 0;

    window->screen = SDL_CreateWindow(
        GAME_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        -1,
        -1,
        SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL
    );

    if (!(window->screen)) {
        printf("Error: %s \n", SDL_GetError());
    }

    // disable cursor on window
    SDL_ShowCursor(SDL_DISABLE);
    
    // create context
    window->gl_context = NULL;
    window->gl_context = SDL_GL_CreateContext(window->screen);

    if (!(window->gl_context)) {
        printf("Error: %s \n", SDL_GetError());
    } 

    GLint m_viewport[4];
    glGetIntegerv(GL_VIEWPORT, m_viewport);
    
    window->width  = (float)m_viewport[2];
    window->height = (float)m_viewport[3];

};

void WINDOW_update(
) {
    SDL_GL_SwapWindow(window->screen);
    SDL_UpdateWindowSurface(window->screen);
};

void WINDOW_free(
) {
    if (!window) {
        return;
    }

    if (window->gl_context) {
        SDL_GL_DeleteContext(window->gl_context);
        window->gl_context = NULL;
    }

    if (window->screen) {
        SDL_DestroyWindow(window->screen);
        window->screen = NULL;
    }

    free(window); 
    window = NULL;
};
