// Created by hengxin on 2024/12/04.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// void qsort( void *ptr, size_t count, size_t size,
//             int (*comp)(const void *, const void *) );

typedef int (*CompareFunction)(const void *, const void *);

int CompareInts(const void *left, const void *right);
int CompareStrs(const void *left, const void *right);
int CompareStrsWrong(const void *left, const void *right);

void PrintInts(const int *integers, size_t len);
void PrintStrs(const char *str[], size_t len);

int main() {
  int integers[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
  int size_of_integers = sizeof integers / sizeof *integers;

  CompareFunction comp = CompareInts;
  // int (*comp)(const void *, const void *) = CompareInts;

  qsort(integers, size_of_integers, sizeof integers[0],
        comp);
  PrintInts(integers, size_of_integers);

  const char *names[] = {
      "Luo Dayou",
      "Cui Jian",
      "Dou Wei",
      "Zhang Chu",
      "Wan Qing",
      "Li Zhi",
      "Yao",
      "ZuoXiao",
      "ErShou Rose",
      "Hu Mage",
  };
  size_t size_of_names = sizeof names / sizeof *names;

  comp = CompareStrs;
  qsort(names, size_of_names, sizeof names[0],
        comp);
  PrintStrs(names, size_of_names);
}

// left: int *
int CompareInts(const void *left, const void *right) {
  int left_int = *(const int *) left;
  int right_int = *(const int *) right;

  return (left_int > right_int) - (left_int < right_int);
}

// left, right: char **
int CompareStrs(const void *left, const void *right) {
  const char *const *pp1 = left;
  const char *const *pp2 = right;

  return strcmp(*pp1, *pp2);
}

int CompareStrsWrong(const void *left, const void *right) {
  return strcmp(left, right);
}

void PrintInts(const int *integers, size_t len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", integers[i]);
  }
  printf("\n");
}

void PrintStrs(const char *str[], size_t len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%s\n", str[i]);
  }
  printf("\n");
}