// Created by hfwei on 2024/12/19.

#include "ll.h"
#include <stdio.h>
#include <stdlib.h>

void Init(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}

bool IsEmpty(const LinkedList *list) { return list->head == NULL; }

bool IsSingleton(const LinkedList *list) {
  // return list->head == list->tail;
  return !IsEmpty(list) && (list->head == list->tail);
}

int GetHeadVal(const LinkedList *list) {
  if (IsEmpty(list)) {
    return -1;
  }

  return list->head->val;
}

void Append(LinkedList *list, int val) {
  Node *node = malloc(sizeof *node);
  if (node == NULL) {
    printf("malloc failed\n");
    return;
  }
  node->val = val;

  if (IsEmpty(list)) {
    list->head = node;
  } else {
    list->tail->next = node;
  }

  list->tail = node;
  list->tail->next = list->head;
}

void Delete(LinkedList *list, Node *prev) {
  if (IsEmpty(list)) {
    return;
  }

  if (IsSingleton(list)) {
    free(list->head);
    Init(list);
    return;
  }

  Node *cur = prev->next;
  Node *next = cur->next;

  prev->next = next;

  // cur != list->head || cur != list->tail
  if (cur == list->head) {
    list->head = next;
  }

  if (cur == list->tail) {
    list->tail = prev;
  }

  free(cur);
}

void Print(const LinkedList *list) {
  if (IsEmpty(list)) {
    printf("empty list\n");
    return;
  }
  Node *node = list->head;

  do {
    printf("%d ", node->val);
    node = node->next;
  } while (node != list->head);

  // wrong version
  // while (node != list->head) {
  //   printf("%d ", node->val);
  //   node = node->next;
  // }
}

void Free(LinkedList *list) {
  while (!IsEmpty(list)) {
    Delete(list, list->head);
  }
}