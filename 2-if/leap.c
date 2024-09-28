//
// Created by hfwei on 2023/10/6.
//

#include <stdio.h>
int main(void) {
  int year = 0;
  scanf("%d", &year);

  int leap = 0;

  // TODO: C operator precedence
  // URL: https://en.cppreference.com/w/c/language/operator_precedence

  // TODO (hfwei): order of evaluation

  // TODO: short-circuit evaluation
  // test: year = 25
  // test: year = 80
  // test: year = 100
  // test: year = 400
  // TODO: ! (year % 100 == 0)
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    leap = 1;
  } else {
    leap = 0;
  }

  // int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

  // TODO: leap = 0
  if (leap == 0) {
    printf("%d is a common year\n", year);
  } else {
    printf("%d is a leap year\n", year);
  }

  return 0;
}