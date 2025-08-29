#include<stdio.h>

int m, n, T, startX, startY, finishX, finishY;
char arr[1001][1001];

int main(void) {
    scanf("%d %d", &m, &n); scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf(" %c", &arr[i][j]);
                if (arr[i][j] == 'S') { startX = i; startY = j; }
                if (arr[i][j] == 'D') { finishX = i; finishY = j; arr[i][j] = '.'; }
            }
        }
        if (attemptEscape(startX, startY)) { printf("ESCAPE!\n"); }
        else { printf("QQ\n"); }
    }
    return 0;
}

int attemptEscape(int x, int y) {
    arr[x][y] = 'x';
    if (x == finishX && y == finishY) { return 1; }
    else {
        if (x - 1 >= 0 && arr[x - 1][y] == '.' && attemptEscape(x - 1, y)) { return 1; }
        if (x + 1 < m && arr[x + 1][y] == '.' && attemptEscape(x + 1, y)) { return 1; }
        if (y - 1 >= 0 && arr[x][y - 1] == '.' && attemptEscape(x, y - 1)) { return 1; }
        if (y + 1 < n && arr[x][y + 1] == '.' && attemptEscape(x, y + 1)) { return 1; }
    }
    return 0;
}