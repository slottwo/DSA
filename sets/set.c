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
    check_set(new_set);

    new_set->lenght = 0;
    new_set->values = (int*)malloc(10*sizeof(int));
    if (new_set->values == NULL) { printf("Unallocated int vetor!"); exit(1); }

    return new_set;
}

int check_set (Set *set_a)
{
    if (set_a != NULL) {
        return 1;
    }
    printf("Unallocated Set!"); exit(1);
}

int check_sets (Set *set_a, Set *set_b)
{
    if (set_a != NULL && set_b != NULL) {
        return 1;
    }
    printf("Unallocated Sets!"); exit(1);
}

void free_set (Set *set_to_destroy)
{
    check_set(set_to_destroy);
    free(set_to_destroy->values);
    free(set_to_destroy);
}

int lenght_set (Set *set_a)
{
    check_set(set_a);
    return set_a->lenght;
}
