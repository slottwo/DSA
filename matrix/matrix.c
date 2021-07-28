#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct matrix
{
  int rows;
  int columns;
  float **values;
};

typedef struct matrix Matrix;

int check(Matrix *m, int quit)
{
  if (quit && m == NULL)
  {
    printf("Memory error");
    exit(1);
  }
  return m == NULL;
}

Matrix *create(int r, int c)
{
  if (r < 0 || c < 0)
  {
    printf("Invalid rows or columns length");
    exit(1);
  }

  Matrix *m;
  m = (Matrix *)malloc(sizeof(Matrix));
  check(m, 1);
  m->rows = r;
  m->columns = c;
  m->values = (float **)malloc(r * sizeof(float *));
  for (int i = 0; i < r; i++)
  {
    m->values[i] = (float *)malloc(c * sizeof(float));
    for (int j = 0; j < c; j++)
    {
      m->values[i][j] = 0.0;
    }
  }
  return m;
  // check(m->values, 1);
}

void destroy(Matrix *m)
{
  for (int i = 0; i < rows(m); i++)
  {
    free(m->values[i]);
  }
  free(m->values);
  free(m);
}

float read(Matrix *m, int r, int c)
{
  check(m, 1);
  if (r < 0 || c < 0 || r > rows(m) || c > rows(m))
  {
    printf("Index out of matrix");
    exit(1);
  }
  return (m->values[r][c]);
}

void write(Matrix *m, int r, int c, float value)
{
  check(m, 1);
  if (r < 0 || c < 0 || r > rows(m) || c > rows(m))
  {
    printf("Index out of matrix");
    exit(1);
  }
  m->values[r][c] = value;
}

int rows(Matrix *m)
{
  return m->rows;
}

int columns(Matrix *m)
{
  return m->columns;
};