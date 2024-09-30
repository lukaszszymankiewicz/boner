#include <stdio.h>

#include "resources.h"
#include "datatable.h"

#include "obscura/texture.h"

void* resources[MAX_RESOURCES];

void RES_read_resources(
    data_t *datas
) {
    int n_data = datas[DATA_TYPE_METADATA].width;

    for (int n=0; n<n_data; n++) {
        int idx = n-1;

        switch (datas[n].type)

        {
            case DATA_TYPE_TABLE:
                resources[idx] = DATATABLE_deserialize(datas[n].path, datas[n].width, datas[n].idx);
                printf("[RESOURCE (%s) read]\n", datas[n].path);
                break;
            case DATA_TYPE_TEXTURE:
                resources[idx] = TEX_read_texture(datas[n].path, datas[n].idx);
                printf("[RESOURCE (%s) read]\n", datas[n].path);
                break;
            case DATA_TYPE_METADATA:
                break;
        }
    }
};

void RES_free_resources(
    data_t *datas
) {
    int n_data = datas[DATA_TYPE_METADATA].width;

    for (int n=0; n<n_data; n++) {
        int idx = n-1;

        switch (datas[n].type)
        {
            case DATA_TYPE_TABLE:
                DATATABLE_free(resources[idx]);
                printf("[RESOURCE (%s) freed]\n", datas[n].path);
                break;
            case DATA_TYPE_TEXTURE:
                TEX_free(resources[idx]);
                printf("[RESOURCE (%s) freed]\n", datas[n].path);
                break;
            case DATA_TYPE_METADATA:
                break;
        }
    }
};
