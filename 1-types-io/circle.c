//
// Created by hfwei on 2023/9/21.
//

#include <stdio.h>

int main(void) {
  // const: constant
  const double PI = 3.14159;

  int radius = 10;

  double circumference = 2 * PI * radius;

  double area = PI * radius * radius;

  /*
   *  format is composed of zero or more directives:
   *    ordinary characters and conversion specifications introduced by %
   */
  printf("radius = %d\ncircumference = %.2f\narea = %.2f\n",
         radius, circumference, area);

  return 0;
}