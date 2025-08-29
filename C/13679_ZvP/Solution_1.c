#include<stdio.h>
int n;
int grid[11][11] = { 0 };
int col[11];
int digLeft[100];
int digRight[100];
long long max = -12345678912345ll;

void star(int row, long long sum) {
    if (row == n) {
        if (sum > max) max = sum;
        return;
    }
    for (int collumn = 0; collumn < n; collumn++) {
        if (!col[collumn] && !digLeft[collumn + row] && !digRight[collumn - row + n]) {
            col[collumn] = digLeft[collumn + row] = digRight[collumn - row + n] = 1;
            star(row + 1, sum + grid[row][collumn]);
            col[collumn] = digLeft[collumn + row] = digRight[collumn - row + n] = 0;
        }
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    star(0, 0);
    if (max != -12345678912345ll) printf("%lld\n", max);
    else printf("no solution\n");
    return 0;
}
