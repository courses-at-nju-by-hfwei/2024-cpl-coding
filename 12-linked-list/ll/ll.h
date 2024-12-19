//
// Created by hfwei on 2023/12/20.
//

#ifndef INC_2023_CPL_CODING_0_13_LINKED_LIST_LL_LL_H_
#define INC_2023_CPL_CODING_0_13_LINKED_LIST_LL_LL_H_

// adding code below

#include <stdbool.h>
typedef struct node {
  int val;
  struct node *next;
} Node;

typedef struct ll {
  Node *head;
  Node *tail;
  // int size;
} LinkedList;

void Init(LinkedList *list);

bool IsEmpty(const LinkedList *list);
bool IsSingleton(const LinkedList *list);

/**
 * @brief Get the value of the head node.
 * @param list
 * @return -1 if list is empty, otherwise the value of the head node.
 */
int GetHeadVal(const LinkedList *list);
Node *Search(const LinkedList *list, int val);

void Print(const LinkedList *list);

void Append(LinkedList *list, int val);
void Insert(LinkedList *list, Node *prev, int val);

/**
 * @brief Delete the node after prev from list.
 * @param list
 * @param prev
 */
void Delete(LinkedList *list, Node *prev);

void Free(LinkedList *list);

#endif //INC_2023_CPL_CODING_0_13_LINKED_LIST_LL_LL_H_