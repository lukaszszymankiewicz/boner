/* global structs init and deinit */

#include "modules.h"
#include "global.h"

controller_t     *keyboard;
game_timer_t     *cap_timer;
game_timer_t     *fps_timer;
game_window_t    *window;
level_manager_t  *level_manager;
canvas_t          *canvas;

void MODULES_init(
) {
    window = WINDOW_init(GAME_NAME);
    CON_init();
    LVLMAN_init();
    TIMER_init_fps_timer();
    TIMER_init_cap_timer();
    canvas = CANVAS_init();
}

void MODULES_free(
) {
    WINDOW_free(window);
    CON_free();
    LVLMAN_free();
    TIMER_free(cap_timer);
    TIMER_free(fps_timer);
    CANVAS_free(canvas);
}
