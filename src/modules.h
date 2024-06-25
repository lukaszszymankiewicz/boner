#include "controller.h"
#include "entity_manager.h"
#include "level_manager.h"
#include "scene.h"
#include "timer.h"
#include "window.h"

#ifndef MODULES_H
#define MODULES_H

extern entity_manager_t *entity_manager;
extern level_manager_t  *level_manager;
extern controller_t     *keyboard;
extern game_timer_t     *fps_timer;
extern game_timer_t     *cap_timer;
extern game_window_t    *window;
extern scene_t          *scene;

void MODULES_init();
void MODULES_free();

#endif
