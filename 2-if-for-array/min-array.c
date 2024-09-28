#include <stdio.h>

#define NUM 5

int main(void) {
  // TODO (hfwei): Variable length array (VLA) folded to constant array as an extension
  // const int NUM = 5;

  // index starting from 0
  // 5 elements (no '\0')
  // int[] numbers = {23, 56, 19, 11, 78};
  // variable-sized object may not be initialized
  // designator: from C99
  int numbers[NUM] = {23, 56, 19, 11, 78};

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