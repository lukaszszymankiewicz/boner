#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "datatable.h"
#include "macros.h"
#include "symbols.h"

#define BASE_ROWS    10
#define MAX_ROWS     2000
#define HASHMAP_SIZE 4157

int hash(
    int key
) {
    return key % HASHMAP_SIZE;
}

hashmap_t* map_init(
) {
    hashmap_t* map = malloc(sizeof(hashmap_t));
    map->entries   = calloc(HASHMAP_SIZE, sizeof(hashentry_t));
    map->size      = HASHMAP_SIZE;

    return map;
}

void map_set(
    hashmap_t* map,
    int        key,
    int        value
) {
    int idx = hash(key);
    
    while ((map->entries[idx].fill) && (map->entries[idx].key != key)) {
        idx = (idx + 1) % map->size;
    }

    map->entries[idx].key   = key;
    map->entries[idx].value = value;
    map->entries[idx].fill  = true;
}

int map_get(
    hashmap_t* map,
    int        key
) {
    int idx = hash(key);
    
    while (map->entries[idx].fill) {

        if (map->entries[idx].key == key) {
            return map->entries[idx].value;
        }

        idx = (idx + 1) % map->size;
    }

    return -1;
}

void map_delete(
    hashmap_t *map,
    int        key
) {
    int idx = hash(key);
    int i = 0;

    while ((map->entries[idx].fill) && (map->entries[idx].key != key)) {
        idx = (idx + 1) % map->size;

        if (map->entries[idx].key == key) {
            map->entries[idx].fill = false;
            map->size--;
            return;
        }
        i++;
    }
}

void DATATABLE_enlarge(
    datatable_t* table
) {
    table->entries = realloc(table->entries, sizeof(int*) * table->rows);

    for (int i=0; i<table->rows; i++) {
        if (i <= table->fill) {
            table->entries[i] = realloc(table->entries[i], sizeof(int) * table->cols);
        } else {
            table->entries[i] = malloc(sizeof(int) * table->cols);
        }
    }
}

datatable_t* DATATABLE_init(
    int cols
) {
    datatable_t* table = (datatable_t*)malloc(sizeof(datatable_t));
    table->map         = map_init();
    table->rows        = BASE_ROWS;
    table->fill        = -1;
    table->cols        = cols;
    table->entries     = (int**)malloc(sizeof(int*) * BASE_ROWS);
    table->last        = 0;

    for (int i=0; i<table->rows; i++) {
        table->entries[i] = (int*)malloc(sizeof(int) * table->cols);
    }

    return table;
}

int* DATATABLE_get_entry(
    datatable_t* table,
    int          key
) {
    assert(key >= 0);
    int entry = map_get(table->map, key);
    assert(key != -1);

    return table->entries[entry];
}

int* DATATABLE_create(
    datatable_t* table,
    int          key
) {
    if (table->fill+1 > table->rows) {
        table->rows *= 2;
        DATATABLE_enlarge(table);
    }
    assert(table->rows < MAX_ROWS);

    map_set(table->map, key, ++table->fill);
    table->entries[table->fill]  = (int*)malloc(sizeof(int) * table->cols);

    table->last = MAX(table->last, key);

    return DATATABLE_get_entry(table, key);
}

int DATATABLE_exist(
    datatable_t* table,
    int          key
) {
    assert(key >= 0);
    return map_get(table->map, key) != -1;
} 

int DATATABLE_get_val(
    datatable_t* table,
    int          key,
    int          idx
) {
    int entry = map_get(table->map, key);
    assert(idx <= table->cols);
    if (entry == -1) {
        printf("key=%d, idx=%d \n", key, idx);
    }
    assert(entry != -1);
    return table->entries[entry][idx];
}

void DATATABLE_set_val(
    datatable_t* table,
    int      key,
    int      idx,
    int      val
) {
    int entry = map_get(table->map, key);
    assert(idx<= table->cols);
    table->entries[entry][idx] = val;
}

void DATATABLE_del(
    datatable_t* table,
    int          key
) {
    int entry = map_get(table->map, key);

    assert(entry != -1);
    assert(entry <= table->rows);

    map_delete(table->map, entry);

    if (entry == table->rows) {
        free(table->entries[entry]);
        table->entries[entry] = NULL;
        free(table->entries[entry]);

        table->rows--;
    } else {
        // free the requested entry
        free(table->entries[entry]);
        table->entries[entry] = NULL;

        // table->entries[entry] = (int*)malloc(sizeof(int)*table->cols);
        table->entries[entry] = table->entries[table->rows-1];

        table->entries[table->rows-1] = NULL;

        table->rows--;
    }
}

void DATATABLE_move(
    datatable_t* table,
    int          from,
    int          to
) {
    int val = map_get(table->map, from);

    map_delete(table->map, from);
    map_set(table->map, to, val);
}

datatable_t* DATATABLE_fill(
    base_int *data,
    int      width
) {
    datatable_t *table = NULL;
    table              = DATATABLE_init(TABLEWIDTH);
    
    ASSERT_RANGE(0, width, MAX_DATA_WIDTH);

    for (int i=0; i<width; i++) {
        
        int key    = data[i * TABLEWIDTH + 0];
        int label  = data[i * TABLEWIDTH + 1];
        int ref_a  = data[i * TABLEWIDTH + 2];
        int ref_b  = data[i * TABLEWIDTH + 3];
        int val    = data[i * TABLEWIDTH + 4];

        DATATABLE_create(table, key);

        DATATABLE_set_val(table, key, DATA_COL_A, label);
        DATATABLE_set_val(table, key, DATA_COL_B, ref_a);
        DATATABLE_set_val(table, key, DATA_COL_C, ref_b);
        DATATABLE_set_val(table, key, DATA_COL_D, val);
        DATATABLE_set_val(table, key, DATA_COL_KEY, key);
    }

    return table;
}

int DATATABLE_last(
    datatable_t* table
) {
    return table->last;
}

datatable_t* DATATABLE_deserialize(
    char        *path,
    int          width,
    int          idx
) {
    FILE *bpt;
    bpt = fopen(path, "rb");

    if (!bpt) {
        printf("read error, file %s cannot be found \n", path);
    }

    int elems = width * TABLEWIDTH;
    int elems_size = elems * sizeof(base_int);

    base_int *resource = NULL;
    resource = (base_int*)malloc(elems_size);

    int elem_read = fread(resource, sizeof(base_int), elems, bpt);

    if (elem_read != elems) {
        printf("read error, elems read = %d (from %d), from file %s \n", elem_read, elems, path);

        if(feof(bpt))
            printf("Premature end of file %s \n", path);
        else
            printf("File read error %s \n", path);
    }

    fclose(bpt);

    datatable_t* data = NULL;
    data = DATATABLE_fill((base_int*)resource, width);

    return data;
}
void map_free(
    hashmap_t* map
) {
    free(map->entries);
    free(map);
}

void DATATABLE_free(
    datatable_t* table
) {
    map_free(table->map);
    table->map = NULL;
    
    for (int i=0; i<table->rows; i++) {
        free(table->entries[i]);
        table->entries[i] = NULL;
    }

    free(table);
    table = NULL;
}
