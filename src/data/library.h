#include "../animation.h"
#include "../behaviour.h"
#include "../controller.h"
#include "../entity_manager.h"
#include "../level.h"
#include "../macros.h"
#include "../shader.h"
#include "../texture.h"

#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_TEXTURE_NUMBER   4
#define MAX_BEH_TYPE        10 

enum ENITY_IDX {
    ENTITY_HERO,
    ENTITY_SKELETON,
    ENTITY_TILESET_A,
    ENTITY_TILESET_B,
    ENTITY_ALL
};

enum WOBBLE_IDX {
    WOBBLE_NO,
    WOBBLE_STABLE,
    WOBBLE_WALKING,
    WOBBLE_CIRCLE,
    WOBBLE_ALL
};

enum ANIMATION_IDX {
    ANIMATION_STANDING,
    ANIMATION_WALKING,
    ANIMATON_JUMPING,
    ANIMATON_FALLING_DOWN,
    ANIMATON_UNUSED_1,
    ANIMATON_UNUSED_2,
    ANIMATON_UNUSED_3,
    ANIMATON_UNUSED_4,
    ANIMATON_UNUSED_5,
    ANIMATON_UNUSED_6,
    ANIMATION_IDX_MAX
};

enum SPRITE_IDX {
    SPRITE_HERO,          
    SPRITE_TILESET_A,     
    SPRITE_SKELETON,      
    SPRITE_ALL           
};

enum LEVEL_IDX {
    LEVEL_NEW,
    LEVEL_ALL
};

enum SHADER_IDX {
    SHADER_TEXTURE,
    SHADER_ALL
};

enum COLLISION_BEHAVIOUR_IDX {
    COLLICION_BEHAVIOUR_NONE,
    COLLISION_BEHAVIOUR_NORMAL,
    COLLISION_BEHAVIOUR_ALL
};

enum BEHAVIOUR_IDX {
    BEHAVIOUR_NONE,
    BEHAVIOUR_INIT,
    BEHAVIOUR_ADD_TO_SECTOR,
    BEHAVIOUR_SET_DEFAULTS,
    BEHAVIOUR_SET_ON_LEVEL,
    BEHAVIOUR_DRAW_SPRITE,
    BEHAVIOUR_SET_CAMERA,
    BEHAVIOUR_EMIT_FROM_LEVEL,
    BEHAVIOUR_NO_EMIT_FROM_LEVEL,
    BEHAVIOUR_ADD_GRAVITY,
    BEHAVIOUR_UPDATE_VELOCITY,
    BEHAVIOUR_UPDATE_POSITION,
    BEHAVIOUR_ORIENT_SEGMENTS,
    BEHAVIOUR_SET_FOCUS,
    BEHAVIOUR_CHECK_COLLISION,
    BEHAVIOUR_IS_COLLIDABLE,
    BEHAVIOUR_CHECK_IF_FALLING,
    BEHAVIOUR_CHECK_IF_STOP_FALLING,
    BEHAVIOUR_CONTROL_JUMP,
    BEHAVIOUR_CONTROL_LEFT,
    BEHAVIOUR_CONTROL_RIGHT,
    BEHAVIOUR_HORIZONTAL_AIR_FRICION,
    BEHAVIOUR_HORIZONTAL_FRICION,
    BEHAVIOUR_DEBUG,
    BEHAVIOUR_ADD_FRAME_TIMER,
    BEHAVIOUR_ANIM_FRAME,
    BEHAVIOUR_CONTINUE_JUMP,
    BEHAVIOUR_CATCH_POS,
    BEHAVIOUR_ALL
};

enum PHASE_IDX {
    PHASE_INIT      = 0,
    PHASE_PRE       = 1,
    PHASE_CONTROL   = 2,
    PHASE_UPDATE    = 3,
    PHASE_COLLISION = 4,
    PHASE_RESOLVE   = 5,
    PHASE_DRAW      = 6,
    PHASE_ALL
};

typedef void (*behaviour_t)(int e, context_t*);
typedef void (*collision_behaviour_t)(int e, context_t* c, collision_t col);

typedef int collision_matrix[ENTITY_ALL][MAX_STATE][ENTITY_ALL][MAX_STATE];
typedef int matrix[PHASE_ALL][ENTITY_ALL][MAX_BEH_TYPE][MAX_BEHAVIOURS];

typedef struct entity_blueprint {
    char        *name;
    int          blueprint_id;
    int          defaults[ENTITY_COMPONENT_ALL];
    animation_t  animation;
} entity_blueprint_t;

typedef struct texture_blueprint {
    int         id;
    const char *filepath;
} texture_blueprint_t;

typedef struct level_blueprint {
    int               id;
    int               x_focus;
    int               y_focus;
    int               x_sectors;
    int               y_sectors;
    level_components  entities;
} level_blueprint_t;

typedef struct shader_program_blueprint {
    int   id;
    const char *vertex_shader_path;
    const char *fragment_shader_path;
    const char *geomentry_shader_path;
} shader_program_blueprint_t;

typedef struct behaviour_blueprint {
    char       *desc;
    int         id;
    behaviour_t behaviour;
} behaviour_blueprint_t;

typedef struct collision_behaviour_blueprint {
    char                  *desc;
    int                    id;
    collision_behaviour_t  behaviour;
} collision_behaviour_blueprint_t;

collision_behaviour_blueprint_t *collision_behaviour_library[COLLISION_BEHAVIOUR_ALL];
// behaviour_blueprint_t           behaviour_library[BEHAVIOUR_ALL];
behaviour_blueprint_t           behaviour_library[BEHAVIOUR_ALL];
entity_blueprint_t              *entity_library[ENTITY_ALL];
level_blueprint_t               *levels_library[LEVEL_ALL];
texture_t                       *sprites_library[SPRITE_ALL];
shader_program_t                *shader_library[SHADER_ALL];

matrix                           behavior_matrix;
collision_matrix                 behaviour_collision_matrix;

// void LIB_create_wobble_library();
void LIB_create_entity_library();
void LIB_create_levels_library();
void LIB_create_lightsources_library();
void LIB_create_shaders_library();
void LIB_create_sprites_library();
void LIB_create_behaviour_library();
void LIB_create_collision_behaviour_library();
void LIB_create_behaviour_matrix();
void LIB_create_collision_behaviour_matrix();

void LIB_init();
void LIB_free_all();

#endif
