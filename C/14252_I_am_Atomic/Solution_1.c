#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int vertex;
    struct _Node *next;
} Node;

void connectEdges(Node **head, int *count, int input) {
    int u, v;
    while (input--) {
        scanf("%d%d", &u, &v);

        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = u;
        newNode->next = head[v];
        head[v] = newNode;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = v;
        newNode->next = head[u];
        head[u] = newNode;

        count[u]++;
        count[v]++;
    }
}

// BFS to find the farthest node and depth from a starting node
void BFS(Node **head, int *queue, int *count, int *depth, int vertices, int start, int *farthestNode, int *maxDepth) {
    for (int i = 1; i <= vertices; i++) depth[i] = -1;  // Reset depths
    int qCount = 0;

    queue[qCount++] = start;
    depth[start] = 0;

    for (int i = 0; i < qCount; i++) {
        for (Node *current = head[queue[i]]; current; current = current->next) {
            if (depth[current->vertex] == -1) {  // Unvisited node
                depth[current->vertex] = depth[queue[i]] + 1;
                queue[qCount++] = current->vertex;
            }
        }
    }

    *maxDepth = 0;
    *farthestNode = start;
    for (int i = 1; i <= vertices; i++) {
        if (depth[i] > *maxDepth) {
            *maxDepth = depth[i];
            *farthestNode = i;
        }
    }
}

int main(void) {
    int vertices;
    scanf("%d", &vertices);

    Node **head = (Node**)malloc((vertices+1) * sizeof(Node*));
    int *queue = (int*)malloc((vertices+1) * sizeof(int));
    int *count = (int*)malloc((vertices+1) * sizeof(int));
    int *depth = (int*)malloc((vertices+1) * sizeof(int));

    for (int i = 1; i <= vertices; i++) {
        head[i] = NULL;
        count[i] = 0;
    }

    connectEdges(head, count, vertices - 1);

    int farthestNode, maxDepth;

    // First BFS: Find the farthest node from any starting node
    BFS(head, queue, count, depth, vertices, 1, &farthestNode, &maxDepth);

    // Second BFS: Find the farthest distance from that node (diameter)
    BFS(head, queue, count, depth, vertices, farthestNode, &farthestNode, &maxDepth);

    printf("%d", (maxDepth + 1) / 2);

    for (int i = 1; i <= vertices; i++) {
        Node *temp = head[i];
        while (temp) {
            Node *deleteNode = temp;
            temp = temp->next;
            free(deleteNode);
        }
    }
    free(head);
    free(queue);
    free(count);
    free(depth);

    return 0;
}