// Created by hengxin on 2024/12/04.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void PrintInts(const int integers[], size_t len);
void PrintStrs(const char *str[], size_t len);

int StrCmpStd(const char *s1, const char *s2);

int main() {
  int integers[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
  int size_of_integers = sizeof integers / sizeof *integers;

  PrintInts(integers, size_of_integers);
  // TODO: Sort integers using qsort
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

  PrintStrs(names, size_of_names);
  // TODO: Sort strings using qsort
  PrintStrs(names, size_of_names);
}

int StrCmpStd(const char *s1, const char *s2) {
  for (; *s1 == *s2; s1++, s2++) {
    if (*s1 == '\0') {
      return 0;
    }
  }

  const unsigned char s1_char = *((const unsigned char *) s1);
  const unsigned char s2_char = *((const unsigned char *) s2);

  return *((const unsigned char *) s1) -
      *((const unsigned char *) s2);
}

void PrintInts(const int integers[], size_t len) {
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