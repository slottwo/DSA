#include <stdio.h>
#include <stdlib.h>
#include "set.h"


int main ()
{
    // i) Criar um conjunto vazio
    
    Set *A, *B;
    A = create_set();
    B = create_set();

    // ii) Preencher um conjunto inicialmente vazio (um conjunto não pode ter elementos repetidos)

    printf("\nFill set A.\n");
    fill_set(A);

    printf("\nFill set B.\n");
    fill_set(B);

    system("pause");
    system("clear");

    printf("\nA = ");
    print_set(A);
    
    printf("\nB = ");
    print_set(B);

    // iii) união de dois conjuntos (se a união estourar o limite de 10 posições essa operação dá um erro e não acontece);
    
    printf("\nA ∪ B = ");
    print_set(union_set(A, B));

    // iv) interseção de dois conjuntos;

    printf("\nA ∩ B = ");
    print_set(inter_set(A, B));

    // v) diferença entre dois conjuntos;

    printf("\nA - B = ");
    print_set(diff_set(A, B));

    // vi) verificar se um conjunto está contido no outro;

    printf("\nA %s B\n", sub_set(A, B) ? "⊂" : "⊄");
    printf("\nB %s A\n", sub_set(B, A) ? "⊂" : "⊄");

    // vii) conjunto complementar (use as funções vi e v para facilitar);

    printf("\n# C_X(Y): Complementary set of Y in relation to X\n");

    printf("\nC_B(A) = ");
    print_set(comp_set(A, B));

    printf("\nC_A(B) = ");
    print_set(comp_set(B, A));

    system("pause");
    return 0;
}
