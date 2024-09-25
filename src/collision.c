/* Algorithms for raw collision detection.
 * Functions works on geometric/math coord system NOT pixel position on screen.
 * This enforces some corrections in the other part of the code.
 */

#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "collision.h"
#include "macros.h"

int val_between(
    float min,
    float val,
    float max
) {
    return ((min <= val) && (val <= max));
}

// checks if two rects overlaps, touching on one side is also considered as
// overlap
int rect_overlap(
    rectangle_t a,
    rectangle_t b
) {
    if (
      a.x + a.w >= b.x &&
      a.x <= b.x + b.w &&
      a.y + a.h >= b.y &&
      a.y <= b.y + b.h
    ) {
        return 1;
    }

    return 0;
}

// Checks if two rects are touching on one side, to be compliant with other
// collision detections functions, this functions is also returning
// `collision_t`, filled with as much data as needed to respond to such
// situation. Function is working ONLY for if rectangle `b` is static.
collision_t rect_touch_sides(
    rectangle_t a,
    rectangle_t b
) {
    collision_t col = { 0 };

    // falling down...
    if (a.vy < 0) {
        // ...and hitting other rect from above
        if ((a.y == b.y + b.h) && (val_between(b.x, a.x, b.x+b.w) || val_between(b.x, a.x+a.w, b.x+b.w))) {
            col.hit = 1;
            col.ny = -1;
            col.new_x = a.x + a.vx;
            col.new_y = a.y;
            return col;
        }

    // going up
    } else if (a.vy > 0) {
        // ...and hittin other rect from below
        if ((a.y + a.h == b.y) && (val_between(b.x, a.x, b.x+b.w) || val_between(b.x, a.x+a.w, b.x+b.w))) {
            col.hit = 1;
            col.ny = 1;
            col.new_x = a.x + a.vx;
            col.new_y = a.y;

            return col;
        }
    }
    
    // going left...
    if (a.vx < 0) {
        // ...and hit other rect from right
        if ((a.x == b.x + b.w) && (val_between(b.y, a.y, b.y+b.h) || val_between(b.y, a.y+a.h, b.y+b.h))) {
            col.hit = 1;
            col.nx = -1;
            col.new_x = a.x;
            col.new_y = a.y + a.vy;

            return col;
        }
    // ...going right
    } else if (a.vx > 0) {
        // .. and hit other rect from left
        if ((a.x + a.w == b.x) && (val_between(b.y, a.y, b.y+b.h) || val_between(b.y, a.y+a.h, b.y+b.h))) {
            col.hit = 1;
            col.nx = 1;
            col.new_x = a.x;
            col.new_y = a.y + a.vy;

            return col;
        }
    }

    return col;
}

// Checks if two rects are colliding. Touching sides are also considered as
// collision. Function is using minkowski difference to transform rectangle 'a'
// to ray, and minkowski sum to properly enlarge rectangle 'b'.
collision_t COL_rect_rect(
    rectangle_t a,
    rectangle_t b
) {
    // only collision with stable colliders are supported
    assert((b.vx == 0) && (b.vy == 0));

    // check if sides are touch (or create empty collision)
    collision_t col = rect_touch_sides(a, b);

    if ((col.hit == 1) || ((a.vx == 0) && (a.vy == 0))) {
        return col;
    }
        
    // determine ray beg
    float rx = a.x + a.w/2.0f;
    float ry = a.y + a.h/2.0f;

    // minkowski sum
    float min_x = b.x - a.w/2.0f;
    float min_y = b.y - a.h/2.0f;
    float max_x = b.x + b.w + a.w/2.0f;
    float max_y = b.y + b.h + a.h/2.0f;

	float last_entry = -INFINITY;
	float first_exit = INFINITY;

    // x collision
    if (a.vx != 0.0) {
        float t1 = (min_x - rx) / a.vx;
        float t2 = (max_x - rx) / a.vx;

        last_entry = fmaxf(last_entry, fminf(t1, t2));
        first_exit = fminf(first_exit, fmaxf(t1, t2));

    } else if (rx <= min_x || rx >= max_x) {
        return col;
    }

    // y collision
    if (a.vy != 0.0) {

        float t1 = (min_y - ry) / a.vy;
        float t2 = (max_y - ry) / a.vy;

        last_entry = fmaxf(last_entry, fminf(t1, t2));
        first_exit = fminf(first_exit, fmaxf(t1, t2));

    } else if (ry <= min_y || ry >= max_y) {
        return col;
    }
    
    // check if collision is detected
    if ((first_exit > last_entry) && (first_exit > 0) && (last_entry < 1)) {   
        col.hit = 1;
        
        // determine new position of 'a' rect according to detected collision
        // and its velocity
        col.new_x = a.x + a.vx * last_entry;
        col.new_y = a.y + a.vy * last_entry;
        col.dist  = last_entry;

        col.dx      = (rx + a.vx * last_entry) - (a.x + a.w/2.0f);
		col.dy      = (ry + a.vy * last_entry) - (a.y + a.h/2.0f);
        col.vx      = a.vx;
        col.vy      = a.vy;

		float px    = (b.w/2.0f) - fabsf(col.dx);
		float py    = (b.h/2.0f) - fabsf(col.dy);
        
		if (px < py) {
			col.nx = (int)((col.dx > 0) - (col.dx < 0));
		} else {
			col.ny = (int)((col.dy > 0) - (col.dy < 0));
		}
    } 

    return col;
}

// Checks which collision is 'better', meaning it happened earlier making it
// having higher priority.
collision_t COL_better(
    collision_t first,
    collision_t second
) {
    if (!(second.hit) && (first.hit)) {
        return first;
    } 

    if (!(first.hit) && (second.hit)) {
        return second;
    } 

    if (second.dist < first.dist) {
        return second;
    } else if (second.dist == first.dist) {
        if ((fabsf(first.vx) > fabsf(first.vy)) && (first.nx != 0)) {
            return second;
        } else if ((fabsf(first.vy) > fabsf(first.vx)) && (first.ny != 0)) {
            return second;
        }
    }

    return first;
}
