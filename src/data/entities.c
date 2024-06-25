#include "library.h"

#include "../animation.h"
#include "../entity.h"
#include "../window.h"

entity_blueprint_t* entity_library[ENTITY_ALL] = {NULL};

entity_blueprint_t entity_blueprint_hero = {
    "OUR SKELETON",
    ENTITY_HERO, 
    {
        NOT_SET,
        ENTITY_HERO, 
        NOT_SET, NOT_SET,
        NOT_SET, NOT_SET,
        NOT_SET, NOT_SET,
        NOT_SET,
        0, 0,
        0, 0,
        RIGHT,
        IDLE,
        0, 
        0,
        SPRITE_SKELETON,
        ENTITY_HERO, 
        LAYER_SPRITE,
        FIRST_BUFFER
    },
    {
        // IDLE
        {
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, IDLE,  0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,    4,  0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,      4,  3, 15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0, 15, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     9, 10,  0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     9, 10,  0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     9, 10,  0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,   50,  0,  0,  0 }
            },
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, IDLE,  0, 0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,    4,  0, 0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,     24,  3,15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,15, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     9, 10, 0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     9, 10, 0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     9, 10, 0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,   20,  0, 0,  0 },
            },
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, IDLE,  0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,    4,  0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,      4, 33, 15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0, 15, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     9, 10,  0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     9, 10,  0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     9, 10,  0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,   20,  0,  0,  0 },
            },
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, IDLE,  0, 0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,    4,  0, 0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,     24, 33,15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,19, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     9, 10, 0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     9, 10, 0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     9, 10, 0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    5,  0, 0,  0 },
            }
        },
        // WALKING
        {
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, WALKING,  0,  0, 0  },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,       6,  0,  0, 0  },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,         4, 63, 15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,         0,  0, 15, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,        9, 10,  0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,        9, 10,  0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,        9, 10,  0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,       3,  0,  0,  0 }
            },
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, WALKING,  0, 0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,       6,  0, 0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,        34, 63,15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,         0,  0,15, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,       3,  0, 0,  0 }
            },
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, WALKING,  0, 0, 0  },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,       6,  0, 0, 0  },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,         4, 93,15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,         0,  0,15, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,       3,  0, 0,  0 }
            },
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, WALKING,  0, 0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,       6,  0, 0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,        34, 93,15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,         0,  0,15, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,       3,  0, 0,  0 }
            },
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, WALKING,  0, 0, 0  },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,       6,  0, 0, 0  },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,         4,123,15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,         0,  0,15, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,       3,  0, 0,  0 }
            },
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, WALKING,  0, 0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,       6,  0, 0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,        33,123,15, 19 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,         0,  0,15, 19 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,       5,  0, 0,  0 }
            }
        },
        // JUMPING
        {
             {
                 {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, JUMPING,  0, 0,  0 },
                 {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,       3,  0, 0,  0 },
                 {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,        25,154,15, 19 },
                 {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,         0,  0,15, 19 },
                 {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,       1,  0, 0,  0 }
             },
             {
                 {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, JUMPING,  0, 0,  0 },
                 {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,       3,  0, 0,  0 },
                 {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,         4,154,15, 19 },
                 {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,         0,  0,15, 19 },
                 {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,       3,  0, 0,  0 }
             },
             {
                 {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, JUMPING,  0, 0,  0 },
                 {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,       3,  0, 0,  0 },
                 {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,        24,154,15, 19 },
                 {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,         0,  0,15, 19 },
                 {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,        9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,       3,  0, 0,  0 }
             }
         },
         // FALLING_DOWN
         {
             {
                 {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR, FALLING_DOWN,  0, 0,  0 },
                 {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,            1,  0, 0,  0 },
                 {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,              4,215,15, 19 },
                 {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,              0,  0,15, 19 },
                 {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,             9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,             9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,             9, 10, 0, 10 },
                 {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,            0,  0, 0,  0 }
             }
         }
     }
};

entity_blueprint_t entity_tileset_a = {
    "tileset_a",
    ENTITY_TILESET_A,
    {
        NOT_SET,
        ENTITY_TILESET_A,
        NOT_SET, NOT_SET,
        NOT_SET, NOT_SET,
        NOT_SET, NOT_SET,
        NOT_SET,
        0, 0,
        0, 0,
        RIGHT,
        INHERIT,
        INHERIT,
        0,
        SPRITE_TILESET_A,
        ENTITY_TILESET_A, 
        LAYER_TILE,
        FIRST_BUFFER,
    },
    {
        // ROW 0
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 1
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 2
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 3
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 4
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // COL 5
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // COL 6
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 7
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 8
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 9
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        }
     }
};

entity_blueprint_t entity_tileset_b = {
    "tileset_b",
    ENTITY_TILESET_B,
    {
        NOT_SET,
        ENTITY_TILESET_B,
        NOT_SET, NOT_SET,
        NOT_SET, NOT_SET,
        NOT_SET, NOT_SET,
        NOT_SET,
        0, 0,
        0, 0,
        RIGHT,
        INHERIT,
        INHERIT,
        0,
        SPRITE_TILESET_A,
        ENTITY_TILESET_B, 
        LAYER_BACKTILE,
        FIRST_BUFFER,
    },
    {
        // ROW 0
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,0*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 1
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    1,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,1*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 2
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    2,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,2*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 3
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    3,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,3*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 4
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    4,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,4*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // COL 5
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    5,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,5*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // COL 6
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    6,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,6*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 7
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    7,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,7*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 8
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    8,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,8*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        },
        // ROW 9
        {
            // COL 0
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   0*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 1
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   1*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 2
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   2*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 3
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   3*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 4
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   4*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 5
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   5*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 6
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   6*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 7
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   7*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 8
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   8*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
            // COL 9
            {
                {ANIMATION_COMPONENT_ID,      FRAME_SHAPE_SCALAR,    9,   0,  0,  0 },
                {ANIMATION_COMPONENT_LEN,     FRAME_SHAPE_SCALAR,   10,   0,  0,  0 },
                {ANIMATION_COMPONENT_OUTLINE, FRAME_SHAPE_RECT,   9*32,9*32, 32, 32 },
                {ANIMATION_COMPONENT_HITBOX,  FRAME_SHAPE_RECT,      0,  0,  32, 32 },
                {ANIMATION_COMPONENT_GRIP,    FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_HANDLE,  FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_LIGHT,   FRAME_SHAPE_POINT,     0,   0,  0,  0 },
                {ANIMATION_COMPONENT_DELAY,   FRAME_SHAPE_SCALAR,    1,   0,  0,  0 }
            },
        }
     }
};
void LIB_read_entity_blueprint(
    entity_blueprint_t* blueprint
) {
    if (blueprint) {
        printf("ENTITY BLUEPRINT ID = %d read\n", blueprint->blueprint_id);
    }
    entity_library[blueprint->blueprint_id]      = blueprint;
};

void LIB_create_entity_library(
) {
    LIB_read_entity_blueprint(&entity_blueprint_hero);
    LIB_read_entity_blueprint(&entity_tileset_a);
    LIB_read_entity_blueprint(&entity_tileset_b);
}
