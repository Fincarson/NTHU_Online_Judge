#include <stdio.h>
#include <stdlib.h>
int row;
int col;
int flag = 0;
int check[1001][1001];


void find_destination(int px, int py, char map[row][col]) {
    check[px][py] = 1;
    if (map[px][py] == 'D') {
        flag = 1;
        return;
    }
    else if (map[px][py] == 'x') return;

    if (px - 1 >= 0) {
        if (check[px - 1][py] == 0)
            find_destination(px - 1, py, map);
    }
    if (px + 1 < row) {
        if (check[px + 1][py] == 0)
            find_destination(px + 1, py, map);
    }
    if (py - 1 >= 0) {
        if (check[px][py - 1] == 0)
            find_destination(px, py - 1, map);
    }
    if (py + 1 < col) {
        if (check[px][py + 1] == 0)
            find_destination(px, py + 1, map);
    }

}

int main() {
    int m, n, testcase_amount;
    scanf("%d %d", &m, &n);
    scanf("%d", &testcase_amount);
    row = m;
    col = n;
    char map[m][n];
    int pos_x, pos_y;

    while (testcase_amount > 0) {
        flag = 0;
        for (int i = 0; i < m; i++) {
            // getchar();
            for (int j = 0; j < n; j++) {
                check[i][j] = 0;
                scanf(" %c", &map[i][j]);
                if (map[i][j] == 'S') {
                    pos_x = i;
                    pos_y = j;
                }
            }
        }


        find_destination(pos_x, pos_y, map);

        if (flag == 1) printf("ESCAPE!\n");
        else printf("QQ\n");

        testcase_amount--;
    }

    return 0;
}