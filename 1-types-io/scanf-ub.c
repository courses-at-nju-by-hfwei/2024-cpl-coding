// Created by hfwei on 2024/9/25.

#include <stdio.h>

int main(void) {
  /*
   * (scanf-ub-1)
   */
  double pi;
  printf("Enter the value of pi:\n");
  scanf("%f", &pi);
  printf("pi = %f\n", pi);

  /*
   * (scanf-ub-2)
   * enter "10000000000000000000" (19 0's)
   */
  int age;
  printf("Enter your age:\n");
  scanf("%d", &age);
  printf("Your age is %d.\n", age);

  /*
   * (scanf-ub-3)
   * enter a long string
   * Linux: *** stack smashing detected *** terminated
   * Aborted
   */
  char name[6];
  printf("What's your name?\n");
  scanf("%s", name);
  printf("Hello %s!\n", name);

  return 0;
}