#include "library.h"

#include "../level.h"

level_blueprint_t* levels_library[LEVEL_ALL] = {NULL};

level_blueprint_t level_blueprint_new = {
  LEVEL_NEW, 
  1, 4,
  10, 12,
  {
    {
      {
        {LEVEL_METADATA, 0, 0, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 0, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 2, 0, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 3, 0, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 4, 0, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 5, 0, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 6, 0, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 7, 0, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 0, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 0, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 1, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 1, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 2, 1, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 3, 1, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 4, 1, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 5, 1, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 6, 1, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 7, 1, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 1, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 1, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 2, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 2, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 2, 2, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 3, 2, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 4, 2, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 5, 2, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 6, 2, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 7, 2, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 2, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 2, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 3, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 3, 5, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 1, 0, 224, 480, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 2, 0, 256, 480, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 3, 0, 288, 480, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 4, 0, 256, 448, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 5, 0, 288, 448, ENTITY_TILESET_A, 1, 0 },
      },
      {
        {LEVEL_METADATA, 2, 3, 1, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 6, 0, 320, 480, ENTITY_TILESET_A, 1, 0 },
      },
      {
        {LEVEL_METADATA, 3, 3, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 4, 3, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 5, 3, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 6, 3, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 7, 3, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 3, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 3, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 4, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 4, 7, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 7, 0, 288, 608, ENTITY_TILESET_B, 6, 2 },
        {LEVEL_ENTITY, 8, 0, 288, 576, ENTITY_TILESET_B, 7, 2 },
        {LEVEL_ENTITY, 10, 0, 192, 512, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 11, 0, 224, 512, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 12, 0, 256, 512, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 13, 0, 288, 512, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 120, 0, 256, 554, ENTITY_HERO, 0, 0 },
      },
      {
        {LEVEL_METADATA, 2, 4, 11, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 15, 0, 320, 608, ENTITY_TILESET_B, 6, 3 },
        {LEVEL_ENTITY, 16, 0, 352, 608, ENTITY_TILESET_B, 6, 4 },
        {LEVEL_ENTITY, 17, 0, 448, 608, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 18, 0, 320, 576, ENTITY_TILESET_B, 7, 3 },
        {LEVEL_ENTITY, 19, 0, 352, 576, ENTITY_TILESET_B, 7, 4 },
        {LEVEL_ENTITY, 21, 0, 320, 544, ENTITY_TILESET_B, 8, 3 },
        {LEVEL_ENTITY, 20, 0, 448, 576, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 22, 0, 448, 544, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 23, 0, 320, 512, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 24, 0, 352, 512, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 25, 0, 448, 512, ENTITY_TILESET_A, 1, 0 },
      },
      {
        {LEVEL_METADATA, 3, 4, 6, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 26, 0, 480, 608, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 27, 0, 576, 608, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 28, 0, 608, 608, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 29, 0, 480, 576, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 30, 0, 480, 544, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 31, 0, 480, 512, ENTITY_TILESET_A, 1, 0 },
      },
      {
        {LEVEL_METADATA, 4, 4, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 5, 4, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 6, 4, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 7, 4, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 4, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 4, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 5, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 5, 2, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 32, 0, 288, 672, ENTITY_TILESET_B, 4, 2 },
        {LEVEL_ENTITY, 33, 0, 288, 640, ENTITY_TILESET_B, 5, 2 },
      },
      {
        {LEVEL_METADATA, 2, 5, 4, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 34, 0, 320, 672, ENTITY_TILESET_B, 4, 3 },
        {LEVEL_ENTITY, 35, 0, 352, 672, ENTITY_TILESET_B, 4, 4 },
        {LEVEL_ENTITY, 36, 0, 320, 640, ENTITY_TILESET_B, 5, 3 },
        {LEVEL_ENTITY, 37, 0, 352, 640, ENTITY_TILESET_B, 5, 4 },
      },
      {
        {LEVEL_METADATA, 3, 5, 7, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 38, 0, 608, 736, ENTITY_TILESET_B, 5, 6 },
        {LEVEL_ENTITY, 39, 0, 576, 704, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 40, 0, 608, 704, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 41, 0, 576, 672, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 42, 0, 608, 672, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 43, 0, 576, 640, ENTITY_TILESET_A, 1, 0 },
        {LEVEL_ENTITY, 44, 0, 608, 640, ENTITY_TILESET_A, 1, 0 },
      },
      {
        {LEVEL_METADATA, 4, 5, 1, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 45, 0, 768, 736, ENTITY_TILESET_A, 1, 2 },
      },
      {
        {LEVEL_METADATA, 5, 5, 14, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 46, 0, 800, 736, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 47, 0, 832, 736, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 48, 0, 864, 736, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 49, 0, 896, 736, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 50, 0, 928, 736, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 51, 0, 800, 704, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 52, 0, 832, 704, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 53, 0, 864, 704, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 54, 0, 896, 704, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 55, 0, 928, 704, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 56, 0, 832, 672, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 57, 0, 864, 672, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 58, 0, 896, 672, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 59, 0, 864, 640, ENTITY_TILESET_A, 1, 2 },
      },
      {
        {LEVEL_METADATA, 6, 5, 1, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 60, 0, 960, 736, ENTITY_TILESET_A, 1, 2 },
      },
      {
        {LEVEL_METADATA, 7, 5, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 5, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 5, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 6, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 6, 2, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 61, 0, 288, 864, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 62, 0, 288, 832, ENTITY_TILESET_A, 1, 1 },
      },
      {
        {LEVEL_METADATA, 2, 6, 2, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 63, 0, 320, 864, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 64, 0, 320, 832, ENTITY_TILESET_A, 1, 1 },
      },
      {
        {LEVEL_METADATA, 3, 6, 2, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 65, 0, 608, 800, ENTITY_TILESET_B, 3, 6 },
        {LEVEL_ENTITY, 66, 0, 608, 768, ENTITY_TILESET_B, 4, 6 },
      },
      {
        {LEVEL_METADATA, 4, 6, 2, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 67, 0, 736, 768, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 68, 0, 768, 768, ENTITY_TILESET_A, 1, 2 },
      },
      {
        {LEVEL_METADATA, 5, 6, 6, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 69, 0, 832, 800, ENTITY_TILESET_B, 8, 4 },
        {LEVEL_ENTITY, 70, 0, 800, 768, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 71, 0, 832, 768, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 72, 0, 864, 768, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 73, 0, 896, 768, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 74, 0, 928, 768, ENTITY_TILESET_A, 1, 2 },
      },
      {
        {LEVEL_METADATA, 6, 6, 2, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 75, 0, 960, 768, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 76, 0, 992, 768, ENTITY_TILESET_A, 1, 2 },
      },
      {
        {LEVEL_METADATA, 7, 6, 14, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 77, 0, 1120, 864, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 78, 0, 1152, 864, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 79, 0, 1184, 864, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 80, 0, 1216, 864, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 81, 0, 1248, 864, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 82, 0, 1120, 832, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 83, 0, 1152, 832, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 84, 0, 1184, 832, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 85, 0, 1216, 832, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 86, 0, 1248, 832, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 87, 0, 1152, 800, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 88, 0, 1184, 800, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 89, 0, 1216, 800, ENTITY_TILESET_A, 1, 2 },
        {LEVEL_ENTITY, 90, 0, 1184, 768, ENTITY_TILESET_A, 1, 2 },
      },
      {
        {LEVEL_METADATA, 8, 6, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 6, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 7, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 7, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 2, 7, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 3, 7, 4, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 91, 0, 512, 992, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 92, 0, 544, 992, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 93, 0, 512, 960, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 94, 0, 544, 960, ENTITY_TILESET_A, 1, 1 },
      },
      {
        {LEVEL_METADATA, 4, 7, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 5, 7, 6, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 95, 0, 832, 992, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 96, 0, 864, 992, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 97, 0, 896, 992, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 98, 0, 832, 960, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 99, 0, 864, 960, ENTITY_TILESET_A, 1, 1 },
        {LEVEL_ENTITY, 100, 0, 896, 960, ENTITY_TILESET_A, 1, 1 },
      },
      {
        {LEVEL_METADATA, 6, 7, 4, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 101, 0, 1024, 960, ENTITY_TILESET_A, 0, 1 },
        {LEVEL_ENTITY, 102, 0, 1056, 960, ENTITY_TILESET_A, 0, 1 },
        {LEVEL_ENTITY, 103, 0, 1024, 928, ENTITY_TILESET_A, 0, 1 },
        {LEVEL_ENTITY, 104, 0, 1056, 928, ENTITY_TILESET_A, 0, 1 },
      },
      {
        {LEVEL_METADATA, 7, 7, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 7, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 7, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 8, 4, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 105, 0, 96, 1120, ENTITY_TILESET_A, 0, 1 },
        {LEVEL_ENTITY, 106, 0, 128, 1120, ENTITY_TILESET_A, 0, 1 },
        {LEVEL_ENTITY, 107, 0, 96, 1088, ENTITY_TILESET_A, 0, 1 },
        {LEVEL_ENTITY, 108, 0, 128, 1088, ENTITY_TILESET_A, 0, 1 },
      },
      {
        {LEVEL_METADATA, 1, 8, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 2, 8, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 3, 8, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 4, 8, 2, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 109, 0, 672, 1120, ENTITY_TILESET_A, 0, 1 },
        {LEVEL_ENTITY, 110, 0, 704, 1120, ENTITY_TILESET_A, 0, 1 },
      },
      {
        {LEVEL_METADATA, 5, 8, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 6, 8, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 7, 8, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 8, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 8, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 9, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 9, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 2, 9, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 3, 9, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 4, 9, 2, 0, 0, 0, 0 },
        {LEVEL_ENTITY, 111, 0, 672, 1152, ENTITY_TILESET_A, 0, 1 },
        {LEVEL_ENTITY, 112, 0, 704, 1152, ENTITY_TILESET_A, 0, 1 },
      },
      {
        {LEVEL_METADATA, 5, 9, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 6, 9, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 7, 9, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 9, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 9, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 10, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 10, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 2, 10, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 3, 10, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 4, 10, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 5, 10, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 6, 10, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 7, 10, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 10, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 10, 0, 0, 0, 0, 0 }
      },
    },
    {
      {
        {LEVEL_METADATA, 0, 11, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 1, 11, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 2, 11, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 3, 11, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 4, 11, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 5, 11, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 6, 11, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 7, 11, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 8, 11, 0, 0, 0, 0, 0 }
      },
      {
        {LEVEL_METADATA, 9, 11, 0, 0, 0, 0, 0 }
      },
    },
  }
};


void LIB_read_level_blueprint(
    level_blueprint_t* blueprint
) {
    if (blueprint) {
        printf("LEVEL BLUEPRINT ID = %d read\n", blueprint->id);
    }
    levels_library[blueprint->id]      = blueprint;
};

void LIB_create_levels_library(
) {
    LIB_read_level_blueprint(&level_blueprint_new);
};

