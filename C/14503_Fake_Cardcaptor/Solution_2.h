#include <stdio.h>
#include <stdlib.h>

extern const int MAX_ARRAY;
extern const int MAX_ELEMENT;

typedef void (*myFunction)(int**, int*);

void placeFunction(int** arr, int* size);
void deleteFunction(int** arr, int* size);
void swapFunction(int** arr, int* size);
void reverseFunction(int** arr, int* size);
void popFunction(int** arr, int* size);
void shiftFunction(int** arr, int* size);
void sortFunction(int** arr, int* size);
void printFunction(int** arr, int* size);

myFunction assignFunction(char* str);

/* =================================== TODO =================================== */
// Param: index, size, elements
void placeFunction(int** arr, int* size) {
    int index, input_size;
    scanf("%d %d", &index, &input_size);
    // fprintf(stderr, "Place %d %d\n", index, input_size);

    for (int i = 0; i < input_size; i++) {
        if (size[index] + i >= MAX_ELEMENT) {
            int trash;
            scanf("%d", &trash);
        }
        else {
            scanf("%d", &arr[index][size[index] + i]);
        }
    }
    size[index] = MAX_ELEMENT < size[index] + input_size ? MAX_ELEMENT : size[index] + input_size;
}

// Param: index
void deleteFunction(int** arr, int* size) {
    int index;
    scanf("%d", &index);
    size[index] = 0;
}

// Param: index1 index2
void swapFunction(int** arr, int* size) {
    int idx1, idx2;
    scanf("%d%d", &idx1, &idx2);
    int* temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;

    int size_temp = size[idx1];
    size[idx1] = size[idx2];
    size[idx2] = size_temp;
}

// Param: None
void reverseFunction(int** arr, int* size) {
    int idx1 = 0, idx2 = MAX_ARRAY - 1;
    while (idx1 < idx2) {
        while (idx1 < MAX_ELEMENT && size[idx1] == 0) idx1++;
        while (idx2 >= 0 && size[idx2] == 0) idx2--;
        if (idx1 >= idx2) break;

        int* temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;

        int size_temp = size[idx1];
        size[idx1] = size[idx2];
        size[idx2] = size_temp;

        idx1++; idx2--;
    }
}


void popFunction(int** arr, int* size) {
    int index, pop_num;
    scanf("%d %d", &index, &pop_num);
    size[index] = size[index] - pop_num;
    size[index] = size[index] < 0 ? 0 : size[index];
}

void shiftFunction(int** arr, int* size) {
    int shift;
    scanf("%d", &shift);
    while (shift < 0)
        shift += MAX_ARRAY;

    int* temp[MAX_ARRAY];
    int temp_size[MAX_ARRAY];
    for (int i = 0; i < MAX_ARRAY; i++) {
        temp[(i + shift) % MAX_ARRAY] = arr[i];
        temp_size[(i + shift) % MAX_ARRAY] = size[i];
    }
    for (int i = 0; i < MAX_ARRAY; i++) {
        arr[i] = temp[i];
        size[i] = temp_size[i];
    }

}

int cmpf(const void* elem1, const void* elem2)
{
    int a = *(int*)elem1;
    int b = *(int*)elem2;
    return (a > b) - (a < b);
}

void sortFunction(int** arr, int* size) {
    int idx;
    scanf("%d", &idx);
    qsort(arr[idx], size[idx], sizeof(int), cmpf);
}

void printFunction(int** arr, int* size) {
    int flag = 0;
    for (int i = 0; i < MAX_ARRAY; i++) {
        if (size[i] != 0) {
            flag = 1;
            printf("%d:", i);

            for (int j = 0; j < size[i]; j++) {
                printf(" %d", arr[i][j]);
            }
            printf("\n");
        }
    }
    if (!flag) {
        printf("Empty QQ\n");
    }
}


myFunction assignFunction(char* str) {
    if (strcmp(str, "place") == 0) return &placeFunction;
    if (strcmp(str, "delete") == 0) return &deleteFunction;
    if (strcmp(str, "swap") == 0) return &swapFunction;
    if (strcmp(str, "reverse") == 0) return &reverseFunction;
    if (strcmp(str, "pop") == 0) return &popFunction;
    if (strcmp(str, "shift") == 0) return &shiftFunction;
    if (strcmp(str, "sort") == 0) return &sortFunction;
    if (strcmp(str, "print") == 0) return &printFunction;
    return NULL;
}
