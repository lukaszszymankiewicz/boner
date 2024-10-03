/* Creating and managing window related code */

#include <GL/glew.h>

#include <stdio.h>
#include <stdlib.h>

#include "window.h"

game_window_t* WINDOW_init(
    char* name
) {
    game_window_t *window = NULL;
    window                = (game_window_t*)malloc(sizeof(game_window_t));
    window->screen        = NULL;

    window->screen = SDL_CreateWindow(
        name,
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
    
    return window;
};

void WINDOW_update(
    game_window_t *window
) {
    SDL_GL_SwapWindow(window->screen);
    SDL_UpdateWindowSurface(window->screen);
};

void WINDOW_free(
    game_window_t *window
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
