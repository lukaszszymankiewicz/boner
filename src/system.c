/* Game logic and entities behaviour and any code snippet attached to entity */

#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "data/library.h"

#include "animation.h"
#include "collision.h"
#include "controller.h"
#include "entity.h"
#include "entity_manager.h"
#include "level_manager.h"
#include "macros.h"
#include "modules.h"
#include "scene.h"
#include "system.h"

// how deep collision checks will be done, 1 means that current entity sector
// and neigboughs in each direction in distance of 1 sector is checked
#define COLLISION_CHECK_DEPTH    1

const static int NEGATIVE  = -1;
const static int POSITIVE  = 1;

const static int JUMP_H      = SUBPIX * 32 * 5;
const static int PREJUMP_LEN = 3;
const static int JUMP_T_HALF = 15;

const static int GRAVITY          = -1 * (2 * JUMP_H) / (JUMP_T_HALF * JUMP_T_HALF);
const static int FALLING_GRAVITY  = (int)(GRAVITY * 1.5);

const static int FULL_JUMP_POWUH  = (2 * JUMP_H) / JUMP_T_HALF;
const static int BASE_JUMP_POWUH  = (int)(FULL_JUMP_POWUH / (PREJUMP_LEN+1));
const static int PRE_JUMP_POWUH   = (int)(FULL_JUMP_POWUH / (PREJUMP_LEN+1));

static int MOVE_POWUH      = SUBPIX * 3;
static int MX_VEL_X        = SUBPIX * 6;
static int MX_VEL_Y_DOWN   = -1 * GRAVITY * 4;
static int X_FRICTION      = 8;
static int AIR_X_FRICTION  = 0;

static int RIGHT_DIR_COEF  = POSITIVE;
static int LEFT_DIR_COEF   = NEGATIVE;
static int UP_DIR_COEF     = POSITIVE;
static int DOWN_DIR_COEF   = NEGATIVE;

// get number of entities for phase + sector
int SYSTEM_get_n(
    int phase,
    int local_sec_x,
    int local_sec_y
) {
    int n;
    int global_sec_y = ENTMAN_global_sec_y(local_sec_x, local_sec_y);
    int global_sec_x = ENTMAN_global_sec_x(local_sec_x, local_sec_y);
    
    // global sector out of range of level - aborting
    if ((global_sec_x < 0) || (global_sec_y < 0)) {
        return 0;
    }

    switch (phase) {
        case PHASE_INIT:
            // convert to global
            n = LVLMAN_n_entities(global_sec_x, global_sec_y);
            break;
        default:
            n = ENTMAN_n_entites_on_sector(local_sec_x, local_sec_y);
            break;
    }

    return n;
}

context_t* SYSTEM_fill_context(
    int phase,
    int local_sec_x,
    int local_sec_y,
    int i
) {
    context_t *ctx = NULL;
    ctx            = (context_t*)malloc(sizeof(context_t));

    int e, idx; 

    int global_sec_x = ENTMAN_global_sec_x(local_sec_x, local_sec_y);
    int global_sec_y = ENTMAN_global_sec_y(local_sec_x, local_sec_y);

    ctx->global_sec_x = global_sec_x;
    ctx->global_sec_y = global_sec_y;

    // for INIT phase, there are not entities created, and there levels is not
    // focused on anything. Entities are read from level data using global
    // sector coords.
    switch (phase) {
        case PHASE_INIT:
            idx            = LVLMAN_get_entity_idx(i);
            e              = LVLMAN_get_component(global_sec_x, global_sec_y, idx, LEVEL_ENTITY_COMPONENT_ID);
            ctx->entity    = e;
            ctx->blueprint = LVLMAN_get_component(global_sec_x, global_sec_y, idx, LEVEL_ENTITY_COMPONENT_BLUEPRINT_ID);
            ctx->phase     = phase;
            ctx->subphase  = IDLE;
            break;
        default:
            e              = ENTMAN_get_entity(local_sec_x, local_sec_y, i);
            ctx->entity    = e;
            ctx->blueprint = ENTMAN_get_component(e, ENTITY_COMPONENT_BLUEPRINT_ID);
            ctx->phase     = phase;
            ctx->subphase  = ENTMAN_get_component(e, ENTITY_COMPONENT_STATE);
            break;
        }
    
    ctx->sec_x = local_sec_x;
    ctx->sec_y = local_sec_y;
    ctx->arg   = i;

    return ctx;
}

