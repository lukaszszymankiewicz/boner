#include <stdbool.h>

#include "framebuffer.h"
#include "mat.h"
#include "shader.h"

#ifndef CANVAS_H
#define CANVAS_H

// these are default frambuffer which must be present, custom ones can be
// introduced as well
enum FRAMEBUFFERS {
    DEFAULT_FRAMEBUFFER,
    SCALED_IMAGE_FRAMEBUFFER
};

#define MAX_TEXTURE_NUMBER           4
#define MAX_LAYERS_ON_CANVAS         6
#define MAX_BUFFERS_ON_CANVAS        3
#define MAX_EFFECTS_ON_LAYER         2
#define SCALED_BUFFER_SPRITE         MAX_TEXTURE_NUMBER + 1
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
} render_object_t;

typedef struct layer {
    char             *name;
    bool              on;
    render_object_t   objs[MAX_DRAWBLE_OBJECTS_ON_LAYER];
} layer_t; 

typedef struct canvas {
    int                n_layers;
    int                n_buffers;
    int                cur_layer;
    int                cur_buffer;
    int                camera_x;
    int                camera_y;
    layer_t            layers[MAX_LAYERS_ON_CANVAS];
    texture_t         *buffers[MAX_BUFFERS_ON_CANVAS];    
} canvas_t; 

typedef struct draw_rect {
    int x;
    int y;
    int w;
    int h;
    int flip_w;
    int flip_h;
} draw_rect_t; 

canvas_t* CANVAS_init();

void CANVAS_set_camera(canvas_t *canvas, int x, int y);
void CANVAS_clear(canvas_t* canvas);
void CANVAS_add_layer(canvas_t* canvas, int layer);
void CANVAS_activate_buffer(canvas_t* canvas, int buffer);
void CANVAS_activate_layer(canvas_t* canvas, int layer);
void CANVAS_add_defalt_buffer(canvas_t* canvas, int w, int h);
void CANVAS_add_buffer(int id, canvas_t *canvas, int window_w, int window_h, int w, int h);
void CANVAS_draw_scaled_buffer(canvas_t* canvas);
void CANVAS_free(canvas_t* canvas);
void CANVAS_render_current_layer(canvas_t* canvas);

void CANVAS_put_texture_to_canvas(
    canvas_t* canvas,
    draw_rect_t *draw,
    draw_rect_t *clip,
    texture_t* texture
);

#endif
