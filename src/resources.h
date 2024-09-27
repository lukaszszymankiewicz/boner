#ifndef RESOURCES_H
#define RESOURCES_H

#define MAX_RESOURCES 10

enum DATA_TYPE {
    DATA_TYPE_TEXTURE,
    DATA_TYPE_TABLE,
    DATA_TYPE_ALL
};

typedef struct data {
    int   idx;
    int   type;
    int   width;
    char* path;
} data_t;

extern void* resources[MAX_RESOURCES];

void RES_read_resources(data_t *datas, int n_data);
void RES_free_resources(data_t *datas, int n_data);

#endif
