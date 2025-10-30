#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void sort_by_age(int l, int r, struct data *arr) {
    if (l < r) {
        int m = l + (r - l) / 2;

        sort_by_age(l, m, arr);
        
        print_elephants(l, m, arr);
        sort_by_age(m + 1, r, arr);
        
        print_elephants(m + 1, r, arr);
        merge_by_age(l, m, r, arr);
        
        print_elephants(l, r, arr);
    }
}


void sort_by_height(int l, int r, struct data *arr) {
    if (l < r) {
        int m = l + (r - l) / 2;

        sort_by_height(l, m, arr);
        
        print_elephants(l, m, arr);
        sort_by_height(m + 1, r, arr);
         
        print_elephants(m + 1, r, arr);
        merge_by_height(l, m, r, arr);
    
        print_elephants(l, r, arr);
    }
}


void print_elephants(int l, int r, struct data *arr) {
    for (int i = l; i <= r; i++) {
        if(i != l) printf(" ");
        printf("%d", arr[i].index);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct data *elephants = (struct data *)malloc(sizeof(struct data) * n);

    for (int i = 0; i < n; i++) {
        elephants[i].index = i + 1;
        scanf("%d %d", &elephants[i].age, &elephants[i].height);
    }


    sort_by_age(0, n - 1, elephants);
    printf("\n");

    sort_by_height(0, n - 1, elephants);
    free(elephants);
    return 0;
}