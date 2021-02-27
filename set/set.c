#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct set
{
    int length;
    float *values;
};

Set* create_set ()
{
    /* Create a new empty set by dynamic allocation

    Returns:
        Set*: New empty set pointer
    */
        
    Set *new_set;

    new_set = (Set*)malloc(sizeof(Set));
    check_set(new_set, 1);

    new_set->length = 0;
    new_set->values = (float*)malloc(10*sizeof(float));
    if ( new_set->values == NULL )
    {
        error_pointer("int[]");
    }

    return new_set;
}

Set* clone_set(Set *set_to_clone)
{
    check_set(set_to_clone, 1);

    Set* set_cloned;
    set_cloned = create_set();

    set_cloned->length = set_to_clone->length;
    for (int i = 0; i < set_to_clone->length; i++)
    {
        set_cloned->values[i] = set_to_clone->values[i];
    }
    
    return set_cloned;
}

void error_pointer (char type[])
{
    printf("Unallocated %s!\n", type); exit(1);
}

int check_set (Set *set_a, int quit)
{
    /* Verify a set pointer is valid
    
    Args:
        set_a (Set*): Set poiter to will be validated

    Returns:
        int: Integer boolean that represents if the pointer is valid
    */
    if ( set_a != NULL ) {
        return 1;
    }
    else if ( quit )
    {
        error_pointer("Set");
        exit(1);
    } // Else
    return 0;
}

int check_sets (Set *set_a, Set *set_b, int quit)
{
    /* Verify two set pointers are valid together

    Args:
        set_a (Set*): Set poiter to will be validated,
        set_b (Set*): Set poiter to will be validated

    Returns:
        int: Integer boolean that represents if the both pointers are valid. If not exit
    */
    if ( set_a != NULL && set_b != NULL ) {
        if (set_a->values != NULL && set_b->values != NULL) { 
            return 1;
        }
    } // Else
    else if ( exit )
    {
        error_pointer("Sets");
        exit(1);
    } // Else
    return 0;
}

int length_set (Set *set_a)
{
    /* Access the number of elements of a set

    Args:
        set_a (Set*): Pointer of a set to will be measured
    
    Returns:
        int: Number of elements of set_a
    */
    check_set(set_a, 1);
    return set_a->length;
}

int check_element(Set *set_a, float element)
{
    // For each element of the set verify if its is the new value
    for (int i = 0; i < length_set(set_a); i++)
    {
        if ( set_a->values[i] == element )
        {
            return 1;
        }
    }
    return 0;
}

int find_element(Set* set_a, float element)
{
    for (int i = 0; i < length_set(set_a); i++)
    {
        if ( set_a->values[i] == element )
        {
            return i;
        }
    }
    return -1;
}

void free_set (Set *set_to_destroy)
{
    /* Destroys a set pointer by releasing the element vector and the struct set itself

    Args:
        set_a (Set*): Set pointer
    */
    if (check_set(set_to_destroy, 0))
    {
        free(set_to_destroy->values);
        free(set_to_destroy);
    }
}

int attach_set(Set *set_to_modify, float new_value, int alert)
{
    /* Modify a set's element

    Args:
        set_to_modify (Set*): 
        new_value (float):

    Returns:
        int: Boolean integer that indicates if the element was modified or not
    */
    
    check_set(set_to_modify, 1);
    
    // Check if the set is not full
    if ( set_to_modify->length < 10 )
    {
        // Check if the element is in the set
        if ( check_element(set_to_modify, new_value) )
        {
            if ( alert ) printf("This value already exists in the set.\n");
            return 0;
        }
        set_to_modify->values[set_to_modify->length] = new_value;
        set_to_modify->length = set_to_modify->length + 1;
        return 1;
    }
    else
    {
        if ( alert ) printf("Set is full!\n");
        return -1;
    }
}

void remove_element(Set* set_a, float value_to_remove)
{
    check_set(set_a, 1);

    int value_index = find_element(set_a, value_to_remove);
    
    if ( value_index != -1 )
    {
        for (int i = value_index; i < set_a->length - 1; i++)
        {
            set_a->values[i] = set_a->values[i+1];
        }
        set_a->length = set_a->length - 1;
    }
}

