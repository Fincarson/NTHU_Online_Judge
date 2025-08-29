#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int val;
    struct _Node *next;
}Node;

Node* Solver(Node* head, int k){
    //If K is 1, then there's no point as it will result the same
    if(k == 1) return head;

    //Set up the node(s)
    Node*groupFront = head;
    Node*groupBack = head;
    Node*reverse = head->next; //To switch point (Left) to (Right)
    Node*connector = NULL; //To connect the pointer

    //Start (Stop when it reaches the end)
    while(groupBack != NULL){
        //Determining how long the node(s) needed to be reversed based on K
        for(int i = 1; i < k && groupBack != NULL; i++) groupBack = groupBack->next;
        if(groupBack == NULL)break;

        //Connect the head to point the other node
        if(connector == NULL){
            head = groupBack;
            connector = groupFront;
        }

        //Connect the connecting node to the other node
        else{
            connector->next = groupBack;
            connector = groupFront;
        }

        //Start Reversing
        Node*nextGroup = groupBack->next;
        while(reverse != nextGroup){
            Node*temp = reverse->next;
            reverse->next = groupFront;
            groupFront = reverse;
            reverse = temp;
        }

        //Set up the groupFront and groupBack for the next reversing
        groupFront = reverse;
        groupBack = reverse;
    }

    //After it's all done:
    connector->next = groupFront;
    return head;
}
