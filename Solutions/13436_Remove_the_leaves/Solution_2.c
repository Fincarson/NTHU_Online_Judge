#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int idx;
    struct Node *next;
} Node;

int count[20001], operation[20001], queue[20001];
Node* head[20001];  // Directly store adjacency lists

void addEdge(int u, int v) {
    Node* newNodeA = (Node*)malloc(sizeof(Node));
    newNodeA->idx = u;
    newNodeA->next = head[v];
    head[v] = newNodeA;

    Node* newNodeB = (Node*)malloc(sizeof(Node));
    newNodeB->idx = v;
    newNodeB->next = head[u];
    head[u] = newNodeB;

    count[u]++;
    count[v]++;
}

void freeMemory(int N) {
    for (int i = 1; i <= N; i++) {
        Node* temp = head[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
        head[i] = NULL;  // Reset for next test case
    }
}

int solve(int N, int K) {
    for (int i = 1; i <= N; i++) {
        head[i] = NULL;  // Initialize adjacency list
        count[i] = 0;
        operation[i] = 999999;
    }

    // Read edges
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int qSize = 0;
    for (int i = 1; i <= N; i++)
        if (count[i] == 1) queue[qSize++] = i, operation[i] = 1;

    // BFS-like processing
    for (int i = 0; i < qSize; i++) {
        int node = queue[i];

        for (Node* temp = head[node]; temp; temp = temp->next) {
            int neighbor = temp->idx;
            if (--count[neighbor] == 1 && operation[neighbor] == 999999) {
                queue[qSize++] = neighbor;
                operation[neighbor] = operation[node] + 1;
            }
        }
    }

    int removed = 0;
    for (int i = 1; i <= N; i++)
        if (operation[i] <= K) removed++;

    freeMemory(N);
    return N - removed;
}

int main() {
    int T, N, K;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &K);
        printf("%d\n", solve(N, K));
    }
    return 0;
}