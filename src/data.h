#include "resources.h"

#ifndef DATA_H
#define DATA_H

enum DATA_READ {
    SPRITE_SKELETON = 0,
    SPRITE_TILE     = 1,    
    ENTITY_SKELETON = 2,
    ENTITY_TILE     = 3,    
    LEVEL_NEW       = 4      
};

data_t datas[MAX_RESOURCES];

#endif
