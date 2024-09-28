#include "library.h"

#include "../symbols.h"
#include "../data.h"

blueprint_t entity_blueprint_hero = {
            { 0                                  ,          ID, 0, 0,                0 },
            { 1                                  , LEVEL_WIDTH, 0, 0,              239 },
            { 2                                  ,         MAP, 0, 0,               40 },
            { 3                                  ,         MAP, 0, 0,              100 },
            { 4                                  ,         MAP, 0, 0,              500 },
            { 5                                  ,         MAP, 0, 0,             1000 },
            { 40                                 ,           0, 0, 0,               14 },
            { 40 + ENTITY_COMPONENT_ANIM_FRAME   ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_ANIM_TIMER   ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_ANIM_DELAY   ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_ANIM_LEN     ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_FRAME_X      ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_FRAME_Y      ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_FRAME_W      ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_FRAME_H      ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_HITBOX_X     ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_HITBOX_Y     ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_HITBOX_W     ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_HITBOX_H     ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_X_POS_DES    ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_Y_POS_DES    ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_X_VEL_DES    ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_Y_VEL_DES    ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_X_VEL        ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_Y_VEL        ,           0, 0, 0,                0 },
            { 40 + ENTITY_COMPONENT_TEXTURE      ,           0, 0, 0,  SPRITE_SKELETON },
            { 40 + ENTITY_COMPONENT_STATE        ,           0, 0, 0,             IDLE },
            { 40 + ENTITY_COMPONENT_SHEET        ,           0, 0, 0,  ENTITY_SKELETON }, 
            { 40 + ENTITY_COMPONENT_LAYER        ,           0, 0, 0,     LAYER_SPRITE },
            { 40 + ENTITY_COMPONENT_BUFFER       ,           0, 0, 0,                1 },
            { 40 + ENTITY_COMPONENT_COLLISIONABLE,           0, 0, 0, COLLISION_BEHAVIOUR_NORMAL },
            { 40 + ENTITY_COMPONENT_DIR          ,           0, 0, 0,                1 },
            { 40 + ENTITY_COMPONENT_PHASES       ,           0, 0, 0,   PHASE_FLAG_ALL },
            { 100, METADATA, 4, IDLE,         110  }, // len + which anim
            { 101, METADATA, 6, WALKING,      210  }, // len + which anim
            { 102, METADATA, 3, JUMPING,      310  }, // len + which anim
            { 103, METADATA, 1, FALLING_DOWN, 410  }, // len + which anim
              { 110, MAP   , 0, 0,     130  }, // map to frames
              { 111, MAP   , 0, 1,     140  },
              { 112, MAP   , 0, 2,     150  },
              { 113, MAP   , 0, 3,     160  },
                { 130,                                0,  0,  0,  0 },
                { 130 + ANIMATION_COMPONENT_OUTLINE,  2,  2, 33, 37 },
                { 130 + ANIMATION_COMPONENT_HITBOX,   0,  0, 33, 37 },
                { 130 + ANIMATION_COMPONENT_GRIP,     9, 10,  0, 10 },
                { 130 + ANIMATION_COMPONENT_HANDLE,   9, 10,  0, 10 },
                { 130 + ANIMATION_COMPONENT_DELAY,    0,  0,  0, 50 },
                { 140,                                0,  0,  0,  0 },
                { 140 + ANIMATION_COMPONENT_OUTLINE, 42,  2, 33, 37 },
                { 140 + ANIMATION_COMPONENT_HITBOX,   0,  0, 33, 37 },
                { 140 + ANIMATION_COMPONENT_GRIP,     9, 10,  0, 10 },
                { 140 + ANIMATION_COMPONENT_HANDLE,   9, 10,  0, 10 },
                { 140 + ANIMATION_COMPONENT_DELAY,    0,  0,  0, 20 },
                { 150,                                0,  0,  0,  0 },
                { 150 + ANIMATION_COMPONENT_OUTLINE,  2, 62, 33, 37 },
                { 150 + ANIMATION_COMPONENT_HITBOX,   0,  0, 33, 37 },
                { 150 + ANIMATION_COMPONENT_GRIP,     9, 10,  0, 10 },
                { 150 + ANIMATION_COMPONENT_HANDLE,   9, 10,  0, 10 },
                { 150 + ANIMATION_COMPONENT_DELAY,    0,  0,  0, 20 },
                { 160,                                0,  0,  0,  0 },
                { 160 + ANIMATION_COMPONENT_OUTLINE, 42, 62, 33, 37 },
                { 160 + ANIMATION_COMPONENT_HITBOX,   0,  0, 33, 37 },
                { 160 + ANIMATION_COMPONENT_GRIP,     9, 10,  0, 10 },
                { 160 + ANIMATION_COMPONENT_HANDLE,   9, 10,  0, 10 },
                { 160 + ANIMATION_COMPONENT_DELAY,    0,  0,  0,  5 },
              { 210, MAP   , 0, 0,     230  }, // map to frames
              { 211, MAP   , 0, 1,     240  },
              { 212, MAP   , 0, 2,     250  },
              { 213, MAP   , 0, 3,     260  },
              { 214, MAP   , 0, 4,     270  },
              { 215, MAP   , 0, 5,     280  },
                { 230,                                 0,  0,  0,  0 },
                { 230 + ANIMATION_COMPONENT_OUTLINE,   2,122,33, 37 },
                { 230 + ANIMATION_COMPONENT_HITBOX,    0,  0,33, 37 },
                { 230 + ANIMATION_COMPONENT_GRIP,      9, 10, 0, 10 },
                { 230 + ANIMATION_COMPONENT_HANDLE,    9, 10, 0, 10 },
                { 230 + ANIMATION_COMPONENT_DELAY,     0,  0, 0,  3 },
                { 240,                                 0,  0, 0,  0 },
                { 240 + ANIMATION_COMPONENT_OUTLINE,  42,122,33, 37 },
                { 240 + ANIMATION_COMPONENT_HITBOX,    0,  0,33, 37 },
                { 240 + ANIMATION_COMPONENT_GRIP,      9, 10, 0, 10 },
                { 240 + ANIMATION_COMPONENT_HANDLE,    9, 10, 0, 10 },
                { 240 + ANIMATION_COMPONENT_DELAY,     0,  0, 0,  3 },
                { 250,                                 0,  0, 0,  0 },
                { 250 + ANIMATION_COMPONENT_OUTLINE,   2,182,33, 37 },
                { 250 + ANIMATION_COMPONENT_HITBOX,    0,  0,33, 37 },
                { 250 + ANIMATION_COMPONENT_GRIP,      9, 10, 0, 10 },
                { 250 + ANIMATION_COMPONENT_HANDLE,    9, 10, 0, 10 },
                { 250 + ANIMATION_COMPONENT_DELAY,     0,  0, 0,  3 },
                { 260,                                 0,  0, 0,  0 },
                { 260 + ANIMATION_COMPONENT_OUTLINE,  42,182,33, 37 },
                { 260 + ANIMATION_COMPONENT_HITBOX,    0,  0,33, 37 },
                { 260 + ANIMATION_COMPONENT_GRIP,      9, 10, 0, 10 },
                { 260 + ANIMATION_COMPONENT_HANDLE,    9, 10, 0, 10 },
                { 260 + ANIMATION_COMPONENT_DELAY,     0,  0, 0,  3 },
                { 270,                                 0,  0, 0,  0 },
                { 270 + ANIMATION_COMPONENT_OUTLINE,   2,242,33, 37 },
                { 270 + ANIMATION_COMPONENT_HITBOX,    0,  0,33, 37 },
                { 270 + ANIMATION_COMPONENT_GRIP,      9, 10, 0, 10 },
                { 270 + ANIMATION_COMPONENT_HANDLE,    9, 10, 0, 10 },
                { 270 + ANIMATION_COMPONENT_DELAY,     0,  0, 0,  3 },
                { 280,                                 0,  0, 0,  0 },
                { 280 + ANIMATION_COMPONENT_OUTLINE,  42,242,33, 37 },
                { 280 + ANIMATION_COMPONENT_HITBOX,    0,  0,33, 37 },
                { 280 + ANIMATION_COMPONENT_GRIP,      9, 10, 0, 10 },
                { 280 + ANIMATION_COMPONENT_HANDLE,    9, 10, 0, 10 },
                { 280 + ANIMATION_COMPONENT_DELAY,     0,  0, 0,  5 },
              { 310, MAP   , 0, 0, 330  }, // map to frames
              { 311, MAP   , 0, 1, 340  },
              { 312, MAP   , 0, 2, 350  },
                { 330,                                0,  0, 0,  0 },
                { 330 + ANIMATION_COMPONENT_OUTLINE, 42,304,33, 37 },
                { 330 + ANIMATION_COMPONENT_HITBOX,   0,  0,33, 37 },
                { 330 + ANIMATION_COMPONENT_GRIP,     9, 10, 0, 10 },
                { 330 + ANIMATION_COMPONENT_HANDLE,   9, 10, 0, 10 },
                { 330 + ANIMATION_COMPONENT_DELAY,    0,  0, 0,  1 },
                { 340,                                0,  0, 0,  0 },
                { 340 + ANIMATION_COMPONENT_OUTLINE,  2,364,33, 37 },
                { 340 + ANIMATION_COMPONENT_HITBOX,   0,  0,33, 37 },
                { 340 + ANIMATION_COMPONENT_GRIP,     9, 10, 0, 10 },
                { 340 + ANIMATION_COMPONENT_HANDLE,   9, 10, 0, 10 },
                { 340 + ANIMATION_COMPONENT_DELAY,    0,  0, 0,  3 },
                { 350,                                0,  0, 0,  0 },
                { 350 + ANIMATION_COMPONENT_OUTLINE, 42,364,33, 37 },
                { 350 + ANIMATION_COMPONENT_HITBOX,   0,  0,33, 37 },
                { 350 + ANIMATION_COMPONENT_GRIP,     9, 10, 0, 10 },
                { 350 + ANIMATION_COMPONENT_HANDLE,   9, 10, 0, 10 },
                { 350 + ANIMATION_COMPONENT_DELAY,    0,  0, 0,  3 },
              { 410, MAP   , 0, 0, 430  }, // map to frames
                { 430,                               0,  0, 0,  0 },
                { 430 + ANIMATION_COMPONENT_OUTLINE, 2,426,33, 37 },
                { 430 + ANIMATION_COMPONENT_HITBOX,  0,  0,33, 37 },
                { 430 + ANIMATION_COMPONENT_GRIP,    9, 10, 0, 10 },
                { 430 + ANIMATION_COMPONENT_HANDLE,  9, 10, 0, 10 },
                { 430 + ANIMATION_COMPONENT_DELAY,   0,  0, 0,  0 },
            { 500, MAP, 0, IDLE,         510  }, 
            { 501, MAP, 0, WALKING,      610  }, 
            { 502, MAP, 0, JUMPING,      710  }, 
            { 503, MAP, 0, FALLING_DOWN, 810  }, 
              { 510, METADATA, 4, PHASE_INIT,      520  }, // n + which phase
              { 511, METADATA, 3, PHASE_PRE,       530  }, // n + which phase
              { 512, METADATA, 3, PHASE_UPDATE,    540  }, // n + which phase
              { 513, METADATA, 4, PHASE_CONTROL,   550  }, // n + which phase
              { 514, METADATA, 1, PHASE_COLLISION, 560  }, // n + which phase
              { 515, METADATA, 4, PHASE_RESOLVE,   570  }, // n + which phase
              { 516, METADATA, 1, PHASE_DRAW,      580  }, // n + which phase
                { 520, BEHAVIOUR, PHASE_INIT, 0, BEHAVIOUR_SET_DEFAULTS   },
                { 521, BEHAVIOUR, PHASE_INIT, 1, BEHAVIOUR_SET_FRAME      },
                { 522, BEHAVIOUR, PHASE_INIT, 2, BEHAVIOUR_SET_HITBOX     },
                { 523, BEHAVIOUR, PHASE_INIT, 3, BEHAVIOUR_BLOCK_INIT     },
                { 530, BEHAVIOUR, PHASE_PRE, 0, BEHAVIOUR_SET_CAMERA      },
                { 531, BEHAVIOUR, PHASE_PRE, 1, BEHAVIOUR_ADD_FRAME_TIMER },
                { 532, BEHAVIOUR, PHASE_PRE, 2, BEHAVIOUR_CATCH_POS       },
                { 540, BEHAVIOUR, PHASE_UPDATE, 0, BEHAVIOUR_ADD_GRAVITY        },
                { 541, BEHAVIOUR, PHASE_UPDATE, 1, BEHAVIOUR_HORIZONTAL_FRICION },
                { 542, BEHAVIOUR, PHASE_UPDATE, 2, BEHAVIOUR_SET_FRAME       },
                { 550, BEHAVIOUR, PHASE_CONTROL, 0, BEHAVIOUR_CONTROL_JUMP    },
                { 551, BEHAVIOUR, PHASE_CONTROL, 1, BEHAVIOUR_CONTROL_LEFT    },
                { 552, BEHAVIOUR, PHASE_CONTROL, 2, BEHAVIOUR_CONTROL_RIGHT   },
                { 553, BEHAVIOUR, PHASE_CONTROL, 3, BEHAVIOUR_UPDATE_VELOCITY },
                { 560, BEHAVIOUR, PHASE_COLLISION, 0, BEHAVIOUR_CHECK_COLLISION },
                { 570, BEHAVIOUR, PHASE_RESOLVE, 0, BEHAVIOUR_ADD_GRAVITY      },
                { 571, BEHAVIOUR, PHASE_RESOLVE, 1, BEHAVIOUR_UPDATE_POSITION  },
                { 572, BEHAVIOUR, PHASE_RESOLVE, 2, BEHAVIOUR_SET_FOCUS        },
                { 573, BEHAVIOUR, PHASE_RESOLVE, 3, BEHAVIOUR_ANIM_FRAME       },
                { 574, BEHAVIOUR, PHASE_RESOLVE, 4, BEHAVIOUR_UPDATE_SECTOR   },
                { 580, BEHAVIOUR, PHASE_DRAW, 0, BEHAVIOUR_DRAW_SPRITE   },
              { 611, METADATA, 3, PHASE_PRE,       620  }, // n + which phase
              { 612, METADATA, 3, PHASE_UPDATE,    630  }, // n + which phase
              { 613, METADATA, 4, PHASE_CONTROL,   640  }, // n + which phase
              { 614, METADATA, 1, PHASE_COLLISION, 650  }, // n + which phase
              { 615, METADATA, 4, PHASE_RESOLVE,   660  }, // n + which phase
              { 616, METADATA, 1, PHASE_DRAW,      670  }, // n + which phase
                { 620, BEHAVIOUR, PHASE_PRE, 0, BEHAVIOUR_SET_CAMERA      },
                { 621, BEHAVIOUR, PHASE_PRE, 1, BEHAVIOUR_ADD_FRAME_TIMER },
                { 622, BEHAVIOUR, PHASE_PRE, 2, BEHAVIOUR_CATCH_POS       },
                { 630, BEHAVIOUR, PHASE_UPDATE, 0, BEHAVIOUR_ADD_GRAVITY        },
                { 631, BEHAVIOUR, PHASE_UPDATE, 1, BEHAVIOUR_HORIZONTAL_FRICION },
                { 632, BEHAVIOUR, PHASE_UPDATE, 2, BEHAVIOUR_SET_FRAME },
                { 640, BEHAVIOUR, PHASE_CONTROL, 0, BEHAVIOUR_CONTROL_JUMP    },
                { 641, BEHAVIOUR, PHASE_CONTROL, 1, BEHAVIOUR_CONTROL_LEFT    },
                { 642, BEHAVIOUR, PHASE_CONTROL, 2, BEHAVIOUR_CONTROL_RIGHT   },
                { 643, BEHAVIOUR, PHASE_CONTROL, 3, BEHAVIOUR_UPDATE_VELOCITY },
                { 650, BEHAVIOUR, PHASE_COLLISION, 0, BEHAVIOUR_CHECK_COLLISION },
                { 660, BEHAVIOUR, PHASE_RESOLVE, 0, BEHAVIOUR_UPDATE_POSITION },
                { 661, BEHAVIOUR, PHASE_RESOLVE, 1, BEHAVIOUR_SET_FOCUS       },
                { 662, BEHAVIOUR, PHASE_RESOLVE, 2, BEHAVIOUR_ANIM_FRAME      },
                { 663, BEHAVIOUR, PHASE_RESOLVE, 3, BEHAVIOUR_UPDATE_SECTOR   },
                { 670, BEHAVIOUR, PHASE_DRAW, 0, BEHAVIOUR_DRAW_SPRITE   },
              { 711, METADATA, 3, PHASE_PRE,       720  }, // n + which phase
              { 712, METADATA, 3, PHASE_UPDATE,    730  }, // n + which phase
              { 713, METADATA, 4, PHASE_CONTROL,   740  }, // n + which phase
              { 714, METADATA, 2, PHASE_COLLISION, 750  }, // n + which phase
              { 715, METADATA, 3, PHASE_RESOLVE,   760  }, // n + which phase
              { 716, METADATA, 1, PHASE_DRAW,      770  }, // n + which phase
                { 720, BEHAVIOUR, PHASE_PRE, 0, BEHAVIOUR_SET_CAMERA      },
                { 721, BEHAVIOUR, PHASE_PRE, 1, BEHAVIOUR_ADD_FRAME_TIMER },
                { 722, BEHAVIOUR, PHASE_PRE, 2, BEHAVIOUR_CATCH_POS       },
                { 730, BEHAVIOUR, PHASE_UPDATE, 0, BEHAVIOUR_ADD_GRAVITY        },
                { 731, BEHAVIOUR, PHASE_UPDATE, 1, BEHAVIOUR_HORIZONTAL_FRICION },
                { 732, BEHAVIOUR, PHASE_UPDATE, 2, BEHAVIOUR_SET_FRAME },
                { 740, BEHAVIOUR, PHASE_CONTROL, 0, BEHAVIOUR_CONTROL_JUMP    },
                { 741, BEHAVIOUR, PHASE_CONTROL, 1, BEHAVIOUR_CONTROL_LEFT    },
                { 742, BEHAVIOUR, PHASE_CONTROL, 2, BEHAVIOUR_CONTROL_RIGHT   },
                { 743, BEHAVIOUR, PHASE_CONTROL, 3, BEHAVIOUR_UPDATE_VELOCITY },
                { 750, BEHAVIOUR, PHASE_COLLISION, 0, BEHAVIOUR_CHECK_COLLISION  },
                { 751, BEHAVIOUR, PHASE_COLLISION, 1, BEHAVIOUR_CHECK_IF_FALLING },
                { 760, BEHAVIOUR, PHASE_RESOLVE, 0, BEHAVIOUR_UPDATE_POSITION },
                { 761, BEHAVIOUR, PHASE_RESOLVE, 1, BEHAVIOUR_SET_FOCUS       },
                { 762, BEHAVIOUR, PHASE_RESOLVE, 2, BEHAVIOUR_ANIM_FRAME      },
                { 763, BEHAVIOUR, PHASE_RESOLVE, 3, BEHAVIOUR_UPDATE_SECTOR   },
                { 770, BEHAVIOUR, PHASE_DRAW, 0, BEHAVIOUR_DRAW_SPRITE   },
              { 811, METADATA, 3, PHASE_PRE,       820  }, // n + which phase
              { 812, METADATA, 3, PHASE_UPDATE,    830  }, // n + which phase
              { 813, METADATA, 0, PHASE_CONTROL,   840  }, // n + which phase
              { 814, METADATA, 1, PHASE_COLLISION, 850  }, // n + which phase
              { 815, METADATA, 4, PHASE_RESOLVE,   860  }, // n + which phase
              { 816, METADATA, 1, PHASE_DRAW,      870  }, // n + which phase
                { 820, BEHAVIOUR, PHASE_PRE, 0, BEHAVIOUR_SET_CAMERA      },
                { 821, BEHAVIOUR, PHASE_PRE, 1, BEHAVIOUR_ADD_FRAME_TIMER },
                { 822, BEHAVIOUR, PHASE_PRE, 2, BEHAVIOUR_CATCH_POS       },
                { 830, BEHAVIOUR, PHASE_UPDATE, 0, BEHAVIOUR_ADD_GRAVITY        },
                { 831, BEHAVIOUR, PHASE_UPDATE, 1, BEHAVIOUR_HORIZONTAL_FRICION },
                { 832, BEHAVIOUR, PHASE_UPDATE, 2, BEHAVIOUR_SET_FRAME },
                { 840, BEHAVIOUR, PHASE_CONTROL, 0, BEHAVIOUR_UPDATE_VELOCITY },// TODO: below add to update phase
                { 850, BEHAVIOUR, PHASE_COLLISION, 0, BEHAVIOUR_CHECK_COLLISION },
                { 860, BEHAVIOUR, PHASE_RESOLVE, 0, BEHAVIOUR_UPDATE_POSITION      },
                { 861, BEHAVIOUR, PHASE_RESOLVE, 1, BEHAVIOUR_CHECK_IF_STOP_FALLING},
                { 862, BEHAVIOUR, PHASE_RESOLVE, 2, BEHAVIOUR_SET_FOCUS            },
                { 863, BEHAVIOUR, PHASE_RESOLVE, 3, BEHAVIOUR_UPDATE_SECTOR        },
                { 870, BEHAVIOUR, PHASE_DRAW, 0, BEHAVIOUR_DRAW_SPRITE   },
            { 1000, MAP, 0, IDLE,         1010  }, 
            { 1001, MAP, 0, WALKING,      1020  }, 
            { 1002, MAP, 0, JUMPING,      1030  }, 
            { 1003, MAP, 0, FALLING_DOWN, 1040  }, 
                { 1010, BEHAVIOUR, IDLE, COLLISION_BODY_SOLID, COLLISION_BEHAVIOUR_NORMAL      },
                { 1020, BEHAVIOUR, WALKING, COLLISION_BODY_SOLID, COLLISION_BEHAVIOUR_NORMAL      },
                { 1030, BEHAVIOUR, JUMPING, COLLISION_BODY_SOLID, COLLISION_BEHAVIOUR_NORMAL      },
                { 1040, BEHAVIOUR, FALLING_DOWN, COLLISION_BODY_SOLID, COLLISION_BEHAVIOUR_NORMAL      }
    };

