#include <stdio.h>
int array[3100][3100];
void karpetRibet(int x, int y, int n, int dir) {
    if (n == 0)return;
    int h = n / 2;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            array[x + i][y + j] = 1;
        }
    }
    if (dir != 4)karpetRibet(x - h, y - h, h, 1);
    if (dir != 3)karpetRibet(x - h, y + n, h, 2);
    if (dir != 2)karpetRibet(x + n, y - h, h, 3);
    if (dir != 1)karpetRibet(x + n, y + n, h, 4);
}

int main()
{
    int n;
    scanf("%d", &n);
    n--;
    int d = 1 << n;             // 2 to the power of n
    int span = (d - 1) * 2 + d;     // span of carpet

    for (int i = 0;i < span;i++) {
        for (int j = 0;j < span;j++) {
            array[i][j] = 0;
        }
    }

    karpetRibet(d - 1, d - 1, d, 0);

    for (int i = 0;i < span;i++) {
        for (int j = 0;j < span;j++) {
            if (array[i][j] == 1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}