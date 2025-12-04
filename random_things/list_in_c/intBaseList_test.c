#include <assert.h>
#include <stdio.h>
#include "intBaseList.h"
#include "intPtrList.h"

int main() {
    ListNode *list1 = createList();
    assert(list1->next == NULL);
    printf("createList Enjoy!\n");

    ListNode *list2 = createListWithValue(5);
    assert(list2->value == 5);
    assert(list2->next == NULL);
    printf("createListWithValue Enjoy!\n");

    addNodeEnd(list2, 4);
    assert(list2->next->value == 4 && list2->next->next == NULL);
    printf("addNodeEnd Enjoy!\n");

    addNodeBegin(list2, 3);
    assert(list2->value == 3 && list2->next->value == 5 && list2->next->next->value == 4);
    printf("addNodeBegin Enjoy!\n");
    
    addNode(list2, 2, 2);
    assert(list2->value == 3 && list2->next->value == 5 && list2->next->next->value == 2 && list2->next->next->next->value == 4);
    printf("addNode Enjoy!\n");
    
    int value1 = pop(list2, 1);
    assert(value1 == 5);
    assert(list2->value == 3 && list2->next->value == 2 && list2->next->next->value == 4);
    printf("pop Enjoy!\n");
    
    value1 = popEnd(list2);
    assert(value1 == 4);
    assert(list2->value == 3 && list2->next->value == 2);
    printf("popEnd Enjoy!\n");
    
    value1 = popBegin(list2);
    assert(list2->value == 2);
    printf("popBegin Enjoy!\n");
    printf("Enjoy!\n");
    return 0;
}