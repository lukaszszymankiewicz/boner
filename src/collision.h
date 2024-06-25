#include "geometry.h"

#ifndef COLLISION_H
#define COLLISION_H

typedef struct collision {
    int      hit;
    float    new_x;
    float    new_y;
    float    dx;
    float    dy;
    int      nx;
    int      ny;
    int      col_id;
    float    dist;
    float    vx;
    float    vy;
} collision_t;

collision_t COL_rect_rect(rectangle_t a, rectangle_t b);
collision_t COL_better(collision_t a, collision_t b);

#endif
