#include "../datatable.h"

#ifndef BPT_H
#define BPT_H

typedef base_int blueprint_t[][TABLEWIDTH];

void BPT_create_entity_library();
void BPT_create_levels_library();
void BPT_serialize(blueprint_t bpt, char *path, int width);

#endif
