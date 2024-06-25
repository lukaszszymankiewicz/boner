/* Entity-related code. Almost all heavy lifting is done here. 
 * Entities are keps in 'sectors', which are basically just a collection of
 * enties on smaller part of the level. Only few of them are 'active', around
 * hero (or other relative point) to save memory and computation power. If
 * needed other sectors are filled or discareded (according to movement of the
 * hero for example). Active sectors (with entities interacting with the world)
 * are called "local", while any sector from the level is called global. Global
 * sectors have fix coordinates.
 * Entities management is using dumb fake-ECP, where every entity have its
 * related component values kept in one big array. More sofisticated (and
 * advanced) system should involve using only those componenets which entity is
 * using (and separate totally the components from values to join it only by
 * component ID). This can be done later on if needed.
 * Entites are created according to its blueprints (see src/data/entities.c).
 */

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#include "data/library.h"

#include "animation.h"
#include "modules.h"
#include "entity.h"
#include "entity_manager.h"
#include "macros.h"

void ENTMAN_clean_sector(
    int x,
    int y
) {
    entity_manager->sectors[y][x].n = 0;
    memset(entity_manager->sectors[y][x].entities, 0, sizeof(int) * MAX_ENTITY_PER_SECTOR);
}

void ENTMAN_clean_sector_col(
    int x
) {
    for (int y=0; y<SECTORS_Y; y++) {
        ENTMAN_clean_sector(x, y);
    }
}

void ENTMAN_clean_sector_row(
    int y
) {
    for (int x=0; x<SECTORS_X; x++) {
        ENTMAN_clean_sector(x, y);
    }
}

void ENTMAN_init(
) {
    entity_manager = NULL;
    entity_manager = (entity_manager_t*)malloc(sizeof(entity_manager_t));

    int middle_x   = SECTOR_DEPTH;
    int middle_y   = SECTOR_DEPTH;

    for (int x=0; x<SECTORS_X; x++) {
        for (int y=0; y<SECTORS_Y; y++) {

            entity_manager->sectors[y][x].n = 0;
            entity_manager->sectors[y][x].delta_x = x - middle_x;
            entity_manager->sectors[y][x].delta_y = SECTORS_Y - 1 - y - middle_y;
            entity_manager->sectors[y][x].global_x = -1; // not set
            entity_manager->sectors[y][x].global_y = -1; // not set

            for (int i=0; i<MAX_ENTITY_PER_SECTOR; i++) {
                entity_manager->sectors[y][x].entities[i] = 0;
            }
        }
    }

    memset(entity_manager->components, 0, ENTITY_N_MAX * ENTITY_COMPONENT_ALL);
}

void ENTMAN_orient_sectors(
    int focus_x,
    int focus_y
) {
    ASSERT_RANGE(0, focus_x, LEVEL_MAX_X_SECTOR);
    ASSERT_RANGE(0, focus_y, LEVEL_MAX_Y_SECTOR);

    for (int x=0; x<SECTORS_X; x++) {
        for (int y=0; y<SECTORS_Y; y++) {
            entity_manager->sectors[y][x].global_x = focus_x + entity_manager->sectors[y][x].delta_x;
            entity_manager->sectors[y][x].global_y = focus_y + entity_manager->sectors[y][x].delta_y;
        }
    }
}

int ENTMAN_n_entites_on_sector(
    int x,
    int y
) {
    ASSERT_RANGE(0, x, SECTORS_X);
    ASSERT_RANGE(0, y, SECTORS_Y);

    return entity_manager->sectors[y][x].n;
}

void ENTMAN_set_component(
    int ent,
    int comp,
    int val
) {
    ASSERT_RANGE(0, comp, ENTITY_COMPONENT_ALL);
    ASSERT_RANGE(0, ent,  ENTITY_N_MAX);
    
    entity_manager->components[ent][comp] = val; 
}

void ENTMAN_add_to_component(
    int ent,
    int comp,
    int val
) {
    ASSERT_RANGE(0, comp, ENTITY_COMPONENT_ALL);
    ASSERT_RANGE(0, ent, ENTITY_N_MAX);
    
    entity_manager->components[ent][comp] += val;
}

int ENTMAN_get_component(
    int ent,
    int comp
) {
    ASSERT_RANGE(0, comp, ENTITY_COMPONENT_ALL);
    ASSERT_RANGE(0, ent, ENTITY_N_MAX);

    return entity_manager->components[ent][comp];
}

char *ENTMAN_get_entity_name(
    int ent
) {
    ASSERT_RANGE(0, ent, ENTITY_N_MAX);

    int bpt = ENTMAN_get_component(ent, ENTITY_COMPONENT_BLUEPRINT_ID);
    return entity_library[bpt]->name;
}
 
int ENTMAN_get_entity(
    int       sec_x,
    int       sec_y,
    int       idx
) {
    ASSERT_RANGE(0, sec_x, SECTORS_X);
    ASSERT_RANGE(0, sec_y, SECTORS_Y);
    ASSERT_RANGE(0, idx, MAX_ENTITY_PER_SECTOR);

    return entity_manager->sectors[sec_y][sec_x].entities[idx];
}