// run one phase behaviours for every entity from st to end
void SYSTEM_run(
    int phase,
    int phase_depth,
    int local_sec_x1,
    int local_sec_y1,
    int local_sec_x2,
    int local_sec_y2
) {
    assert(local_sec_x1 >= 0); 
    assert(local_sec_y1 >= 0); 
    assert(local_sec_x2 >= 0); 
    assert(local_sec_y2 >= 0); 

    local_sec_x1 = MAX(0, local_sec_x1);
    local_sec_y1 = MAX(0, local_sec_y1);

    assert(local_sec_x2 > local_sec_x1);
    assert(local_sec_y2 > local_sec_y1);

    assert(phase_depth >=0);

    ASSERT_RANGE(0, phase, PHASE_ALL);
    
    for (int x=local_sec_x1; x<local_sec_x2; x++) { 
        for (int y=local_sec_y1; y<local_sec_y2; y++) { 
    
            int n_entities = SYSTEM_get_n(phase, x, y);
                for (int i=0; i<n_entities; i++) {
                    context_t *ctx   = NULL;
                    ctx              = SYSTEM_fill_context(phase, x, y, i);
                    int n_behaviours = BEH_n_behaviours(ctx);

                for (int j=FIRST_BEHAVIOUR_IDX; j<n_behaviours+1; j++) {
                    BEH_run(ctx, j);
                }

                if (ctx != NULL) {
                    free(ctx);
                }

            }
        }
    }
}

// run one phase behaviour on column of secotrs
void SYSTEM_run_on_col(
    int phase,
    int phase_depth,
    int local_sec_x
) {
    SYSTEM_run(
        phase,
        phase_depth,
        local_sec_x,
        SECTOR_DEPTH - phase_depth,
        local_sec_x+1,
        SECTOR_DEPTH + phase_depth + 1
    );
}

// run one phase behaviour on row of secotrs
void SYSTEM_run_on_row(
    int phase,
    int phase_depth,
    int local_sec_y
) {
    SYSTEM_run(
        phase,
        phase_depth,
        SECTOR_DEPTH - phase_depth,
        local_sec_y,
        SECTOR_DEPTH + phase_depth + 1,
        local_sec_y+1
    );
}

// run one phase behaviour on quadrant of secotrs
void SYSTEM_run_on_quadrant(
    int phase,
    int phase_depth
) {
    int local_sec_x1 = SECTOR_DEPTH - phase_depth;
    int local_sec_y1 = SECTOR_DEPTH - phase_depth;
    int local_sec_x2 = SECTOR_DEPTH + phase_depth + 1;
    int local_sec_y2 = SECTOR_DEPTH + phase_depth + 1;

    SYSTEM_run(phase, phase_depth, local_sec_x1, local_sec_y1, local_sec_x2, local_sec_y2);
}

void SYSTEM_add_velocity(
    int        ent,
    context_t* ctx
) {
    int vx      = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);
    int vy      = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);
    
    int new_y;
    int new_x;

    if (vx>0) {
        new_x = MIN(vx, MX_VEL_X * RIGHT_DIR_COEF);
        ENTMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_x);
    } else if (vx<0) {
        new_x = MAX(vx, MX_VEL_X * LEFT_DIR_COEF);
        ENTMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_x);
    } else {
        new_x = 0;
        ENTMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_x);
    }

    if (vy>0) {
        new_y = vy;
        ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, new_y);
    } else if (vy<0) {
        new_y = MAX(vy, MX_VEL_Y_DOWN * DOWN_DIR_COEF);
        ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, new_y);
    } else {
        new_y = 0;
        ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, new_y);
    }
}

