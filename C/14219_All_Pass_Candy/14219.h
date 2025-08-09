#ifndef _FUNCTION_H_
#define _FUNCTION_H_

typedef struct _ListNode {
    int val;
    struct _ListNode* next;
} ListNode;

ListNode* mergeLists(ListNode** lists, int n);

// Implement the above function in a `.c` file
// You might start with the following codes:

/*
#include "function.h"

ListNode *mergeLists(ListNode** lists, int n) {
    // ...
}
*/

#endif
