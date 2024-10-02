/* Game logic and entities behaviour and any code snippet attached to entity */
#include <assert.h>
#include <stdio.h>

#include "obscura/canvas.h"
#include "obscura/window.h"
#include "obscura/texture.h"

#include "collision.h"
#include "controller.h"
#include "datatable.h"
#include "geometry.h"
#include "entity.h"
#include "level_manager.h"
#include "resources.h"
#include "macros.h"
#include "modules.h"
#include "system.h"
#include "symbols.h"

// how deep collision checks will be done, 1 means that current entity sector
// and neigboughs in each direction in distance of 1 sector is checked
#define COLLISION_CHECK_DEPTH    1

const static int NEGATIVE  = -1;
const static int POSITIVE  = 1;

// TODO: those values should be propably just another componnent
const static int JUMP_H      = SUBPIX * 32 * 5;
const static int PREJUMP_LEN = 4;
const static int JUMP_T_HALF = 15;

const static int GRAVITY          = -1 * (2 * JUMP_H) / (JUMP_T_HALF * JUMP_T_HALF);
const static int FALLING_GRAVITY  = (int)(GRAVITY * 1.5);

const static int FULL_JUMP_POWUH  = (2 * JUMP_H) / JUMP_T_HALF;
const static int BASE_JUMP_POWUH  = (int)(FULL_JUMP_POWUH / (PREJUMP_LEN+1));
const static int PRE_JUMP_POWUH   = (int)(FULL_JUMP_POWUH / (PREJUMP_LEN+1));

const static int RIGHT_DIR_COEF  = POSITIVE;
const static int LEFT_DIR_COEF   = NEGATIVE;
const static int UP_DIR_COEF     = POSITIVE;
const static int DOWN_DIR_COEF   = NEGATIVE;

const static int MOVE_POWUH      = SUBPIX * 3;
const static int MX_VEL_X        = SUBPIX * 6;
const static int MX_VEL_Y_DOWN   = DOWN_DIR_COEF * GRAVITY * 8;
const static int X_FRICTION      = 8;
const static int AIR_X_FRICTION  = 0;

const static int SECTOR_WIDTH  = 160;
const static int SECTOR_HEIGHT = 120;

// run one phase behaviours for every entity from st to end
void SYSTEM_run(
    int phase,
    int phase_depth,
    int sec_x1,
    int sec_y1,
    int sec_x2,
    int sec_y2
) {
    assert(sec_x1 >= 0); 
    assert(sec_y1 >= 0); 
    assert(sec_x2 >= 0); 
    assert(sec_y2 >= 0); 

    sec_x1 = MAX(0, sec_x1);
    sec_y1 = MAX(0, sec_y1);

    sec_x2 = MIN(LVLMAN_size_x(), sec_x2);
    sec_y2 = MIN(LVLMAN_size_y(), sec_y2);

    assert(sec_x2 > sec_x1);
    assert(sec_y2 > sec_y1);

    assert(phase_depth >=0);

    ASSERT_RANGE(0, phase, PHASE_ALL);
    
    for (int x=sec_x1; x<sec_x2; x++) { 
        for (int y=sec_y1; y<sec_y2; y++) { 
    
            int n_entities = LVLMAN_n_entities(x, y);

            for (int i=0; i<n_entities; i++) {

                int idx    = LVLMAN_entity_idx(x, y, i);
                int phases = LVLMAN_get_component(idx, ENTITY_COMPONENT_PHASES);

                if  (!(phases & (1 << phase))) {
                    continue;
                }

                int bpt = LVLMAN_get_component(idx, ENTITY_COMPONENT_BPT);
                int state = LVLMAN_try_get_component(idx, ENTITY_COMPONENT_STATE, IDLE);
                int n_behaviours = ENT_get_n_beh(bpt, state, phase);

                for (int n=0; n<n_behaviours; n++) {
                    int beh = ENT_get_nth_beh(bpt, state, phase, n);
                    behaviour_library[beh](idx);
                }
            }
        }
    }
}

void SYSTEM_run_on_quadrant(
    int phase,
    int phase_depth
) {
    int focus_x = LVLMAN_focus_x();
    int focus_y = LVLMAN_focus_y();

    int sec_x1 = focus_x - phase_depth;
    int sec_y1 = focus_y - phase_depth;
    int sec_x2 = focus_x + phase_depth + 1;
    int sec_y2 = focus_y + phase_depth + 1;

    SYSTEM_run(phase, phase_depth, sec_x1, sec_y1, sec_x2, sec_y2);
}