void SYSTEM_update_position(
    int        ent,
    context_t* ctx
) {
    int x   = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y   = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);
    int vx  = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);
    int vy  = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);

    int new_vx, new_vy;
    int new_x, new_y;

    int x_des  = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_POS_DES);
    int y_des  = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_POS_DES);
    int vx_des = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_VEL_DES);
    int vy_des = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL_DES);
    
    if (vx_des == NOT_SET) {
        new_vx = vx;
    } else {
        new_vx = vx_des;
    }

    if (vy_des == NOT_SET) {
        new_vy = vy;
    } else {
        new_vy = vy_des;
    }

    if (x_des == NOT_SET) {
        new_x = (vx / SUBPIX) + x;
    } else {
        new_x = x_des;
    }

    if (y_des == NOT_SET) {
        new_y = (vy / SUBPIX) + y;
    } else {
        new_y = y_des;
    }

    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_POS, new_x);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_POS, new_y);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_vx);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, new_vy);
}

void SYSTEM_add_gravity(
    int        ent,
    context_t* ctx
) {
    int state = ENTMAN_get_component(ent, ENTITY_COMPONENT_STATE);

    if (state == FALLING_DOWN) {
        ENTMAN_add_to_component(ent, ENTITY_COMPONENT_Y_VEL, FALLING_GRAVITY);
    } else {
        ENTMAN_add_to_component(ent, ENTITY_COMPONENT_Y_VEL, GRAVITY);
    }
}

void SYSTEM_emit_from_level(
    int        ent,
    context_t* ctx
) {
    int global_sec_x = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_SEC);
    int global_sec_y = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_SEC);

    LVLMAN_delete_entity(global_sec_x, global_sec_y, ent);
}

void SYSTEM_no_emit_from_level(
    int        ent,
    context_t* ctx
) {
    // bitchslap, do nothing
}

void SYSTEM_put_to_scene(
    int        ent,
    context_t* ctx
) {

    int x = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);

    int txt    = ENTMAN_get_component(ent, ENTITY_COMPONENT_TEXTURE);
    int layer  = ENTMAN_get_component(ent, ENTITY_COMPONENT_LAYER);
    int buffer = ENTMAN_get_component(ent, ENTITY_COMPONENT_BUFFER);

    SCENE_activate_buffer(buffer);
    SCENE_activate_layer(layer);

    assert(x>=0);
    assert(y>=0);

    assert(txt>=0);
    assert(buffer>=0);
    assert(layer>=0);

    texture_t* texture    = sprites_library[txt]; 
    int        texture_id = texture->gl_id;
    int        texture_w  = texture->width;
    int        texture_h  = texture->height;
    int        sprite     = texture->sprite;

    int state          = ENTMAN_get_component(ent, ENTITY_COMPONENT_STATE);
    int frame          = ENTMAN_get_component(ent, ENTITY_COMPONENT_ANIM_FRAME);
    int dir            = ENTMAN_get_component(ent, ENTITY_COMPONENT_DIR);

    int frame_w = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_OUTLINE, FRAME_RECT_W);
    int frame_h = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_OUTLINE, FRAME_RECT_H);
    int frame_x = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_OUTLINE, FRAME_RECT_X);
    int frame_y = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_OUTLINE, FRAME_RECT_Y);
    
    assert(frame_w>=0);
    assert(frame_h>=0);
    assert(frame_x>=0);
    assert(frame_y>=0);

    char *name = ENTMAN_get_entity_name(ent);
    int flip_hor = dir;

    array_t *vertices = SCENE_texture_pos(
        x,          y,
        frame_w,    frame_h,
        frame_x,    frame_y,
        frame_w,    frame_h,
        texture_w,  texture_h,
        flip_hor,   false
    );

    SCENE_put_texture_to_scene(name, vertices, texture_id, sprite);
}

void SYSTEM_set_camera(
    int        ent,
    context_t* ctx
) {
    int x = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);

    window->camera_x = x - SCREEN_WIDTH/2; 
    window->camera_y = y - SCREEN_HEIGHT/2; 
}

void SYSTEM_init_entity(
    int        ent,
    context_t* ctx
) {
    int n    = ctx->arg;
    int idx  = LVLMAN_get_entity_idx(n);

    int state = LVLMAN_get_component(ctx->global_sec_x, ctx->global_sec_y, idx, LEVEL_ENTITY_START_ANIM);
    int frame = LVLMAN_get_component(ctx->global_sec_x, ctx->global_sec_y, idx, LEVEL_ENTITY_START_FRAME);
    
    ENTMAN_set_component(ent, ENTITY_COMPONENT_BLUEPRINT_ID, ctx->blueprint);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_STATE, state);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_ANIM_FRAME, frame);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_ID, ent);
}

