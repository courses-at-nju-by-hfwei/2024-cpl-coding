// Created by hfwei on 2024/10/10.

#include <stdio.h>

int main() {
  const int array[] = {0, 1, 2, 3, 4};
  int i = -1;

  size_t size = sizeof array / sizeof array[0];
  printf("The size of the array is %zu\n", size);

  if (i <= size) {
    printf("i <= sizeof array\n");
  } else {
    printf("i > sizeof array\n");
  }

  return 0;
}