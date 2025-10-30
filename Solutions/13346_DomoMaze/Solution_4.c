#include <stdio.h>

int dp[20][20][4];

int x[2] = { -1, -1 };
int y[2] = { -1, -1 };
int idx;

int main() {
    int w, h;
    scanf("%d %d", &w, &h);
    getchar();

    for (int i = 1; i <= w; i++) {
        for (int k = 1; k <= h; k++)
            if (getchar() == '1') {
                x[idx] = i;
                y[idx] = k;
                idx++;
            }

        getchar();
    }

    dp[0][0][3] = 1;

    for (int bit = 3; bit >= 0; bit--) {
        for (int i = 1; i <= w; i++)
            for (int k = 1; k <= h; k++) {
                int sum = dp[i - 1][k][bit] + dp[i][k - 1][bit] + dp[i - 1][k - 1][bit];

                int not_tp = 1;

                if (x[0] == i && y[0] == k && (bit % 2)) {
                    not_tp = 0;
                    dp[i][k][bit] = 0;
                    dp[i - 2][k - 2][bit - 1] += sum;
                }

                if (x[1] == i && y[1] == k && bit >= 2) {
                    not_tp = 0;
                    dp[i][k][bit] = 0;
                    dp[i - 2][k - 2][bit - 2] += sum;
                }

                if (not_tp)
                    dp[i][k][bit] += dp[i - 1][k][bit] + dp[i][k - 1][bit] + dp[i - 1][k - 1][bit];
            }
    }

    printf("%d\n", dp[w][h][0] + dp[w][h][1] + dp[w][h][2] + dp[w][h][3]);
}