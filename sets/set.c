#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct set
{
    int lenght;
    int *values;
};

Set* create_set ()
{
    Set *new_set;

    new_set = (Set*)malloc(sizeof(Set));
    check_pointer(VALUE_set, (Pointer){new_set});

    new_set->lenght = 0;
    new_set->values = (int*)malloc(10*sizeof(int));
    if (check_set(new_set)) { printf("Unallocated set!"); exit(1); }

    return new_set;
}

int check_set(Set *set_a)
{
    return set_a != NULL;
}

int check_sets(Set *set_a, Set *set_b)
{
    return !(set_a == NULL || set_b == NULL);
}
