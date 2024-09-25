#include "datatable.h"

#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

typedef struct level_manager {
  level_t  level;
  int      id;
} level_manager_t;

void LVLMAN_init();

int LVLMAN_width();
int LVLMAN_size_x();
int LVLMAN_size_y();
int LVLMAN_focus_x();
int LVLMAN_focus_y();
int LVLMAN_sector_map_idx(int x, int y);
int LVLMAN_sector_metadata_idx(int x, int y);
int LVLMAN_n_entities(int x, int y);
int LVLMAN_entity_idx(int x, int y, int n);

void LVLMAN_change_n_entity_on_sector(int idx, int delta);

int LVLMAN_get_component(int idx, int comp);
int LVLMAN_try_get_component(int idx, int comp, int def);

int* LVLMAN_get_entry(int idx, int comp);
int* LVLMAN_add(int idx);

void LVLMAN_set(int idx, int col, int val);

void LVLMAN_set_component(int idx, int comp, int val);
void LVLMAN_set_sector_x(int idx, int val);
void LVLMAN_set_sector_y(int idx, int val);
void LVLMAN_set_ent_metadata_n(int idx, int val);
void LVLMAN_set_ent_map_nth(int idx, int val);
void LVLMAN_add_to_component(int idx, int comp, int val);
void LVLMAN_remove_ent_from_sector(int ent);
void LVLMAN_move_ent_to_sector(int ent, int sec_x, int sec_y);
int LVLMAN_check_component(int idx, int comp);

int LVLMAN_last();
void LVLMAN_set_focus_x(int val);
void LVLMAN_set_focus_y(int val);

int LVLMAN_get_sector_x(int idx);
int LVLMAN_get_sector_y(int idx);

void LVLMAN_move(int from, int to);
int LVLMAN_move_to_end(int from);

void LVLMAN_delete(int idx);
void LVLMAN_free();
void LVLMAN_debug();

#endif
