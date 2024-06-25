/*single level things. Single level is a 4D array of data, with similiar methods
 * and idea as entities data.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "level.h"
#include "macros.h"

level_t* LVL_new(
    level_components *components,
    int               x_sectors,
    int               y_sectors
) {
    assert(components != NULL);
    ASSERT_RANGE(0, x_sectors, LEVEL_MAX_X_SECTOR);
    ASSERT_RANGE(0, y_sectors, LEVEL_MAX_Y_SECTOR);

    level_t *level    = NULL;
    level             = (level_t*)malloc(sizeof(level_t));
    
    level->components = components;
    level->x_sectors  = x_sectors;
    level->y_sectors  = y_sectors;

    return level;
}
// switching from high y->screen bottom to low y->screen bottom coord
int LVL_y_sec_corr(
    level_t* level,
    int      sec
) {
    return level->y_sectors - sec - 1;
}

void LVL_set_component(
    level_t *level,
    int      sec_x,
    int      sec_y,
    int      record,
    int      component,
    int      val
) {
    ASSERT_RANGE(0, sec_x, LEVEL_MAX_X_SECTOR);
    ASSERT_RANGE(0, sec_y, LEVEL_MAX_Y_SECTOR);
    ASSERT_RANGE(0, record, LEVEL_MAX_RECORD); 
    ASSERT_RANGE(0, component, LEVEL_COMPONENT_ALL);
    
    // correction needed 
    // int y_corr = LVL_y_sec_corr(level, sec_y);
    int y_corr = sec_y;

    (*(level->components))[y_corr][sec_x][record][component] = val;
}

int LVL_get_component(
    level_t *level,
    int      sec_x,
    int      sec_y,
    int      record,
    int      component
) {
    ASSERT_RANGE(0, sec_x, LEVEL_MAX_X_SECTOR);
    ASSERT_RANGE(0, sec_y, LEVEL_MAX_Y_SECTOR);
    ASSERT_RANGE(0, record, LEVEL_MAX_RECORD); 
    ASSERT_RANGE(0, component, LEVEL_COMPONENT_ALL);

    // correction needed 
    int y_corr = sec_y;
    // int y_corr = LVL_y_sec_corr(level, sec_y);

    return (*(level->components))[y_corr][sec_x][record][component];
}

int LVL_n_entities(
    level_t *level,
    int      x,
    int      y
) {
    return LVL_get_component(level, x, y, LEVEL_METADATA_IDX, LEVEL_METADATA_SEC_N);
}

void LVL_free(
    level_t* level
) {
    level->components = NULL;
    free(level);
    level = NULL;
}
