#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "datatable.h"
#include "macros.h"
#include "modules.h"
#include "level_manager.h"
#include "symbols.h"

void LVLMAN_set_level(
    level_t level
) {
    level_manager->level = level;
}

// metadata
int LVLMAN_id(
) {
    return DATATABLE_get_val(level_manager->level, ID, DATA_COL_D);
}

int LVLMAN_width(
) {
    return DATATABLE_get_val(level_manager->level, LEVEL_WIDTH, DATA_COL_D);
}

int LVLMAN_size_x(
) {
    return DATATABLE_get_val(level_manager->level, LEVEL_SIZE_X, DATA_COL_D);
}

int LVLMAN_size_y(
) {
    return DATATABLE_get_val(level_manager->level, LEVEL_SIZE_Y, DATA_COL_D);
}

int LVLMAN_focus_x(
) {
    return DATATABLE_get_val(level_manager->level, LEVEL_FOCUS_X, DATA_COL_D);
}

int LVLMAN_focus_y(
) {
    return DATATABLE_get_val(level_manager->level, LEVEL_FOCUS_Y, DATA_COL_D);
}

void LVLMAN_set_focus_x(
    int val
) {
    DATATABLE_set_val(level_manager->level, LEVEL_FOCUS_X, DATA_COL_D, val);
}

void LVLMAN_set_focus_y(
    int val
) {
    DATATABLE_set_val(level_manager->level, LEVEL_FOCUS_X, DATA_COL_D, val);
}

void LVLMAN_init(
) {
    level_manager        = NULL;
    level_manager        = (level_manager_t*)malloc(sizeof(level_manager_t));
}

// sector
int LVLMAN_sector_map_idx(
    int x,
    int y
) {
    int map_idx = MAP + y * LVLMAN_size_y() + x;

    assert(x == DATATABLE_get_val(level_manager->level, map_idx, DATA_COL_B));
    assert(y == DATATABLE_get_val(level_manager->level, map_idx, DATA_COL_C));

    return map_idx;
}

int LVLMAN_sector_metadata_idx(
    int x, 
    int y
) {
    int map_idx             = LVLMAN_sector_map_idx(x, y);
    int sector_metadata_idx = DATATABLE_get_val(level_manager->level, map_idx, DATA_COL_D);
    
    assert(METADATA == DATATABLE_get_val(level_manager->level, sector_metadata_idx, DATA_COL_A));
    assert(x == DATATABLE_get_val(level_manager->level, sector_metadata_idx, DATA_COL_B));
    assert(y == DATATABLE_get_val(level_manager->level, sector_metadata_idx, DATA_COL_C));
    
    return sector_metadata_idx;
}

int LVLMAN_n_entities(
    int      x,
    int      y
) {
    int sector_metadata_idx = LVLMAN_sector_metadata_idx(x, y);

    return DATATABLE_get_val(level_manager->level, sector_metadata_idx, DATA_COL_D);
}

int LVLMAN_entity_idx( 
    int x, 
    int y,
    int n
) {
    int sector_metadata_idx = LVLMAN_sector_metadata_idx(x, y);

    assert(n>=0);
    assert(n<=LVLMAN_n_entities(x, y));

    int entity_map_idx = sector_metadata_idx + n + 1;

    assert(MAP == DATATABLE_get_val(level_manager->level, entity_map_idx, DATA_COL_A));

    return DATATABLE_get_val(level_manager->level, entity_map_idx, DATA_COL_D);
}

// single entity components
int LVLMAN_get_component(
    int idx,
    int comp 
) {
    int comp_idx = idx + comp;

    return DATATABLE_get_val(level_manager->level, comp_idx, DATA_COL_D);
}

int LVLMAN_try_get_component(
    int idx,
    int comp,
    int def
) {
    int comp_idx = idx + comp;

    int ex  = DATATABLE_exist(level_manager->level, comp_idx);
    int res = def;
    
    if (ex) {
        assert(ENTITY_DATA == DATATABLE_get_val(level_manager->level, comp_idx, DATA_COL_A));
        res = DATATABLE_get_val(level_manager->level, comp_idx, DATA_COL_D);
    }
    
    return res;
}

int* LVLMAN_get_entry(
    int idx,
    int comp
) {
    int comp_idx = idx + comp;

    return DATATABLE_get_entry(level_manager->level, comp_idx);
}

