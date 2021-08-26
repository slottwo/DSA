#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node
{
  struct data value;
  struct node *next;
};

typedef struct node Node;


int isNull(void *p)
{
  return p == NULL;
}


List* createList()
{
  List *new_list;
  new_list = (List *)malloc(sizeof(List));
  if (isNull(new_list)) { printf("Memory error\n"); return NULL; }
  *new_list = NULL;
  return new_list;
}


void freeList(List *list)
{
  if(!isNull(list))
  {
    Node *element;
    while (!isNull(*list))
    {
      element = *list;
      *list = (*list)->next;
      free(element);
    }
    free(list);
  }
}


int isEmpty(List *list)
{
  if (isNull(list)) { printf("Inexistent list\n"); return -1; }
  return isNull(*list);
}


int length(List *list)
{
  // Checkup
  if (isNull(list)) { return -1; }  // Check if list exists
  if (isEmpty(list)) { return 0; }  // If list is empty, length = 0
  
  // Defining variables
  int count = 0;
  Node *pathfinder = *list;  // Set pathfinder to 1st position
  
  // Scrolling through list
  while (!isNull(pathfinder))
  {
    count++;  // Counting elements
    pathfinder = pathfinder->next;  // Set to next postion
  }
  
  return count;
}


int insertTop(List *list, Data value)
{
  // Checup
  if (isNull(list)) { printf("Inexistent list\n"); return 0; }

  // Defining variables
  Node *new_element = (Node *)malloc(sizeof(Node));
  if (isNull(new_element)) { printf("Memory error\n"); return 0; }  // Check new_element creation
  new_element->value = value;  // Fill element
  
  // Insertion
  new_element->next = *list;  // Set the 1st/NULL(if list is empty) to next of new_element
  *list = new_element;  // Set the new_element as 1st
  return 1;
}


int insertBot(List *list, Data value)
{
  // Checkup
  if (isNull(list)) { printf("Inexistent list\n"); return 0; }
  
  // Defining variables
  Node *new_element = (Node *)malloc(sizeof(Node));
  if (isNull(new_element)) { printf("Memory error\n"); return 0; }  // Check new_element creation
  new_element->value = value;  // Fill element
  new_element->next = NULL;  // Set NULL(end) to next of new_element

  // If no has nodes, just like `insertTop`
  if (isEmpty(list)) { *list = new_element; return 1; }
  
  // Else
  Node *pathfinder = *list;
  while (isNull(pathfinder->next))  // Scrolling through list to find the last node
  {
    pathfinder = pathfinder->next;
  }
  pathfinder->next = new_element;  // Set new_element at the list's end, using the penultimate
  
  return 1;
}


int removeTop(List *list)
{
  // Checkup
  if (isNull(list)) { printf("Inexistent list\n"); return 0; }

  // Defining variables
  Node *to_be_deleted = *list;

  // Set te top to 2nd element
  *list = to_be_deleted->next;
  
  // Free auxiliar element
  free(to_be_deleted);

  return 1;
}

int removeBot(List *list)
{
  // Checkup
  if (isNull(list)) { printf("Inexistent list\n"); return 0; }

  // Defining variables
  Node *to_be_deleted = *list;

  // Set te top to 2nd element
  *list = to_be_deleted->next;
  
  // Free auxiliar element
  free(to_be_deleted);
}

int removeById(List *list, int);

int insertOrderly(List *list, Data value)
{
  // Checkup
  if (isNull(list)) { printf("Inexistent list\n"); return 0; }
  
  // Defining variables
  Node *new_element = (Node *)malloc(sizeof(Node));
  if (isNull(new_element)) { printf("Memory error\n"); return 0; }  // Check new_element creation
  new_element->value = value;  // Fill element
  
  // If no has nodes, just like `insertTop`
  if (isEmpty(list)) { new_element->next = *list; *list = new_element; return 1; }

  // Else
  Node *pathfinder = *list;  // A auxiliar node
  while (new_element->value.id < pathfinder->next->value.id)  // Scrolling through list to find a bigger element
  {
    pathfinder = pathfinder->next;
  }
  new_element = pathfinder->next;
  pathfinder->next = new_element;
  
  // Set new_element at the list's end, using the penultimate
  return 1;
}


int findOne(List *list, int id, Data *value)
{
  // Checkup
  if (isEmpty(list)) { return NULL; }
  
  // Defining variables
  Data *value; value = NULL;
  Node *pathfinder = *list; // Set pathfinder to 1st position
  
  // Scrolling through list to find the Node with targeted id
  do
  {
    if (pathfinder->value.id == id) { *value = pathfinder->value; break; }
    pathfinder = pathfinder->next;
  } while (!isNull(pathfinder));
  
  return value;
}


int accessByIndex(List *list, int index, Data *value)
{
  // Checkup
  if (isEmpty(list)) { return NULL; }
  
  // Defining variables
  Node *pathfinder = *list;  // Set pathfinder to 1st position

  for (int i = 0; i < index; i++)  // Ends in penultimate position
  {
    pathfinder = pathfinder->next;  // Set to next postion
    if (!isNull(pathfinder)) { printf("Index out of range\n"); return 0; }  // Get out when is in end of list
  }

  *value = pathfinder->value;  // Return by pointer

  return 1;
}


int printList(List *list)
{
  if (isNull(list)) { printf("Inexistent list\n"); return 0; }
  if (isEmpty(list)) return 1;
  
  Node *reader = *list;
  while (!isNull(reader))
  {
    printf("%s -> ", reader->value.name);
    reader = reader->next;
  }
  printf("END\n");

  return 1;
}
