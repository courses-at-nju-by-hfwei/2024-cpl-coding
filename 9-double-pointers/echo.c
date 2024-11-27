/**
 * Echo program (command-line) arguments.
 *
 * Created by hengxin on 11/27/2024.
 */

#include <stdio.h>

// arg: argument
// c: count
// v: vector

// argv[0]: the name of the program
// argv[1 .. argc - 1]: command line arguments
// argv[argc]: NULL
int main(int argc, char *argv[]) {
  // for version with argv
  // for (int i = 1; i < argc; ++i) {
  //   printf("argv[%d] = %s\n", i, argv[i]);
  // }

  // for version with pointers
  // for (char **ptr = argv + 1; *ptr != NULL; ptr++) {
  //   printf("%s\n", *ptr);
  // }

  // while version
  // char **ptr = argv + 1;
  // while (*ptr != NULL) {
  //   printf("%s\n", *ptr);
  //   ptr++;
  // }

  // WRONG
  // char **ptr = argv + 1;
  // while (*ptr++ != NULL) {
  //   printf("%s\n", *ptr);
  // }

  char **ptr = argv;
  // *++ptr
  // *ptr++
  // *--ptr
  // *ptr--
  while (*++ptr != NULL) {
    printf("%s\n", *ptr);
  }

  return 0;
}