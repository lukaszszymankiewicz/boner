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

    printf("[BLUEPRINT %s write]\n", path);
    f = fopen(path, "wb");
    int written_elems = fwrite(bpt, sizeof(base_int), elems, f);

    printf("    %d rows of data succesfully written \n", written_elems);

    if (written_elems != elems) {
        printf("    write error, rows of data written = %d\n", written_elems);
    }

    fclose(f);
}
