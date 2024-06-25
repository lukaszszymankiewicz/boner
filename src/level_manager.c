/* Managing levels code */

#include <assert.h>

#include "data/library.h"

#include "modules.h"
#include "level_manager.h"
#include "level.h"

#define MUST_BE_ON_LEVEL ENTITY_HERO

void LVLMAN_init(
) {
    level_manager        = NULL;
    level_manager        = (level_manager_t*)malloc(sizeof(level_manager_t));
}

int check_correctness(
) {
    int bpt;
    int x = level_manager->focus_x;
    int y = level_manager->focus_y;
    int n = LVL_n_entities(level_manager->level, x, y);
    
    for (int i=0; i<n; i++) {
        bpt = LVLMAN_get_component(x, y, i, LEVEL_ENTITY_COMPONENT_BLUEPRINT_ID);
        if (bpt == MUST_BE_ON_LEVEL) { 
            return 1;
        }
    }
    return 0;
}

void LVLMAN_set_level(
    int              blueprint_id
) {
    assert(blueprint_id >=0);
    assert(blueprint_id < LEVEL_ALL);

    level_t* level = NULL;

    level = LVL_new(
        &(levels_library[blueprint_id]->entities),
        levels_library[blueprint_id]->x_sectors,
        levels_library[blueprint_id]->y_sectors
    );

    level_manager->id      = blueprint_id;
    level_manager->level   = level;
    level_manager->focus_x = levels_library[blueprint_id]->x_focus;
    level_manager->focus_y = levels_library[blueprint_id]->y_focus;

    check_correctness();
}


int LVLMAN_x_sectors(
) {
    return level_manager->level->x_sectors;
}

int LVLMAN_y_sectors(
) {
    return level_manager->level->y_sectors;
}

int LVLMAN_n_entities(
    int x,
    int y
) {
    return LVL_n_entities(level_manager->level, x, y);
}

int LVLMAN_get_entity_idx(
    int i
) {
    return i + LEVEL_ENTITY_IDX;
}

int LVLMAN_get_component(
    int sec_x,
    int sec_y,
    int component,
    int val
) {
    return LVL_get_component(level_manager->level, sec_x, sec_y, component, val);
}

void LVLMAN_set_component(
    int sec_x,
    int sec_y,
    int component,
    int val,
    int new_val
) {
    LVL_set_component(level_manager->level, sec_x, sec_y, component, val, new_val);
}

int LVLMAN_entity_idx(
    int sec_x,
    int sec_y,
    int ent
) {
    for (int i=0; i<LEVEL_MAX_RECORD; i++) {
        int idx = LVLMAN_get_entity_idx(i);
        int id  = LVLMAN_get_component(sec_x, sec_y, idx, LEVEL_ENTITY_COMPONENT_ID);

        if (id == ent) {
            return i;
        }
    }

    return -1;
}

void LVLMAN_debug_sector(
    int sec_x,
    int sec_y
) {
    for (int i=0; i<LEVEL_MAX_RECORD; i++) {
        for (int j=0; j<LEVEL_MAX_RECORD; j++) {
            int val = (*(level_manager->level->components))[sec_y][sec_x][i][j];
            printf("%d | ", val);
        }
        printf("\n\n");
    }

}

void LVLMAN_delete_entity(
    int sec_x,
    int sec_y,
    int ent
) {
    int idx = LVLMAN_entity_idx(sec_x, sec_y, ent);
    assert(idx != -1);
    int n = LVL_n_entities(level_manager->level, sec_x, sec_y);

    if (idx == n-1) {
        LVLMAN_set_component(sec_x, sec_y, LEVEL_METADATA_IDX, LEVEL_METADATA_SEC_N, n-1);
    } else {
        LVLMAN_set_component(sec_x, sec_y, LEVEL_METADATA_IDX, LEVEL_METADATA_SEC_N, n-1);

        for (int j=LEVEL_ENTITY_COMPONENT_ID; j<LEVEL_COMPONENT_ALL; j++) {
            int val = LVL_get_component(level_manager->level, sec_x, sec_y, n, j);
            LVLMAN_set_component(sec_x, sec_y, idx, j, val);
        }
    }

    int n_new = LVL_get_component(level_manager->level, sec_x, sec_y, LEVEL_METADATA_IDX, LEVEL_METADATA_SEC_N);

    assert(n_new >= 0);
    assert(n_new < n);
}

void LVLMAN_free(
) {
    LVL_free(level_manager->level);
    level_manager->level = NULL;

    free(level_manager);
    level_manager = NULL;
}
