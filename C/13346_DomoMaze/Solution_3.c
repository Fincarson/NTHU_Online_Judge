#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int H, W;

int DP(int** original, int initial, int initX, int initY) {

    int** arr = (int**)malloc(H * sizeof(int*));
    for (int i = 0; i < H; i++) {
        arr[i] = (int*)malloc(W * sizeof(int));
        memset(arr[i], 0, sizeof(int) * W);
    }

    int ans = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == initX && j == initY) {
                arr[i][j] = initial;
            }
            else if (original[i][j] == 1) {

                /* Initialize new array */
                int** arr2 = (int**)malloc(H * sizeof(int*));
                for (int a = 0; a < H; a++) {
                    arr2[a] = (int*)malloc(W * sizeof(int));
                    memset(arr2[a], 0, sizeof(int) * W);
                    for (int b = 0; b < W; b++) {
                        arr2[a][b] = original[a][b];
                        if (i == a && b == j) {
                            arr2[a][b] = 0;
                        }
                    }
                }
                /* Recursive Calling */

                int tmp = 0;
                if (i > 0) {
                    tmp += arr[i - 1][j];
                }
                if (j > 0) {
                    tmp += arr[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    tmp += arr[i - 1][j - 1];
                }

                ans += DP(arr2, tmp, i - 2, j - 2);

            }
            else {
                if (i > 0) {
                    arr[i][j] += arr[i - 1][j];
                }
                if (j > 0) {
                    arr[i][j] += arr[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    arr[i][j] += arr[i - 1][j - 1];
                }
            }

        }
    }

    return ans + arr[H - 1][W - 1];
}

int main() {

    scanf("%d%d", &H, &W);
    int** arr = (int**)malloc(H * sizeof(int*));
    for (int i = 0; i < H; i++) arr[i] = (int*)malloc(W * sizeof(int));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    int ans = DP(arr, 1, 0, 0);
    printf("%d\n", ans);
}