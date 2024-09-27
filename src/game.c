#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include "obscura/gfx.h"
#include "obscura/canvas.h"
#include "obscura/window.h"

#include "controller.h"
#include "data.h"
#include "game.h"
#include "global.h"
#include "level_manager.h"
#include "modules.h"
#include "resources.h"
#include "system_manager.h"
#include "symbols.h"
#include "timer.h"

#define FIRST_BUFFER 1

game_t *game      = NULL;

void GAME_handle_window_events(
) {
    while (SDL_PollEvent(&(game->event)) != 0) {
        if (game->event.type == SDL_QUIT) { 
            game->loop = false; 
        } else if (game->event.type == SDL_WINDOWEVENT && game->event.window.event == SDL_WINDOWEVENT_RESIZED) {
        }
    }
}

void GAME_init(
) {
    game                 = (game_t*)malloc(sizeof(game_t));
    game->loop           = true;
    game->frame          = 0;
};

void GAME_start_time(
) {
    TIMER_start(fps_timer);
    TIMER_start(cap_timer);
}

// prepare all screen layers and framebuffers
void GAME_fill_canvas(
) {
    CANVAS_add_defalt_buffer(canvas, window->width, window->height);
    
    CANVAS_add_layer(canvas, LAYER_BACKTILE);
    CANVAS_add_layer(canvas, LAYER_TILE);
    CANVAS_add_layer(canvas, LAYER_SPRITE);
    CANVAS_add_layer(canvas, SCALED_IMAGE);
    
    CANVAS_add_buffer(canvas, window, FIRST_BUFFER, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void GAME_update_time(
) {
    game->frame_ticks = TIMER_get_ticks(cap_timer);
    game->frame++;

    // delay frame if needed
    if(game->frame_ticks < SCREEN_TICKS_PER_FRAME) {
        SDL_Delay(SCREEN_TICKS_PER_FRAME - game->frame_ticks);
    }
}

bool GAME_shold_run(
) {
    return (game->loop) && (game->frame != -1);
}

void GAME_render_scaled_image(
) {
    CANVAS_activate_buffer(canvas, FIRST_BUFFER);
    CANVAS_activate_layer(canvas, SCALED_IMAGE);
    CANVAS_draw_scaled_buffer(canvas);

    CANVAS_activate_buffer(canvas, DEFAULT_FRAMEBUFFER);
    CANVAS_activate_layer(canvas, SCALED_IMAGE);
    CANVAS_render_current_layer(canvas);
}

// whole rendering pipeline
void GAME_render(
) {
    CANVAS_activate_layer(canvas, LAYER_BACKTILE);
    CANVAS_render_current_layer(canvas);

    CANVAS_activate_layer(canvas, LAYER_TILE);
    CANVAS_render_current_layer(canvas);

    CANVAS_activate_layer(canvas, LAYER_SPRITE);
    CANVAS_render_current_layer(canvas);

    GAME_render_scaled_image();
    WINDOW_update(window);
}

void GAME_loop(
) {
    if (!game) {
        return;
    }

    while(GAME_shold_run()) {
        GAME_start_time();
        CANVAS_clear(canvas);
        CON_update();
        SYSMAN_run();       
        GAME_render();
        GAME_update_time();
        GAME_handle_window_events();
    }
}

// TODO: rethink is it a really good place for this one
void GAME_set_level(
) { 
    level_manager->level = resources[LEVEL_NEW];
};

void GAME_new(
) {
    GAME_init();
    MODULES_init();
    
    // TODOL this 5 should be reachable somehow
    RES_read_resources(datas, 5);

    GAME_set_level();

    // TODO: this should be invoked by one OBSCURA_init() function (both 
    // LIB_create_shaders_library and GFX_init)
    GFX_init();
    LIB_create_shaders_library();

    GAME_fill_canvas();
}

void GAME_close(
) {
    // TODO: this should be invoked by OBSCURA_free() function
    LIB_free_shaders_library();
    RES_free_resources(datas, 5);
    MODULES_free();
    free(game);
    SDL_Quit();
};

void GAME_run(
) {
    GAME_new();
    GAME_loop();
    GAME_close();
}
