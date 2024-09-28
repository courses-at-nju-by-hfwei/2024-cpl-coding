// Created by hfwei on 2024/9/25.

// Get-Content .\scanf-c17-ex2-input.txt | .\scanf-c17-ex2.exe > scanf-c17-ex2-output.txt
// ./scanf-c17-ex2 < scanf-c17-ex2-input.txt > scanf-c17-ex2-output.txt

#include <stdio.h>

// Example 2 from C17 (Page 234)
int main(void) {
  int i;
  double x;
  char name[50];

  // enter "56789 0123 56a72"
  scanf("%2d%lf%*d %[0123456789]",
        &i, &x, name);

  // fscanf(stdin, ...);

  printf("i = %d\n"
         "x = %f\n"
         "name = %s\n",
         i, x, name);

  return 0;
}