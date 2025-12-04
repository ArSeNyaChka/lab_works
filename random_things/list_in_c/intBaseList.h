#ifndef intList
#define intList

typedef struct ListNode {
  int value;
  struct ListNode *next;
} ListNode;

ListNode *createNode(int value, ListNode *next);
ListNode *createList();
ListNode *createListWithValue(int value);

ListNode *getNodeFromIndex(ListNode *list, int index);
ListNode *getLastNode(ListNode *list);
int listLen(ListNode *list);

void addNodeEnd(ListNode *list, int value);
void addNodeBegin(ListNode *list, int value);
void addNode(ListNode *list, int index, int value);

int popEnd(ListNode *list);
int popBegin(ListNode *list);
int pop(ListNode *list, int index);

#endif