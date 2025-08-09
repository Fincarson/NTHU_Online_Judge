#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int idx;
    struct _Node *next;
}Node;

void connectEdges(Node **head, int *count, int *queue, int *opeation, int N), addNodes(Node **head, int *count, int u, int v);
int breadthFirstSearch(Node **head, int *count, int *queue, int *operation, int N, int K);
void freeMemory(Node **head, int *count, int *queue, int *operation, int N);

int main(void){
    int T = 0, N = 0, K = 0; scanf("%d", &T);
    Node **head = NULL;
    int *count = NULL;
    int *queue = NULL;
    int *operation = NULL;

    while(T--){
        scanf("%d%d", &N, &K);
        head = (Node**)malloc((N+1)*sizeof(Node*));
        count = (int*)malloc((N+1)*sizeof(int));
        queue = (int*)malloc((N+1)*sizeof(int));
        operation = (int*)malloc((N+1)*sizeof(int));

        connectEdges(head, count, queue, operation, N);
        printf("%d\n", breadthFirstSearch(head, count, queue, operation, N, K));
        freeMemory(head, count, queue, operation, N);
    }
    return 0;
}

void connectEdges(Node **head, int *count, int *queue, int *operation, int N){
    int i = 0;
    for( i = 1; i<=N; i++){
        head[i] = NULL;
        count[i] = 0;
        operation[i] = 0;
    }

    int u, v;
    for(i = 1; i<N; i++){
        scanf("%d%d", &u, &v);
        addNodes(head, count, u, v);
    }
}

void addNodes(Node **head, int *count, int u, int v){
    Node *newNode = NULL;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->idx = u;
    newNode->next = head[v];
    head[v] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->idx = v;
    newNode->next = head[u];
    head[u] = newNode;

    count[u]++; count[v]++;
}

int breadthFirstSearch(Node **head, int *count, int *queue, int *operation, int N, int K){
    int qCount = 0, i = 0;

    for(i = 1; i<=N; i++) if(count[i] == 1){
        queue[qCount++] = i;
        operation[i] = 1;
    }

    for(i = 0; i<qCount; i++){
        for(Node *current = head[queue[i]]; current; current = current->next){
            if(--count[current->idx] == 1 && !operation[current->idx]){
                operation[current->idx] = operation[queue[i]]+1;
                queue[qCount++] = current->idx;
            }
        }
    }

    int remove = 0;
    for(i = 1; i<=N; i++) if(operation[i] <= K) remove++;

    return N-remove;
}

void freeMemory(Node **head, int *count, int *queue, int *operation, int N){
    Node *deleteNode = NULL;
    for(int i = 1; i<=N; i++){
        for(Node *temp = head[i]; temp;){
            deleteNode = temp; temp = temp->next;
            free(deleteNode); deleteNode = NULL;
        }
        head[i] = NULL;
    }
    free(head); free(count); free(queue); free(operation);
}