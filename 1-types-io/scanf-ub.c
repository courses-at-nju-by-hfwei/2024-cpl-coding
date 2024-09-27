//
// Created by hfwei on 2024/9/25.
//

#include <stdio.h>

int main(void) {
  /*
   * (1) double
   */
  double d;
  scanf("%f", &d);
  printf("d = %f\n", d);

  /*
   * (2) using the value of uninitialized variable
   */
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  printf("Your age is %d.\n", age);

  /*
   * (3) long string
   * segmentation fault: buffer overflow: Process finished with exit code -1073741819 (0xC0000005)
   */
  char name[12];
  printf("What's your name? ");
  scanf("%s", name);
  printf("Hello %s!\n", name);

  return 0;
}