#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>

int max(int x, int y) {
    return x < y ? y : x;
}

int n;
char s[30];

int check(int mask) {
    int cur = -1, ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
            if (cur != s[i] - 'a') {
                cur = s[i] - 'a';
                ans += (cnt + 1) * cnt / 2;
                cnt = 0;
            }
            cnt++;
        }
    }
    ans += (cnt + 1) * cnt / 2;
    return ans;
}

void solve() {
    scanf("%s", s);
    n = strlen(s);
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int x = check(i);
        ans = max(ans, x);
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}