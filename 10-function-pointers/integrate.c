// Created by hfwei on 2024/12/04.
// A nice function pointer example on Riemann integration:
// https://en.wikipedia.org/wiki/Function_pointer

#include <stdio.h>
#include <math.h>

#define NUM_OF_PARTITIONS 1000000

double Integrate(double low, double high, double (*func)(double));

double Square(double x);

int main() {
  double low = 0.0;
  double high = 1.0;
  double integration = 0.0;

  // gcc -pedantic (invalid application of sizeof to a function type)
  // See "Function to pointer conversion" (https://en.cppreference.com/w/c/language/conversion)
  // See also https://en.cppreference.com/w/c/language/sizeof
  printf("sizeof sin: %zu\n", sizeof sin);
  printf("sizeof &sin: %zu\n", sizeof &sin);

  integration = Integrate(low, high, sin);
  printf("sin(x) from %f to %f is %f\n", low, high, integration);

  integration = Integrate(low, high, cos);
  printf("cos(x) from %f to %f is %f\n", low, high, integration);

  integration = Integrate(low, high, Square);
  printf("Square(x) from %f to %f is %f\n", low, high, integration);

  double (*funcs[])(double) = {sin, cos, Square};

  int len = sizeof(funcs) / sizeof(*funcs);
  for (int i = 0; i < len; ++i) {
    printf("integration: %f\n", Integrate(low, high, funcs[i]));
  }

  return 0;
}

double Integrate(double low, double high, double (*func)(double)) {
  double interval = (high - low) / NUM_OF_PARTITIONS;

  double sum = 0.0;
  for (int i = 0; i < NUM_OF_PARTITIONS; i++) {
    double xi = low + interval * i;
    double yi = func(xi);
    sum += yi * interval;
  }

  return sum;
}

double Square(double x) {
  return x * x;
}