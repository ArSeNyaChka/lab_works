#include "intBaseList.h"
#include <assert.h>
#include <stdlib.h>

// typedef struct ListNode {
//     int value;
//     struct ListNode *next;
// } ListNode;

/*
 * List/Node creating
 */
ListNode *createNode(int value, ListNode *next) {
  ListNode *list = malloc(sizeof(ListNode));
  list->value = value;
  list->next = next;
  return list;
}

ListNode *createList() {
  ListNode *list = malloc(sizeof(ListNode));
  list->next = NULL;
  return list;
}

ListNode *createListWithValue(int value) { return createNode(value, NULL); }

/*
 * Node/Len getting
 */
ListNode *getNodeFromIndex(ListNode *list, int index) {
  assert(index >= 0 && "Out of bounts");
  assert(list != NULL && "List is NULL");
  for (int i = 0; i < index; i++) {
    assert(list->next != NULL && "Out of bounts!!!");
    list = list->next;
  }
  return list;
}

ListNode *getLastNode(ListNode *list) {
  while (list->next != NULL)
    list = list->next;
  return list;
}

int listLen(ListNode *list) {
  if (list == NULL)
    return 0;
  int len = 1;
  while (list->next != NULL) {
    list = list->next;
    len++;
  }
  return len;
}

/*
 * Add nodes
 */
void addNodeEnd(ListNode *list, int value) {
  assert(list != NULL && "Can not add in NULL List");
  list = getLastNode(list);
  list->next = createListWithValue(value);
}

void addNodeBegin(ListNode *list, int value) {
  assert(list != NULL && "Can not add in NULL List");
  ListNode *tempRoot = createNode(list->value, list->next);
  list->value = value;
  list->next = tempRoot;
}

void addNode(ListNode *list, int index, int value) {
  assert(index >= 0 && "Out of bounts");
  assert(list != NULL && "Can not add in NULL List");
  if (index == 0)
    return addNodeBegin(list, value);
  list = getNodeFromIndex(list, index - 1);
  ListNode *node = createNode(value, list->next);
  list->next = node;
}

/*
 * Delete Nodes
 */
int popEnd(ListNode *list) {
  assert(list != NULL && "List is NULL");
  assert(list->next != NULL && "List has only one node! Use `free(list)`");
  while (list->next->next != NULL)
    list = list->next;
  int value = list->next->value;
  free(list->next);
  list->next = NULL;
  return value;
}

int popBegin(ListNode *list) {
  assert(list != NULL && "List is NULL");
  assert(list->next != NULL && "List has only one node! Use `free(list)`");
  int value = list->value;
  list->value = pop(list, 1);
  return value;
}

int pop(ListNode *list, int index) {
  assert(list != NULL && "List is NULL");
  assert(list->next != NULL && "List has only one node! Use `free(list)`");
  if (index == 0)
    return popBegin(list);
  list = getNodeFromIndex(list, index - 1);
  int value = list->next->value;
  ListNode *nextNode = list->next->next;
  free(list->next);
  list->next = nextNode;
  return value;
}
