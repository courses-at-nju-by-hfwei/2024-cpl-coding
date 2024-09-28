#include <stdio.h>

#define NUM 5

int main(void) {
  int numbers[NUM] = { 0 };

  // int i = 0;
  // &: address-of operator (numbers[i] is an lvalue)
  for (int i = 0; i < NUM; i++) {
    scanf("%d", &numbers[i]);
  }

  // []: array subscripting operator
  int min = numbers[0];

  // syntax + semantics
  // syntax: for (init-clause; condition-expression; iteration-expression) loop-statement
  // semantics: debug!!!
  // (1): []
  // (2): i < NUM: not i <= NUM (accessing out-of-bounds; 访问越界)
  // (3): int i = 1; since C99 (declaration in for-loop); code in standard C library
  for (int i = 1;
       i < NUM;
       i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }

  printf("min = %d\n", min);

  return 0;
}