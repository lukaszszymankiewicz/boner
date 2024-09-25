#include "library.h"

#include "../datatable.h"

#include <stdio.h>


void BPT_serialize(
    blueprint_t  bpt,
    char        *path,
    int          width
) {
    int elems = width * TABLEWIDTH;

    FILE *f;

    f = fopen(path, "wb");
    int written_elems = fwrite(bpt, sizeof(base_int), elems, f);
    printf("elems %d succesfully write to file %s \n", written_elems, path);

    if (written_elems != elems) {
        printf("write error, elems write = %d, to file %s \n", written_elems, path);
    }

    fclose(f);
}
