#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "function.h"

ListNode* conquer(ListNode* left, ListNode* right) {
    if (!left) return right; if (!right) return left;

    ListNode dummy;
    dummy.val = 0; dummy.next = NULL;

    ListNode* tail = &dummy;
    while (left && right) {
        if (left->val < right->val) {
            tail->next = left; tail = tail->next;
            left = left->next;
        }
        else {
            tail->next = right; tail = tail->next;
            right = right->next;
        }
    }
    tail->next = (left) ? left : right;
    return dummy.next;
}

ListNode* divide(ListNode* head) {
    if (!head || head->next == NULL) return head;

    ListNode* hare = head, * tortoise = head;
    while (true) {
        hare = (hare->next) ? hare->next->next : hare->next;
        if (!hare) break;
        tortoise = tortoise->next;
    }
    ListNode* middle = tortoise->next;
    tortoise->next = NULL;

    ListNode* left = divide(head);
    ListNode* right = divide(middle);
    return conquer(left, right);
}

ListNode* mergeLists(ListNode** lists, int n) {
    ListNode dummy; dummy.val = 0; dummy.next = NULL;

    ListNode* tail = &dummy;
    for (int i = 0; i < n; i++) {
        while (tail->next != NULL) tail = tail->next;
        tail->next = lists[i]; tail = tail->next;
    }
    dummy.next = divide(dummy.next);
    return dummy.next;
}