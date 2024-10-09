// Created by hfwei on 2024/10/10.

#include <stdio.h>

int main(void) {
  int number = 0;
  scanf("%d", &number);

  // Initialize the number of digits to 1
  int num_of_digits = 1;

  // For numbers other than 0, adjust number of digits
  for (; number / 10 != 0; num_of_digits++) {
    number /= 10;
  }

  printf("Number of digits is %d\n", num_of_digits);

  return 0;
}