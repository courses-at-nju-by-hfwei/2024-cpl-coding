// Created by hfwei on 2024/10/31.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int Add(unsigned int left, unsigned int right);
unsigned int Sub(unsigned int left, unsigned int right);
unsigned int Mul(unsigned int left, unsigned int right);
unsigned int Div(unsigned int left, unsigned int right);
unsigned int Mod(unsigned int left, unsigned int right);

int main(void) {
  // addition
  unsigned int left_add = UINT_MAX / 2 + 1;
  unsigned int right_add = UINT_MAX / 2 + 1;

  printf("%u + %u = %u\n\n", left_add, right_add, Add(left_add, right_add));

  // subtraction
  unsigned int left_sub = 1;
  unsigned int right_sub = 2;

  printf("%u - %u = %u\n\n", left_sub, right_sub, Sub(left_sub, right_sub));

  // multiplication
  unsigned int left_mul = UINT_MAX;
  unsigned int right_mul = 2;

  printf("%u * %u = %u\n", left_mul, right_mul, Mul(left_mul, right_mul));

  // division
}

unsigned int Add(unsigned int left, unsigned int right) {
  //  unsigned int sum = left + right;
  //  return sum;

  if (left + right > UINT_MAX) {
    printf("Too Big!\n");
    exit(1);
  } else {
    unsigned int sum = left + right;
    return sum;
  }
}

unsigned int Sub(unsigned int left, unsigned int right) {
  //  unsigned int sub = left - right;
  //  return sub;

  if (left - right < 0) {
    printf("The result is negative!\n");
    exit(1);
  } else {
    unsigned int sub = left - right;
    return sub;
  }
}

unsigned int Mul(unsigned int left, unsigned int right) {
  //  unsigned int mul = left * right;
  //  return mul;

  if (left * right > UINT_MAX) {
    printf("The result is negative!\n");
    exit(1);
  } else {
    unsigned int mul = left * right;
    return mul;
  }
}

unsigned int Div(unsigned int left, unsigned int right) {
  if (right == 0) {
    printf("Division by zero!\n");
    exit(1);
  }

  return left / right;
}

unsigned int Mod(unsigned int left, unsigned int right) {
  if (right == 0) {
    printf("Division by zero!\n");
    exit(1);
  }

  return left % right;
}