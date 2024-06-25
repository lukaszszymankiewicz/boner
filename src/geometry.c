/* geometry algorithms */

#include "macros.h"
#include "geometry.h"

// translate from pix position to "math" geometry rect
// pixel is an 1x1 rect, the axes are creating the lines of this rectangle - so
// the center of a pixel has (0.5, 0.5) position, this needs to be included
rectangle_t GEO_px_to_rect(
    int x,
    int y,
    int w,
    int h,
    int vx,
    int vy
) {
    return (rectangle_t){
        (float)x - PIX_COEF,
        (float)y - PIX_COEF,
        (float)w,
        (float)h,
        (float)vx,
        (float)vy
    };
}
