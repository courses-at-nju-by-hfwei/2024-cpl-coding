//
// Created by hfwei on 2023/11/30.
// Visualization:
// https://pythontutor.com/render.html#code=%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0Aint%20main%28void%29%20%7B%0A%20%20char%20msg%5B%5D%20%3D%20%22Hello%20World!%22%3B%0A%20%20msg%5B0%5D%20%3D%20'N'%3B%0A%20%20printf%28%22%25s%5Cn%22,%20msg%29%3B%0A%0A%20%20char%20*ptr_msg%20%3D%20%22Hello%20World!%22%3B%0A%20%20ptr_msg%5B0%5D%20%3D%20'N'%3B%0A%20%20printf%28%22%25s%5Cn%22,%20msg%29%3B%0A%0A%20%20return%200%3B%0A%7D&cumulative=true&curInstr=6&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
// See String literals: https://en.cppreference.com/w/c/language/string_literal
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // it is actually char msg[] = { 'H', 'e', ..., '\0' };
  char msg[] = "Hello World!";
  printf("%s\n", msg);

  // array name is read-only
  // msg = "Hello";

  msg[0] = 'N';
  printf("%s\n", msg);

  // string literal;
  // may be stored in read-only memory
  // static storage duration (text segment)
  char *ptr_msg = "Hello Hello World!";
  char *ptr_msg_another = "Hello Hello World!";
  printf("%p\n%p\n", ptr_msg, ptr_msg_another);

  // undefined behavior

  // On Linux (or Debug mode on Windows): interrupted by signal 11: SIGSEGV
  // SIG: signal; SEGV: segmentation violation

  // On Windows: Process finished with exit code -1073741819 (0xC0000005)
  // See
  // https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55
  //
  ptr_msg[0] = 'N';
  printf("%s\n", msg);

  // using malloc
  char *malloc_msg = malloc(20);
  malloc_msg = strcpy(malloc_msg, "Hello World!");
  malloc_msg[0] = 'N';
  free(malloc_msg);

  return 0;
}