// Created by hfwei on 2024/11/20.

#include <stdio.h>
#include <string.h>

char *StrCat(char *s1, const char *s2);
char *StrCatGLibC(char *dest, const char *src);

char *StrNCat(char *s1, const char *s2, size_t n);
size_t StrNLen(const char *s, size_t max);
char *StrNCatGLic(char *s1, const char *s2, size_t n);

int main(void) {
  char str[50] = "Hello ";
  char str2[50] = "World!";

//  strcat(str, str2);
//  strcat(str, " ...");
//  strcat(str, " Goodbye World!");

  strcat(strcat(strcat(str, str2), " ..."), " Goodbye World!");

//  strcat(str, str2);
//  strncat(str, " Goodbye World!", 3);

  puts(str);

  return 0;
}

char *StrCat(char *s1, const char *s2) {
  char *s;
  for (s = s1; *s != '\0'; s++);

  for (; (*s = *s2) != '\0'; s++, s2++);

  return s1;
}

// https://github.com/bminor/glibc/blob/master/string/strcat.c
char *StrCatGLibC(char *dest, const char *src) {
  strcpy(dest + strlen(dest), src);
  return dest;
}

char *StrNCat(char *s1, const char *s2, size_t n) {
  char *s;
  for (s = s1; *s != '\0'; s++);

  for (; 0 < n && *s2 != '\0'; --n) {
    *s++ = *s2++;
  }
  *s = '\0';

  return s1;
}

// https://github.com/intel/safestringlib/blob/master/safeclib/strnlen_s.c
size_t StrNLen(const char *s, size_t max) {
  size_t count = 0;

  while (max && *s) {
    count++;
    max--;
    s++;
  }

  return count;
}

char *StrNCatGLic(char *s1, const char *s2, size_t n) {
  char *s = s1;

  s1 += strlen(s1);

  size_t ss = StrNLen(s2, n);

  s1[ss] = '\0';
  memcpy(s1, s2, ss);

  return s;
}