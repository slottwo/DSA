#include <stdio.h>
#include <stdlib.h>
#include "point.h"

struct point
{
  float x;
  float y;
};

Point *create(float x, float y)
{
  Point *p;
  p = (Point *)malloc(sizeof(Point));
  if (p == NULL)
  {
    printf("Memory error");
    exit(1);
  }
  p->x = x;
  p->y = y;
}

void destroy(Point *p)
{
  free(p);
}

void access(Point *p, float *x, float *y)
{
  *x = p->x;
  *y = p->y;
}

void assing(Point *p, float x, float y)
{
  p->x = x;
  p->x = y;
}
