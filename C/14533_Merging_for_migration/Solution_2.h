#include <stdio.h>
#include <stdlib.h>

struct data {
    int index;
    int age;
    int height;
};
void merge_by_age(int l, int m, int r, struct data* arr) {
    int n1 = m - l + 1;
    int n2 = r - m;

    struct data* L = (struct data*)malloc(n1 * sizeof(struct data));
    struct data* R = (struct data*)malloc(n2 * sizeof(struct data));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].age < R[j].age ||
            (L[i].age == R[j].age && L[i].index <= R[j].index)) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_by_height(int l, int m, int r, struct data* arr) {
    int n1 = m - l + 1;
    int n2 = r - m;

    struct data* L = (struct data*)malloc(n1 * sizeof(struct data));
    struct data* R = (struct data*)malloc(n2 * sizeof(struct data));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].height < R[j].height ||
            (L[i].height == R[j].height && L[i].index <= R[j].index)) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}
