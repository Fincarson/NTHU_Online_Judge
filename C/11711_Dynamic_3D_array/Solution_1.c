#include<stdio.h>
#include<stdlib.h>

unsigned*** new_3d_array(unsigned n, unsigned m,unsigned k){
    unsigned ***arr;
    arr       = (unsigned***) malloc(n *         sizeof(unsigned**));
    arr[0]    = (unsigned**)  malloc(n * m *     sizeof(unsigned*));
    arr[0][0] = (unsigned*)   malloc(n * m * k * sizeof(unsigned));

    for(int i = 0; i<n; i++){
        arr[i] = arr[0] + m*i;
        for(int j = 0; j<m; j++){
            arr[i][j] = arr[0][0] + m*k*i + k*j;
        }
    }
    return arr;
}


void delete_3d_array(unsigned ***arr){
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}