void ENTMAN_add_entity_to_sector(
    int ent,
    int sec_x,
    int sec_y
) {
    ASSERT_RANGE(0, sec_x, SECTORS_X);
    ASSERT_RANGE(0, sec_y, SECTORS_Y);

    int n = entity_manager->sectors[sec_y][sec_x].n;
    assert(n+1 < MAX_ENTITY_PER_SECTOR);

    entity_manager->sectors[sec_y][sec_x].entities[n] = ent;
    ENTMAN_set_component(ent, ENTITY_COMPONENT_N_SEC, n);
    entity_manager->sectors[sec_y][sec_x].n++;
}

void ENTMAN_remove_entity_from_sector(
    int ent,
    int sec_x,
    int sec_y
) {
    ASSERT_RANGE(0, sec_x, SECTORS_X);
    ASSERT_RANGE(0, sec_y, SECTORS_Y);

    int old_n  = entity_manager->sectors[sec_y][sec_x].n;
    int n      = ENTMAN_get_component(ent, ENTITY_COMPONENT_N_SEC);
    int qe     = entity_manager->sectors[sec_y][sec_x].entities[n];
    assert(qe == ent);
    
    assert(old_n - 1 >= 0);
    int last_e = entity_manager->sectors[sec_y][sec_x].entities[old_n-1];
    assert(last_e > 0);

    entity_manager->sectors[sec_y][sec_x].entities[old_n-1] = -1;
    entity_manager->sectors[sec_y][sec_x].entities[n]       = last_e;
    entity_manager->sectors[sec_y][sec_x].n--;
}

// set default component values according to its blueprint.
void ENTMAN_set_defaults(
    int ent
) {
    ASSERT_RANGE(0, ent, ENTITY_N_MAX);

    int b = ENTMAN_get_component(ent, ENTITY_COMPONENT_BLUEPRINT_ID);

    for (int comp=ENTITY_COMPONENT_X_POS; comp<ENTITY_COMPONENT_ALL; comp++) {
        int val = entity_library[b]->defaults[comp];
        ENTMAN_set_component(ent, comp, val);
    }
}

int ENTMAN_frame_data(
    int       ent,
    int       state,
    int       frame,
    int       record,
    int       coord
) {
    int anim_blueprint = ENTMAN_get_component(ent, ENTITY_COMPONENT_SHEET);
    
    animation_t* animation = &(entity_library[anim_blueprint]->animation);

    return ANIM_get_component_value(animation, state, frame, record, coord);
}

// switch entities from one sector to another
void ENTMAN_switch_entities(
    int x1, // from
    int y1, // from
    int x2, // to
    int y2  // to
) {
    ASSERT_RANGE(0, x1, SECTORS_X);
    ASSERT_RANGE(0, x2, SECTORS_X);
    ASSERT_RANGE(0, y1, SECTORS_Y);
    ASSERT_RANGE(0, y2, SECTORS_Y);

    // let the God bless the C99
    int *dest   = &(entity_manager->sectors[y2][x2].entities[0]);
    int *source = &(entity_manager->sectors[y1][x1].entities[0]);
    memcpy(dest, source, sizeof(int) * MAX_ENTITY_PER_SECTOR);
    entity_manager->sectors[y2][x2].n = entity_manager->sectors[y1][x1].n;
}

// Move all entites from one sector to another. Direction of sectors movement is
// aligned with direction of entity which caused this sector movement
void ENTMAN_move_sectors_down(
) {
    for (int y=0; y<SECTORS_Y-1; y++) {
        for (int x=0; x<SECTORS_X; x++) {
            ENTMAN_switch_entities(x, y+1, x, y);
        }
    }
    ENTMAN_clean_sector_row(SECTORS_Y-1);
}

// Move all entities from one sector to another. Direction of sectors movement
// is aligned with direction of entity which caused this sector movement.
void ENTMAN_move_sectors_up(
) {
    for (int y=SECTORS_Y-1; y>0; y--) {
        for (int x=0; x<SECTORS_X; x++) {
            ENTMAN_switch_entities(x, y-1, x, y);
        }
    }
    ENTMAN_clean_sector_row(0);
}

// Move all entities from one sector to another direction of sectors movement is
// aligned with direction of entity which caused this sector movement
void ENTMAN_move_sectors_right(
) {
    for (int x=0; x<SECTORS_X-1; x++) {
        for (int y=0; y<SECTORS_Y; y++) {
            ENTMAN_switch_entities(x+1, y, x, y);
        }
    }
    ENTMAN_clean_sector_col(SECTORS_X-1);
}

