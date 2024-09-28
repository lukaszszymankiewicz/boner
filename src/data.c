#include "resources.h"

#include "data.h"

data_t datas[] = {
    { SPRITE_SKELETON, DATA_TYPE_TEXTURE, -1, "./src/data/sprites/skeleton.png"  },
    { SPRITE_TILE,     DATA_TYPE_TEXTURE, -1, "./src/data/sprites/tileset_a.png" },
    { ENTITY_SKELETON, DATA_TYPE_TABLE,  239, "./src/data/entites/hero"          },
    { ENTITY_TILE,     DATA_TYPE_TABLE,   27, "./src/data/entites/tile"          },
    { LEVEL_NEW,       DATA_TYPE_TABLE,  901, "./src/data/levels/base"           }
};
