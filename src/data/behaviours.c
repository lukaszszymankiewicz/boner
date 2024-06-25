#include <stdio.h>

#include "library.h"

#include "../system.h"


#define FOR_ALL_COLLIDER_STATES(m, ent, st, col, beh) for (int i=0; i<MAX_STATE; i++) { m[ent][st][col][i] = beh; }
#define FOR_ALL_STATES(m, a, b, c, d) for (int i=0; i<MAX_STATE; i++) { m[a][b][i][c] = d; }

collision_matrix behaviour_collision_matrix  = { };
matrix           behavior_matrix             = { };

behaviour_blueprint_t behaviour_library[BEHAVIOUR_ALL] = {
    {"empty"                          , BEHAVIOUR_NONE                   , SYSTEM_init_entity             },
    {"init entity"                    , BEHAVIOUR_INIT                   , SYSTEM_init_entity             },
    {"add entity to sector"           , BEHAVIOUR_ADD_TO_SECTOR          , SYSTEM_add_entity_to_sector    },
    {"set default components values"  , BEHAVIOUR_SET_DEFAULTS           , SYSTEM_set_defaults            },
    {"set entity on using level data" , BEHAVIOUR_SET_ON_LEVEL           , SYSTEM_set_on_level            },
    {"draw sprite"                    , BEHAVIOUR_DRAW_SPRITE            , SYSTEM_put_to_scene            },
    {"set camera according to entity" , BEHAVIOUR_SET_CAMERA             , SYSTEM_set_camera,             },
    {"delete entity from level data"  , BEHAVIOUR_EMIT_FROM_LEVEL        , SYSTEM_emit_from_level         },
    {"perserve entity on level data"  , BEHAVIOUR_NO_EMIT_FROM_LEVEL     , SYSTEM_no_emit_from_level      },
    {"add gravity to entity velocity" , BEHAVIOUR_ADD_GRAVITY            , SYSTEM_add_gravity             },
    {"set desired velocity to actual" , BEHAVIOUR_UPDATE_VELOCITY        , SYSTEM_add_velocity            },
    {"update position due velocty"    , BEHAVIOUR_UPDATE_POSITION        , SYSTEM_update_position         },
    {"reorient segments if needed"    , BEHAVIOUR_ORIENT_SEGMENTS        , SYSTEM_orient_segments         },
    {"set main segment to put focus"  , BEHAVIOUR_SET_FOCUS              , SYSTEM_set_focus               },
    {"check collision"                , BEHAVIOUR_CHECK_COLLISION        , SYSTEM_check_collision         },
    {"dummy"                          , BEHAVIOUR_IS_COLLIDABLE          , SYSTEM_is_collidable           },
    {"check if falling"               , BEHAVIOUR_CHECK_IF_FALLING       , SYSTEM_check_if_falling        },
    {"check if stop falling"          , BEHAVIOUR_CHECK_IF_STOP_FALLING  , SYSTEM_check_stop_falling      },
    {"jump da fuck up"                , BEHAVIOUR_CONTROL_JUMP           , SYSTEM_jump                    },
    {"check if moving left"           , BEHAVIOUR_CONTROL_LEFT           , SYSTEM_left                    },
    {"check if moving right"          , BEHAVIOUR_CONTROL_RIGHT          , SYSTEM_right                   },
    {"apply horizontal air friction"  , BEHAVIOUR_HORIZONTAL_AIR_FRICION , SYSTEM_horizontal_air_friction },
    {"apply horizontal friction"      , BEHAVIOUR_HORIZONTAL_FRICION     , SYSTEM_horizontal_friction     },
    {"debug entity"                   , BEHAVIOUR_DEBUG                  , SYSTEM_debug_entity            },
    {"add frame timer"                , BEHAVIOUR_ADD_FRAME_TIMER        , SYSTEM_add_frame_timer         },
    {"animate aniamtion"              , BEHAVIOUR_ANIM_FRAME             , SYSTEM_anim_frame              },
    {"cum ulate jmp powuh"            , BEHAVIOUR_CONTINUE_JUMP          , SYSTEM_continue_jump           },
    {"assume that pos will change"    , BEHAVIOUR_CATCH_POS              , SYSTEM_catch_pos_change        }
};

