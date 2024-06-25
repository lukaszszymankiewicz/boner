#include "system.h"

void SYSMAN_run_phase(
    int phase,
    int depth
) {
    SYSTEM_run_on_quadrant(phase, depth);
}

void SYSMAN_run(
) {
    for (int phase=0; phase<PHASE_ALL; phase++) {
        SYSMAN_run_phase(phase, FULL_DEPTH);
    }
}
