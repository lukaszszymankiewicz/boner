#include <assert.h>

#include "datatable.h"
#include "entity.h"
#include "geometry.h"
#include "level_manager.h"
#include "macros.h"
#include "modules.h"
#include "resources.h"
#include "symbols.h"

int ENT_def_begin_idx(
    entity_t ent
) {
    return DATATABLE_get_val(ent, DEFAULTS_BEGIN_IDX, DATA_COL_D);
}

int ENT_beh_begin_idx(
    entity_t ent
) {
    return DATATABLE_get_val(ent, BEHAVIOUR_BEGIN_IDX, DATA_COL_D);
}

int ENT_anim_begin_idx(
    entity_t ent
) {
    return DATATABLE_get_val(ent, ANIMATION_BEGIN_IDX, DATA_COL_D);
}

int ENT_collision_begin_idx(
    entity_t ent
) {
    return DATATABLE_get_val(ent, COLLISION_BEGIN_IDX, DATA_COL_D);
}

int ENT_anim(
    int bpt,
    int anim
) {
    entity_t ent = resources[bpt];

    int anim_idx = ENT_anim_begin_idx(ent) + anim;

    return DATATABLE_get_val(ent, anim_idx, DATA_COL_D);
}

int ENT_anim_len(
    int bpt,
    int anim
) {
    entity_t ent = resources[bpt];

    int anim_idx = ENT_anim_begin_idx(ent) + anim;

    return DATATABLE_get_val(ent, anim_idx, DATA_COL_B);
}

int ENT_frame_data(
    int bpt, 
    int state,
    int frame,
    int comp,
    int val
) {
    entity_t ent        = resources[bpt];
    int frame_idx       = ENT_anim(bpt, state) + frame;
    int frame_data_idx  = DATATABLE_get_val(ent, frame_idx, DATA_COL_D);
    
    return DATATABLE_get_val(ent, frame_data_idx+comp, val);
}

rectangle_t ENT_hitbox_rect(
    int ent
) {
    int x      = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y      = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);
    int hx     = LVLMAN_get_component(ent, ENTITY_COMPONENT_HITBOX_X);
    int hy     = LVLMAN_get_component(ent, ENTITY_COMPONENT_HITBOX_Y);
    int hw     = LVLMAN_get_component(ent, ENTITY_COMPONENT_HITBOX_W);
    int hh     = LVLMAN_get_component(ent, ENTITY_COMPONENT_HITBOX_H);

    int vx     = LVLMAN_try_get_component(ent, ENTITY_COMPONENT_X_VEL, 0);
    int vy     = LVLMAN_try_get_component(ent, ENTITY_COMPONENT_Y_VEL, 0);
    
    rectangle_t rect = GEO_px_to_rect(
        x + hx,
        y + hy,
        hw,
        hh,
        (vx/SUBPIX),
        (vy/SUBPIX)
    );

    return rect;
}

rectangle_t ENT_static_hitbox_rect(
    int ent
) {
    rectangle_t rect = ENT_hitbox_rect(ent);
    
    rect.vx = 0;
    rect.vy = 0;

    return rect;

}

void ENT_change_state(
    int ent,
    int anim
) {
    ASSERT_RANGE(0, anim, MAX_STATE);
    
    int cur_state = LVLMAN_get_component(ent, ENTITY_COMPONENT_STATE);

    if (cur_state == anim) {
        // do nothing
    } else {
        // set new animation and zero the timers
        LVLMAN_set_component(ent, ENTITY_COMPONENT_STATE, anim);
        LVLMAN_set_component(ent, ENTITY_COMPONENT_ANIM_TIMER, 0);
        LVLMAN_set_component(ent, ENTITY_COMPONENT_ANIM_FRAME, 0);
    }
}

int ENT_get_def(
    int comp,
    int bpt
) {
    entity_t ent = resources[bpt];

    int comp_idx = ENT_def_begin_idx(ent) + comp;

    return DATATABLE_get_val(ent, comp_idx, DATA_COL_D);
}

int ENT_check_def(
    int comp,
    int bpt
) {
    entity_t ent = resources[bpt];

    int comp_idx = ENT_def_begin_idx(ent) + comp;

    return DATATABLE_exist(ent, comp_idx);
}

int ENT_get_n_beh(
    int bpt,
    int state,
    int phase
) {
    ASSERT_RANGE(0, state, MAX_STATE);
    ASSERT_RANGE(0, phase, PHASE_ALL);

    entity_t ent = resources[bpt];

    int idx = ENT_beh_begin_idx(ent) + state;
    assert(MAP == DATATABLE_get_val(ent, idx, DATA_COL_A));

    int beh_idx = DATATABLE_get_val(ent, idx, DATA_COL_D) + phase;
    assert(METADATA == DATATABLE_get_val(ent, beh_idx, DATA_COL_A));

    return DATATABLE_get_val(ent, beh_idx, DATA_COL_B);
}

int ENT_get_nth_beh(
    int bpt,
    int state,
    int phase,
    int n
) {
    ASSERT_RANGE(0, state, MAX_STATE);
    ASSERT_RANGE(0, phase, PHASE_ALL);

    entity_t ent = resources[bpt];

    int idx = ENT_beh_begin_idx(ent) + state;
    assert(MAP == DATATABLE_get_val(ent, idx, DATA_COL_A));

    int beh_idx = DATATABLE_get_val(ent, idx, DATA_COL_D) + phase;
    assert(METADATA == DATATABLE_get_val(ent, beh_idx, DATA_COL_A));

    int nth_beh = DATATABLE_get_val(ent, beh_idx, DATA_COL_D) + n;
    assert(BEHAVIOUR == DATATABLE_get_val(ent, nth_beh, DATA_COL_A));
    assert(phase == DATATABLE_get_val(ent, nth_beh, DATA_COL_B));
    assert(n == DATATABLE_get_val(ent, nth_beh, DATA_COL_C));
    
    return DATATABLE_get_val(ent, nth_beh, DATA_COL_D);
}

int ENT_get_collide_fun(
    int bpt,
    int state,
    int col_body
) {
    ASSERT_RANGE(0, state, MAX_STATE);

    entity_t ent = resources[bpt];

    int idx = ENT_collision_begin_idx(ent) + state;
    assert(MAP == DATATABLE_get_val(ent, idx, DATA_COL_A));
    assert(state == DATATABLE_get_val(ent, idx, DATA_COL_C));

    int col_fun_idx = DATATABLE_get_val(ent, idx, DATA_COL_D) + col_body;
    assert(BEHAVIOUR == DATATABLE_get_val(ent, col_fun_idx, DATA_COL_A));
    assert(state == DATATABLE_get_val(ent, col_fun_idx, DATA_COL_B));
    assert(col_body == DATATABLE_get_val(ent, col_fun_idx, DATA_COL_C));

    return DATATABLE_get_val(ent, col_fun_idx, DATA_COL_D);
}
