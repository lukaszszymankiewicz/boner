#include <stdint.h>

#ifndef SYMBOLS_H
#define SYMBOLS_H

#define ANIMATION_DELAY_VALUE   3
#define DEFAULTS_BEGIN_IDX      2
#define ANIMATION_BEGIN_IDX     3
#define BEHAVIOUR_BEGIN_IDX     4
#define COLLISION_BEGIN_IDX     5
#define SUBPIX         8
#define NOT_SET       -1

enum BEHAVIOUR_IDX {
    BEHAVIOUR_DRAW_SPRITE,
    BEHAVIOUR_SET_CAMERA,
    BEHAVIOUR_ADD_GRAVITY,
    BEHAVIOUR_UPDATE_VELOCITY,
    BEHAVIOUR_UPDATE_POSITION,
    BEHAVIOUR_SET_FOCUS,
    BEHAVIOUR_CHECK_COLLISION,
    BEHAVIOUR_CHECK_IF_FALLING,
    BEHAVIOUR_CHECK_IF_STOP_FALLING,
    BEHAVIOUR_CONTROL_JUMP,
    BEHAVIOUR_CONTROL_LEFT,
    BEHAVIOUR_CONTROL_RIGHT,
    BEHAVIOUR_HORIZONTAL_AIR_FRICION,
    BEHAVIOUR_HORIZONTAL_FRICION,
    BEHAVIOUR_ADD_FRAME_TIMER,
    BEHAVIOUR_ANIM_FRAME,
    BEHAVIOUR_CONTINUE_JUMP,
    BEHAVIOUR_CATCH_POS,
    BEHAVIOUR_SET_HITBOX,
    BEHAVIOUR_SET_FRAME,
    BEHAVIOUR_SET_DEFAULTS,
    BEHAVIOUR_BLOCK_INIT,
    BEHAVIOUR_UPDATE_SECTOR,
    BEHVIOUR_CATCH_STATE,
    BEHVIOUR_UPDATE_STATE,
    BEHAVIOUR_ALL
};

enum PHASE_IDX {
    PHASE_PRE       = 0,
    PHASE_INIT      = 1,
    PHASE_UPDATE    = 2,
    PHASE_CONTROL   = 3,
    PHASE_COLLISION = 4,
    PHASE_RESOLVE   = 5,
    PHASE_DRAW      = 6,
    PHASE_ALL
};

enum PHASE_FLAG_IDX {
    PHASE_FLAG_INIT      = 1 << PHASE_INIT,
    PHASE_FLAG_PRE       = 1 << PHASE_PRE,
    PHASE_FLAG_UPDATE    = 1 << PHASE_UPDATE,
    PHASE_FLAG_CONTROL   = 1 << PHASE_CONTROL,
    PHASE_FLAG_COLLISION = 1 << PHASE_COLLISION,
    PHASE_FLAG_RESOLVE   = 1 << PHASE_RESOLVE,
    PHASE_FLAG_DRAW      = 1 << PHASE_DRAW,
    PHASE_FLAG_ALL       = PHASE_FLAG_INIT + PHASE_FLAG_PRE + PHASE_FLAG_CONTROL + PHASE_FLAG_UPDATE + PHASE_FLAG_COLLISION + PHASE_FLAG_RESOLVE + PHASE_FLAG_DRAW
};

enum state       { IDLE, WALKING, JUMPING, FALLING_DOWN, PREJUMP, NOTHING, STATE_7, STATE_8, STATE_9, MAX_STATE };
enum direction   { RIGHT, LEFT, UP, DOWN, NONE };
enum layers      { LAYER_BACKTILE, LAYER_TILE, LAYER_SPRITE, SCALED_IMAGE, LAYER_ALL };

