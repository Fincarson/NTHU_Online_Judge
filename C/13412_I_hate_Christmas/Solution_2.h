#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int val;
    struct _Node *next;
}Node;

Node* Solver(Node* head, int k){
    Node** arr = (Node**)malloc(k*sizeof(Node*));
    Node* temp = head;
    for(int i=0;i<k;i++){
        if(temp==NULL){
            free(arr);
            return head;
        }
        arr[i] = temp;
        temp = temp->next;
    }
    for(int i=k-1;i>0;i--){
        arr[i]->next = arr[i-1];
    }
    Node* temp2 = arr[k-1];
    Node* temp3 = arr[0];
    free(arr);
    temp3->next = Solver(temp, k);
    return temp2;
}