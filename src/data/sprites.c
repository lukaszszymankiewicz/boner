#include "library.h"

#include "../texture.h"

texture_t *sprites_library[SPRITE_ALL] = { NULL };

texture_blueprint_t texture_blueprint_hero = {
    SPRITE_HERO,
    "./src/data/sprites/hero.png"
};

texture_blueprint_t texture_blueprint_tileset_a = {
    SPRITE_TILESET_A,
    "./src/data/sprites/tileset_a.png"
};

texture_blueprint_t texture_blueprint_skeleton = {
    SPRITE_SKELETON,
    "./src/data/sprites/skeleton.png"
};

void LIB_read_sprites_blueprint(
    texture_blueprint_t *blueprint
) {
    texture_t* sprite = TEX_read_texture(blueprint->filepath, blueprint->id);

    if (sprite) {
        printf("SPRITE BLUEPRINT ID = %d read\n", blueprint->id);
    }
    sprites_library[blueprint->id]      = sprite;
};

void LIB_create_sprites_library(
) {
    LIB_read_sprites_blueprint(&texture_blueprint_hero);
    LIB_read_sprites_blueprint(&texture_blueprint_tileset_a);
    LIB_read_sprites_blueprint(&texture_blueprint_skeleton);
};
