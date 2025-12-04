#include "intPtrList.h"
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
ListNode *getNodeFromIndex(ListNode **listPtr, int index) {
  ListNode *list = *listPtr;
  assert(index >= 0 && "Out of bounts");
  assert(list != NULL && "List is NULL");
  for (int i = 0; i < index; i++) {
    assert(list->next != NULL && "Out of bounts!!!");
    list = list->next;
  }
  return list;
}

ListNode *getLastNode(ListNode **listPtr) {
  ListNode *list = *listPtr;
  while (list->next != NULL)
    list = list->next;
  return list;
}

int listLen(ListNode **listPtr) {
  ListNode *list = *listPtr;
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
void addNodeEnd(ListNode **listPtr, int value) {
  if (*listPtr == NULL) {
    *listPtr = createListWithValue(value);
    return;
  }
  ListNode *list = *listPtr;
  list = getLastNode(&list);
  list->next = createListWithValue(value);
}

void addNodeBegin(ListNode **listPtr, int value) {
  if (*listPtr == NULL) {
    *listPtr = createListWithValue(value);
    return;
  }
  *listPtr = createNode(value, *listPtr);
}

void addNode(ListNode **listPtr, int index, int value) {
  assert(index >= 0 && "Out of bounts");
  if (*listPtr == NULL) {
    assert(index == 0 && "Out of bounts");
    *listPtr = createListWithValue(value);
    return;
  }
  ListNode *list = *listPtr;
  if (index == 0)
    return addNodeBegin(listPtr, value);
  list = getNodeFromIndex(&list, index - 1);
  ListNode *node = createNode(value, list->next);
  list->next = node;
}

/*
 * Delete Nodes
 */
int popEnd(ListNode **listPtr) {
  ListNode *list = *listPtr;
  assert(list != NULL && "List is NULL");
  if (list->next == NULL)
    return popBegin(listPtr);
  while (list->next->next != NULL)
    list = list->next;
  int value = list->next->value;
  free(list->next);
  list->next = NULL;
  return value;
}

int popBegin(ListNode **listPtr) {
  ListNode *list = *listPtr;
  assert(list != NULL && "List is NULL");
  int value = list->value;
  list = list->next;
  free(*listPtr);
  *listPtr = list;
  return value;
}

int pop(ListNode **listPtr, int index) {
  ListNode *list = *listPtr;
  assert(list != NULL && "List is NULL");
  if (index == 0)
    return popBegin(listPtr);
  list = getNodeFromIndex(&list, index - 1);
  int value = list->next->value;
  ListNode *nextNode = list->next->next;
  free(list->next);
  list->next = nextNode;
  return value;
}
