#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct element
{
    Data value;
    Element *next;
};

int check (void *pointer)
{
    return pointer == NULL;
}

List* create_ls ()
{
    List *ls;
    ls = (List*)malloc(sizeof(List));
    if (check(ls)) { printf("List not created.\n"); return NULL; }
    *ls = NULL;
    return ls;
}

Data* create_dt (int id, char* name)
{
    Data* new_dt = (Data*)malloc(sizeof(Data));
    new_dt->id = id;
    strcpy(new_dt->name, name);
    return new_dt;
}

/*
int access_ls (List* ls, Data target, int is_id, Data* caught)
{
    if (check(ls)) { printf("List not exist to be acessed.\n"); return 0; }
    if (check(*ls)) { printf("List is empty.\n"); return 0; }
    
    Element *researcher;
    researcher = *ls;

    if (is_id) {
        while (!check(researcher) && researcher->value.id != target.id)
        {
            researcher = researcher->next;
        }
    }
    else {    
        while (!check(researcher) && researcher->value.name != target.name)
        {
            researcher = researcher->next;
        }
    }

    if (check(researcher))
    {
        printf("Element not found.\n");
        // free(researcher);
        return 0;
    }
    
    *caught = researcher->value;
    
    if (check(caught)) { printf("Search result not returned."); return 0; }
    
    free(researcher);
    
    return 1;
}
*/

int access_ls_by_id (List *ls, int id, Data *caught)
{
    if (check(ls)) { printf("List not exist to be acessed.\n"); return 0; }
    if (check(*ls)) { printf("List is empty.\n"); return 0; }
    
    Element *researcher;
    researcher = *ls;
    
    while (!check(researcher) && researcher->value.id != id)
    {
        researcher = researcher->next;
    }

    if (check(researcher)) { printf("Element not found.\n"); free(researcher); return 0; }
    
    caught = &(researcher->value);
    
    if (check(caught)) { printf("Search result not returned."); return 0; }
    
    free(researcher);
    
    return 1;
}

int access_ls_by_name (List* ls, char* name, Data* caught)
{
    if (check(ls)) { printf("List not exist to be acessed.\n"); return 0; }
    if (check(*ls)) { printf("List is empty.\n"); return 0; }
    
    Element *researcher;
    researcher = *ls;

    while (!check(researcher) && researcher->value.name != name)
    {
        researcher = researcher->next;
    }

    if (check(researcher)) { printf("Element not found.\n"); free(researcher); return 0; }
    
    caught = &(researcher->value);;
    
    if (check(caught)) { printf("Search result not returned."); return 0; }
    
    free(researcher);
    
    return 1;
}

int insert_ls (List* ls, Data new_value)
{
    if (check(ls)) { printf("List not exist to be edited.\n"); return 0; }
    Element *new_element;
    new_element = (Element*)malloc(sizeof(Element));

    if (check(new_element)) { printf("It was not possible to create a new element for the list"); return 0; }

    new_element->value = new_value;
    new_element->next = *ls;
    *ls = new_element;
    return 1;
}


int remove_ls (List* ls)
{
    if (check(ls)) { printf("List not exist to be edited.\n"); return 0; }
    if (check(*ls)) { printf("List is empty.\n"); return 0; }
    Element *phantom = *ls;
    *ls = phantom->next;
    free(phantom);
    return 1;
}


int destroy_ls (List* ls)
{
    if (check(ls)) { printf("List not exist to be destroyed.\n"); return 0; }
    free(ls);
}