void SYSTEM_add_velocity(
    int ent
) {
    int vx      = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);
    int vy      = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);
    
    int new_y;
    int new_x;

    if (vx>0) {
        new_x = MIN(vx, MX_VEL_X * RIGHT_DIR_COEF);
        LVLMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_x);
    } else if (vx<0) {
        new_x = MAX(vx, MX_VEL_X * LEFT_DIR_COEF);
        LVLMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_x);
    } else {
        new_x = 0;
        LVLMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_x);
    }

    if (vy>0) {
        new_y = vy;
        LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, new_y);
    } else if (vy<0) {
        new_y = MAX(vy, MX_VEL_Y_DOWN * DOWN_DIR_COEF);
        LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, new_y);
    } else {
        new_y = 0;
        LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, new_y);
    }
}

void SYSTEM_update_position(
    int ent
) {
    int x   = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y   = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);
    int vx  = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);
    int vy  = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);

    int new_vx, new_vy;
    int new_x, new_y;

    int x_des  = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_POS_DES);
    int y_des  = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_POS_DES);
    int vx_des = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_VEL_DES);
    int vy_des = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL_DES);
    
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

    LVLMAN_set_component(ent, ENTITY_COMPONENT_X_POS, new_x);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_POS, new_y);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_vx);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, new_vy);
}

void SYSTEM_add_gravity(
    int ent
) {
    int state = LVLMAN_get_component(ent, ENTITY_COMPONENT_STATE);

    if (state == FALLING_DOWN) {
        LVLMAN_add_to_component(ent, ENTITY_COMPONENT_Y_VEL, FALLING_GRAVITY);
    } else {
        LVLMAN_add_to_component(ent, ENTITY_COMPONENT_Y_VEL, GRAVITY);
    }
}

void SYSTEM_put_to_canvas(
    int ent
) {
    int x      = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y      = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);
    int txt    = LVLMAN_get_component(ent, ENTITY_COMPONENT_TEXTURE);
    int layer  = LVLMAN_get_component(ent, ENTITY_COMPONENT_LAYER);
    int buffer = LVLMAN_get_component(ent, ENTITY_COMPONENT_BUFFER);
    
    CANVAS_activate_buffer(canvas, buffer);
    CANVAS_activate_layer(canvas, layer);

    assert(x>=0);
    assert(y>=0);

    assert(txt>=0);
    assert(buffer>=0);
    assert(layer>=0);

    texture_t* texture    = resources[txt]; 
    int        texture_id = texture->gl_id;
    int        texture_w  = texture->width;
    int        texture_h  = texture->height;
    int        sprite     = texture->sprite;

    int dir     = LVLMAN_get_component(ent, ENTITY_COMPONENT_DIR);
    int frame_x = LVLMAN_get_component(ent, ENTITY_COMPONENT_FRAME_X);
    int frame_y = LVLMAN_get_component(ent, ENTITY_COMPONENT_FRAME_Y);
    int frame_w = LVLMAN_get_component(ent, ENTITY_COMPONENT_FRAME_W);
    int frame_h = LVLMAN_get_component(ent, ENTITY_COMPONENT_FRAME_H);

    draw_rect_t draw = { x, y, frame_w, frame_h, dir, false };
    draw_rect_t clip = { frame_x, frame_y, frame_w, frame_h, dir, false };

    int camera_x = window->camera_x;
    int camera_y = window->camera_y;

    CANVAS_put_texture_to_canvas(
        canvas,
        camera_x,   camera_y,
        &draw,
        &clip,
        texture
    );
}

void SYSTEM_set_camera(
    int ent
) {
    int buffer = LVLMAN_get_component(ent, ENTITY_COMPONENT_BUFFER);
    int w      = canvas->buffers[buffer]->width;
    int h      = canvas->buffers[buffer]->height;

    WINDOW_set(
        window,
        LVLMAN_get_component(ent, ENTITY_COMPONENT_X_POS) - (w / 2),
        LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_POS) - (h / 2)
    );
}

