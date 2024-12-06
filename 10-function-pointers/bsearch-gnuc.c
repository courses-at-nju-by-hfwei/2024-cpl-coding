// Created by hfwei on 2024/12/04.
// Question: What if char key_name[] = "Zhang Chu"?

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// See https://codebrowser.dev/glibc/glibc/stdlib/stdlib.h.html#__compar_fn_t
// The first is a pointer to the key for the search,
// and the second is a pointer to the array element to be compared with the key.
typedef int (*__compar_fn_t)(const void *, const void *);

// See https://codebrowser.dev/glibc/glibc/bits/stdlib-bsearch.h.html#19
void *bsearch(const void *__key, const void *__base,
              size_t __nmemb, size_t __size,
              __compar_fn_t __compar);
void *bsearch_leftmost(const void *__key, const void *__base,
                       size_t __nmemb, size_t __size,
                       __compar_fn_t __compar);

int CompareStrs(const void *left, const void *right);
int CompareStrsCI(const void *left, const void *right);
int CompareStrsAddress(const void *left, const void *right);

// int (*GetCompareFunction(bool case_sensitive))(const void *, const void *);
__compar_fn_t GetCompareFunction(bool case_sensitive) {
  return case_sensitive ? &CompareStrs : &CompareStrsCI;
}

const char *names[] = {
    "Cui Jian",
    "Dou Wei",
    "ErShou Rose",
    "Hu Mage",
    "Li Zhi",
    "Luo Dayou",
    "Wan Qing",
    "Yao",
    "Zhang Chu",
    "Zhang Chu",
    "Zhang Chu",
    "Zhang Chu",
    "ZuoXiao",
};

int main(void) {
  char *key_name = "Zhang Chu";

  // char **name_ptr = bsearch(&key_name, names,
  //                           sizeof names / sizeof *names,
  //                           sizeof *names,
  //                           CompareStrs);

  // char **name_ptr = bsearch(&key_name, names,
  //                           sizeof names / sizeof *names,
  //                           sizeof *names,
  //                           CompareStrsAddress);

  char **name_ptr = bsearch_leftmost(&key_name, names,
                                     sizeof names / sizeof *names,
                                     sizeof *names,
                                     CompareStrsAddress);

  if (name_ptr != NULL) {
    printf("Found %s at index %lld.\n",
           *name_ptr, name_ptr - (char **) names);
  } else {
    printf("Could not find %s.\n", key_name);
  }

  char *key_name_ci = "zhang chu";

  char **name_ci_ptr = bsearch(&key_name_ci, names,
                               sizeof names / sizeof *names,
                               sizeof *names,
                               GetCompareFunction(false));
  if (name_ci_ptr != NULL) {
    printf("Found %s at index %lld.\n",
           *name_ci_ptr,
           name_ci_ptr - (char **) names);
  } else {
    printf("Could not find %s.\n", key_name_ci);
  }

  return 0;
}

int CompareStrs(const void *left, const void *right) {
  char *const *pp1 = left;
  char *const *pp2 = right;
  return strcmp(*pp1, *pp2);
}

int CompareStrsCI(const void *left, const void *right) {
  const char *const *pp1 = left;
  const char *const *pp2 = right;
  // see https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-strcasecmp-case-insensitive-string-comparison
  return strcasecmp(*pp1, *pp2);
}

// What is the advantage of this version? (performance???)
// What is the disadvantage of this version? (not flexible???)
int CompareStrsAddress(const void *left, const void *right) {
  const char *pp1 = left;
  const char *pp2 = right;
  return strcmp(pp1, pp2);
}

void *bsearch(const void *__key, const void *__base, size_t __nmemb, size_t __size,
              __compar_fn_t __compar) {
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;
  __l = 0;
  __u = __nmemb;
  while (__l < __u) {
    __idx = (__l + __u) / 2;
    __p = (const void *) (((const char *) __base) + (__idx * __size));
    __comparison = (*__compar)(__key, __p);
    if (__comparison < 0) {
      __u = __idx;
    } else if (__comparison > 0) {
      __l = __idx + 1;
    } else {
      return (void *) __p;
    }
  }

  return NULL;
}

void *bsearch_leftmost(const void *__key, const void *__base,
                       size_t __nmemb, size_t __size,
                       __compar_fn_t __compar) {
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;

  __l = 0;
  __u = __nmemb;
  // added by ant
  void *__index = NULL;

  while (__l < __u) {
    __idx = (__l + __u) / 2;
    __p = (const void *) (((const char *) __base) + (__idx * __size));
    __comparison = (*__compar)(__key, __p);
    if (__comparison < 0) {
      __u = __idx;
    } else if (__comparison > 0) {
      __l = __idx + 1;
    } else {
      // added by ant
      __index = (void *) __p;
      __u = __idx - 1;
    }
  }

  // added by ant
  return __index;
}