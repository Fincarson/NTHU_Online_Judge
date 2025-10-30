#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

int main(){
    int n;
    scanf("%d", &n);

    /* Find the size of the pattern */
    int size = 1;
    for(int i=1; i<=n; i++){
        size = size * 2 + 1;
    }

    /* Making 2D array */
    int ** board;
    board = (int**)malloc(size * sizeof(int*));
    for(int i=0; i<size; i++){
        board[i] = (int*)malloc(size * sizeof(int));
        /* Set the value of the array inside to be 0 */
        memset(board[i], 0, size * sizeof(int));
    }

    /* Calling the function */
    pattern(board, n);

    /* Print */
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%c", board[i][j] ? '#' : ' ');
        }
        printf("\n");
    }

    return 0;
}