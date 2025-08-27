#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _Node {
    int number;
    struct _Node* next;
    struct _Node* prev;
}Node;

Node* head;
Node* createList(int n) {
    Node dummy;
    dummy.number = -1; dummy.next = NULL; dummy.prev = NULL;
    Node* tail = &dummy;
    Node* newNode = NULL;

    for(int i = 1; i <= n; i++){
        newNode = (Node*)malloc(sizeof(Node));
        newNode->number = i; newNode->next = NULL; newNode->prev = tail;
        tail->next = newNode; tail = tail->next;
    }
    tail->next = dummy.next;
    dummy.next->prev = tail;

    return dummy.next;
}

void solveJosephus(int n, int k) {
    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->number = 0; dummy->next = head; dummy->prev = head;
    Node*tail = dummy, *deleteNode = dummy;

    bool clockWise = false;
    int steps, num;
    while(k--){
        scanf("%d", &num);
        clockWise = (num&1) ? true : false;
        steps = (num%n) ? num%(n--) : (n--);
        while(steps--) tail = (clockWise) ? tail->next : tail->prev;

        free(deleteNode); deleteNode = tail;
        tail->next->prev = tail->prev;
        tail->prev->next = tail->next;
        printf("%d\n", tail->number);
    }
}
