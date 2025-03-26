#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct {
  double a; //  NOTE: Higher precision makes `double` ideal for handling geometric calculations where accuracy matters
  double b;
  double c;
} triangle_t;

int is_equilateral(triangle_t sides);
int is_isosceles(triangle_t sides);
int is_scalene(triangle_t sides);

#endif


