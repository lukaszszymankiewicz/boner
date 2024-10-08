/* matrix manipulation code */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mat.h"

array_t* MAT_new(
    int rows, 
    int cols
) {
    array_t *arr  = NULL;
    arr           = (array_t*)malloc(sizeof(array_t));

    arr->rows     = rows;
    arr->cols     = cols;
    arr->cap      = arr->rows * arr->cols;

    arr->values   = NULL;
    arr->values   = (float*)malloc(sizeof(float) * arr->cap);

    memset(arr->values, 0.0, arr->cap);

    return arr;
}

int MAT_n(
    array_t* arr
) {
    return arr->rows * arr->cols;
}

int MAT_size(
    array_t* arr
) {
    return sizeof(float) * (arr->rows * arr->cols);
}

array_t *MAT_scalar_new(
    float a1
) {
    array_t *arr   = MAT_new(1, 1);
    arr->values[0] = a1;

    return arr;
}

array_t *MAT_vec2_new(
    float a1, float a2
) {
    array_t *arr   = NULL;
    arr            = MAT_new(2, 1);
    arr->values[0] = a1;
    arr->values[1] = a2;

    return arr;
}

array_t *MAT_vec4_new(
    float a1, float a2, float a3, float a4
) {
    array_t *arr   = MAT_new(4, 1);
    arr->values[0] = a1;
    arr->values[1] = a2;
    arr->values[2] = a3;
    arr->values[3] = a4;

    return arr;
}

void MAT_free(
    array_t *arr
) {
    if (arr == NULL) {
        return;
    }
    if (arr->values != NULL) {
        free(arr->values);
        arr->values = NULL;
    }
    free(arr);
    arr = NULL;
}

array_t* MAT_join(
    array_t *arr1,
    array_t *arr2
) {
    if (!arr2) {
        return arr1;
    }

    if (!arr1) {
        return arr2;
    }

    int new_rows = arr1->rows;
    int new_cols = arr1->cols + arr2->cols;
     
    array_t *new = NULL;
    new          = MAT_new(new_rows, new_cols);

    int i=0; 

    for (int r=0; r<new_rows; r++) {
        for (int c=0; c<arr1->cols; c++) {
            new->values[i++] = arr1->values[r*arr1->cols + c];
        }

        for (int c=0; c<arr2->cols; c++) {
            new->values[i++] = arr2->values[r*arr2->cols + c];
        }
    }
    MAT_free(arr1);
    MAT_free(arr2);

    return new;
}

array_t* MAT_append(
    array_t *arr1,
    array_t *arr2
) {
    if (!arr2) {
        return arr1;
    }

    if (!arr1) {
        return arr2;
    }

    array_t *new      = NULL;
    new               = MAT_new(arr1->rows + arr2->rows, arr1->cols);

    memcpy(new->values, arr1->values, sizeof(float) * arr1->cap);
    memcpy(new->values + arr1->cap, arr2->values, sizeof(float) * arr2->cap);

    MAT_free(arr1);
    MAT_free(arr2);

    return new;
}

void MAT_debug(
    array_t *arr
) {
    for (int r=0; r<arr->rows; r++) {
        for (int c=0; c<arr->cols; c++) {
            printf("%f ", arr->values[r*arr->cols + c]);
        }
        printf("\n");
    }
}
