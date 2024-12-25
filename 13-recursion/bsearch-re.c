// Created by hfwei on 2024/12/25.

// Visualization (search for 2 as an example):
// https://tinyurl.com/bsearch-re
// (Using https://tinyurl.com/)

#include <stdio.h>

#define LEN 10

int BinarySearch(int key, const int dict[], int low, int high);

int main() {
  const int dictionary[LEN] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

  int key;
  scanf("%d", &key);

  printf("The index of %d is %d.\n", key,
         BinarySearch(key, dictionary, 0, LEN - 1));

  return 0;
}

int BinarySearch(int key, const int dict[], int low, int high) {
  // if (low == high) {
  //   if (dict[low] == key) {
  //     return low;
  //   }
  //   return - 1;
  // }

  if (low > high) {
    return -1;
  }

  int mid = (low + high) / 2;
  if (dict[mid] == key) {
    return mid;
  }

  if (dict[mid] > key) {
    return BinarySearch(key, dict, low, mid - 1);
  }

  return BinarySearch(key, dict, mid + 1, high);
}