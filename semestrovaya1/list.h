#ifndef listLib
#define listLib

#include "ball.h"

struct ListNode {
  Ball value;
  struct ListNode *next;
};

ListNode *createNode(Ball value, ListNode *next);
ListNode *createList();
ListNode *createListWithValue(Ball value);

ListNode *getNodeFromIndex(ListNode *&list, int index);
ListNode *getLastNode(ListNode *&list);
int listLen(ListNode *&list);

void addNodeEnd(ListNode *&list, Ball value);
void addNodeBegin(ListNode *&list, Ball value);
void addNode(ListNode *&list, int index, Ball value);

Ball popEnd(ListNode *&list);
Ball popBegin(ListNode *&list);
Ball pop(ListNode *&list, int index);
void deleteList(ListNode *&list);

#endif