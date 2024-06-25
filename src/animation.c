#include <assert.h>

#include "animation.h"
#include "macros.h"

// get single animation data value
int ANIM_get_component_value(
    animation_t       *animation,
    int                anim,
    int                frame,
    int                component,
    int                value
) {
    assert(animation);
    ASSERT_RANGE(0, anim, ANIMATION_MAX);
    ASSERT_RANGE(0, frame, ANIMATION_MAX_FRAMES);
    ASSERT_RANGE(0, component, ANIMATION_COMPONENT_ALL);
    ASSERT_RANGE(0, value, ANIMATION_MAX_COMPONENT_VALUE);
    
    switch ((*(animation))[anim][frame][component][FRAME_SHAPE])
    {
        case FRAME_SHAPE_RECT:
            assert(value <= 5);
            break;
        case FRAME_SHAPE_POINT:
            assert(value <= 5);
            break;
        case FRAME_SHAPE_SCALAR:
            assert(value <= 2);
            break;
        default:
            // unknown FRAME_SHAPE
            assert(0);
            break;
    }

    return (*(animation))[anim][frame][component][value];
}
