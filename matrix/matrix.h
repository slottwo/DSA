typedef struct matrix Matrix;

int check(Matrix *, int);
Matrix *create(int, int);
void destroy(Matrix *);
float read(Matrix *, int, int);
void write(Matrix *, int, int, float);
int rows(Matrix *);
int columns(Matrix *);