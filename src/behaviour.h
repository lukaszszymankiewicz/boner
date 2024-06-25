/* Handling the entity behaviour according to their state, frame etc.
 * Correct behaviour is read from `context_t` struct. Behaviours are run
 * sequentially (see src/data/behaviours.c) for each entity, state and state.
 */

#include "collision.h"

#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#define BEHAVIOURS_IDX      0
#define FIRST_BEHAVIOUR_IDX 1
#define MAX_BEHAVIOURS      5

// contex of each behaviour
typedef struct context {
    int entity;
    int blueprint;
    int sec_x;
    int sec_y;
    int global_sec_x;
    int global_sec_y;
    int phase;
    int subphase;
    int arg;
} context_t;

void BEH_run_collision(int e, context_t *c, collision_t col);
void BEH_run(context_t* c, int i);
int BEH_n_behaviours(context_t* c);

#endif
