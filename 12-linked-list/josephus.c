// Created by hfwei on 2024/12/19.

#include <assert.h>
#include <stdio.h>

#include "ll/ll.h"

#define NUM 12

void SitAroundCircle(LinkedList *list, int num);
void KillUntilOne(LinkedList *list);
int GetSurvivor(const LinkedList *list);

int main(void) {
  printf("I hate the Josephus game!\n");

  LinkedList list;
  Init(&list);

  SitAroundCircle(&list, NUM);
  // Print(&list);

  KillUntilOne(&list);
  int survivor = GetSurvivor(&list);
  printf("%d : %d\n", NUM, survivor);

  Free(&list);

  return 0;
}

void SitAroundCircle(LinkedList *list, int num) {
  for (int i = 1; i <= num; i++) {
    Append(list, i);
  }
}

void KillUntilOne(LinkedList *list) {
  Node *node = list->head;

  while (!IsSingleton(list)) {
    // use node to delete node->next
    Delete(list, node);
    node = node->next;
  }
}

int GetSurvivor(const LinkedList *list) {
  assert(IsSingleton(list));

  return GetHeadVal(list);
}