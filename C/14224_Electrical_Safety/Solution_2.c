#include <stdio.h>
#include <stdlib.h>

void heapify(long long *heap, int size, int root){
    int smallest = root;
    int left = 2*root + 1;
    int right = 2*root +2;
    // Store indices, NOT the values inside the array

    if(left < size && heap[left] < heap[smallest]) smallest = left;
    if(right < size && heap[right] < heap[smallest]) smallest = right;

    if(smallest != root){
        long long temp = heap[root];
        heap[root] = heap[smallest];
        heap[smallest] = temp;

        heapify(heap, size, smallest);
    }
}

long long extractMin(long long *heap, int *size) {
    long long minValue = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return minValue;
}

void insertHeap(long long *heap, int *size, long long value) {
    int i = (*size)++;
    heap[i] = value;
    heapify(heap, *size, i);
}

long long calculateCost(long long *appliances, int N){
    int heapSize = N;
    long long totalCost = 0;

    // Sort the array to build the Min-Heap
    for(int i = (heapSize/2)-1; i >= 0; i--){
        heapify(appliances, heapSize, i);
    }

    long long first = 0, second = 0, merged = 0;
    while (heapSize > 1) {
        first = extractMin(appliances, &heapSize);
        second = extractMin(appliances, &heapSize);
        merged = first + second;
        totalCost += merged;
        insertHeap(appliances, &heapSize, merged);
    }

    return totalCost;
}

int main(void){
    int N; scanf("%d", &N);

    long long *appliances = (long long*)malloc((N+1)*sizeof(long long));
    for(int i = 0; i < N; i++) scanf("%lld", &appliances[i]);

    printf("%lld", calculateCost(appliances, N));
    free(appliances);
    return 0;
}