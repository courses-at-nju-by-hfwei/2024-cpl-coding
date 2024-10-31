// Created by hfwei on 2024/10/30.

#include <limits.h>
#include <stdio.h>

int main() {
  double pi = 3.14159;

  // below: obtain its fractional part
  double fraction = pi - (int)pi;

  int num = 100000000; // (9 digits)
  printf("LLONG_MAX = %lld\n", LLONG_MAX);
  long long llint = (long long)num * num;
  printf("i = %lld\n", llint);

  return 0;
}