void SYSTEM_add_entity_to_sector(
    int        ent,
    context_t* ctx
) {
    ENTMAN_add_entity_to_sector(ent, ctx->sec_x, ctx->sec_y);
}

void SYSTEM_set_defaults(
    int        ent,
    context_t* ctx
) {
    int bpt = ctx->blueprint;

    for (int comp=ENTITY_COMPONENT_X_POS; comp<ENTITY_COMPONENT_ALL; comp++) {
        int val = entity_library[bpt]->defaults[comp];

        if (val != INHERIT) {
            ENTMAN_set_component(ent, comp, val);
        }
    }
}

void SYSTEM_set_on_level(
    int        ent,
    context_t* ctx
) {
    int x = ctx->global_sec_x;
    int y = ctx->global_sec_y;
    int n = ctx->arg;

    // set entity on proper position behaviour
    int idx          = LVLMAN_get_entity_idx(n);
    int x_pos        = LVLMAN_get_component(x, y, idx, LEVEL_ENTITY_COMPONENT_X);
    int y_pos        = LVLMAN_get_component(x, y, idx, LEVEL_ENTITY_COMPONENT_Y);
    int global_sec_x = LVLMAN_get_component(x, y, LEVEL_METADATA_IDX, LEVEL_METADATA_SEC_X);
    int global_sec_y = LVLMAN_get_component(x, y, LEVEL_METADATA_IDX, LEVEL_METADATA_SEC_Y);
    
    ASSERT_RANGE(global_sec_x*SECTOR_W, x_pos, global_sec_x*SECTOR_W+SECTOR_W);
    ASSERT_RANGE(global_sec_y*SECTOR_H, y_pos, global_sec_y*SECTOR_H+SECTOR_H);

    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_SEC, global_sec_x);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_SEC, global_sec_y);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_POS, x_pos);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_POS, y_pos);

    assert(x == global_sec_x);
    assert(y == global_sec_y);
}

void SYSTEM_orient_segments(
    int        ent,
    context_t* ctx
) {
    int delta;

    int x_pos    = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y_pos    = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);
    
    // globals
    int x_sec    = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_SEC);
    int y_sec    = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_SEC);

    int up_sec_x = x_pos / SECTOR_W;
    int up_sec_y = y_pos / SECTOR_H;

    if (up_sec_y != y_sec) {

        delta = up_sec_y - y_sec;
        ASSERT_RANGE(-1, delta, 1);
        
        // setup new orientation
        ENTMAN_orient_sectors(up_sec_x, up_sec_y);

        // entity to orient by must be removed to safely switch sectors...
        ENTMAN_remove_entity_from_sector(ent, SECTOR_DEPTH, SECTOR_DEPTH);
        
        // switch sectors according to movement of entity to orient by
        // up_sec_y < sec_y
        if(delta < 0) {
            ENTMAN_move_sectors_down();
            SYSTEM_run_on_row(PHASE_INIT, INIT_DEPTH, SECTORS_Y-1);
        // up_sec_y < sec_y
        } else {
            ENTMAN_move_sectors_up();
            SYSTEM_run_on_row(PHASE_INIT, INIT_DEPTH, 0);
        }

        // ...add entity back
        ENTMAN_add_entity_to_sector(ent, SECTOR_DEPTH, SECTOR_DEPTH);
        ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_SEC, up_sec_y);
    }

    if (up_sec_x != x_sec) {

        delta = up_sec_x - x_sec;
        ASSERT_RANGE(-1, delta, 1);
            
        // setup new orientation
        ENTMAN_orient_sectors(up_sec_x, up_sec_y);

        // entity to orient by must be removed to safely switch sectors...
        ENTMAN_remove_entity_from_sector(ent, SECTOR_DEPTH, SECTOR_DEPTH);

        // switch sectors according to movement of entity to orient by
        // up_sec_x < sec_x
        if(delta < 0) {
            ENTMAN_move_sectors_left();
            SYSTEM_run_on_col(PHASE_INIT, INIT_DEPTH, 0);

        // up_sec_x > sec_x
        } else {
            ENTMAN_move_sectors_right();
            SYSTEM_run_on_col(PHASE_INIT, INIT_DEPTH, SECTORS_X-1);
        }

        // ...add entity back
        ENTMAN_add_entity_to_sector(ent, SECTOR_DEPTH, SECTOR_DEPTH);
        ENTMAN_set_component(ent, ENTITY_COMPONENT_X_SEC, up_sec_x);
    }
}

