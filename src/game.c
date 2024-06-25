/* Main game file, here the start, end and the main loop of the game is
 * controlled */

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include "data/library.h"

#include "modules.h"
#include "controller.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "level_manager.h"
#include "scene.h"
#include "system_manager.h"
#include "timer.h"
#include "window.h"

game_t *game      = NULL;

void GAME_handle_window_events(
) {
    while (SDL_PollEvent(&(game->event)) != 0) {
        if (game->event.type == SDL_QUIT) { 
            game->loop = false; 
        } else if (game->event.type == SDL_WINDOWEVENT && game->event.window.event == SDL_WINDOWEVENT_RESIZED) {
            // TODO
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
void GAME_fill_scene(
) {
    SCENE_add_defalt_buffer();

    SCENE_add_layer(LAYER_BACKTILE, "Backtiles");
    SCENE_add_layer(LAYER_TILE,     "Tiles");
    SCENE_add_layer(LAYER_SPRITE,   "Sprites");
    SCENE_add_layer(SCALED_IMAGE,   "Pixelated Image");
    
    SCENE_add_buffer(FIRST_BUFFER, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void GAME_update_time(
) {
    // update ticks
    game->frame_ticks = TIMER_get_ticks(cap_timer);
    
    // update frame
    game->frame++;

    // delay frame if needed
    if(game->frame_ticks < SCREEN_TICKS_PER_FRAME) {
        SDL_Delay(SCREEN_TICKS_PER_FRAME - game->frame_ticks);
    }
}

// check if game should run or it ended
bool GAME_shold_run(
) {
    return (game->loop) && (game->frame != -1);
}

void GAME_render_scaled_image(
) {
    SCENE_activate_buffer(FIRST_BUFFER);
    SCENE_activate_layer(SCALED_IMAGE);
    SCENE_draw_scaled_buffer();

    SCENE_activate_buffer(DEFAULT_FRAMEBUFFER);
    SCENE_activate_layer(SCALED_IMAGE);
    SCENE_render_current_layer();
}

// whole rendering pipeline
void GAME_render(
) {
    SCENE_activate_layer(LAYER_BACKTILE);
    SCENE_render_current_layer();

    SCENE_activate_layer(LAYER_TILE);
    SCENE_render_current_layer();

    SCENE_activate_layer(LAYER_SPRITE);
    SCENE_render_current_layer();

    GAME_render_scaled_image();
    WINDOW_update();
}

// main game loop
void GAME_loop(
) {
    if (!game) {
        return;
    }

    while(GAME_shold_run()) {
        GAME_start_time();
        SCENE_clear();
        CON_update();
        SYSMAN_run_all();       
        GAME_render();
        GAME_update_time();
        GAME_handle_window_events();
    }
}

// orient sectors accoringg to main focus point
void GAME_orient_level(
) {
    int sec_x = level_manager->focus_x;
    int sec_y = level_manager->focus_y;

    ENTMAN_orient_sectors(sec_x, sec_y);
}

void GAME_new(
) {
    GAME_init();
    MODULES_init();

    GFX_init();
    LIB_init();

    LVLMAN_set_level(LEVEL_NEW);
    GAME_orient_level();
    SYSMAN_run_init();

    GAME_fill_scene();
}

void GAME_close(
) {
    LIB_free_all();
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