collision_behaviour_blueprint_t collision_normal = {
    "collide normally - collidor is solid and stays solid",
    COLLISION_BEHAVIOUR_NORMAL,
    (collision_behaviour_t)SYSTEM_normal_collision
};

void LIB_read_collision_behaviour_blueprint(
    collision_behaviour_blueprint_t *blueprint
) {
    printf("COLLISION BEHAVIOUR BLUEPRINT ID = %d read\n", blueprint->id);
    collision_behaviour_library[blueprint->id] = blueprint;
};

void LIB_create_collision_behaviour_library(
) {
    LIB_read_collision_behaviour_blueprint(&collision_normal);
}

void LIB_create_behaviour_matrix(
) {
    // hero 
    behavior_matrix[PHASE_INIT  ][ENTITY_HERO     ][IDLE][0] = 5;
    behavior_matrix[PHASE_INIT  ][ENTITY_HERO     ][IDLE][1] = BEHAVIOUR_INIT;
    behavior_matrix[PHASE_INIT  ][ENTITY_HERO     ][IDLE][2] = BEHAVIOUR_SET_DEFAULTS;
    behavior_matrix[PHASE_INIT  ][ENTITY_HERO     ][IDLE][3] = BEHAVIOUR_ADD_TO_SECTOR;
    behavior_matrix[PHASE_INIT  ][ENTITY_HERO     ][IDLE][4] = BEHAVIOUR_SET_ON_LEVEL;
    behavior_matrix[PHASE_INIT  ][ENTITY_HERO     ][IDLE][5] = BEHAVIOUR_EMIT_FROM_LEVEL;

    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][IDLE][0] = 3;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][IDLE][1] = BEHAVIOUR_SET_CAMERA;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][IDLE][2] = BEHAVIOUR_ADD_FRAME_TIMER;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][IDLE][3] = BEHAVIOUR_CATCH_POS;

    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][IDLE][0] = 2;
    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][IDLE][1] = BEHAVIOUR_ADD_GRAVITY;
    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][IDLE][2] = BEHAVIOUR_HORIZONTAL_FRICION;

    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][IDLE][0] = 4;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][IDLE][1] = BEHAVIOUR_CONTROL_JUMP;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][IDLE][2] = BEHAVIOUR_CONTROL_LEFT;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][IDLE][3] = BEHAVIOUR_CONTROL_RIGHT;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][IDLE][4] = BEHAVIOUR_UPDATE_VELOCITY;

    behavior_matrix[PHASE_COLLISION][ENTITY_HERO  ][IDLE][0] = 1;
    behavior_matrix[PHASE_COLLISION][ENTITY_HERO  ][IDLE][1] = BEHAVIOUR_CHECK_COLLISION;

    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][IDLE][0] = 4;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][IDLE][1] = BEHAVIOUR_UPDATE_POSITION;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][IDLE][2] = BEHAVIOUR_ORIENT_SEGMENTS;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][IDLE][3] = BEHAVIOUR_SET_FOCUS;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][IDLE][4] = BEHAVIOUR_ANIM_FRAME;

    behavior_matrix[PHASE_DRAW  ][ENTITY_HERO     ][IDLE][0] = 1;
    behavior_matrix[PHASE_DRAW  ][ENTITY_HERO     ][IDLE][1] = BEHAVIOUR_DRAW_SPRITE;

    // WALKING
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][WALKING][0] = 3;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][WALKING][1] = BEHAVIOUR_SET_CAMERA;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][WALKING][2] = BEHAVIOUR_ADD_FRAME_TIMER;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][WALKING][3] = BEHAVIOUR_CATCH_POS;

    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][WALKING][0] = 2;
    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][WALKING][1] = BEHAVIOUR_ADD_GRAVITY;
    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][WALKING][2] = BEHAVIOUR_HORIZONTAL_FRICION;

    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][WALKING][0] = 4;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][WALKING][1] = BEHAVIOUR_CONTROL_JUMP;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][WALKING][2] = BEHAVIOUR_CONTROL_LEFT;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][WALKING][3] = BEHAVIOUR_CONTROL_RIGHT;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][WALKING][4] = BEHAVIOUR_UPDATE_VELOCITY;

    behavior_matrix[PHASE_COLLISION][ENTITY_HERO  ][WALKING][0] = 1;
    behavior_matrix[PHASE_COLLISION][ENTITY_HERO  ][WALKING][1] = BEHAVIOUR_CHECK_COLLISION;

    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][WALKING][0] = 4;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][WALKING][1] = BEHAVIOUR_UPDATE_POSITION;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][WALKING][2] = BEHAVIOUR_ORIENT_SEGMENTS;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][WALKING][3] = BEHAVIOUR_SET_FOCUS;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][WALKING][4] = BEHAVIOUR_ANIM_FRAME;

    behavior_matrix[PHASE_DRAW  ][ENTITY_HERO     ][WALKING][0] = 1;
    behavior_matrix[PHASE_DRAW  ][ENTITY_HERO     ][WALKING][1] = BEHAVIOUR_DRAW_SPRITE;
    // JUMPING
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][JUMPING][0] = 3;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][JUMPING][1] = BEHAVIOUR_SET_CAMERA;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][JUMPING][2] = BEHAVIOUR_ADD_FRAME_TIMER;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][JUMPING][3] = BEHAVIOUR_CATCH_POS;

    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][JUMPING][0] = 2;
    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][JUMPING][1] = BEHAVIOUR_ADD_GRAVITY;
    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][JUMPING][2] = BEHAVIOUR_HORIZONTAL_AIR_FRICION;

    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][JUMPING][0] = 4;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][JUMPING][1] = BEHAVIOUR_CONTROL_JUMP;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][JUMPING][2] = BEHAVIOUR_CONTROL_LEFT;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][JUMPING][3] = BEHAVIOUR_CONTROL_RIGHT;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][JUMPING][4] = BEHAVIOUR_UPDATE_VELOCITY;

    behavior_matrix[PHASE_COLLISION][ENTITY_HERO  ][JUMPING][0] = 2;
    behavior_matrix[PHASE_COLLISION][ENTITY_HERO  ][JUMPING][1] = BEHAVIOUR_CHECK_COLLISION;
    behavior_matrix[PHASE_COLLISION][ENTITY_HERO  ][JUMPING][2] = BEHAVIOUR_CHECK_IF_FALLING;

    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][JUMPING][0] = 3;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][JUMPING][1] = BEHAVIOUR_UPDATE_POSITION;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][JUMPING][2] = BEHAVIOUR_ORIENT_SEGMENTS;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][JUMPING][3] = BEHAVIOUR_SET_FOCUS;

    behavior_matrix[PHASE_DRAW  ][ENTITY_HERO     ][JUMPING][0] = 1;
    behavior_matrix[PHASE_DRAW  ][ENTITY_HERO     ][JUMPING][1] = BEHAVIOUR_DRAW_SPRITE;

    // FALLING_DOWN
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][FALLING_DOWN][0] = 3;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][FALLING_DOWN][1] = BEHAVIOUR_SET_CAMERA;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][FALLING_DOWN][2] = BEHAVIOUR_ADD_FRAME_TIMER;
    behavior_matrix[PHASE_PRE   ][ENTITY_HERO     ][FALLING_DOWN][3] = BEHAVIOUR_CATCH_POS;

    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][FALLING_DOWN][0] = 2;
    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][FALLING_DOWN][1] = BEHAVIOUR_ADD_GRAVITY;
    behavior_matrix[PHASE_UPDATE][ENTITY_HERO     ][FALLING_DOWN][2] = BEHAVIOUR_HORIZONTAL_AIR_FRICION;

    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][FALLING_DOWN][0] = 1;
    behavior_matrix[PHASE_CONTROL][ENTITY_HERO    ][FALLING_DOWN][1] = BEHAVIOUR_UPDATE_VELOCITY;

    behavior_matrix[PHASE_COLLISION][ENTITY_HERO  ][FALLING_DOWN][0] = 1;
    behavior_matrix[PHASE_COLLISION][ENTITY_HERO  ][FALLING_DOWN][1] = BEHAVIOUR_CHECK_COLLISION;

    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][FALLING_DOWN][0] = 4;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][FALLING_DOWN][1] = BEHAVIOUR_UPDATE_POSITION;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][FALLING_DOWN][2] = BEHAVIOUR_CHECK_IF_STOP_FALLING;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][FALLING_DOWN][3] = BEHAVIOUR_ORIENT_SEGMENTS;
    behavior_matrix[PHASE_RESOLVE][ENTITY_HERO    ][FALLING_DOWN][4] = BEHAVIOUR_SET_FOCUS;

    behavior_matrix[PHASE_DRAW  ][ENTITY_HERO     ][FALLING_DOWN][0] = 1;
    behavior_matrix[PHASE_DRAW  ][ENTITY_HERO     ][FALLING_DOWN][1] = BEHAVIOUR_DRAW_SPRITE;

    // colliding tileset 
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_A][IDLE][0] = 5;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_A][IDLE][1] = BEHAVIOUR_INIT;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_A][IDLE][2] = BEHAVIOUR_SET_DEFAULTS;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_A][IDLE][3] = BEHAVIOUR_ADD_TO_SECTOR;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_A][IDLE][4] = BEHAVIOUR_SET_ON_LEVEL;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_A][IDLE][5] = BEHAVIOUR_NO_EMIT_FROM_LEVEL;

    FOR_ALL_STATES(behavior_matrix, PHASE_COLLISION, ENTITY_TILESET_A, 0, 1);
    FOR_ALL_STATES(behavior_matrix, PHASE_COLLISION, ENTITY_TILESET_A, 1, BEHAVIOUR_IS_COLLIDABLE);

    FOR_ALL_STATES(behavior_matrix, PHASE_DRAW, ENTITY_TILESET_A, 0, 1);
    FOR_ALL_STATES(behavior_matrix, PHASE_DRAW, ENTITY_TILESET_A, 1, BEHAVIOUR_DRAW_SPRITE);

    // nocolliding tileset 
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_B][IDLE][0] = 5;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_B][IDLE][1] = BEHAVIOUR_INIT;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_B][IDLE][2] = BEHAVIOUR_SET_DEFAULTS;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_B][IDLE][3] = BEHAVIOUR_ADD_TO_SECTOR;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_B][IDLE][4] = BEHAVIOUR_SET_ON_LEVEL;
    behavior_matrix[PHASE_INIT  ][ENTITY_TILESET_B][IDLE][5] = BEHAVIOUR_NO_EMIT_FROM_LEVEL;

    FOR_ALL_STATES(behavior_matrix, PHASE_DRAW, ENTITY_TILESET_B, 0, 1);
    FOR_ALL_STATES(behavior_matrix, PHASE_DRAW, ENTITY_TILESET_B, 1, BEHAVIOUR_DRAW_SPRITE);
}

void LIB_create_collision_behaviour_matrix(
) {
    FOR_ALL_COLLIDER_STATES(behaviour_collision_matrix, ENTITY_HERO, IDLE, ENTITY_TILESET_A, COLLISION_BEHAVIOUR_NORMAL);
    FOR_ALL_COLLIDER_STATES(behaviour_collision_matrix, ENTITY_HERO, WALKING, ENTITY_TILESET_A, COLLISION_BEHAVIOUR_NORMAL);
    FOR_ALL_COLLIDER_STATES(behaviour_collision_matrix, ENTITY_HERO, FALLING_DOWN, ENTITY_TILESET_A, COLLISION_BEHAVIOUR_NORMAL);
}

