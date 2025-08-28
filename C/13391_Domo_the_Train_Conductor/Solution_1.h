#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddFront(Node** head, Node** back, int num){
    //Create a new node
    Node*newNode = (Node*)malloc(sizeof(Node));

    //Input the number into idx
    newNode->idx = num;

    //Since it's at the front, the new node points to what the *head is pointing
    newNode->next = (*head)->next;

    //Since it's at the front, the *head points to this new node
    (*head)->next = newNode;

    //If there's no node before adding
    if(*back == *head) *back = newNode;
}

void AddBack(Node** head, Node** back, int num){
    //Create a new Node
    Node*newNode = (Node*)malloc(sizeof(Node));

    //Input the number into the idx
    newNode->idx = num;

    //Since it's at the back, new node points to NULL
    newNode->next = NULL;

    //Point the previous node to this new one
    (*back)->next = newNode;

    //Set the back as the new node
    *back = newNode;
}

void DeleteFront(Node** head, Node** back){
    //If there's no node, return
    if((*head)->next ==  NULL) return;

    //Set the front node as a temporary node
    Node*temp = (*head)->next;

    //Change the *next so the head points to the next node
    (*head)->next = temp->next;

    //If the back is the temp
    if(*back == temp)*back = head;

    //free the temp to DELETE the node
    free(temp);
}

void Delete(Node** head, Node** back, int num){
    //If there's no node = return
    if((*head)->next == NULL) return;

    //Set the nodes
    Node*current = (*head)->next;
    Node*previous = *head;

    //Start (Stop when the *current reaches NULL)
    while(current != NULL){
        //If we find the matching numbers
        if(current->idx == num){
            //If the node is the back
            if(*back == current) *back = current->next == NULL? previous:current->next;

            //Deleting the node
            previous->next = current->next;
            free(current);
            current = previous->next;
        }

        //If the numbers do not match, move on to the next node
        else{
            current = current->next;
            previous = previous->next;
        }
    }
}

void Swap(Node** head, Node** back){
    //If there's no node = return
    if((*head)->next == NULL) return;

    //Set up the nodes
    Node*current = (*head)->next->next;
    Node*previous = (*head)->next;
    *back = previous;

    //Switching the pointers from pointing LEFT to pointing RIGHT
    while(current != NULL){
        Node*temp = current;
        current = current->next;
        temp->next = previous;
        previous = temp;
    }

    //Set the head and the back after switching all the pointers
    (*head)->next = previous;
    (*back)->next = NULL;

    /*
    === TIP(S) ===
    Don't try to reposition the nodes and start connecting
    Instead, just let the nodes as they are, switch the pointers, and set up the *head and *back
    Here's the visualization of what's happening in this code:

                              |back|
                                |
                                v
    1. |head| -> |1| -> |2| -> |3|-> NULL


                |back|
                  |
                  v
    2. |head| -> |1| -> |2| -> |3|-> NULL





    3. |head| -> |1| <- |2| <- |3|


              |back|
                |
                v
    4. NULL <- |1| <- |2| <- |3| <- |head|



    And the flip the picture.
    |head| -> |3| -> |2| -> |1| -> NULL



    */
}