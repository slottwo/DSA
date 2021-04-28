#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "list.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    List *list01;
    list01 = create_ls();
    printf("List successfully created\n");
    
    printf("Tentando remover arquivo na lista vazia propositalmente.\n");
    remove_ls(list01);

    Data *temp;
    Data *result;
    
    printf("Criando Pedro, id = 0\n");
    temp = create_dt(0, "Pedro");
    
    printf("Inserindo Pedro\n");
    if (insert_ls(list01, *temp) == 1) { printf("Inserido com sucesso.\n"); }
    
    printf("Criando Rafaela, id = 4\n");
    temp = create_dt(4, "Rafaela");
    
    printf("Inserindo Rafaela\n");
    if (insert_ls(list01, *temp) == 1) { printf("Inserido com sucesso.\n"); }
    
    printf("Criando Allyson, id = 3\n");
    temp = create_dt(3, "Allyson");

    printf("Inserindo Allyson\n");
    if (insert_ls(list01, *temp) == 1) { printf("Inserido com sucesso.\n"); }
    
    free(temp);

    printf("Procurando pelo id = 3\n");
    if (access_ls_by_id(list01, 3, result)) { printf("Acessado com sucesso.\n"); }
    
    printf("Exibindo resultado da busca (falso): ");
    char* name;
    strcpy(name, "Nome");
    printf("%s\n", name);
    printf("Exibindo resultado da busca: ");
    printf("%s\n", result->name);
    printf("Exibiu?\n");

    // printf("Procurando por Rafaela\n");
    // if (access_ls_by_name(list01, "Rafaela", result)) { printf("Acessado com sucesso.\n"); }
    
    // printf("Exibindo resultado da nova busca");
    // printf("%d", result->id);

    // free(result);

    return 0;
}