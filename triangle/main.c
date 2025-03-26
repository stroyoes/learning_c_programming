#include <stdio.h>

#include "triangle.h"

static void show_err() {
  printf("\nERROR: Expected atleast one float value for the triangle side.");
}

int main() {
  triangle_t sides;

  printf("Enter the value of side 'a': ");
  if (scanf("%lf", &sides.a) != 1) {
    show_err();
    return -1;
  }

  printf("Enter the value of side 'b': ");
  if (scanf("%lf", &sides.b) != 1) {
    show_err();
    return -1;

  }

  printf("Enter the value of side 'c': ");
  if (scanf("%lf", &sides.c) != 1) {
    show_err();
    return -1;
  }

  printf("\nThe traingle is (%f, %f, %f) .\nIt is %s .\n",sides.a, sides.b, sides.c, is_equilateral(sides) ? "equilateral and isosceles" : is_isosceles(sides) ? "isosceles" : is_scalene(sides) ? "scalene" : "an invalid triangle");

  return 0;
}
