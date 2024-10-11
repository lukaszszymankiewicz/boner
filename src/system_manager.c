#include "level_manager.h"
#include "system.h"

void SYSMAN_run(
) {
    int x = LVLMAN_focus_x();
    int y = LVLMAN_focus_y();
    
    // TODO: maybe just init everything at start
    SYSTEM_run(PHASE_INIT, 3, x, y);
    SYSTEM_run(PHASE_PRE, FULL_DEPTH, x, y);

    SYSTEM_run(PHASE_UPDATE, FULL_DEPTH, x, y);
    SYSTEM_run(PHASE_CONTROL, FULL_DEPTH, x, y);
    SYSTEM_run(PHASE_COLLISION, FULL_DEPTH, x, y);
    SYSTEM_run(PHASE_RESOLVE, FULL_DEPTH, x, y);
    SYSTEM_run(PHASE_DRAW, FULL_DEPTH, x, y);
}
