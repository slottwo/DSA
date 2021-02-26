#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Declara as variáveis internas da estrutura "Matrix" (struct matrix)
struct matrix {
    int len_rows;
    int len_columns;
    float **values;
};

// Função pointeiro do tipo Matriz, retorna uma matriz de dimensões rows X
Matrix* create_matrix (int rows, int columns) {
    int i, j;
    Matrix *new_mat;
    
    new_mat = (Matrix*)malloc(sizeof(Matrix));
    if (new_mat == NULL) {
        printf("Unallocated matrix.\n");
        exit(1);
    }
    
    new_mat->len_rows = rows;
    new_mat->len_columns = columns;
    new_mat->values = (float**)malloc(rows*sizeof(float*));

    for (i = 0; i < rows; i++) {
        new_mat->values[i] = (float*)malloc(columns*sizeof(float));
        if (new_mat->values[i] == NULL) {
            printf("Unallocated row.\n");
            exit(1);
        }
        for (j = 0; j < columns; j++) {
            new_mat->values[i][j] = 0;
        }
    }
    return new_mat;
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
