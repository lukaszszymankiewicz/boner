#include "geometry.h"

#ifndef ENTITY_H
#define ENTITY_H

#define SUBPIX         8
#define NOT_SET       -1

int ENT_anim_len(int bpt, int anim);
int ENT_frame_data(int bpt, int state, int frame, int comp, int val);

int ENT_def_idx();
int ENT_get_def(int comp, int bpt);
int ENT_check_def(int comp, int bpt);

rectangle_t ENT_hitbox_rect(int ent);
rectangle_t ENT_static_hitbox_rect(int ent);

void ENT_change_state(int ent, int anim);

int ENT_get_n_beh(int bpt, int state, int phase);
int ENT_get_nth_beh(int bpt, int state, int phase, int n);
int ENT_get_collide_fun(int bpt, int state, int col_body);

#endif
