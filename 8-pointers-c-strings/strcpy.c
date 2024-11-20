// Created by hfwei on 2024/11/20.
//
// C Operator Precedence:
// https://en.cppreference.com/w/c/language/operator_precedence#:~:text=C%20Operator%20Precedence%20%20%20%20Precedence%20,union%20member%20access%20%2028%20more%20rows%20
// Python Tutor:
// https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstring.h%3E%0A%0Avoid%20StrCpy%28char%20*dest,%20const%20char%20*src%29%3B%0Avoid%20StrCpy1%28char%20*dest,%20const%20char%20*src%29%3B%0Avoid%20StrCpy2%28char%20*dest,%20const%20char%20*src%29%3B%0Avoid%20StrCpy3%28char%20*dest,%20const%20char%20*src%29%3B%0Avoid%20StrCpy4%28char%20*dest,%20const%20char%20*src%29%3B%0Avoid%20StrCpy5%28char%20*dest,%20const%20char%20*src%29%3B%0Achar%20*StrCpyStd%28char%20*dest,%20const%20char%20*src%29%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20const%20char%20*src%20%3D%20%22Hello%20World%22%3B%0A%20%20char%20*dest%20%3D%20malloc%28strlen%28src%29%20%2B%201%29%3B%0A%0A%20%20StrCpy4%28dest,%20src%29%3B%0A%20%20printf%28%22dest%20%3D%20%25s%5Cn%22,%20dest%29%3B%0A%0A%20%20strlen%28StrCpyStd%28dest,%20src%29%29%3B%0A%0A%20%20return%200%3B%0A%7D%0A%0Avoid%20StrCpy%28char%20*dest,%20const%20char%20*src%29%20%7B%0A%20%20int%20i%20%3D%200%3B%0A%20%20while%20%28src%5Bi%5D%20!%3D%20'%5C0'%29%20%7B%0A%20%20%20%20dest%5Bi%5D%20%3D%20src%5Bi%5D%3B%0A%20%20%20%20i%2B%2B%3B%0A%20%20%7D%0A%0A%20%20dest%5Bi%5D%20%3D%20'%5C0'%3B%0A%7D%0A%0Avoid%20StrCpy1%28char%20*dest,%20const%20char%20*src%29%20%7B%0A%20%20int%20i%20%3D%200%3B%0A%20%20while%20%28%28dest%5Bi%5D%20%3D%20src%5Bi%5D%29%20!%3D%20'%5C0'%29%20%7B%0A%20%20%20%20i%2B%2B%3B%0A%20%20%7D%0A%7D%0A%0Avoid%20StrCpy2%28char%20*dest,%20const%20char%20*src%29%20%7B%0A%20%20int%20i%20%3D%200%3B%0A%20%20while%20%28%28*%28dest%20%2B%20i%29%20%3D%20*%28src%20%2B%20i%29%29%20!%3D%20'%5C0'%29%20%7B%0A%20%20%20%20i%2B%2B%3B%0A%20%20%7D%0A%7D%0A%0Avoid%20StrCpy3%28char%20*dest,%20const%20char%20*src%29%20%7B%0A%20%20while%20%28%28*dest%20%3D%20*src%29%20!%3D%20'%5C0'%29%20%7B%0A%20%20%20%20src%2B%2B%3B%0A%20%20%20%20dest%2B%2B%3B%0A%20%20%7D%0A%0A%20%20printf%28%22%25s%5Cn%22,%20src%29%3B%0A%7D%0A%0Avoid%20StrCpy4%28char%20*dest,%20const%20char%20*src%29%20%7B%0A%20%20while%20%28%28*dest%2B%2B%20%3D%20*src%2B%2B%29%20!%3D%20'%5C0'%29%3B%0A%0A%20%20printf%28%22%25s%5Cn%22,%20src%29%3B%0A%7D%0A%0Avoid%20StrCpy5%28char%20*dest,%20const%20char%20*src%29%20%7B%0A%20%20while%20%28%28*dest%2B%2B%20%3D%20*src%2B%2B%29%29%0A%20%20%20%20%3B%0A%7D%0A%0Achar%20*StrCpyStd%28char%20*dest,%20const%20char%20*src%29%20%7B%0A%20%20for%20%28char%20*s%20%3D%20dest%3B%20%28*s%2B%2B%20%3D%20*src%2B%2B%29%20!%3D%20'%5C0'%3B%29%3B%0A%20%20return%20dest%3B%0A%7D&cumulative=true&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief We assume that there is enough room for storing src.
 *  Otherwise, it is an undefined behavior.
 *
 *  If copying takes place between objects that overlap,
 *  then behavior is undefined.
 *
 *  In Docs:
 *  (1) The behavior is undefined if the dest array is not large enough.
 *  (2) The behavior is undefined if the strings overlap.
 *  (3) The behavior is undefined if either dest is not a pointer to a character
 * array or src is not a pointer to a null-terminated byte string.
 *
 * @param dest may NOT be null-terminated
 * @param src  must be null-terminated
 */
