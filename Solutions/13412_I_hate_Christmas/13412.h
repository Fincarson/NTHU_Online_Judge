#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int val;
    struct _Node *next;
}Node;
Node* Solver(Node* head, int k);