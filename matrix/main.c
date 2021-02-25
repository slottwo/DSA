#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    struct matrix *mat1;
    
    mat1 = create_matrix(1, 2);
    
    access_matrix(mat1, 1, 2);
    return 0;
}
