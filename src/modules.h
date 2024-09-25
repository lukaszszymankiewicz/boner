#include "controller.h"
#include "level_manager.h"
#include "timer.h"

#include "obscura/canvas.h"
#include "obscura/window.h"

#ifndef MODULES_H
#define MODULES_H

extern level_manager_t  *level_manager;
extern controller_t     *keyboard;
extern game_timer_t     *fps_timer;
extern game_timer_t     *cap_timer;
extern game_window_t    *window;
extern canvas_t          *canvas;

void MODULES_init();
void MODULES_free();

#endif