void SYSTEM_set_focus(
    int        ent,
    context_t* ctx
) {
    int up_sec_x = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_SEC);
    int up_sec_y = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_SEC);

    level_manager->focus_x = up_sec_x;
    level_manager->focus_y = up_sec_y;
}

void SYSTEM_normal_collision(
    int         ent,
    context_t*  ctx,
    collision_t col
) {
    int vx = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);
    int vy = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);

    int new_vx = vx;
    int new_vy = vy;

    int new_x  = (int)(col.new_x+PIX_COEF);
    int new_y  = (int)(col.new_y+PIX_COEF);

    if (col.nx != 0) { new_vx = 0; }
    if (col.ny != 0) { new_vy = 0; } 
    
    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_POS_DES, new_x);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_POS_DES, new_y);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_VEL_DES, new_vx);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL_DES, new_vy);
}

// by now only collision between moving entity (like hero) and static entities
// are supported
void SYSTEM_check_collision(
    int        ent,
    context_t* ctx
) {
    int st_x  = ctx->sec_x - COLLISION_CHECK_DEPTH;
    int st_y  = ctx->sec_y - COLLISION_CHECK_DEPTH;
    int end_x = ctx->sec_x + COLLISION_CHECK_DEPTH + 1;
    int end_y = ctx->sec_y + COLLISION_CHECK_DEPTH + 1;
    
    collision_t col = { 0 };
    col.dist        = -INFINITY;
    
    rectangle_t ent_hb = ENTMAN_hit_box_rect(ent);

    context_t *col_ctx   = NULL;

    for (int x=st_x; x<end_x; x++) { 
        for (int y=st_y; y<end_y; y++) { 

            int n = ENTMAN_n_entites_on_sector(x, y);
            
            // check collision with every entity in nearby sectors
            for (int i=0; i<n; i++) {
                
                int ec           = ENTMAN_get_entity(x, y, i);
                col_ctx          = SYSTEM_fill_context(PHASE_COLLISION, x, y, i);
                int n_behaviours = BEH_n_behaviours(col_ctx);
                
                // check if collidable, collision with itself is also prohibited
                if (!n_behaviours || (ec == ent)) {
                    free(col_ctx);
                    col_ctx = NULL;
                    continue;
                }

                rectangle_t col_hb = ENTMAN_hit_box_rect(ec);
                collision_t candidate = COL_rect_rect(ent_hb, col_hb);
                candidate.col_id = ec;
                
                if (candidate.hit) {
                    col = COL_better(col, candidate);
                }

                free(col_ctx);
                col_ctx = NULL;
            }
        }
    }

    if (col.hit) { 
        BEH_run_collision(ent, ctx, col);
    }
}

void SYSTEM_is_collidable(
    int        ent,
    context_t* ctx
) {

}

void SYSTEM_right(
    int        ent,
    context_t* ctx
) {
    int button     = CON_button_pressed(KEY_PRESSED_RIGHT);

    if (!button) {
        return;
    }

    ENTMAN_set_component(ent, ENTITY_COMPONENT_DIR, RIGHT);
    ENTMAN_add_to_component(ent, ENTITY_COMPONENT_X_VEL, MOVE_POWUH * RIGHT_DIR_COEF);
}

void SYSTEM_left(
    int        ent,
    context_t* ctx
) {
    int button     = CON_button_pressed(KEY_PRESSED_LEFT);

    if (!button) {
        return;
    }

    ENTMAN_set_component(ent, ENTITY_COMPONENT_DIR, LEFT);
    ENTMAN_add_to_component(ent, ENTITY_COMPONENT_X_VEL, MOVE_POWUH * LEFT_DIR_COEF);
}

void SYSTEM_jump(
    int        ent,
    context_t* ctx
) {
    int button     = CON_button_pressed(KEY_PRESSED_SPACE);
    int state      = ENTMAN_get_component(ent, ENTITY_COMPONENT_STATE);

    if (!button) {
        return;
    }

    if (state == JUMPING) {
        int timer = ENTMAN_get_component(ent, ENTITY_COMPONENT_ANIM_TIMER);

        if (timer <= PREJUMP_LEN) {
            ENTMAN_add_to_component(ent, ENTITY_COMPONENT_Y_VEL, PRE_JUMP_POWUH);
        }

    } else {
        ENTMAN_change_state(ent, JUMPING);
        ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, BASE_JUMP_POWUH);
    }
}

