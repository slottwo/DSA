#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int main()
{
    List *list1, *list2;
    Data item1 = {.id=1}, item2 = {.id=3}, item3 = {.id=2};
    strcpy(item1.name, "I1"); strcpy(item2.name, "I2"); strcpy(item3.name, "I3");

    list1 = createList();
    list2 = NULL;  // Simulate a error

    printf("List 01 %ssuccessfully created\n\n", isEmpty(list1) > 0 ? "" : "un");
    printf("List 02 %ssuccessfully created\n\n", isEmpty(list2) > 0 ? "" : "un");

    printf("Item 01 %ssuccessfully inserted at end of list\n\n", insertBot(list1, item1) ? "" : "un");
    printf("Item 02 %ssuccessfully inserted at top of list\n\n", insertTop(list1, item2) ? "" : "un");
    printf("Item 03 %ssuccessfully inserted ordely into the list\n\n", insertOrderly(list1, item3) ? "" : "un");

    printf("List 01:\n");
    printList(list1);

    return 0;
}
