/* Code related to obtain and store pixel positions, translating it into proper
 * gl types and prepare it to render. Each call to put something to canvas will
 * gather the data needed and render everything altogether on command. Scene can
 * have multiple layers (and buffers), which allows achieve flexible effects and
 * depth. Single, atomic thing to render is stored in `render_object_t`.
 * Before putting anything to layer (or buffer), it must be set to 'active'.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "canvas.h"
#include "framebuffer.h"
#include "mat.h"
#include "render.h"
#include "texture.h"

#define RECT_VERTICES_ROWS         6
#define RECT_VERTICES_COLS         2

array_t *CANVAS_texture_unit(
) {
    return MAT_scalar_new(DEFAULT_TEXTURE_UNIT);
}

void CANVAS_clear(
    canvas_t* canvas
) {
    for (int i=0; i<canvas->n_layers; i++) {
        for (int j=0; j<MAX_DRAWBLE_OBJECTS_ON_LAYER; j++) {

            if (canvas->layers[i].objs[j].on == 0) {
                continue;
            }

            canvas->layers[i].objs[j].on            =  0;
            canvas->layers[i].objs[j].texture       = -1;
            canvas->layers[i].objs[j].n_vertices    =  0;
            canvas->layers[i].objs[j].count         =  0;
        
            for (int u=0; u<MAX_SHADER_UNIFORMS; u++) {
                if (canvas->layers[i].objs[j].uniforms[u] != NULL) {
                    MAT_free(canvas->layers[i].objs[j].uniforms[u]);
                    canvas->layers[i].objs[j].uniforms[u] = NULL;
                }
            }

            MAT_free(canvas->layers[i].objs[j].vertices);
            canvas->layers[i].objs[j].vertices = NULL;
            canvas->layers[i].objs[j].shader_id = -1;
        }
    }

    canvas->cur_layer                 = -1;

    for (int b=0; b<canvas->n_buffers; b++) {
        RENDER_clear_buffer(canvas->buffers[b]->gl_id);
    }
}

void CANVAS_add_layer(
    canvas_t *canvas,
    int      layer
) {
    if (layer>MAX_LAYERS_ON_CANVAS || layer<0) { 
        printf("Requested layer exceeds has inproper index number! \n");
        return;
    }

    for (int j=0; j<MAX_DRAWBLE_OBJECTS_ON_LAYER; j++) {
        canvas->layers[layer].objs[j].vertices = NULL;
        canvas->layers[layer].objs[j].on       = 0;

        for (int u=0; u<MAX_SHADER_UNIFORMS; u++) {
            canvas->layers[layer].objs[j].uniforms[u] = NULL;
        }
    }

    canvas->layers[layer].on     = true;
    canvas->n_layers++;
}

void CANVAS_add_defalt_buffer(
    canvas_t* canvas,
    int      w,
    int      h
) {
    canvas->buffers[canvas->n_buffers]          = (texture_t*)malloc(sizeof(texture_t));
    canvas->buffers[canvas->n_buffers]->x0      = 0;
    canvas->buffers[canvas->n_buffers]->y0      = 0;
    canvas->buffers[canvas->n_buffers]->width   = w;
    canvas->buffers[canvas->n_buffers]->height  = h;
    canvas->buffers[canvas->n_buffers]->m       = 1;
    canvas->buffers[canvas->n_buffers]->texture = 0;

    canvas->n_buffers++;
}

void CANVAS_add_buffer(
    int            sprite,
    canvas_t       *canvas,
    int            window_w,
    int            window_h,
    int            w,
    int            h
) {
    canvas->buffers[canvas->n_buffers] = BUFFER_init(window_w, window_h, w, h);
    canvas->buffers[canvas->n_buffers]->sprite = sprite;
    canvas->n_buffers++;
}

canvas_t* CANVAS_init(
) {
    canvas_t *canvas    = NULL;
    canvas             = (canvas_t*)malloc(sizeof(canvas_t));
    canvas->n_layers   = 0;
    canvas->n_buffers  = 0;
    canvas->cur_layer  = -1;
    canvas->cur_buffer = 0;

    for(int b=0; b<MAX_BUFFERS_ON_CANVAS; b++) {
        canvas->buffers[b] = NULL;
    }

    return canvas;
}

void CANVAS_set_camera(
    canvas_t *canvas,
    int            x,
    int            y
) {
    canvas->camera_x = x;
    canvas->camera_y = y;
};

void CANVAS_reset_camera(
    canvas_t *canvas
) {
    canvas->camera_x = 0;
    canvas->camera_y = 0;
};

void CANVAS_activate_buffer(
    canvas_t* canvas,
    int      buffer
) {
    canvas->cur_buffer = buffer;
}

void CANVAS_activate_layer(
    canvas_t* canvas,
    int      layer
) {
    canvas->cur_layer = layer;
}

void CANVAS_add_uniform(
    render_object_t *object,
    const char      *name,
    array_t         *arr
) {
    if (!object) {
        printf("wrong object requested: \n"); 
    }

    int shader       = object->shader_id;
    if (shader<0) {
        printf("wrong shader requested: %d \n", shader); 
    }

    int i            = RENDER_get_uniform_index(shader, name);
    if (i<0) {
        printf("wrong uniform requested \n");
    }

    int size         = RENDER_get_uniform_size(shader, i);
    if (size<MAT_size(arr)) {
        printf("wrong size of uniform requested! \n"); 
    }

    object->uniforms[i] = arr;

}

void CANVAS_free(
    canvas_t* canvas
) {
    CANVAS_clear(canvas);

    for (int i=0; i<canvas->n_buffers; i++) {
        BUFFER_destroy(canvas->buffers[i]->gl_id);
        BUFFER_free(canvas->buffers[i]);
        canvas->buffers[i] = NULL;
    }

    free(canvas);      
    canvas = NULL;
}

bool CANVAS_layer_is_on(
    canvas_t* canvas,
    int      layer
) {
    return canvas->layers[layer].on;
}

bool CANVAS_layer_is_off(
    canvas_t* canvas,
    int      layer
) {
    return !(CANVAS_layer_is_on(canvas, layer));
}

array_t *CANVAS_coord_to_matrix(
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

array_t *CANVAS_set_scale(
    canvas_t* canvas
) {
    int w = canvas->buffers[canvas->cur_buffer]->width;
    int h = canvas->buffers[canvas->cur_buffer]->height;

    return MAT_vec2_new(w, h);
}

array_t *CANVAS_texture_pos(
    draw_rect_t *draw,
    draw_rect_t *clip,
    texture_t   *texture
) {
    int tex_w  = texture->width;
    int tex_h  = texture->height;
    int corr_w = (int)(draw->flip_w) * clip->w;
    int corr_h = (int)(draw->flip_h) * clip->h;
    
    array_t *pos_arr = CANVAS_coord_to_matrix(
        (float)(draw->x +       0),
        (float)(draw->y +       0),
        (float)(draw->x + draw->w),
        (float)(draw->y + draw->h)
    );
    array_t *tex_arr = CANVAS_coord_to_matrix(
        (float)(clip->x +       0 + corr_w) / (float)tex_w,
        (float)(clip->y + clip->h - corr_h) / (float)tex_h,
        (float)(clip->x + clip->w - corr_w) / (float)tex_w,
        (float)(clip->y +       0 + corr_h) / (float)tex_h
    );

    array_t *new = NULL;
    new          = MAT_join(pos_arr, tex_arr);

    return new;
}

render_object_t* CANVAS_get_cur_obj(
    canvas_t* canvas,
    int       sprite
) {
    return &(canvas->layers[canvas->cur_layer].objs[sprite]);
}

void CANVAS_put_texture_to_canvas(
    canvas_t    *canvas,
    draw_rect_t *draw,
    draw_rect_t *clip,
    texture_t   *texture
) {
    array_t *vertices       = CANVAS_texture_pos(draw, clip, texture);
    render_object_t* object = CANVAS_get_cur_obj(canvas, texture->sprite);

    object->shader_id       = SHADER_TEXTURE;
    object->texture         = texture->texture;
    object->mode            = RENDER_MODE_TEXTURE;
    object->vertices        = MAT_append(object->vertices, vertices);
    object->n_vertices      = MAT_n(object->vertices);
    object->count           = (int) object->n_vertices / object->vertices->cols;
    
    if (object->on == 0) {
        array_t *scale_arr      = CANVAS_set_scale(canvas);
        array_t *texture_arr    = CANVAS_texture_unit();
        array_t *camera_arr     = MAT_vec2_new(canvas->camera_x, canvas->camera_y);

        CANVAS_add_uniform(object, "aScale", scale_arr); 
        CANVAS_add_uniform(object, "aCamera", camera_arr); 
        CANVAS_add_uniform(object, "ourTexture", texture_arr);
    }

    object->on              = 1;
}

// scale cur_buffer to fit on DEFAULT_FRAMEBUFFER (physical screen size) and put
// such texture on current layer
void CANVAS_draw_scaled_buffer(
    canvas_t* canvas
) {
    int buffer  = canvas->cur_buffer;

    int texture = canvas->buffers[buffer]->texture;
    int x0      = canvas->buffers[buffer]->x0;
    int y0      = canvas->buffers[buffer]->y0;
    int m       = canvas->buffers[buffer]->m;
    int w       = canvas->buffers[buffer]->width;
    int h       = canvas->buffers[buffer]->height;

    CANVAS_activate_buffer(canvas, DEFAULT_FRAMEBUFFER);

    draw_rect_t draw = { x0, y0, w*m, h*m, false, true };
    draw_rect_t clip = { 0, 0, w, h, false, true };

    int old_x = canvas->camera_x;
    int old_y = canvas->camera_y;

    CANVAS_reset_camera(canvas);

    CANVAS_put_texture_to_canvas(
        canvas,
        &draw,
        &clip,
        canvas->buffers[SCALED_IMAGE_FRAMEBUFFER]
    );

    CANVAS_activate_buffer(canvas, buffer);

    CANVAS_set_camera(canvas, old_x, old_y);
}

void CANVAS_render_current_layer(
    canvas_t* canvas
) {
    int layer  = canvas->cur_layer;
    int target = canvas->cur_buffer;
    
    // no objects to render
    if (CANVAS_layer_is_off(canvas, layer)) {
        return;
    }

    for (int i=0; i<MAX_DRAWBLE_OBJECTS_ON_LAYER; i++) {
        render_object_t object = canvas->layers[layer].objs[i];

        if (!object.vertices) {
            continue;
        }

        RENDER_set_viewport(
            canvas->buffers[target]->gl_id,
            canvas->buffers[target]->width,
            canvas->buffers[target]->height
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
