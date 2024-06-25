#ifndef LEVEL_H
#define LEVEL_H

#define LEVEL_MAX_X_SECTOR    13
#define LEVEL_MAX_Y_SECTOR    13 
#define LEVEL_MAX_RECORD      20

#define LEVEL_METADATA 42
#define LEVEL_ENTITY   69

#define LEVEL_METADATA_IDX           0
#define LEVEL_ENTITY_IDX             1

#define LEVEL_COMPONENT_RECORD_TYPE         0
#define LEVEL_ENTITY_COMPONENT_ID           1
#define LEVEL_ENTITY_COMPONENT_EMIT         2
#define LEVEL_ENTITY_COMPONENT_X            3
#define LEVEL_ENTITY_COMPONENT_Y            4
#define LEVEL_ENTITY_COMPONENT_BLUEPRINT_ID 5
#define LEVEL_ENTITY_START_ANIM             6
#define LEVEL_ENTITY_START_FRAME            7

#define LEVEL_METADATA_SEC_X         1
#define LEVEL_METADATA_SEC_Y         2
#define LEVEL_METADATA_SEC_N         3
#define LEVEL_METADATA_FREE_A        4
#define LEVEL_METADATA_FREE_B        5
#define LEVEL_METADATA_FREE_C        6
#define LEVEL_METADATA_FREE_D        7
#define LEVEL_COMPONENT_ALL          8

typedef int level_components[LEVEL_MAX_Y_SECTOR][LEVEL_MAX_X_SECTOR][LEVEL_MAX_RECORD][LEVEL_COMPONENT_ALL];

typedef struct level {
    level_components *components;
    int               x_sectors;
    int               y_sectors;
} level_t;

level_t* LVL_new(level_components *components, int x_sectors, int y_sectors);

int LVL_n_entities(level_t *level, int sec_x, int sec_y);
int LVL_get_component(level_t *level, int sec_x, int sec_y, int record, int component);

void LVL_set_component(level_t *level, int sec_x, int sec_y, int record, int component, int val);
void LVL_free(level_t* level);

#endif
