#include <stdbool.h>
#include <stdint.h>

#ifndef LEVEL_H
#define LEVEL_H

#define MAX_DATA_WIDTH   1000
#define TABLEWIDTH       5 

typedef int32_t base_int;

typedef struct {
    int  key;
    int  value;
    bool fill;
} hashentry_t;

typedef struct {
    hashentry_t* entries;
    int          size;
} hashmap_t;

typedef struct {
    hashmap_t*    map;
    base_int**     entries;
    int           fill;
    int           cols;
    int           rows;
    int           last;
} datatable_t;

enum LEVEL_DATA {
    ID            = 0,
    LEVEL_WIDTH   = 1,
    LEVEL_SIZE_X  = 2,
    LEVEL_SIZE_Y  = 3,
    LEVEL_FOCUS_X = 4,
    LEVEL_FOCUS_Y = 5,
    MAP           = 6,
    METADATA      = 7,
    ENTITY_DATA   = 8,
    ENTITY_NTH    = 9,
    BEHAVIOUR     = 10
};

enum LEVEL_DATA_ENTRIES {
    DATA_COL_A,
    DATA_COL_B,
    DATA_COL_C,
    DATA_COL_D,
    DATA_COL_KEY,
    DATA_COL_ALL
};

datatable_t* DATATABLE_fill(base_int *data, int width);

int* DATATABLE_get_entry(datatable_t* table, int key);
int* DATATABLE_create(datatable_t* table, int key);

int DATATABLE_exist(datatable_t* table, int key);
int DATATABLE_get_val(datatable_t* table, int key, int idx);

int DATATABLE_last(datatable_t* table);

void DATATABLE_set_val(datatable_t* table, int key, int idx, int val);
void DATATABLE_free(datatable_t* table);
void DATATABLE_del(datatable_t* table, int key);
void DATATABLE_move(datatable_t* table, int from, int to);

datatable_t* DATATABLE_deserialize(char *path, int width, int idx);

// TODO: this should be moved to appriopirate modules
typedef datatable_t* level_t;
typedef datatable_t* entity_t;

#endif
