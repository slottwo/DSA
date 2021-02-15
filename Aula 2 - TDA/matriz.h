typedef struct matriz Matriz;

Matriz* cria (int, int);

void libera (Matriz*);
void acessa (Matriz*, float*, float*);
void atribui (Matriz*, float, float);
int linhas (Matriz* mat);
int colunas (Matriz* mat);