#include "entity.h"
#include "geometry.h"

#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

// macros
#define N_SECTORS_PER_DEPTH(d) (d * 2 + 1)

#define MAX_SAVED_ENTITY             10
#define SECTOR_W                     160
#define SECTOR_H                     128
#define MAX_ENTITY_PER_SECTOR        40

// How many sectors are created in each direction around main sector. This value
// set to '1' means that there are one sector in each direction from the main
// one, making it 1 (main) + 8 (in each direction) in total.
#define SECTOR_DEPTH                 2

#define SECTORS_X                    N_SECTORS_PER_DEPTH(SECTOR_DEPTH)
#define SECTORS_Y                    N_SECTORS_PER_DEPTH(SECTOR_DEPTH)
#define ENTITY_N_MAX                 SECTORS_Y * SECTORS_X * MAX_ENTITY_PER_SECTOR

enum ENITY_COMPONENTS {
    ENTITY_COMPONENT_ID,
    ENTITY_COMPONENT_BLUEPRINT_ID,
    ENTITY_COMPONENT_X_POS,
    ENTITY_COMPONENT_Y_POS,
    ENTITY_COMPONENT_X_POS_DES,
    ENTITY_COMPONENT_Y_POS_DES,
    ENTITY_COMPONENT_X_SEC,
    ENTITY_COMPONENT_Y_SEC,
    ENTITY_COMPONENT_N_SEC,
    ENTITY_COMPONENT_X_VEL,
    ENTITY_COMPONENT_Y_VEL,
    ENTITY_COMPONENT_X_VEL_DES,
    ENTITY_COMPONENT_Y_VEL_DES,
    ENTITY_COMPONENT_DIR,
    ENTITY_COMPONENT_STATE,
    ENTITY_COMPONENT_ANIM_FRAME,
    ENTITY_COMPONENT_ANIM_TIMER,
    ENTITY_COMPONENT_TEXTURE,
    ENTITY_COMPONENT_SHEET,
    ENTITY_COMPONENT_LAYER,
    ENTITY_COMPONENT_BUFFER,
    ENTITY_COMPONENT_ALL
};

typedef struct sector {
    int entities[MAX_ENTITY_PER_SECTOR];
    int n;
    int delta_x;
    int delta_y;
    int global_x;
    int global_y;
} sector_t;

typedef struct entity_manager {
    sector_t  sectors[SECTORS_Y][SECTORS_X];
    int       components[ENTITY_N_MAX][ENTITY_COMPONENT_ALL];
} entity_manager_t;

void ENTMAN_init();
void ENTMAN_orient_sectors(int sec_x, int sec_y);
void ENTMAN_set_component(int e, int component, int val);
void ENTMAN_add_entity_to_sector(int e, int sec_x, int sec_y);
void ENTMAN_add_to_component(int e, int component, int val);
void ENTMAN_remove_entity_from_sector(int e, int sec_x, int sec_y);
void ENTMAN_clean_sector(int x, int y);

void ENTMAN_clean_sector_col(int x);
void ENTMAN_clean_sector_row(int y);

void ENTMAN_move_sectors_down();
void ENTMAN_move_sectors_up();
void ENTMAN_move_sectors_right();
void ENTMAN_move_sectors_left();

int ENTMAN_get_entity(int sec_x, int sec_y, int idx);
int ENTMAN_global_sec_x(int x, int y);
int ENTMAN_global_sec_y(int x, int y);
int ENTMAN_n_entites_on_sector(int x, int y);

void ENTMAN_set_defaults(int e);
void ENTMAN_change_state(int e, int anim);
void ENTMAN_free();
void ENTMAN_debug_entity(int e);

int ENTMAN_frame_data(int e, int state, int frame, int record, int coord);
int ENTMAN_get_component(int e, int component);

rectangle_t ENTMAN_hit_box_rect(int e);
char* ENTMAN_get_entity_name(int e);

#endif
