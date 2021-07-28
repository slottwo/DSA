#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

typedef void (*function)();

int main()
{
  int i, j, r, c;
  float value;

  Matrix *neo;
  // Input: matrix length
  printf("Empty matrix [rows x columns]: ");
  scanf("%d x %d", &r, &c);
  neo = create(r, c);

  // Log: counting rows and columns
  printf("The matrix ins %d x %d.\n", rows(neo), columns(neo));

  // Print: matrix, still empty
  printf("\nMatrix:\n");
  for (i = 0; i < rows(neo); i++)
  {
    printf("| ");
    for (j = 0; j < columns(neo); j++)
    {
      printf("%.2f ", read(neo, i, j));
    }
    printf("|\n");
  }
  printf("\n");

  // Input: matrix values
  printf("Filling the matrix:\n");
  for (i = 0; i < rows(neo); i++)
  {
    for (j = 0; j < columns(neo); j++)
    {
      printf("(%d,%d): ", i + 1, j + 1);
      scanf("%f", &value);
      write(neo, i, j, value);
    }
  }

  // Output: Print: filled matrix
  printf("\nMatrix:\n");
  for (i = 0; i < rows(neo); i++)
  {
    printf("| ");
    for (j = 0; j < columns(neo); j++)
    {
      printf("%.2f ", read(neo, i, j));
    }
    printf("|\n");
  }
  printf("\n");

  // Free: matrix
  destroy(neo);

  // Exit
  return 0;
}
