#include <stdio.h>
#include <stdlib.h>
#include "function.h"

typedef struct _ListNode {
    int val;
    struct _ListNode* next;
} ListNode;

typedef struct{
    ListNode* node;
}HeapNode;

typedef struct{
    HeapNode* arr;
    int size;
}MinHeap;

void swapping(HeapNode* nodeA, HeapNode* nodeB){
    HeapNode temp = *nodeA;
    *nodeA = *nodeB;
    *nodeB = temp;
}

void inserting(MinHeap* heap, ListNode* node){
    int i = heap->size++;
    heap->arr[i].node = node;
    while(i > 0 && heap->arr[i].node->val < heap->arr[(i-1)/2].node->val){
        swapping(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapify(MinHeap* heap, int i){
    int smallest = i, left = 2*i + 1, right = 2*i + 2;
    if(left < heap->size && heap->arr[left].node->val < heap->arr[smallest].node->val) smallest = left;
    if(right < heap->size && heap->arr[right].node->val < heap->arr[smallest].node->val) smallest = right;
    if(smallest != i){
        swapping(&heap->arr[smallest], &heap->arr[i]);
        heapify(heap, smallest);
    }
}

ListNode* extract(MinHeap* heap){
    ListNode* newNode = heap->arr[0].node;
    if(newNode->next) heap->arr[0].node = newNode->next;
    else heap->arr[0].node = heap->arr[--heap->size].node;
    heapify(heap, 0);
    return newNode;
}


ListNode* mergeLists(ListNode** lists, int n) {
    MinHeap heap;
    heap.arr = (MinHeap*)malloc(n*sizeof(MinHeap));
    heap.size = 0;

    for(int i = 0; i < n; i++) inserting(&heap, lists[i]);

    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    ListNode* tail = dummy;
    while(heap.size > 0){
        ListNode* newNode = extract(&heap);
        tail->next = newNode;
        tail = tail->next;
    }

    ListNode* mergedHead = dummy->next;
    free(dummy);
    free(heap.arr);
    return mergedHead;
}



/*
=== TOPIC(S) ===
Heap Sort


=== AUTHOR(S) ===
黃奮盛 Vincent
*/