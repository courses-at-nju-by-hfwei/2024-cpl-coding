// Benchmarking standard strncmp and STRNCMP in glibc.
// Created by hfwei on 2024/11/20.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// https://github.com/lattera/glibc/blob/master/string/strncmp.c
int STRNCMP(const char *s1, const char *s2, size_t n) {
  unsigned char c1 = '\0';
  unsigned char c2 = '\0';

  if (n >= 4) {
    size_t n4 = n >> 2;
    do {
      c1 = (unsigned char)*s1++;
      c2 = (unsigned char)*s2++;
      if (c1 == '\0' || c1 != c2)
        return c1 - c2;
      c1 = (unsigned char)*s1++;
      c2 = (unsigned char)*s2++;
      if (c1 == '\0' || c1 != c2)
        return c1 - c2;
      c1 = (unsigned char)*s1++;
      c2 = (unsigned char)*s2++;
      if (c1 == '\0' || c1 != c2)
        return c1 - c2;
      c1 = (unsigned char)*s1++;
      c2 = (unsigned char)*s2++;
      if (c1 == '\0' || c1 != c2)
        return c1 - c2;
    } while (--n4 > 0);
    n &= 3;
  }

  while (n > 0) {
    c1 = (unsigned char)*s1++;
    c2 = (unsigned char)*s2++;
    if (c1 == '\0' || c1 != c2)
      return c1 - c2;
    n--;
  }

  return c1 - c2;
}

void benchmark(const char *label,
               int (*cmp_func)(const char *, const char *, size_t),
               const char *s1, const char *s2, size_t n, size_t iterations) {
  clock_t start = clock();

  for (size_t i = 0; i < iterations; i++) {
    cmp_func(s1, s2, n);
  }

  clock_t end = clock();
  double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

  printf("%s: %.6f seconds\n", label, elapsed);
}

int main() {
  const size_t len = 1000000;
  const size_t iterations = 100000;
  char *s1 = malloc(len + 1);
  char *s2 = malloc(len + 1);

  memset(s1, 'a', len);
  memset(s2, 'a', len);
  s1[len] = '\0';
  s2[len] = '\0';

  printf("Benchmarking identical strings:\n");
  benchmark("STRNCMP", STRNCMP, s1, s2, len, iterations);
  benchmark("strncmp", strncmp, s1, s2, len, iterations);

  // Introduce a mismatch in the last character
  s2[len - 1] = 'b';

  printf("\nBenchmarking mismatched strings:\n");
  benchmark("STRNCMP", STRNCMP, s1, s2, len, iterations);
  benchmark("strncmp", strncmp, s1, s2, len, iterations);

  free(s1);
  free(s2);

  return 0;
}