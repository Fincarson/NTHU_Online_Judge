#include <stdio.h>
int a[8];
int b[8][8];
int small = 2147483647;
int all = 0;
int testcount;

int count(int side) {
    int stop;
    for (int i = 0; i < 9; i++) {
        a[side] = i;
        if (i == 8) return small;
        stop = 0;
        for (int j = 0; j < side; j++) {
            if (a[side] == a[j] || side + a[side] == j + a[j] ||
                side - a[side] == j - a[j]) {
                stop = 1;
            }
        }
        if (side == 7 && stop == 0) {
            all = 0;
            for (int k = 0; k < 8; k++) all += b[k][a[k]];
            testcount += 1;
            small = (all > small) ? small : all;
        }
        else if (stop == 0) small = count(side + 1);
    }
    return small;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int ans[n];
    for (int h = 0; h < n; h++) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                scanf("%d", &b[i][j]);
            }
        }
        for (int i = 0; i < 8; i++) {
            a[i] = -1;
        }
        small = 2147483647;
        testcount = 0;
        ans[h] = count(0);
    }
    for (int h = 0; h < n; h++) {
        printf("%d", ans[h]);
        printf("\n");
    }
    return 0;
}