void SYSTEM_check_if_falling(
    int        ent,
    context_t* ctx
) {
    int vy = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);

    if (vy < 0) {
       ENTMAN_change_state(ent, FALLING_DOWN);
    }
}

void SYSTEM_check_stop_falling(
    int        ent,
    context_t* ctx
) {
    int vy = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);

    if (vy == 0) {
        ENTMAN_change_state(ent, IDLE);
    }
}

void SYSTEM_horizontal_air_friction(
    int        ent,
    context_t* ctx
) {
    int xv = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);

    if (xv == 0) {
       return;
    }
    int new_xv;
    
    // left
    if (xv < 0) {
        new_xv = MIN(0, xv + AIR_X_FRICTION);
    // right
    } else {
        new_xv = MAX(0, xv - AIR_X_FRICTION);
    }

    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_xv);
}

void SYSTEM_horizontal_friction(
    int        ent,
    context_t* ctx
) {
    int xv = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);

    if (xv == 0) {
       return;
    }
    int new_xv;
    
    // left
    if (xv < 0) {
        new_xv = MIN(0, xv + X_FRICTION);
    // right
    } else {
        new_xv = MAX(0, xv - X_FRICTION);
    }
    
    if (new_xv == 0) {
        ENTMAN_change_state(ent, IDLE);
    } else {
        ENTMAN_change_state(ent, WALKING);
    }

    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_xv);
}

void SYSTEM_debug_entity(
    int        ent,
    context_t* ctx
) {
    ENTMAN_debug_entity(ent);
}

void SYSTEM_add_frame_timer(
    int        ent,
    context_t* ctx
) {
    ENTMAN_add_to_component(ent, ENTITY_COMPONENT_ANIM_TIMER, 1);
}

void SYSTEM_anim_frame(
    int        ent,
    context_t* ctx
) {
    int state = ENTMAN_get_component(ent, ENTITY_COMPONENT_STATE);
    int frame = ENTMAN_get_component(ent, ENTITY_COMPONENT_ANIM_FRAME);
    int timer = ENTMAN_get_component(ent, ENTITY_COMPONENT_ANIM_TIMER);
    int delay = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_DELAY, DELAY_VALUE);
    int len   = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_LEN, FRAME_VALUE);
    
    // if current fram delay is filled - move to next animation frame
    if (timer >= delay) {
        ENTMAN_set_component(ent, ENTITY_COMPONENT_ANIM_TIMER, 0);
        
        // if animation is comeplete, start over
        if ((frame+1) >= len) {
            ENTMAN_set_component(ent, ENTITY_COMPONENT_ANIM_FRAME, 0);
        // ... or just continue
        } else {
            ENTMAN_add_to_component(ent, ENTITY_COMPONENT_ANIM_FRAME, 1);
        }
    }
}

void SYSTEM_continue_jump(
    int        ent,
    context_t* ctx
) {
    int state   = ENTMAN_get_component(ent, ENTITY_COMPONENT_STATE);
    int frame   = ENTMAN_get_component(ent, ENTITY_COMPONENT_ANIM_FRAME);
    int timer   = ENTMAN_get_component(ent, ENTITY_COMPONENT_ANIM_TIMER);
    int delay   = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_DELAY, DELAY_VALUE);
    int button  = CON_button_still_pressed(KEY_PRESSED_SPACE);
    
    if ((timer < delay) && (button)) {
        // ENTMAN_add_to_component(ent, ENTITY_COMPONENT_Y_VEL, PRE_JUMP_POWUH);
        ENTMAN_change_state(ent, JUMPING);
    } else {
        ENTMAN_change_state(ent, JUMPING);
    }
}

void SYSTEM_catch_pos_change(
    int        ent,
    context_t* ctx
) {
    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_POS_DES, NOT_SET);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_POS_DES, NOT_SET);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_X_VEL_DES, NOT_SET);
    ENTMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL_DES, NOT_SET);
}
