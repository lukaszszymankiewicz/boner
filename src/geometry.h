#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct rectangle {
    float    x;
    float    y;
    float    w;
    float    h;
    float    vx;
    float    vy;
} rectangle_t;

rectangle_t GEO_px_to_rect(
    int x,
    int y,
    int w,
    int h,
    int vx,
    int vy
);

#endif
