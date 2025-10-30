#include <stdio.h>

int w, h;
char _DomoMaze[20][20];
int cal[20][20];

int main()
{
    scanf("%d %d", &w, &h);

    for (int i = 1; i <= w; i++)
        for (int k = 1; k <= h; k++)
            scanf(" %c", &_DomoMaze[i][k]);

    for (int i = 0; i <= w; i++) cal[i][0] = 0;
    for (int i = 0; i <= h; i++) cal[0][i] = 0;

    cal[0][0] = 1;

    for (int i = 1; i <= w; i++)
        for (int k = 1; k <= h; k++)
        {
            if (_DomoMaze[i][k] == '1') cal[i][k] = 0;
            else cal[i][k] = cal[i - 1][k] + cal[i][k - 1] + cal[i - 1][k - 1];
        }

    printf("%d\n", cal[w][h]);
}
