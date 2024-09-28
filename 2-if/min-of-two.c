//
// Created by hfwei on 2023/10/6.
//

#include <stdio.h>

int main(void) {
  int a = 0;
  int b = 0;

  scanf("%d%d", &a, &b);

  // TODO: calculate the minimum of a and b
  // code style: space, {, newline, tab vs. spaces
  // do not ignore { } for single-line statements
  // google format, format on save
  // ?:
  int min = 0;
  if (a >= b) {
    min = b;
  } else {
    min = a;
  }

  // conditional operator, ternary operator
  // int min = a >= b ? b : a;

  printf("min(%d, %d) = %d\n", a, b, min);

  return 0;
}