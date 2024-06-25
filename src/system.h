#include "collision.h"

#ifndef SYSTEM_H
#define SYSTEM_H

#define FULL_DEPTH      2
#define INIT_DEPTH      FULL_DEPTH
#define DRAW_DEPTH      FULL_DEPTH
#define PRE_DEPTH       FULL_DEPTH
#define UPDATE_DEPTH    FULL_DEPTH
#define RESOLVE_DEPTH   FULL_DEPTH
#define COLLISION_DEPTH FULL_DEPTH
#define CONTROL_DEPTH   0

void SYSTEM_run_on_quadrant(int phase, int phase_depth);

void SYSTEM_update_position(int e, context_t* c);
void SYSTEM_add_velocity(int e, context_t* c);
void SYSTEM_add_gravity(int e, context_t* c);
void SYSTEM_put_to_scene(int e, context_t* c);
void SYSTEM_emit_from_level(int e, context_t* c);
void SYSTEM_no_emit_from_level(int e, context_t* c);
void SYSTEM_set_camera(int e, context_t* c);
void SYSTEM_init_entity(int e, context_t* c);
void SYSTEM_add_entity_to_sector(int e, context_t* c);
void SYSTEM_set_defaults(int e, context_t* c);
void SYSTEM_set_on_level(int e, context_t* c);
void SYSTEM_orient_segments(int e, context_t* c);
void SYSTEM_set_focus(int e, context_t* c);
void SYSTEM_check_collision(int e, context_t* c);
void SYSTEM_is_collidable(int e, context_t* c);
void SYSTEM_normal_collision(int e, context_t* c, collision_t col);
void SYSTEM_jump(int e, context_t* c);
void SYSTEM_check_if_falling(int e, context_t* c);
void SYSTEM_check_stop_falling(int e, context_t* c);
void SYSTEM_right(int e, context_t* c);
void SYSTEM_left(int e, context_t* c);
void SYSTEM_horizontal_air_friction(int e, context_t* c);
void SYSTEM_horizontal_friction(int e, context_t* c);
void SYSTEM_debug_entity(int e, context_t* c);
void SYSTEM_add_frame_timer(int e, context_t* c);
void SYSTEM_anim_frame(int e, context_t* c);
void SYSTEM_continue_jump(int e, context_t* c);
void SYSTEM_catch_pos_change(int e, context_t* c);

#endif
