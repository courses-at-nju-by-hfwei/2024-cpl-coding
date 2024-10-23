// Created by hfwei on 2024/10/16.
// Code generated by ChatGPT.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 10000
#define RANGE 100

int main(void) {
  int numbers[MAX_LEN] = { 0 };

  int size = 0;
  scanf("%d", &size);

  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    numbers[i] = rand() % RANGE;
  }

  // print the original array
  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  // TODO: insertion sort
  for (int i = 1; i < size; i++) {
    // numbers[0 .. i - 1] are already sorted
    // now consider key, the i-th element
    int key = numbers[i];

    // move elements > key
    int j = i - 1;
    while (j >= 0 && numbers[j] > key) {
      numbers[j + 1] = numbers[j];
      j--;
    }

    // a for-loop version
//    for (j = i - 1; j >= 0 && numbers[j] > key; j--) {
//      numbers[j + 1] = numbers[j];
//    }

    // a wrong for-loop version
//    for (j = i - 1; j >= 0; j--) {
//      if (numbers[j] > key) {
//        numbers[j + 1] = numbers[j];
//      }
//    }

    // put key there
    numbers[j + 1] = key;

    // now numbers[0 .. i] is already sorted
    for (int j = 0; j < size; j++) {
      printf("%d ", numbers[j]);
    }
    printf("\n");
  }

  // print the sorted array
  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  return 0;
}