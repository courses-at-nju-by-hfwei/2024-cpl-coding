// Created by hfwei on 2024/9/25.

#include <stdio.h>

// Example 3 from C17 (Page 234)
int main(void) {
  int count = 0;
  double quant = 0;
  char units[21] = "";
  char item[21] = "";

  // input:
  // 2 quarts of oil
  // -12.8degrees Celsius
  // lots of luck
  // 10.0LBS
  // of
  //     dirt
  // 100ergs of energy
  do {
    count = scanf("%lf%20s of %20s",
                  &quant, units, item);
    scanf("%*[^\n]");

    // added
    printf("count = %d\n"
           "quant = %f\n"
           "units = %s\n"
           "item = %s\n",
           count, quant, units, item);
  } while (!feof(stdin) && !ferror(stdin));

  // output:
  // count = 3;
  // quant = 2; strcpy(units, "quarts"); strcpy(item, "oil");

  // count = 2; // "C" fails to match "o"
  // quant = -12.8; strcpy(units, "degrees");

  // count = 0; // "l" fails to match "%f"

  // count = 3;
  // quant = 10.0; strcpy(units, "LBS"); strcpy(item, "dirt");

  // count = 0; // "100e" fails to match "%f" // 100.000000 rgs energy!!! (not conformed to the C Standard)

  // count = EOF;

  // A bug in gcc: https://sourceware.org/bugzilla/show_bug.cgi?id=1765#c1

  // input & output:
  // 2 quarts of oil
  // quant = 2.000000
  // units = quarts
  // item = oil

  // -12.8degrees Celsius
  // quant = -12.800000
  // units = degrees
  // item = oil

  // lots of luck
  // quant = -12.800000
  // units = degrees
  // item = oil

  // 10.0LBS
  // of
  //     dirt
  // quant = 10.000000
  // units = LBS
  // item = dirt

  // 100ergs of energy
  // quant = 100.000000
  // units = rgs
  // item = energy

  return 0;
}