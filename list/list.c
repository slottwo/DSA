#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct element
{
    Data value;
    
    Element *next;
};


List* create ()
{
    List *l;
    l = (List*)malloc(sizeof(List));
    if (l == NULL)
    {
        printf("List not created");
        exit(1);
    }
    return l;
}