void StrCpy1(char *dest, const char *src);
void StrCpy2(char *dest, const char *src);
void StrCpy3(char *dest, const char *src);
void StrCpy4(char *dest, const char *src);
void StrCpy5(char *dest, const char *src);
void StrCpy6(char *dest, const char *src);
char *StrCpyStd(char *dest, const char *src);
char *StrNCpyStd(char *dest, const char *src, size_t n) {

int main() {
  const char *src = "Hello World";
  // VLA (Do not use it; it is optional since C11)
  // char dest[strlen(src) + 1];
  char *dest = malloc(strlen(src) + 1);

  StrCpy5(dest, src);
  strlen(dest);
  printf("dest = %s\n", dest);

  strlen(StrCpyStd(dest, src));

  return 0;
}

void StrCpy1(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }

  dest[i] = '\0';
}

void StrCpy2(char *dest, const char *src) {
  int i = 0;
  while ((dest[i] = src[i]) != '\0') {
    i++;
  }
}

void StrCpy3(char *dest, const char *src) {
  int i = 0;
  // dest[i] : *(dest + i)
  while ((*(dest + i) = *(src + i)) != '\0') {
    i++;
  }
}

void StrCpy4(char *dest, const char *src) {
  while ((*dest = *src) != '\0') {
    src++;
    dest++;
  }

  printf("%s\n", src);
}

// See C Operator Precedence:
// https://en.cppreference.com/w/c/language/operator_precedence#:~:text=C%21Operator%20Precedence%20%20%20%20Precedence%20,union%20member%20access%20%2028%20more%20rows%20
// Visualization:
// https://pythontutor.com/visualize.html#code=%23include%20%3Cstring.h%3E%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0Avoid%20StrCpy4%28char%20*dest,%20const%20char%20*src%29%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20const%20char%20*src%20%3D%20%22Hello%20World%22%3B%0A%20%20char%20*dest%20%3D%20malloc%28strlen%28src%29%20%2B%201%29%3B%0A%0A%20%20StrCpy4%28dest,%20src%29%3B%0A%20%20printf%28%22dest%20%3D%20%25s%5Cn%22,%20dest%29%3B%0A%0A%20%20free%28dest%29%3B%0A%20%20%0A%20%20return%200%3B%0A%7D%0A%0A%0Avoid%20StrCpy4%28char%20*dest,%20const%20char%20*src%29%20%7B%0A%20%20while%20%28%0A%20%20%20%20%28*dest%2B%2B%20%0A%20%20%20%20%20%20%3D%20*src%2B%2B%29%20%0A%20%20%20%20%20%20%20%20!%3D%20'%5C0'%29%3B%0A%0A%20%20printf%28%22%25s%5Cn%22,%20src%29%3B%0A%7D&cumulative=true&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
// Tricky difference between StrCpy4: src, dest beyond '\0'
// You SHOULD be able to understand this!!!
void StrCpy5(char *dest, const char *src) {
  // dest++: dest, dest = dest + 1
  // *dest++: *dest, not *(dest + 1)
  while ((*dest++ = *src++) != '\0');

  printf("%s\n", src);
}

// NOT Recommended!
// See ASCII Chart: https://en.cppreference.com/w/c/language/ascii
void StrCpy6(char *dest, const char *src) {
  // '\0': null character (NUL), 0
  // `\0' is not NULL
  while ((*dest++ = *src++));
}

// See https://en.cppreference.com/w/c/string/byte/strcpy
char *StrCpyStd(char *dest, const char *src) {
  for (char *s = dest; (*s++ = *src++) != '\0';);
  return dest;
}

char *StrNCpyStd(char *dest, const char *src, size_t n) {
  char *s;
  for (s = dest; 0 < n && *src != '\0'; --n) {
    *s++ = *src++;
  }

  for (; 0 < n; --n) {
    *s++ = '\0';
  }

  return dest;
}