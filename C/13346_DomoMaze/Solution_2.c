#include <stdio.h>
#include <string.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int arr[5][x][y];
    int  dp[5][x][y];

    memset(arr, 0, sizeof(int) * x * y * 5);
    memset(dp, 0, sizeof(int) * x * y * 5);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%1d", &arr[0][i][j]);
            arr[4][i][j]
                = arr[3][i][j]
                = arr[2][i][j]
                = arr[1][i][j]
                = arr[0][i][j];
        }
    }

    dp[0][0][0] = 1;

    int offset = 1;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (arr[k][i][j] == 1) {
                    // Copy the protal
                    memcpy(arr[offset], arr[k], sizeof(int) * x * y);
                    arr[offset][i][j] = 0;
                    // Initialie the portal move
                    dp[offset][i - 2][j - 2] = dp[k][i - 1][j] + dp[k][i][j - 1] + dp[k][i - 1][j - 1];

                    offset++;
                }
                else {
                    if (i > 0) dp[k][i][j] += dp[k][i - 1][j];
                    if (j > 0) dp[k][i][j] += dp[k][i][j - 1];
                    if (i > 0 && j > 0) dp[k][i][j] += dp[k][i - 1][j - 1];
                }
            }
        }
    }

    printf("%d\n", dp[0][x - 1][y - 1] + dp[1][x - 1][y - 1] + dp[2][x - 1][y - 1] + dp[3][x - 1][y - 1] + dp[4][x - 1][y - 1]);
    return 0;
}