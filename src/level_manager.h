#include "level.h"

#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

typedef struct level_manager {
    level_t      *level;
    int           id;
    int           focus_x;
    int           focus_y;
} level_manager_t;

void LVLMAN_init();
void LVLMAN_set_level(int blueprint_id);
void LVLMAN_free();

int LVLMAN_get_entity_idx(int i);
int LVLMAN_n_entities(int x, int y);
int LVLMAN_get_component(int sec_x, int sec_y, int record, int type);
void LVLMAN_set_component(int sec_x, int sec_y, int component, int val, int new_val);

int LVLMAN_x_sectors();
int LVLMAN_y_sectors();
void LVLMAN_delete_entity(int sec_x, int sec_y, int ent);
void LVLMAN_debug_sector(int sec_x, int sec_y);

#endif
