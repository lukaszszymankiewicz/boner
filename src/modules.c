/* global structs init and deinit */

#include "modules.h"

controller_t     *keyboard;
entity_manager_t *entity_manager;
game_timer_t     *cap_timer;
game_timer_t     *fps_timer;
game_window_t    *window;
level_manager_t  *level_manager;
scene_t          *scene;

void MODULES_init(
) {
    WINDOW_init();
    CON_init();
    ENTMAN_init();
    LVLMAN_init();
    TIMER_init_fps_timer();
    TIMER_init_cap_timer();
    SCENE_init();
}

void MODULES_free(
) {
    WINDOW_free();
    CON_free();
    ENTMAN_free();
    LVLMAN_free();
    TIMER_free(cap_timer);
    TIMER_free(fps_timer);
    SCENE_free();
}
