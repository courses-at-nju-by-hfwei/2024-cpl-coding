// Created by hfwei on 2024/10/10.

#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int max = 0;
  scanf("%d", &max);

  // TODO: print primes between 1 and max

  int count = 0;

  for (int number = 2; number <= max; number++) {
    // decide whether number is a prime
    // Since C99: bool (macro extended to _Bool; with macros true and false)
    // Since C23: will become keywords (bool, true, false); do not need stdbool.h
    bool is_prime = true;
    for (int factor = 2; factor * factor <= number; factor++) {
      if (number % factor == 0) {
        is_prime = false;
        break;  // test: number = 18
      }
    }

    if (is_prime) { // TODO: is_prime == 1; is_prime != 0
      count++;
      printf("%d ", number);  // TODO: comment this for performance
    }
  }

  printf("\ncount = %d\n", count);

  return 0;
}