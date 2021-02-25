#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct matrix {
    int len_rows;
    int len_columns;
    float **values;
};

Matrix* create_matrix (int rows, int columns) {
    int i, j;
    Matrix *mat;
    
    mat = (Matrix*)malloc(sizeof(Matrix));
    if (mat == NULL) {
        printf("Unallocated matrix.\n");
        exit(1);
    }
    
    mat->len_rows = rows;
    mat->len_columns = columns;
    mat->values = (float**)malloc(rows*sizeof(float*));

    for (i = 0; i < rows; i++) {
        mat->values[i] = (float*)malloc(sizeof(float));
        if (mat->values[i] == NULL) {
            printf("Unallocated row.\n");
            exit(1);
        }
        for (j = 0; i < columns; i++) {
            mat->values[i][j] = 0.0;
        }
    }
    return mat;
}

void free_matrix (Matrix* mat) {
    if (mat != NULL) {
        int i;
        for (i = 0; i < rows(mat); i++) {
            free(mat->values[i]);
        };
        free(mat->values);
        free(mat);
    }
};

float access_matrix (Matrix* mat, int row, int column) {
    if (mat == NULL) {
        printf("Non-existent matrix.\n");
        exit(1);
    }
    else if (row < 0 || row >= rows(mat))
    {
        printf("Invalid line index.\n");
        exit(1);
    }
    else if (column < 0 || column >= columns(mat))
    {
        printf("Invalid column index.\n");
        exit(1);
    }
    else {
        return mat->values[row][column];
    }
}

void attach_matrix (Matrix* mat, int row, int column, float value) {
    if (mat == NULL) {
        printf("Non-existent matrix.\n");
        exit(1);
    }
    else if (row < 0 || row >= rows(mat))
    {
        printf("Invalid line index.\n");
        exit(1);
    }
    else if (column < 0 || column >= columns(mat))
    {
        printf("Invalid column index.\n");
        exit(1);
    }
    else {
        mat->values[row][column] = value;
    }
}

int rows (Matrix* mat) {
    if (mat != NULL) {
        return mat->len_rows;
    }
}

int columns (Matrix* mat) {
    if (mat != NULL) {
        return mat->len_columns;
    }
}
