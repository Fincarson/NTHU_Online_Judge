#include <stdio.h>
#include <stdlib.h>
#include "function.h"


Node* createNode(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}
void printList(Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    
    int tmp;
    scanf("%d", &tmp);
    head = createNode(tmp);
    Node* tail = head;
    
    while(1)
    {
        scanf("%d", &tmp);
        if(tmp==-1)
            break;
        tail->next = createNode(tmp);
        tail = tail->next;
    }
    
    int k;
    scanf("%d", &k);
    Node* res = Solver(head, k);
    printList(res);
    
    return 0;
}