void LVLMAN_set(
    int idx,
    int col,
    int val
) {
    ASSERT_RANGE(0, col, DATA_COL_ALL);

    return DATATABLE_set_val(level_manager->level, idx, col, val);
}

int LVLMAN_get(
    int idx,
    int col
) {
    return DATATABLE_get_val(level_manager->level, idx, col);
}

void LVLMAN_set_ent_metadata_n(
    int idx,
    int val
) {
    assert(METADATA == DATATABLE_get_val(level_manager->level, idx, DATA_COL_A));

    LVLMAN_set(idx, DATA_COL_D, val);
}

void LVLMAN_set_ent_map_nth(
    int idx,
    int val
) {
    assert(MAP == DATATABLE_get_val(level_manager->level, idx, DATA_COL_A));

    LVLMAN_set(idx, DATA_COL_C, val);
}

int LVLMAN_get_ent_nth(
    int ent
) {
    return DATATABLE_get_val(level_manager->level, ent, DATA_COL_D);
}

int LVLMAN_get_sector_x(
    int idx
) {
    LVLMAN_get(idx, DATA_COL_B);
}

int LVLMAN_get_sector_y(
    int idx
) {
    LVLMAN_get(idx, DATA_COL_C);
}

void LVLMAN_set_sector_x(
    int idx,
    int val
) {
    assert(ENTITY_NTH == DATATABLE_get_val(level_manager->level, idx, DATA_COL_A));

    LVLMAN_set(idx, DATA_COL_B, val);
}

void LVLMAN_set_sector_y(
    int idx,
    int val
) {
    assert(ENTITY_NTH == DATATABLE_get_val(level_manager->level, idx, DATA_COL_A));

    LVLMAN_set(idx, DATA_COL_C, val);
}

void LVLMAN_set_component(
    int idx,
    int comp,
    int val
) {
    LVLMAN_set(idx + comp, DATA_COL_D, val);
}

void LVLMAN_change_n_entity_on_sector(
    int idx,
    int delta
) {
    int cur_val = DATATABLE_get_val(level_manager->level, idx, DATA_COL_D);

    return DATATABLE_set_val(level_manager->level, idx, DATA_COL_D, cur_val + delta);
}

void LVLMAN_add_to_component(
    int idx,
    int comp,
    int val
) {
    int comp_idx = idx + comp;
    int cur_val = LVLMAN_get_component(idx, comp);

    return DATATABLE_set_val(level_manager->level, comp_idx, DATA_COL_D, cur_val + val);
}

int LVLMAN_check(
    int idx
) {
    return DATATABLE_exist(level_manager->level, idx);
}

int LVLMAN_check_component(
    int idx,
    int comp
) {
    int comp_idx = idx + comp;

    return DATATABLE_exist(level_manager->level, comp_idx);
}

int* LVLMAN_add(
    int idx
) {
    DATATABLE_create(level_manager->level, idx);
}

void LVLMAN_delete(
    int idx
) {
    DATATABLE_del(level_manager->level, idx);
}

int LVLMAN_last(
) {
    return DATATABLE_last(level_manager->level);
}

void LVLMAN_move(
    int from,
    int to
) {
    DATATABLE_move(level_manager->level, from, to);
}

int LVLMAN_move_to_end(
    int from
) {
    int to = LVLMAN_last() + 1;

    DATATABLE_move(level_manager->level, from, to);
    level_manager->level->last = to;

    return to;
}

void LVLMAN_move_ent_to_sector(
    int ent,
    int sec_x,
    int sec_y
) {
    // check if there is place for entity map in new sector
    int metadata = LVLMAN_sector_metadata_idx(sec_x, sec_y);
    int n = LVLMAN_n_entities(sec_x, sec_y);

    int place = metadata + n + 1; 
    int new_metadata_idx;

    // if key for new entity map is occupied, move of sector metadata +
    // entity maps needs to be moved to the end
    if (LVLMAN_check(place)) {

        // move meta
        new_metadata_idx = LVLMAN_move_to_end(metadata);
        place = new_metadata_idx;

        // move ent metadatas
        for (int e=metadata+1; e<metadata+n+1; e++) {
            place = LVLMAN_move_to_end(e);
        }
        place++;
    } else {
        new_metadata_idx = metadata;
    }

    int* new_map = LVLMAN_add(place);

    new_map[DATA_COL_A] = MAP;
    new_map[DATA_COL_B] = 0;
    new_map[DATA_COL_C] = n+1;
    new_map[DATA_COL_D] = ent;

    // correct sector map
    int sector_map = LVLMAN_sector_map_idx(sec_x, sec_y);

    LVLMAN_set(sector_map, DATA_COL_D, new_metadata_idx);

    // set n on metadata
    LVLMAN_set(new_metadata_idx, DATA_COL_D, n+1);

    // set nth on map
    LVLMAN_set_ent_map_nth(place, n);
    
    // set nth on ent
    // TODO: move this operation to more readable function
    LVLMAN_set(ent, DATA_COL_D, n);

    // lasty update the the sector of entity
    LVLMAN_set_sector_x(ent, sec_x);
    LVLMAN_set_sector_y(ent, sec_y);
}

