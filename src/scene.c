/* Code related to obtain and store pixel positions, translating it into proper
 * gl types and prepare it to render. Each call to put something to scene will
 * gather the data needed and render everything altogether on command. Scene can
 * have multiple layers (and buffers), which allows achieve flexible effects and
 * depth. Single, atomic thing to render is stored in `render_object_t`.
 * Before putting anything to layer (or buffer), it must be set to 'active'.
 */

#include "data/library.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "framebuffer.h"
#include "macros.h"
#include "mat.h"
#include "modules.h"
#include "render.h"
#include "scene.h"

#define RECT_VERTICES_ROWS         6
#define RECT_VERTICES_COLS         2

array_t *SCENE_texture_unit(
) {
    return MAT_scalar_new(DEFAULT_TEXTURE_UNIT);
}

void SCENE_clear(
) {
    for (int i=0; i<scene->n_layers; i++) {
        for (int j=0; j<MAX_DRAWBLE_OBJECTS_ON_LAYER; j++) {

            if (scene->layers[i].objs[j].on == 0) {
                continue;
            }

            scene->layers[i].objs[j].on            =  0;
            scene->layers[i].objs[j].texture       = -1;
            scene->layers[i].objs[j].n_vertices    =  0;
            scene->layers[i].objs[j].count         =  0;
        
            for (int u=0; u<MAX_SHADER_UNIFORMS; u++) {
                if (scene->layers[i].objs[j].uniforms[u] != NULL) {
                    MAT_free(scene->layers[i].objs[j].uniforms[u]);
                    scene->layers[i].objs[j].uniforms[u] = NULL;
                }
            }

            MAT_free(scene->layers[i].objs[j].vertices);
            scene->layers[i].objs[j].vertices = NULL;
            scene->layers[i].objs[j].shader_id = -1;
        }
    }

    scene->cur_layer                 = -1;

    for (int b=0; b<scene->n_buffers; b++) {
        RENDER_clear_buffer(scene->buffers[b]->id);
    }
}

void SCENE_add_layer(
    int   layer,
    char *name
) {
    if (layer>MAX_LAYERS_ON_SCENE || layer<0) { 
        printf("Requested layer exceeds has inproper index number! \n");
        return;
    }

    for (int j=0; j<MAX_DRAWBLE_OBJECTS_ON_LAYER; j++) {
        scene->layers[layer].objs[j].vertices = NULL;
        scene->layers[layer].objs[j].on       = 0;

        for (int u=0; u<MAX_SHADER_UNIFORMS; u++) {
            scene->layers[layer].objs[j].uniforms[u] = NULL;
        }
    }

    scene->layers[layer].on     = true;
    scene->layers[layer].name   = name;
    scene->n_layers++;
}

void SCENE_add_defalt_buffer(
) {
    scene->buffers[scene->n_buffers]          = (framebuffer_t*)malloc(sizeof(framebuffer_t));
    scene->buffers[scene->n_buffers]->x0      = 0;
    scene->buffers[scene->n_buffers]->y0      = 0;
    scene->buffers[scene->n_buffers]->w       = window->width;
    scene->buffers[scene->n_buffers]->h       = window->height;
    scene->buffers[scene->n_buffers]->m       = 1;
    scene->buffers[scene->n_buffers]->texture = 0;
    scene->buffers[scene->n_buffers]->id      = DEFAULT_FRAMEBUFFER;

    scene->n_buffers++;
}

void SCENE_add_buffer(
    int    id,
    int    w,
    int    h
) {
    scene->buffers[id] = BUFFER_init(id, w, h);
    scene->n_buffers++;
}

void SCENE_init(
) {
    scene             = NULL;
    scene             = (scene_t*)malloc(sizeof(scene_t));
    scene->n_layers   = 0;
    scene->n_buffers  = 0;
    scene->cur_layer  = -1;
    scene->cur_buffer = 0;

    for(int b=0; b<MAX_BUFFERS_ON_SCENE; b++) {
        scene->buffers[b] = NULL;
    }
}

void SCENE_activate_buffer(
    int buffer
) {
    assert (buffer >= 0);
    assert (buffer < BUFFER_ALL);
    scene->cur_buffer = buffer;
}

void SCENE_activate_layer(
    int         layer
) {
    assert (layer >= 0);
    assert (layer < LAYER_ALL);
    scene->cur_layer = layer;
}

void SCENE_add_uniform(
    render_object_t *object,
    const char      *name,
    array_t         *arr
) {
    if (!object) {
        printf("wrong object requested: \n"); 
    }

    int shader       = object->shader_id;
    if (shader<0) {
        printf("wrong shader requested: %d for object %s \n", shader, object->name); 
    }

    int i            = RENDER_get_uniform_index(shader, name);
    if (i<0) {
        printf("wrong uniform requested: %s \n", name); 
    }

    int size         = RENDER_get_uniform_size(shader, i);
    if (size<MAT_size(arr)) {
        printf("wrong size of uniform requested! \n"); 
    }

    object->uniforms[i] = arr;

}

void SCENE_free(
) {
    SCENE_clear();

    for (int i=0; i<scene->n_buffers; i++) {
        BUFFER_destroy(scene->buffers[i]->id);
        BUFFER_free(scene->buffers[i]);
        scene->buffers[i] = NULL;
    }

    free(scene);      
    scene = NULL;
}

