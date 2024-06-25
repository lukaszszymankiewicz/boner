/* Totally unused - keep just as a trashbin for old code */

#include "entity.h"

// refrence code to calculate where how item is held - to be implemented back
// soon
// void ENT_set_hold(
//     entity_t *entity
// ) {
//     int dir_x, dir_y;
// 
//     switch (entity->direction)
//     {
//         case LEFT:
//             dir_x = FRAME_POINT_L_X;
//             dir_y = FRAME_POINT_L_Y;
//             break;
//         case RIGHT:
//             dir_x = FRAME_POINT_R_X;
//             dir_y = FRAME_POINT_R_Y;
//             break;
//         default:
//             assert(0);
//             break;
//     }
//     
//     int x0 = ENT_frame_data(entity, FRAME_TYPE_GRIP, dir_x);
//     int y0 = ENT_frame_data(entity, FRAME_TYPE_GRIP, dir_y);
// 
//     int handle_x = ENT_frame_data(entity, FRAME_TYPE_HANDLE, dir_x);
//     int handle_y = ENT_frame_data(entity, FRAME_TYPE_HANDLE, dir_y);
// 
//     entity->hold->x = entity->x + x0 - handle_x;
//     entity->hold->y = entity->y + y0 - handle_y;
// }
