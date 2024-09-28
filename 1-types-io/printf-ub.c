// Created by hfwei on 2024/9/25.

#include <stdio.h>

int main(void) {
  // (printf-ub-1)
  int secret = 42;
  printf("secret = %f\n", secret);

  // (printf-ub-2)
  double pi = 3.14159;
  printf("pi = %d\n", pi);

  // (printf-ub-3)
  int light_speed = 299792458;
  printf("light_speed = %c\n", light_speed);

  return 0;
}