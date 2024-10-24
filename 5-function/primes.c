// Created by hfwei on 2024/10/23.

#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int number);

int main(void) {
  int max = 0;
  scanf("%d", &max);

  int count = 0;

  for (int number = 2; number <= max; number++) {
    if (IsPrime(number)) {
      count++;
      printf("%d ", number);
    }
  }

  printf("\ncount = %d\n", count);

  return 0;
}

bool IsPrime(int number) {
  for (int factor = 2; factor * factor <= number; factor++) {
    if (number % factor == 0) {
      return false;
    }
  }

  return true;
}