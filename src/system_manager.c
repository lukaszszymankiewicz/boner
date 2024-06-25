#include "data/library.h"

#include "system.h"
void SYSMAN_run_control(
) {
    SYSTEM_run_on_quadrant(PHASE_CONTROL, CONTROL_DEPTH);
}

void SYSMAN_run_init(
) {
    SYSTEM_run_on_quadrant(PHASE_INIT, INIT_DEPTH);
}

void SYSMAN_run_update(
) {
    SYSTEM_run_on_quadrant(PHASE_UPDATE, UPDATE_DEPTH);
}

void SYSMAN_run_resolve(
) {
    SYSTEM_run_on_quadrant(PHASE_RESOLVE, RESOLVE_DEPTH);
}

void SYSMAN_run_pre_tasks(
) {
    SYSTEM_run_on_quadrant(PHASE_PRE, PRE_DEPTH);
}

void SYSMAN_run_collision(
) {
    SYSTEM_run_on_quadrant(PHASE_COLLISION, COLLISION_DEPTH);
}

void SYSMAN_run_draw(
) {
    SYSTEM_run_on_quadrant(PHASE_DRAW, DRAW_DEPTH);
}

void SYSMAN_run_all(
) {
    SYSMAN_run_pre_tasks();
    SYSMAN_run_control();
    SYSMAN_run_update();
    SYSMAN_run_collision();
    SYSMAN_run_resolve();
    SYSMAN_run_draw();
}

