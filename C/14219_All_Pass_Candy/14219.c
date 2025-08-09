#include <stdio.h>
#include <stdlib.h>

#include "function.h"

ListNode* readList() {
    int m;
    scanf("%d", &m);
    ListNode* nodes = (ListNode*)malloc((m + 1) * sizeof(ListNode));
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &nodes[i].val);
        nodes[i - 1].next = &nodes[i];
    }
    nodes[m].next = NULL;
    return nodes;
}

int main() {
    int n;
    scanf("%d", &n);
    ListNode** dummys = (ListNode**)malloc(n * sizeof(ListNode*));
    for (int i = 0; i < n; ++i) dummys[i] = readList();

    ListNode** lists = (ListNode**)malloc(n * sizeof(ListNode*));
    for (int i = 0; i < n; ++i) lists[i] = dummys[i]->next;

    for (ListNode* cur = mergeLists(lists, n);
         cur; cur = cur->next)
        printf("%d ", cur->val);

    free(lists);
    for (int i = 0; i < n; ++i) free(dummys[i]);
    free(dummys);

    return 0;
}
