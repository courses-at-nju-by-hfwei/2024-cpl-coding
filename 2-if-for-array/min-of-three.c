#include <stdio.h>

int main(void) {
  int a = 0;
  int b = 0;
  int c = 0;

  scanf("%d%d%d", &a, &b, &c);

  // TODO: calculate the minimum of a, b and c
  int min = 0;

  if (a > b) {
    if (b > c) {
      min = c;
    } else {  // b <= c and b < a
      min = b;
    }
  } else {  // a <= b
    if (a < c) {
      min = a;
    } else {  // c <= a <= b
      min = c;
    }
  }

  printf("min(%d, %d, %d) = %d\n", a, b, c, min);

  return 0;
}