#include <stdlib.h>
#include "matriz.h"

struct matriz
{
    int linhas;
    int colunas;
    float **valores;
};

Matriz* cria (int linhas, int colunas) {
    Matriz *mat;
    mat = (Matriz*)malloc(sizeof(Matriz));
    if (mat == NULL) { printf("Oops! l.14"); exit(1); }
    mat->linhas = linhas;
    mat->colunas = colunas;
    mat->valores = (float *)malloc(colunas*sizeof(float));
    if (mat == NULL) { printf("Oops!"); exit(1); }
    for (int i = 0; i < linhas; i++) {
        mat->valores[i] = (float *)malloc(colunas*sizeof(float));
        if (mat == NULL) { printf("Oops!"); exit(1); }
    }
}
void libera (Matriz* mat) {
    if (mat != NULL) {
        // for (int i = 0; i < )
        // free(mat->valores[i]);
        free(mat);
    }
};
void acessa (Matriz* mat, float linha, int coluna) {
    if (mat == NULL) { printf("Oops!"); exit(1); }    
};
void atribui (Matriz*, float, float);
int linhas (Matriz* mat) {
    return 0;
}
int colunas (Matriz* mat) {
    return 0;
}