void LVLMAN_remove_ent_from_sector(
    int ent
) {
    int sec_x = LVLMAN_get(ent, DATA_COL_B);
    int sec_y = LVLMAN_get(ent, DATA_COL_C);

    int nth = LVLMAN_get_ent_nth(ent);
    int n = LVLMAN_n_entities(sec_x, sec_y);

    int metadata_idx = LVLMAN_sector_metadata_idx(sec_x, sec_y);
    int map_idx = metadata_idx + nth + 1;

    LVLMAN_delete(map_idx);

    // move last entity from old sector to empty space created by moving
    if ((n-1) != nth) {
        int last_ent = metadata_idx + n;

        LVLMAN_set_ent_map_nth(last_ent, nth);
        LVLMAN_move(last_ent, metadata_idx+nth+1);
    }

    LVLMAN_set_ent_metadata_n(metadata_idx, n-1);

    // detach from any sector
    LVLMAN_set_sector_x(ent, -1);
    LVLMAN_set_sector_y(ent, -1);
}

void LVLMAN_debug(
    int key
) {
    int xx = LVLMAN_size_x();
    int yy = LVLMAN_size_y();

    for (int i=0; i<LEVEL_FOCUS_Y+1; i++) {
        int* entry = DATATABLE_get_entry(level_manager->level, i);
        printf("%d | %d, %d, %d, %d \n", i, entry[0], entry[1], entry[2], entry[3]);
    }

    // maps
    for (int y=0; y<yy; y++) {
        for (int x=0; x<xx; x++) {
            int i = MAP + y * yy + x;
            int* entry = DATATABLE_get_entry(level_manager->level, i);

            printf("  %d | %d, %d, %d, %d \n", i, entry[0], entry[1], entry[2], entry[3]);
        }
    }

    // metadata and entites
    for (int y=0; y<yy; y++) {
        for (int x=0; x<xx; x++) {
            int i = MAP + y * yy + x;
            int* entry = DATATABLE_get_entry(level_manager->level, i);
            // map to metadata
            int key = entry[3];
            
            // metadata
            entry = DATATABLE_get_entry(level_manager->level, key);
            printf("    %d | %d, %d, %d, %d \n", key, entry[0], entry[1], entry[2], entry[3]);

            int ents = entry[3];
            
            // printf ents maps
            for (int e=1; e<ents+1; e++) {
                entry = DATATABLE_get_entry(level_manager->level, key+e);
                printf("      %d | %d, %d, %d, %d \n", key+e, entry[0], entry[1], entry[2], entry[3]);
            }

            // printf ents contetn
            for (int e=1; e<ents+1; e++) {
                entry = DATATABLE_get_entry(level_manager->level, key+e);
                int entkey  = entry[3];
                entry = DATATABLE_get_entry(level_manager->level, entkey);
                printf("        %d | %d, %d, %d, %d \n", entkey, entry[0], entry[1], entry[2], entry[3]);

                for (int comp=1; comp<AVAILABLE_COMPONENTS; comp++) {
                    if (DATATABLE_exist(level_manager->level, entkey+comp)) {
                        entry = DATATABLE_get_entry(level_manager->level, entkey+comp);
                        printf("        %d | %d, %d, %d, %d \n", entkey+comp, entry[0], entry[1], entry[2], entry[3]);
                    }

                }
            }
        }
    }

}
void LVLMAN_free(
) {
    level_manager->level = NULL;

    free(level_manager);
    level_manager = NULL;
}
