#ifndef ENTITY_H
#define ENTITY_H

#define SUBPIX   8
#define NOT_SET -1
#define INHERIT -2

enum state       { IDLE, WALKING, JUMPING, FALLING_DOWN, PREJUMP, NOTHING, STATE_7, STATE_8, STATE_9, MAX_STATE };
enum direction   { RIGHT, LEFT, UP, DOWN, NONE };
enum layers      { LAYER_BACKTILE, LAYER_TILE, LAYER_SPRITE, SCALED_IMAGE, LAYER_ALL };

#endif