blueprint_t entity_blueprint_tile = {
        { 0, 12,          0, 0, 0         },
        { 1, LEVEL_WIDTH, 0, 0, 276-250+1 },
        { 2,         MAP, 0, 0, 40        },
        { 3,         MAP, 0, 0, -1        },
        { 4,         MAP, 0, 0, 500       },
        { 5,         MAP, 0, 0, -1        },
        { 40,                             0, 0, 0, 0,                                     },
        { 40 + ENTITY_COMPONENT_FRAME_X,  0, 0, 0, 0                                      },
        { 40 + ENTITY_COMPONENT_FRAME_Y,  0, 0, 0, 0                                      },
        { 40 + ENTITY_COMPONENT_FRAME_W,  0, 0, 0, 32                                     },
        { 40 + ENTITY_COMPONENT_FRAME_H,  0, 0, 0, 32                                     },
        { 40 + ENTITY_COMPONENT_DIR,      0, 0, 0, 0                                      },
        { 40 + ENTITY_COMPONENT_HITBOX_X, 0, 0, 0, 0                                      },
        { 40 + ENTITY_COMPONENT_HITBOX_Y, 0, 0, 0, 0                                      },
        { 40 + ENTITY_COMPONENT_HITBOX_W, 0, 0, 0, 32                                     },
        { 40 + ENTITY_COMPONENT_HITBOX_H, 0, 0, 0, 32                                     }, 
        { 40 + ENTITY_COMPONENT_TEXTURE,  0, 0, 0, SPRITE_TILE                            },
        { 40 + ENTITY_COMPONENT_SHEET,    0, 0, 0, ENTITY_TILE                            }, 
        { 40 + ENTITY_COMPONENT_LAYER,    0, 0, 0, LAYER_TILE                             },
        { 40 + ENTITY_COMPONENT_BUFFER,   0, 0, 0, 1                                      },
        { 40 + ENTITY_COMPONENT_PHASES,   0, 0, 0, PHASE_FLAG_INIT + PHASE_FLAG_DRAW      },
        { 500, MAP, 0, IDLE,         510  }, 
          { 510, METADATA, 2, PHASE_INIT,      520  }, // n + which phase
          { 516, METADATA, 1, PHASE_DRAW,      580  }, // n + which phase
            { 520, BEHAVIOUR, PHASE_INIT, 0, BEHAVIOUR_SET_DEFAULTS   },
            { 521, BEHAVIOUR, PHASE_INIT, 1, BEHAVIOUR_BLOCK_INIT     },
            { 580, BEHAVIOUR, PHASE_DRAW, 0, BEHAVIOUR_DRAW_SPRITE    }
    };

void BPT_create_entity_library(
) {
    int w;

    w = entity_blueprint_hero[1][4];
    BPT_serialize(entity_blueprint_hero, "./src/data/entites/hero", w);

    w = entity_blueprint_tile[1][4];
    BPT_serialize(entity_blueprint_tile, "./src/data/entites/tile", w);
}
