/* Handling entites animation data (frames coord, delay, hitboxes etc).
 * Control of the animations are `system`'s job (see: src/system.c)
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#define ANIMATION_MAX_FRAMES           10
#define ANIMATION_MAX                  10
#define ANIMATION_MAX_COMPONENT_VALUE  6

// record data shape
#define FRAME_SHAPE_RECT        0
#define FRAME_SHAPE_POINT       1
#define FRAME_SHAPE_SCALAR      2

// record columns 
#define FRAME_TYPE        0
#define FRAME_SHAPE       1

// record rect columns
#define FRAME_RECT_X      2
#define FRAME_RECT_Y      3
#define FRAME_RECT_W      4
#define FRAME_RECT_H      5

// record frame columns
#define FRAME_POINT_R_X   2
#define FRAME_POINT_R_Y   3
#define FRAME_POINT_L_X   4
#define FRAME_POINT_L_Y   5

#define FRAME_SCALAR      2
#define FRAME_VALUE       2
#define DELAY_VALUE       2

enum ANIMATION_COMPONENT {
    ANIMATION_COMPONENT_ID      = 0,
    ANIMATION_COMPONENT_LEN     = 1,
    ANIMATION_COMPONENT_OUTLINE = 2,
    ANIMATION_COMPONENT_HITBOX  = 3,
    ANIMATION_COMPONENT_GRIP,
    ANIMATION_COMPONENT_HANDLE,
    ANIMATION_COMPONENT_LIGHT,
    ANIMATION_COMPONENT_DELAY,
    ANIMATION_COMPONENT_ALL
};

typedef int animation_t[ANIMATION_MAX][ANIMATION_MAX_FRAMES][ANIMATION_COMPONENT_ALL][ANIMATION_MAX_COMPONENT_VALUE];

int ANIM_get_component_value(
    animation_t *animation,
    int          anim,
    int          frame,
    int          component,
    int          value
);

#endif
