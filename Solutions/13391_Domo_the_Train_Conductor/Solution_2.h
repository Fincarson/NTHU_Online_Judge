#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddFront(Node** head, Node** back, int num){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->idx = -1;
    temp->next = *head;
    (*head)->idx = num;
    *head = temp;
}
void AddBack(Node** head, Node** back, int num){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->idx = num;
    temp->next = NULL;
    (*back)->next = temp;
    *back = temp;
}

void DeleteFront(Node** head, Node** back){
    if((*back)->idx==-1)return;
    Node *temp = *head;
    *head = (*head)->next;
    (*head)->idx = -1;
    free(temp);
}

void Delete(Node** head, Node** back, int num){
    Node *temp = *head;
    Node *temp2;
    while(temp!=NULL){
        *back = temp;
        if(temp->next==NULL){
            return;
        }else if((temp->next)->idx == num){
            temp2 = (temp->next)->next;
            free(temp->next);
            temp->next = temp2;
        }else{
            temp = temp->next;
        }
    }
}

void Swap(Node** head, Node** back){
    Node *temp = *head;
    Node *tempf;
    Node *tempb;
    temp = temp->next;
    free(*head);
    *back = temp;
    tempb = temp;
    temp = temp->next;
    while(temp!=NULL){
        tempf = temp->next;
        temp->next = tempb;
        tempb = temp;
        temp = tempf;
    }
    (*back)->next = NULL;
    Node *temp1 = malloc(sizeof(Node));
    temp1->idx = -1;
    temp1->next = tempb;
    *head = temp1;
}