#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "matrix.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    float value;

    printf("Declarando a matriz: \"mat\"\n");
    struct matrix *mat;
    
    printf("Criando o conteúdo da matriz: \"mat\"\n");
    mat = create_matrix(2, 2);
    
    printf("Linhas: %d\n", rows(mat));
    printf("Colunas: %d\n", columns(mat));
    
    printf("Acessando a célula (1,2): %.2f\n", access_matrix(mat, 0, 1));
    
    printf("Modificando a célula (1,2): ");
    scanf("%f", &value);
    attach_matrix(mat, 0, 1, value);

    printf("Reacessando a célula (1,2): %.2f\n", access_matrix(mat, 0, 1));
    
    printf("Destruindo a matriz: \"mat\"\n");
    free_matrix(mat);
    
    return 0;
}
