#include "collision.h"
#include "symbols.h"

#ifndef SYSTEM_H
#define SYSTEM_H

#define FULL_DEPTH      2

typedef void (*behaviour)(int);
typedef void (*collision_behaviour)(int, collision_t);

behaviour behaviour_library[BEHAVIOUR_ALL];
collision_behaviour collision_behaviour_library[COLLISION_BEHAVIOUR_ALL];

void SYSTEM_run_on_quadrant(int phase, int phase_depth);
void SYSTEM_normal_collision(int e, collision_t col);

#endif
