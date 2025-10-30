#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddFront(Node** head, Node** back, int num);
void AddBack(Node** head, Node** back, int num);
void DeleteFront(Node** head, Node** back);
void Delete(Node** head, Node** back, int num);
void Swap(Node** head, Node** back);