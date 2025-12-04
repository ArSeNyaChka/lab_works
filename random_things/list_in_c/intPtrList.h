#ifndef intList
#define intList

typedef struct ListNode {
  int value;
  struct ListNode *next;
} ListNode;

ListNode *createNode(int value, ListNode *next);
ListNode *createList();
ListNode *createListWithValue(int value);

ListNode *getNodeFromIndex(ListNode **list, int index);
ListNode *getLastNode(ListNode **listPtr);
int listLen(ListNode **listPtr);

void addNodeEnd(ListNode **listPtr, int value);
void addNodeBegin(ListNode **listPtr, int value);
void addNode(ListNode **listPtr, int index, int value);

int popEnd(ListNode **listPtr);
int popBegin(ListNode **listPtr);
int pop(ListNode **listPtr, int index);

#endif