void fill_set (Set *empty_set)
{
    /*
    Fill a set as a empty set, that is, 

    Args:
        empty_set (Set*): 
    
    Returns:
        void
    */
    check_set(empty_set, 1);
    
    float number;
    char answer;
    
    empty_set->length = 0;

    printf("Enter float numbers (max. 10)\n");

    // Loop up to 10 or until canceled
    for (int i = 0; i < 10; i++)
    {
        do
        {
            // Request the `number`
            printf("%d.: ", i+1);
            scanf("%f", &number);
            // Insert `number` in the set
        } while ( !attach_set(empty_set, number, 1) );

        // Continue?
        do
        {
            printf("Continue? [Y/n]");
            scanf(" %c", &answer);
        } while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');
        
        if (answer == 'Y' || answer == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
}

float access_set (Set *set_a, int index)
{
    /* Access a single set element.
    
    Args:
        set_a (Set*):
        index (int): Element position in the set.
    */
    check_set(set_a, 1);
    if (index < length_set(set_a))
    {
        return set_a->values[index];
    }
}

void print_set(Set *set_to_print)
{
    check_set(set_to_print, 1);
    int len = length_set(set_to_print);
    if ( len > 0 )
    {
        printf("{%.2f", access_set(set_to_print, 0));
        for (int i = 1; i < len; i++)
        {
            printf(", %.2f", access_set(set_to_print, i));
        }
        printf("}\n");
    }
    else
    {
        printf("{}\n");
    }
}

Set* inter_set(Set* set_a, Set* set_b)
{
    /* Takes the intersecion between two sets

    Args:
        set_a (Set*): First set to intersect
        set_b (Set*): Second set to intersect

    Returns:
        Set*: Intersection set
    */
    check_sets(set_a, set_b, 1);
    
    int i;
    float element;
    Set *inter;
    inter = create_set();

    // For each element of set_a
    for (i = 0; i < length_set(set_a); i++)
    {
        element = access_set(set_a, i);
        // Check if element is in set_b
        if ( check_element(set_b, element) )
        {
            // And add to intersection set
            attach_set(inter, element, 0);
        }
    }
    
    return inter;
}

Set* diff_set(Set* set_a, Set* set_b)
{
    /* Takes the differece between two sets

    Args:
        set_a (Set*): Minuend,
        set_b (Set*): Subtrahend

    Returns:
        Set*: Difference set
    */
    check_sets(set_a, set_b, 1);
    
    Set *diff, *inter;
    diff = clone_set(set_a);
    inter = inter_set(set_a, set_b);

    for (int i = 0; i < length_set(inter); i++)
    {
        remove_element(diff, access_set(inter, i));
    }
    
    free_set(inter);

    return diff;
}

Set* sum_set (Set *set_a, Set *set_b)
{
    /* Create a "sum set" (max 20)
    
    Args:
        set_a (Set*): ,
        set_b (Set*):
    
    Returns:
        Set*: "sum set"
    */
    
    int len_a = length_set(set_a);
    int len_b = length_set(set_b);
    Set* sum;
    sum = clone_set(set_a);

    sum->length = len_a + len_b;
    
    for (int i = 0; i < len_b; i++)
    {
        sum->values[len_a + i] = set_b->values[i];
    }

    return sum;
}

Set* union_set(Set* set_a, Set* set_b)
{
    /* Takes the union between two sets

    Args:
        set_a (Set*): First set to join
        set_b (Set*): Second set to join

    Returns:
        Set*: Union set
    */
    check_sets(set_a, set_b, 1);
    
    Set *us, *inter, *sum;
    inter = inter_set(set_a, set_b);
    sum = sum_set(set_a, set_b);

    if ( length_set(set_a) + length_set(set_b) - length_set(inter) > 10 )
    {
        printf("Union set out of limit!\n");
        exit(1);
    }
    
    us = diff_set(sum, inter);

    free_set(sum);
    free_set(inter);

    return us;
}

int sub_set(Set *set_a, Set *set_b)
{
    check_sets(set_a, set_b, 1);

    Set *inter;
    inter = inter_set(set_a, set_b);

    return length_set(inter) == length_set(set_a);
}

Set* comp_set(Set *set_a, Set *set_b)
{
    check_sets(set_a, set_b, 1);
    
    if ( sub_set(set_a, set_b) )
    {
        return diff_set(set_b, set_a);
    }
    else
    {
        return create_set();
    }
}