// Move all entities from one sector to another direction of sectors movement is
// aligned with direction of entity which caused this sector movement
void ENTMAN_move_sectors_left(
) {
    for (int x=SECTORS_X-1; x>0; x--) {
        for (int y=0; y<SECTORS_Y; y++) {
            ENTMAN_switch_entities(x-1, y, x, y);
        }
    }
    ENTMAN_clean_sector_col(0);
}

int ENTMAN_global_sec_x(
    int x, int y
) {
    ASSERT_RANGE(0, x, SECTORS_X);
    ASSERT_RANGE(0, y, SECTORS_Y);

    return entity_manager->sectors[y][x].global_x;
}

int ENTMAN_global_sec_y(
    int x, int y
) {
    ASSERT_RANGE(0, x, SECTORS_X);
    ASSERT_RANGE(0, y, SECTORS_Y);

    return entity_manager->sectors[y][x].global_y;
}
void ENTMAN_change_state(
    int ent,
    int anim
) {
    ASSERT_RANGE(0, anim, MAX_STATE);
    ASSERT_RANGE(0, ent, ENTITY_N_MAX);
    
    int cur_state = ENTMAN_get_component(ent, ENTITY_COMPONENT_STATE);
    
    if (cur_state == anim) {
        // do nothing
    } else {
        // set new animation and zero the timers
        ENTMAN_set_component(ent, ENTITY_COMPONENT_STATE, anim);
        ENTMAN_set_component(ent, ENTITY_COMPONENT_ANIM_TIMER, 0);
        ENTMAN_set_component(ent, ENTITY_COMPONENT_ANIM_FRAME, 0);
    }
}

rectangle_t ENTMAN_hit_box_rect(
    int ent
) {
    ASSERT_RANGE(0, ent, ENTITY_N_MAX);

    int state  = ENTMAN_get_component(ent, ENTITY_COMPONENT_STATE);
    int frame  = ENTMAN_get_component(ent, ENTITY_COMPONENT_ANIM_FRAME);
    int x  = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_POS);
    int y  = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_POS);
    int hx = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_HITBOX, FRAME_RECT_X);
    int hy = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_HITBOX, FRAME_RECT_Y);
    int hw = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_HITBOX, FRAME_RECT_W);
    int hh = ENTMAN_frame_data(ent, state, frame, ANIMATION_COMPONENT_HITBOX, FRAME_RECT_H);
    int vx = ENTMAN_get_component(ent, ENTITY_COMPONENT_X_VEL);
    int vy = ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL);
    
    rectangle_t rect = GEO_px_to_rect(
        x + hx,
        y + hy,
        hw,
        hh,
        (vx/SUBPIX),
        (vy/SUBPIX)
    );

    return rect;

}

void ENTMAN_debug_sector(
    int x,
    int y
) {
    int n = entity_manager->sectors[y][x].n;
    for (int i=0; i<n; i++) {
        int e = entity_manager->sectors[y][x].entities[i];
        printf("ID=%d | ", ENTMAN_get_component(e, ENTITY_COMPONENT_ID));
        printf("BPT=%d \n", ENTMAN_get_component(e, ENTITY_COMPONENT_BLUEPRINT_ID));
    }
}

void ENTMAN_debug_entity(
    int ent
) {
   printf("ENTITY_COMPONENT_ID=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_ID));
   printf("ENTITY_COMPONENT_BLUEPRINT_ID=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_BLUEPRINT_ID));
   printf("ENTITY_COMPONENT_X_POS=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_X_POS));
   printf("ENTITY_COMPONENT_Y_POS=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_POS));
   printf("ENTITY_COMPONENT_X_SEC=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_X_SEC));
   printf("ENTITY_COMPONENT_Y_SEC=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_SEC));
   printf("ENTITY_COMPONENT_N_SEC=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_N_SEC));
   printf("ENTITY_COMPONENT_X_VEL=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_X_VEL));
   printf("ENTITY_COMPONENT_Y_VEL=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL));
   printf("ENTITY_COMPONENT_X_VEL_DES=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_X_VEL_DES));
   printf("ENTITY_COMPONENT_Y_VEL_DES=%d \n\n", ENTMAN_get_component(ent, ENTITY_COMPONENT_Y_VEL_DES));
   printf("ENTITY_COMPONENT_DIR=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_DIR));
   printf("ENTITY_COMPONENT_STATE=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_STATE));
   printf("ENTITY_COMPONENT_ANIM_FRAME=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_ANIM_FRAME));
   printf("ENTITY_COMPONENT_ANIM_TIMER=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_ANIM_TIMER));
   printf("ENTITY_COMPONENT_TEXTURE=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_TEXTURE));
   printf("ENTITY_COMPONENT_SHEET=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_SHEET));
   printf("ENTITY_COMPONENT_LAYER=%d \n", ENTMAN_get_component(ent, ENTITY_COMPONENT_LAYER));
   printf("ENTITY_COMPONENT_BUFFER=%d \n\n", ENTMAN_get_component(ent, ENTITY_COMPONENT_BUFFER));
};

void ENTMAN_free(
) { 
    free(entity_manager);
    entity_manager = NULL;
}