void SYSTEM_update_sector(
    int ent
) {
    int x = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);

    int sec_x = LVLMAN_get_sector_x(ent);
    int sec_y = LVLMAN_get_sector_y(ent);

    int new_sec_x = x / SECTOR_WIDTH;
    int new_sec_y = y / SECTOR_HEIGHT;
    
    if ((new_sec_x!=sec_x) || (new_sec_y!=sec_y)) {
        LVLMAN_remove_ent_from_sector(ent);
        LVLMAN_move_ent_to_sector(ent, new_sec_x, new_sec_y);
    }
}

void SYSTEM_set_focus(
    int ent
) {
    int x = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);
     
    int sec_x = LVLMAN_get_sector_x(ent);
    int sec_y = LVLMAN_get_sector_y(ent);

    int focus_x = x / SECTOR_WIDTH;
    int focus_y = y / SECTOR_HEIGHT;
}

void SYSTEM_normal_collision(
    int         ent,
    collision_t col
) {
    int vx = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);
    int vy = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);

    int new_vx = vx;
    int new_vy = vy;

    int new_x  = (int)(col.new_x+PIX_COEF);
    int new_y  = (int)(col.new_y+PIX_COEF);

    if (col.nx != 0) { new_vx = 0; }
    if (col.ny != 0) { new_vy = 0; } 
    
    LVLMAN_set_component(ent, ENTITY_COMPONENT_X_POS_DES, new_x);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_POS_DES, new_y);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_X_VEL_DES, new_vx);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL_DES, new_vy);
}

// by now only collision between moving entity (like hero) and static entities
// are supported
void SYSTEM_check_collision(
    int ent
) {
    int sec_x = LVLMAN_get_sector_x(ent);
    int sec_y = LVLMAN_get_sector_y(ent);

    int st_x  = sec_x - COLLISION_CHECK_DEPTH;
    int st_y  = sec_y - COLLISION_CHECK_DEPTH;
    int end_x = sec_x + COLLISION_CHECK_DEPTH + 1;
    int end_y = sec_y + COLLISION_CHECK_DEPTH + 1;
    
    collision_t col = { 0 };
    col.dist        = -INFINITY;

    rectangle_t ent_hb   = ENT_hitbox_rect(ent);

    for (int x=st_x; x<end_x; x++) { 
        for (int y=st_y; y<end_y; y++) { 

            int n = LVLMAN_n_entities(x, y);
            
            // check collision with every entity in nearby sectors
            for (int i=0; i<n; i++) {

                int ec         = LVLMAN_entity_idx(x, y, i);
                int collidable = LVLMAN_check_component(ec, ENTITY_COMPONENT_COLLISIONABLE);

                if ((ec == ent) || (!collidable)) {
                    continue;
                }

                rectangle_t col_hb    = ENT_static_hitbox_rect(ec);
                collision_t candidate = COL_rect_rect(ent_hb, col_hb);
                candidate.col_id      = ec;
                
                if (candidate.hit) {
                    col = COL_better(col, candidate);
                }
            }
        }
    }

    if (col.hit) { 
        // get collider entity ID
        int col_id = col.col_id;

        int bpt       = LVLMAN_get_component(ent, ENTITY_COMPONENT_BPT);
        int state     = LVLMAN_get_component(ent, ENTITY_COMPONENT_STATE);
        int body_type = LVLMAN_get_component(col_id, ENTITY_COMPONENT_COLLISIONABLE);

        int collision_fun_idx = ENT_get_collide_fun(bpt, state, body_type);

        // run collision function
        collision_behaviour_library[collision_fun_idx](ent, col);
    }
}

void SYSTEM_right(
    int ent
) {
    int button = CON_button_pressed(KEY_PRESSED_RIGHT);

    if (!button) {
        return;
    }

    LVLMAN_set_component(ent, ENTITY_COMPONENT_DIR, RIGHT);
    LVLMAN_add_to_component(ent, ENTITY_COMPONENT_X_VEL, MOVE_POWUH * RIGHT_DIR_COEF);
}

void SYSTEM_left(
    int ent
) {
    int button = CON_button_pressed(KEY_PRESSED_LEFT);

    if (!button) {
        return;
    }

    LVLMAN_set_component(ent, ENTITY_COMPONENT_DIR, LEFT);
    LVLMAN_add_to_component(ent, ENTITY_COMPONENT_X_VEL, MOVE_POWUH * LEFT_DIR_COEF);
}

void SYSTEM_jump(
    int ent
) {
    int button = CON_button_pressed(KEY_PRESSED_SPACE);

    if (!button) {
        return;
    }

    ENT_change_state(ent, PREJUMP);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL, BASE_JUMP_POWUH);
}