bool SCENE_layer_is_on(
    int      layer
) {
    return scene->layers[layer].on;
}

bool SCENE_layer_is_off(
    int      layer
) {
    return !(SCENE_layer_is_on(layer));
}

array_t *SCENE_coord_to_matrix(
    float x1, float y1,
    float x2, float y2
) {
    array_t *arr  = MAT_new(RECT_VERTICES_ROWS, RECT_VERTICES_COLS);
    
    arr->values[0 ] = x1; arr->values[1 ] = y2;
    arr->values[2 ] = x2; arr->values[3 ] = y2;
    arr->values[4 ] = x2; arr->values[5 ] = y1;
    arr->values[6 ] = x1; arr->values[7 ] = y2;
    arr->values[8 ] = x2; arr->values[9 ] = y1;
    arr->values[10] = x1; arr->values[11] = y1;

    return arr;
}

array_t *SCENE_set_scale(
) {
    int w = scene->buffers[scene->cur_buffer]->w;
    int h = scene->buffers[scene->cur_buffer]->h;

    return MAT_vec2_new(w, h);
}

array_t *SCENE_texture_pos(
    int   draw_x, int   draw_y,
    int   draw_w, int   draw_h,
    int   clip_x, int   clip_y,
    int   clip_w, int   clip_h,
    int    tex_w, int    tex_h,
    bool  flip_w, bool  flip_h
) {
    int corr_w = (int)(flip_w) * clip_w;
    int corr_h = (int)(flip_h) * clip_h;
    
    array_t *pos_arr = SCENE_coord_to_matrix(
        (float)(draw_x +      0),
        (float)(draw_y +      0),
        (float)(draw_x + draw_w),
        (float)(draw_y + draw_h)
    );
    array_t *tex_arr = SCENE_coord_to_matrix(
        (float)(clip_x +      0 + corr_w) / (float)tex_w,
        (float)(clip_y + clip_h - corr_h) / (float)tex_h,
        (float)(clip_x + clip_w - corr_w) / (float)tex_w,
        (float)(clip_y +      0 + corr_h) / (float)tex_h
    );

    array_t *new = NULL;
    new          = MAT_join(pos_arr, tex_arr);

    return new;
}

void SCENE_put_texture_to_scene(
    char    *name,
    array_t *vertices,
    int      texture,
    int      sprite      
) {
    render_object_t* object = &(scene->layers[scene->cur_layer].objs[sprite]);

    object->shader_id       = SHADER_TEXTURE;
    object->texture         = texture;
    object->mode            = RENDER_MODE_TEXTURE;
    object->vertices        = MAT_append(object->vertices, vertices);
    object->n_vertices      = MAT_n(object->vertices);
    object->count           = (int) object->n_vertices / object->vertices->cols;
    object->name            = name;
    
    if (object->on == 0) {
        array_t *scale_arr      = SCENE_set_scale();
        array_t *texture_arr    = SCENE_texture_unit();
        array_t *camera_arr     = MAT_vec2_new(window->camera_x, window->camera_y);

        SCENE_add_uniform(object, "aScale", scale_arr); 
        SCENE_add_uniform(object, "aCamera", camera_arr); 
        SCENE_add_uniform(object, "ourTexture", texture_arr);
    }

    object->on              = 1;
}

// scale cur_buffer to fit on DEFAULT_FRAMEBUFFER (physical screen size) and put
// such texture on current layer
void SCENE_draw_scaled_buffer(
) {
    int buffer = scene->cur_buffer;

    // force camera to be zero
    window->camera_x = 0;
    window->camera_y = 0;
    
    int texture = scene->buffers[scene->cur_buffer]->texture;
    int x0      = scene->buffers[scene->cur_buffer]->x0;
    int y0      = scene->buffers[scene->cur_buffer]->y0;
    int m       = scene->buffers[scene->cur_buffer]->m;
    int w       = scene->buffers[scene->cur_buffer]->w;
    int h       = scene->buffers[scene->cur_buffer]->h;

    SCENE_activate_buffer(DEFAULT_FRAMEBUFFER);

    array_t *vertices = SCENE_texture_pos(
        x0,    y0,
        w*m,   h*m,
        0,     0,
        w,     h,
        w,     h,
        false, true
    );

    SCENE_put_texture_to_scene("buffer", vertices, texture, FIRST_EFFECT_IDX);
    SCENE_activate_buffer(buffer);
}

void SCENE_render_current_layer(
) {
    int layer  = scene->cur_layer;
    int target = scene->cur_buffer;
    
    // no objects to render
    if (SCENE_layer_is_off(layer)) {
        return;
    }

    for (int i=0; i<MAX_DRAWBLE_OBJECTS_ON_LAYER; i++) {
        render_object_t object = scene->layers[layer].objs[i];

        if (!object.vertices) {
            continue;
        }

        RENDER_set_viewport(
            scene->buffers[target]->id,
            scene->buffers[target]->w,
            scene->buffers[target]->h
        );

        RENDER_shader(
            object.shader_id,
            object.texture,
            object.vertices->values,
            object.n_vertices,
            object.uniforms,
            object.count,
            object.mode
        );
    }
}
