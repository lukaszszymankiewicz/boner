#include <stdio.h>

#include "resources.h"
#include "datatable.h"

#include "obscura/texture.h"

void* resources[MAX_RESOURCES];

// TODO: where is freeing the resources?
void RES_read_resources(
    data_t *datas,
    int n_data
) {
    for (int n=0; n<n_data; n++) {
        switch (datas[n].type)

        {
            case DATA_TYPE_TABLE:
                resources[n] = DATATABLE_deserialize(datas[n].path, datas[n].width, datas[n].idx);
                break;
            case DATA_TYPE_TEXTURE:
                resources[n] = TEX_read_texture(datas[n].path, datas[n].idx);
                break;
        }

        printf("[RESOURCE (%s) read]\n", datas[n].path);
    }
};
