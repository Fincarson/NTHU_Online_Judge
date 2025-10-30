#include <stdio.h>

char mp[1010][1010];
int ans = 0;
int n, m;
void dfs(int x, int y) {
    if (x<0 || y<0 || x>n || y>m || mp[x][y] != '#') return;
    mp[x][y] = '.';
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0;i < n;i++) {
        scanf("%s", mp[i]);
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (mp[i][j] == '#') {
                ans++;
                dfs(i, j);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