void SYSTEM_check_if_falling(
    int ent
) {
    int vy = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);

    if (vy < 0) {
       ENT_change_state(ent, FALLING_DOWN);
    }
}

void SYSTEM_check_stop_falling(
    int ent
) {
    int vy = LVLMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);

    if (vy == 0) {
        ENT_change_state(ent, IDLE);
    }
}

void SYSTEM_horizontal_air_friction(
    int ent
) {
    int xv = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);

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

    LVLMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_xv);
}

void SYSTEM_horizontal_friction(
    int ent
) {
    int xv = LVLMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);
    int new_xv;

    if (xv == 0) {
       return;
    }
    
    // left
    if (xv < 0) {
        new_xv = MIN(0, xv + X_FRICTION);

    // right
    } else {
        new_xv = MAX(0, xv - X_FRICTION);
    }
    
    if (new_xv == 0) {
        ENT_change_state(ent, IDLE);
    } else {
        ENT_change_state(ent, WALKING);
    }

    LVLMAN_set_component(ent, ENTITY_COMPONENT_X_VEL, new_xv);
}

void SYSTEM_add_frame_timer(
    int ent
) {
    LVLMAN_add_to_component(ent, ENTITY_COMPONENT_ANIM_TIMER, 1);
}

void SYSTEM_set_frame(
    int ent
) {
    int state   = LVLMAN_get_component(ent, ENTITY_COMPONENT_STATE);
    int frame   = LVLMAN_get_component(ent, ENTITY_COMPONENT_ANIM_FRAME);
    int bpt     = LVLMAN_get_component(ent, ENTITY_COMPONENT_BPT);

    int frame_x = ENT_frame_data(bpt, state, frame, ANIMATION_COMPONENT_OUTLINE, ANIMATION_RECT_X);
    int frame_y = ENT_frame_data(bpt, state, frame, ANIMATION_COMPONENT_OUTLINE, ANIMATION_RECT_Y);
    int frame_w = ENT_frame_data(bpt, state, frame, ANIMATION_COMPONENT_OUTLINE, ANIMATION_RECT_W);
    int frame_h = ENT_frame_data(bpt, state, frame, ANIMATION_COMPONENT_OUTLINE, ANIMATION_RECT_H);

    int delay   = ENT_frame_data(bpt, state, frame, ANIMATION_COMPONENT_DELAY, ANIMATION_DELAY_VALUE);
    int len     = ENT_anim_len(bpt, state);

    LVLMAN_set_component(ent, ENTITY_COMPONENT_FRAME_X, frame_x);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_FRAME_Y, frame_y);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_FRAME_W, frame_w);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_FRAME_H, frame_h);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_ANIM_DELAY, delay);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_ANIM_LEN, len);
}

void SYSTEM_set_hitbox(
    int ent
) {
    int state   = LVLMAN_get_component(ent, ENTITY_COMPONENT_STATE);
    int frame   = LVLMAN_get_component(ent, ENTITY_COMPONENT_ANIM_FRAME);
    int bpt     = LVLMAN_get_component(ent, ENTITY_COMPONENT_BPT);

    int hitbox_x = ENT_frame_data(bpt, state, frame, ANIMATION_COMPONENT_HITBOX, ANIMATION_RECT_X);
    int hitbox_y = ENT_frame_data(bpt, state, frame, ANIMATION_COMPONENT_HITBOX, ANIMATION_RECT_Y);
    int hitbox_w = ENT_frame_data(bpt, state, frame, ANIMATION_COMPONENT_HITBOX, ANIMATION_RECT_W);
    int hitbox_h = ENT_frame_data(bpt, state, frame, ANIMATION_COMPONENT_HITBOX, ANIMATION_RECT_H);

    LVLMAN_set_component(ent, ENTITY_COMPONENT_HITBOX_X, hitbox_x);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_HITBOX_Y, hitbox_y);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_HITBOX_W, hitbox_w);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_HITBOX_H, hitbox_h);
}