enum ENTITY_COMPONENT {
    ENTITY_COMPONENT_EMPTY          = 1,
    ENTITY_COMPONENT_BPT            = 2,
    ENTITY_COMPONENT_PHASES         = 3,
    ENTITY_COMPONENT_X_POS          = 4,
    ENTITY_COMPONENT_Y_POS          = 5,
    ENTITY_COMPONENT_X_POS_DES      = 6,
    ENTITY_COMPONENT_Y_POS_DES      = 7,
    ENTITY_COMPONENT_X_VEL          = 8,
    ENTITY_COMPONENT_Y_VEL          = 9,
    ENTITY_COMPONENT_X_VEL_DES      = 10,
    ENTITY_COMPONENT_Y_VEL_DES      = 11,
    ENTITY_COMPONENT_DIR            = 12,
    ENTITY_COMPONENT_STATE          = 13,
    ENTITY_COMPONENT_STATE_DES      = 14,
    ENTITY_COMPONENT_ANIM_FRAME     = 15,
    ENTITY_COMPONENT_ANIM_TIMER     = 16,
    ENTITY_COMPONENT_FRAME_X        = 17,
    ENTITY_COMPONENT_FRAME_Y        = 18,
    ENTITY_COMPONENT_FRAME_W        = 19,
    ENTITY_COMPONENT_FRAME_H        = 20,
    ENTITY_COMPONENT_ANIM_DELAY     = 21,
    ENTITY_COMPONENT_ANIM_LEN       = 22,
    ENTITY_COMPONENT_TEXTURE        = 23,
    ENTITY_COMPONENT_SHEET          = 24,
    ENTITY_COMPONENT_LAYER          = 25,
    ENTITY_COMPONENT_BUFFER         = 26,
    ENTITY_COMPONENT_COLLISIONABLE  = 27,
    ENTITY_COMPONENT_HITBOX_X       = 28,
    ENTITY_COMPONENT_HITBOX_Y       = 29,
    ENTITY_COMPONENT_HITBOX_W       = 30,
    ENTITY_COMPONENT_HITBOX_H       = 31,
    ENTITY_COMPONENT_JUMP_H         = 32,
    ENTITY_COMPONENT_JUMP_HALF_T    = 33,
    ENTITY_COMPONENT_PREJUMP_LEN    = 34,
    ENTITY_COMPONENT_WEIGHT         = 35,
    ENTITY_COMPONENT_MOVE_POWUH     = 36,
    ENTITY_COMPONENT_X_FRICTION     = 37,
    ENTITY_COMPONENT_AIR_X_FRICTION = 38,
    ENTITY_COMPONENT_MAX_X_VEL      = 39,
    ENTITY_COMPONENT_MAX_Y_VEL      = 40,
    AVAILABLE_COMPONENTS            = 41
};

enum ANIMATION_COMPONENT {
    ANIMATION_COMPONENT_OUTLINE  = 1,
    ANIMATION_COMPONENT_HITBOX   = 2,
    ANIMATION_COMPONENT_GRIP     = 3,
    ANIMATION_COMPONENT_HANDLE   = 4,
    ANIMATION_COMPONENT_DELAY    = 5,
    ANIMATION_COMPONENT_ALL      = 6
};

enum ANIMATION_RECORD {
    ANIMATION_RECT_X,
    ANIMATION_RECT_Y,
    ANIMATION_RECT_W,
    ANIMATION_RECT_H
};

enum COLLISION_BEHAVIOUR_IDX {
    COLLISION_BEHAVIOUR_NORMAL,
    COLLISION_BEHAVIOUR_ALL
};

enum COLLISION_BODY_TYPE {
    COLLISION_BODY_SOLID,
    COLLISION_BODY_ALL
};

const static int NEGATIVE       = -1;
const static int POSITIVE       =  1;
const static int RIGHT_DIR_COEF = POSITIVE;
const static int LEFT_DIR_COEF  = NEGATIVE;
const static int UP_DIR_COEF    = POSITIVE;
const static int DOWN_DIR_COEF  = NEGATIVE;
const static int SECTOR_WIDTH   = 160;
const static int SECTOR_HEIGHT  = 120;

#endif
