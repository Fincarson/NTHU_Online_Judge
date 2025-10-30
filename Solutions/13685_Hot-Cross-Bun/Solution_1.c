#include <stdio.h>
int n, m;
char grid[21][21];

long min = -1;
int dr[5] = { 0, 0, 0, -1, 1 };
int dc[5] = { 0, -1, 1, 0, 0 };

void cross(int row, int col, int count) {
    if (row == n + 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j] == 'o')
                    return;
            }
        }
        if (min == -1 || count < min) min = count;
    }
    else {
        int nextrow = row;
        int nextcol = col + 1;
        if (nextcol == m + 1) {
            nextrow++;
            nextcol = 1;
        }
        cross(nextrow, nextcol, count);
        for (int i = 0; i < 5; i++) {
            if (grid[row + dr[i]][col + dc[i]] == 'o' && (row + dr[i] <= n) &&
                (col + dc[i] <= m))
                grid[row + dr[i]][col + dc[i]] = 'x';
            else if (grid[row + dr[i]][col + dc[i]] == 'x' && (row + dr[i] <= n) &&
                (col + dc[i] <= m))
                grid[row + dr[i]][col + dc[i]] = 'o';
        }
        cross(nextrow, nextcol, count + 1);
        for (int i = 0; i < 5; i++) {
            if (grid[row + dr[i]][col + dc[i]] == 'o' && (row + dr[i] <= n) &&
                (col + dc[i] <= m))
                grid[row + dr[i]][col + dc[i]] = 'x';
            else if (grid[row + dr[i]][col + dc[i]] == 'x' && (row + dr[i] <= n) &&
                (col + dc[i] <= m))
                grid[row + dr[i]][col + dc[i]] = 'o';
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }
    cross(1, 1, 0);
    if (min == -1) printf("no solution\n");
    else printf("%ld\n", min);

    return 0;
}
