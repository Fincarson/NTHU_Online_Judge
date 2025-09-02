#include <stdio.h> 

int sol = 0;
int n, m;
char arr[500][500];
int visited[500][500];

void dfs(int x, int y, int step) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return;
    }
    if (arr[x][y] == '#') {
        return;
    }
    if (visited[x][y] == 1) {
        return;
    }
    else {
        visited[x][y] = 1;
    }

    if (arr[x][y] == 'M') {
        sol += 2 * step;
    }

    dfs(x + 1, y, step + 1);
    dfs(x - 1, y, step + 1);
    dfs(x, y + 1, step + 1);
    dfs(x, y - 1, step + 1);

    return;
}

int main() {
    int start_x, start_y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'S') { // We start from S,
                start_x = i;      // We will record the initial position
                start_y = j;
            }
        }
    }

    dfs(start_x, start_y, 0); // Start from S with 0 step
    printf("%d\n", sol); // Print the solution

}
