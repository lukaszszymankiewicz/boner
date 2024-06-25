#include "data/library.h"

#include <stdbool.h>

#include "framebuffer.h"
#include "mat.h"
#include "shader.h"

#ifndef SCENE_H
#define SCENE_H

#define MAX_LAYERS_ON_SCENE          6
#define MAX_BUFFERS_ON_SCENE         3
#define MAX_EFFECTS_ON_LAYER         2
#define FIRST_EFFECT_IDX             MAX_TEXTURE_NUMBER + 1
#define MAX_DRAWBLE_OBJECTS_ON_LAYER MAX_TEXTURE_NUMBER + MAX_EFFECTS_ON_LAYER


typedef struct render_object {
    int         on;
    int         shader_id;
    int         texture;
    int         mode;
    int         n_vertices;
    int         count;
    array_t    *vertices;    
    array_t    *uniforms[MAX_SHADER_UNIFORMS];
    char       *name;
} render_object_t;

typedef struct layer {
    char             *name;
    bool              on;
    render_object_t   objs[MAX_DRAWBLE_OBJECTS_ON_LAYER];
} layer_t; 

typedef struct scene {
    int                n_layers;
    int                n_buffers;
    int                cur_layer;
    int                cur_buffer;
    layer_t            layers[MAX_LAYERS_ON_SCENE];
    framebuffer_t     *buffers[MAX_BUFFERS_ON_SCENE];    
} scene_t; 

void SCENE_init();
void SCENE_clear();
void SCENE_add_layer(int layer, char *name);
void SCENE_activate_buffer(int buffer);
void SCENE_activate_layer(int layer);
void SCENE_add_defalt_buffer();
void SCENE_add_buffer(int id, int w, int h);

void SCENE_draw_scaled_buffer();

void SCENE_free();
void SCENE_render_current_layer();

array_t *SCENE_texture_pos(
    int   draw_x, int   draw_y,
    int   draw_w, int   draw_h,
    int   clip_x, int   clip_y,
    int   clip_w, int   clip_h,
    int    tex_w, int    tex_h,
    bool  flip_w, bool  flip_h
); 

void SCENE_put_texture_to_scene(
    char    *name,
    array_t *vertices,
    int      texture,
    int      sprite
);

#endif
