// Created by hfwei on 2024/10/6.

#include <stdio.h>

int main(void) {
  int year = 0;
  scanf("%d", &year);

  int leap = 0;

  // TODO: leap year or not (logical expressions)
  if ((year % 4 == 0 && year % 100 != 0) ||
        year % 400 == 0) {
    leap = 1;
  }

  if (leap == 0) {
    printf("%d is a common year\n", year);
  } else {
    printf("%d is a leap year\n", year);
  }

  return 0;
}