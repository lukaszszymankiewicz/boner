#include <assert.h>

#include "data/library.h"

#include "behaviour.h"
#include "collision.h"
#include "macros.h"

// get behaviour for given phase + entity + state.
int BEH_get(
    int     bpt, 
    int     phase,
    int     state,
    int     n 
) {
    ASSERT_RANGE(0, phase, PHASE_ALL);
    ASSERT_RANGE(0, bpt, ENTITY_ALL);
    ASSERT_RANGE(0, state, MAX_STATE);
    ASSERT_RANGE(0, n, MAX_BEHAVIOURS+1);
    
    int behavior_idx = behavior_matrix[phase][bpt][state][n];
    ASSERT_RANGE(0, behavior_idx, BEHAVIOUR_ALL);
    assert(behavior_idx != 0);

    return behavior_idx;
}

// get collision behaviour for given phase + entity + state.
int BEH_get_collision(
    int     bpt, 
    int     state,
    int     bpt_col,
    int     state_col 
) {
    ASSERT_RANGE(0, bpt, ENTITY_ALL);
    ASSERT_RANGE(0, bpt_col, PHASE_ALL);
    ASSERT_RANGE(0, state, MAX_STATE);
    ASSERT_RANGE(0, state_col, MAX_STATE);

    int collision_fun_idx = behaviour_collision_matrix[bpt][state][bpt_col][state_col];
    
    ASSERT_RANGE(0, collision_fun_idx, COLLISION_BEHAVIOUR_ALL);
    assert(collision_fun_idx != 0);
    
    return collision_fun_idx;
}

int BEH_n_behaviours(
    context_t *ctx
) {
    int bpt   = ctx->blueprint;
    int phase = ctx->phase;
    int state = ctx->subphase;

    ASSERT_RANGE(0, phase, PHASE_ALL);
    ASSERT_RANGE(0, bpt, ENTITY_ALL);
    ASSERT_RANGE(0, state, MAX_STATE);
    
    // number of behaviours per given phase + entity + state has constant index
    // `BEHAVIOURS_IDX`
    return behavior_matrix[phase][bpt][state][BEHAVIOURS_IDX];
}

// Run collision behaviour for given phase + entity + state.
// Collision data is stored in `collision_t`
void BEH_run_collision(
    int          ent,
    context_t   *ctx,
    collision_t  col
) {
    // get collider entity ID
    int col_id = col.col_id;

    int bpt       = ENTMAN_get_component(ent, ENTITY_COMPONENT_BLUEPRINT_ID);
    int bpt_col   = ENTMAN_get_component(col_id, ENTITY_COMPONENT_BLUEPRINT_ID);
    int state     = ENTMAN_get_component(ent, ENTITY_COMPONENT_STATE);
    int state_col = ENTMAN_get_component(col_id, ENTITY_COMPONENT_STATE);
    
    // get collision function ID
    int collision_fun_idx = BEH_get_collision(bpt, state, bpt_col, state_col);
    
    // run collision function
    collision_behaviour_library[collision_fun_idx]->behaviour(ent, ctx, col);
}

void BEH_run(
    context_t* ctx,
    int        n
) {
    int ent    = ctx->entity;
    int bpt    = ctx->blueprint;
    int phase  = ctx->phase;
    int state  = ctx->subphase;

    assert(BEH_n_behaviours(ctx) >= n);

    int behavior_idx = BEH_get(bpt, phase, state, n);
    behaviour_library[behavior_idx].behaviour(ent, ctx);
}