void SYSTEM_anim_frame(
    int ent
) {
    int state = LVLMAN_get_component(ent, ENTITY_COMPONENT_STATE);
    int frame = LVLMAN_get_component(ent, ENTITY_COMPONENT_ANIM_FRAME);
    int timer = LVLMAN_get_component(ent, ENTITY_COMPONENT_ANIM_TIMER);
    int delay = LVLMAN_get_component(ent, ENTITY_COMPONENT_ANIM_DELAY);
    int len   = LVLMAN_get_component(ent, ENTITY_COMPONENT_ANIM_LEN);
    
    // if current fram delay is filled - move to next animation frame
    if (timer >= delay) {
        LVLMAN_set_component(ent, ENTITY_COMPONENT_ANIM_TIMER, 0);
        
        // if animation is complete, start over
        if ((frame+1) >= len) {
            LVLMAN_set_component(ent, ENTITY_COMPONENT_ANIM_FRAME, 0);
        // ... or just continue
        } else {
            LVLMAN_add_to_component(ent, ENTITY_COMPONENT_ANIM_FRAME, 1);
        }

        SYSTEM_set_frame(ent);
        SYSTEM_set_hitbox(ent);
    }
}

void SYSTEM_continue_jump(
    int ent
) {
    int frame  = LVLMAN_get_component(ent, ENTITY_COMPONENT_ANIM_FRAME);
    int timer  = LVLMAN_get_component(ent, ENTITY_COMPONENT_ANIM_TIMER);
    int delay  = LVLMAN_get_component(ent, ENTITY_COMPONENT_ANIM_DELAY);
    int button = CON_button_still_pressed(KEY_PRESSED_SPACE);

    int state = LVLMAN_get_component(ent, ENTITY_COMPONENT_STATE);

    assert(state==PREJUMP);

    if ((timer < delay) && (button)) {
        LVLMAN_add_to_component(ent, ENTITY_COMPONENT_Y_VEL, PRE_JUMP_POWUH);
    } else {
        ENT_change_state(ent, JUMPING);
    }
}

void SYSTEM_catch_pos_change(
    int ent
) {
    LVLMAN_set_component(ent, ENTITY_COMPONENT_X_POS_DES, NOT_SET);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_POS_DES, NOT_SET);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_X_VEL_DES, NOT_SET);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_Y_VEL_DES, NOT_SET);
}

void SYSTEM_set_defaults(
    int ent
) {
    int bpt     = LVLMAN_try_get_component(ent, ENTITY_COMPONENT_BPT, -1);
    
    if (bpt == -1) {
        printf("Entity missing the blueprint value!");
        return;
    }

    for (int comp=0; comp<AVAILABLE_COMPONENTS; comp++) {

        if (LVLMAN_check_component(ent, comp)) {
            continue; 
        }

        if (ENT_check_def(comp, bpt)) {
            int val = ENT_get_def(comp, bpt);

            // TODO: correct it (without the sum operator)
            DATATABLE_create(level_manager->level, ent+comp);

            int* entry = LVLMAN_get_entry(ent, comp);

            entry[DATA_COL_A] = ENTITY_DATA;
            entry[DATA_COL_B] = -1;
            entry[DATA_COL_C] = -1;
            entry[DATA_COL_D] = val;
        }
    }
}

void SYSTEM_block_init(
    int ent
) {
    int val     = LVLMAN_get_component(ent, ENTITY_COMPONENT_PHASES);
    int new_val = val & ~(1 << PHASE_INIT);
    LVLMAN_set_component(ent, ENTITY_COMPONENT_PHASES, new_val);
}

behaviour behaviour_library[BEHAVIOUR_ALL] = {
    SYSTEM_put_to_canvas            ,
    SYSTEM_set_camera              ,
    SYSTEM_add_gravity             ,
    SYSTEM_add_velocity            ,
    SYSTEM_update_position         ,
    SYSTEM_set_focus               ,
    SYSTEM_check_collision         ,
    SYSTEM_check_if_falling        ,
    SYSTEM_check_stop_falling      ,
    SYSTEM_jump                    ,
    SYSTEM_left                    ,
    SYSTEM_right                   ,
    SYSTEM_horizontal_air_friction ,
    SYSTEM_horizontal_friction     ,
    SYSTEM_add_frame_timer         ,
    SYSTEM_anim_frame              ,
    SYSTEM_continue_jump           ,
    SYSTEM_catch_pos_change        ,
    SYSTEM_set_hitbox              ,
    SYSTEM_set_frame               ,
    SYSTEM_set_defaults            ,
    SYSTEM_block_init              ,
    SYSTEM_update_sector           
};

collision_behaviour collision_behaviour_library[COLLISION_BEHAVIOUR_ALL] = {
    SYSTEM_normal_collision
};
