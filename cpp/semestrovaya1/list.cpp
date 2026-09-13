#include "list.h"
#include "ball.h"
#include <stdexcept>

// struct ListNode {
//     int value;
//     struct ListNode *next;
// };
  
/*
 * List/Node creating
 */
ListNode *createNode(Ball value, ListNode *next) {
  ListNode *list = new ListNode;
  list->value = value;
  list->next = next;
  return list;
}

ListNode *createList() {
  ListNode *list = new ListNode;
  list->next = nullptr;
  return list;
}

ListNode *createListWithValue(Ball value) { return createNode(value, nullptr); }

/*
 * Node/Len getting
 */
ListNode *getNodeFromIndex(ListNode *&list, int index) {
  if (index < 0) throw std::runtime_error("Out of bounds");
  if (list == nullptr) throw std::runtime_error("List is null");

  ListNode *node = list;

  for (int i = 0; i < index; i++) {
    node = node->next;
    if (node == nullptr) throw std::runtime_error("Out of bounds");
  }

  return node;
}

ListNode *getLastNode(ListNode *&list) {
  if (list == nullptr) throw std::runtime_error("List is null");
  
  ListNode *node = list;
  while (node->next != nullptr)
    node = node->next;
  return node;
}

int listLen(ListNode *&list) {
  if (list == nullptr)
    return 0;

  const ListNode *node = list;
  int len = 1;

  while (node->next != nullptr) {
    node = node->next;
    len++;
  }

  return len;
}

/*
 * Add nodes
 */
void addNodeEnd(ListNode *&list, Ball value) {
  if (list == nullptr) {
    list = createListWithValue(value);
    return;
  }

  ListNode *node = getLastNode(list);
  node->next = createListWithValue(value);
}

void addNodeBegin(ListNode *&list, Ball value) {
  if (list == nullptr) {
    list = createListWithValue(value);
    return;
  }

  list = createNode(value, list);
}

void addNode(ListNode *&list, int index, Ball value) {
  if (index < 0) throw std::runtime_error("Out of bounds");
  
  if (index == 0) return addNodeBegin(list, value);

  // Упадет только если список пустой и index != 0
  if (list == nullptr) throw std::runtime_error("Out of bounds");

  ListNode *node = getNodeFromIndex(list, index - 1);
  ListNode *newNode = createNode(value, list->next);
  node->next = newNode;
}

/*
 * Delete Nodes
 */
Ball popEnd(ListNode *&list) {
  if (list == nullptr) throw std::runtime_error("List is null");

  ListNode *node = list;

  if (list->next == nullptr)
    return popBegin(list);

  while (node->next->next != nullptr)
    node = node->next;

  Ball value = node->next->value;
  delete node->next;
  node->next = nullptr;

  return value;
}

Ball popBegin(ListNode *&list) {
  if (list == nullptr) throw std::runtime_error("List is null");

  ListNode *node = list;
  Ball value = list->value;

  list = list->next;
  delete node;

  return value;
}

Ball pop(ListNode *&list, int index) {
  if (list == nullptr) throw std::runtime_error("List is null");

  if (index == 0) return popBegin(list);

  ListNode *node = getNodeFromIndex(list, index - 1);
  Ball value = node->next->value;
  ListNode *nextNode = list->next->next;

  delete node->next;
  node->next = nextNode;

  return value;
}

void deleteList(ListNode *&list) {
  if (list == nullptr)
    return;

  while (list != nullptr) {
    ListNode *next = list->next;
    delete list;
    list = next;
  }
}
