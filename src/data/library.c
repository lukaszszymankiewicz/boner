#include "library.h"

#include "../texture.h"
#include "../shader.h"


void LIB_init(
) {
    printf("[RESOURCES]\n");
    LIB_create_entity_library();
    // LIB_create_wobble_library();
    LIB_create_sprites_library();
    LIB_create_levels_library();
    LIB_create_shaders_library();
    LIB_create_behaviour_matrix();
    LIB_create_collision_behaviour_library();
    LIB_create_collision_behaviour_matrix();
}

void LIB_free_all(
) {
    TEX_free(sprites_library[SPRITE_HERO]);
    TEX_free(sprites_library[SPRITE_SKELETON]);
    TEX_free(sprites_library[SPRITE_TILESET_A]);
    SHADER_free(shader_library[SHADER_TEXTURE]);
}
