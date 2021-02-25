typedef struct matrix Matrix;

Matrix* create_matrix (int, int);
void free_matrix (Matrix*);
float access_matrix (Matrix*, int, int);
void attach_matrix (Matrix*, int, int, float);
int rows (Matrix*);
int columns (Matrix*);
