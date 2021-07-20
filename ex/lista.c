#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Lista *criar()
{
    Lista *ldse;
    ldse = (Lista *)malloc(sizeof(Lista));
    if (ldse != NULL)
    {
        *ldse = NULL;
    }
    return ldse;
}

void destruir(Lista *ldse)
{
    if (ldse != NULL)
    {
        Elemento *aux;
        while (*ldse != NULL)
        {
            aux = *ldse;
            *ldse = (*ldse)->prox;
            free(aux);
        }
        //free(ldse);
    }
}

int inserirInicio(Lista *ldse, struct aluno novosdados)
{
    if (ldse == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL)
            return 0;
        novo->dados = novosdados;
        novo->prox = *ldse;
        *ldse = novo;
        return 1;
    }
}

int inserirFim(Lista *ldse, struct aluno novosdados)
{
    if (ldse == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL)
            return 0;
        novo->dados = novosdados;
        novo->prox = NULL;
        if (vazia(ldse))
        {
            *ldse = novo;
        }
        else
        {
            Elemento *aux = *ldse;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
        return 1;
    }
}

int inserirMeio(Lista *ldse, struct aluno novosdados)
{
    if (ldse == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL)
            return 0;
        novo->dados = novosdados;
        if (vazia(ldse) || (*ldse)->dados.matricula > novo->dados.matricula)
        {
            novo->prox = *ldse;
            *ldse = novo;
        }
        else
        {
            Elemento *ant = *ldse;
            Elemento *aux = ant->prox;
            while (aux != NULL && aux->dados.matricula < novo->dados.matricula)
            {
                ant = aux;
                aux = aux->prox;
            }
            ant->prox = novo;
            novo->prox = aux;
        }
        return 1;
    }
}

int removerInicio(Lista *ldse)
{
    if (vazia(ldse))
    {
        return 0;
    }
    else
    {
        Elemento *aux = *ldse;
        *ldse = aux->prox;
        free(aux);
        return 1;
    }
}

int removerFim(Lista *ldse)
{
    if (vazia(ldse))
    {
        return 0;
    }
    else if ((*ldse)->prox == NULL)
    {
        Elemento *aux = *ldse;
        *ldse = aux->prox;
        free(aux);
        return 1;
    }
    else
    {
        Elemento *ant = *ldse;
        Elemento *aux = ant->prox;
        while (aux->prox != NULL)
        {
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = aux->prox;
        free(aux);
        return 1;
    }
}

int removerMeio(Lista *ldse, int x)
{
    if (vazia(ldse))
    {
        return 0;
    }
    else if ((*ldse)->dados.matricula == x)
    {
        Elemento *aux = *ldse;
        *ldse = aux->prox;
        free(aux);
        return 1;
    }
    else
    {
        Elemento *ant = *ldse;
        Elemento *aux = ant->prox;
        while (aux != NULL && aux->dados.matricula != x)
        {
            ant = aux;
            aux = aux->prox;
        }
        if (aux == NULL)
            return 0;
        ant->prox = aux->prox;
        free(aux);
        return 1;
    }
}

int acessarIndice(Lista *ldse, int pos, struct aluno *a)
{
    if (vazia(ldse))
        return 0;
    else if (pos < 0)
        return 0;
    else
    {
        int cont = 0;
        Elemento *aux = *ldse;
        while (aux != NULL && pos != cont)
        {
            aux = aux->prox;
            cont++;
        }
        if (aux == NULL)
            return 0;
        *a = aux->dados;
        return 1;
    }
}

int acessarValor(Lista *ldse, int x, struct aluno *a)
{
    if (vazia(ldse))
        return 0;
    else
    {
        Elemento *aux = *ldse;
        while (aux != NULL && aux->dados.matricula != x)
        {
            aux = aux->prox;
        }
        if (aux == NULL)
            return 0;
        *a = aux->dados;
        return 1;
    }
}

int tamanho(Lista *ldse)
{
    if (vazia(ldse))
    {
        return 0;
    }
    int cont = 0;
    Elemento *aux = *ldse;
    while (aux != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int cheia(Lista *ldse)
{
    return 0;
}

int vazia(Lista *ldse)
{
    if (ldse == NULL)
    {
        return 1;
    }
    else if (*ldse == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
