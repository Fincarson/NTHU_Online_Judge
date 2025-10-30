#include <stdio.h>

int n, k;
char mp[20][20];
int asi_ele[20] = {};
int asi_vis[20] = {};

int afr_row[20] = {};
int afr_dia1[25] = {};
int afr_dia2[25] = {};

int ans = 0;

void dfs1(int x) {
    if (x == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (asi_vis[i] || mp[x][i] == 'X')
            continue;
        if ((x >= 2) && ((asi_ele[x - 2] - i == 2) || (asi_ele[x - 2] - i == -2)))
            continue;
        asi_vis[i] = 1;
        asi_ele[x] = i;
        dfs1(x + 1);
        asi_vis[i] = 0;
    }
}

void dfs2(int x) {
    if (x == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (mp[x][i] == 'X')
            continue;
        if (afr_row[i] || afr_dia1[x + i] || afr_dia2[x - i + n])
            continue;
        afr_row[i] = afr_dia1[x + i] = afr_dia2[x - i + n] = 1;
        dfs2(x + 1);
        afr_row[i] = afr_dia1[x + i] = afr_dia2[x - i + n] = 0;
    }

}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0;i < n;i++) {
        scanf("%s", mp[i]);
    }
    if (k)
        dfs1(0);
    else
        dfs2(0);
    printf("%d", ans);
    return 0;
}
