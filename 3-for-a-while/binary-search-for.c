// Created by hfwei on 2024/10/10.

#include <stdio.h>

#define LEN 10
int dictionary[LEN] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };

int main(void) {
  int key = 0;
  scanf("%d", &key);

  int index = -1;

  for (int low = 0, high = LEN - 1; low <= high; ) {
    int mid = (low + high) / 2;

    if (key > dictionary[mid]) {
      low = mid + 1;
    } else if (key < dictionary[mid]) {
      high = mid - 1;
    } else {  // key == dictionary[mid]
      index = mid;
      high = mid - 1; // find the leftmost index of the key
    }
  }

  if (index == -1) {
    printf("Not found!\n");
  } else {
    printf("The index of %d is %d.\n", key, index);
  }

  return 0;
}