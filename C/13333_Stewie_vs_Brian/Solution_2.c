#include <stdio.h>
#define bool int
#define false 0
#define true 1

int good = false;
int _list[10][10];
int row[10][10];
int column[10][10];
int square[10][10];

int seq[9] = { 5, 2, 7, 1, 9, 3, 4, 6, 8 };

int check(int r, int c, int num) {
    if (row[r][num] == 1) return false;
    if (column[c][num] == 1) return false;
    if (square[r / 3 * 3 + c / 3][num] == 1) return false;
    return true;
}

void go(int src) {
    if (src == 81) {
        for (int i = 0; i < 9; i++)
            for (int k = 0; k < 9; k++)
                printf("%d%c", _list[i][k], (k != 8 ? ' ' : '\n'));
        good = true;
        return;
    }
    int r = src / 9;
    int c = src % 9;
    if (_list[r][c] != 0) go(src + 1);
    else {
        for (int i = 8; i >= 0; i--) {
            if (check(r, c, seq[i])) {
                row[r][seq[i]] = 1;
                column[c][seq[i]] = 1;
                square[r / 3 * 3 + c / 3][seq[i]] = 1;
                _list[r][c] = seq[i];
                go(src + 1);
                if (good)return;
                _list[r][c] = 0;
                row[r][seq[i]] = 0;
                column[c][seq[i]] = 0;
                square[r / 3 * 3 + c / 3][seq[i]] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int k = 0; k < 9; k++) {
            scanf("%d", &_list[i][k]);
            if (_list[i][k] != 0) {
                row[i][_list[i][k]] = 1;
                column[k][_list[i][k]] = 1;
                square[i / 3 * 3 + k / 3][_list[i][k]] = 1;
            }
        }
    go(0);
    if (!good) printf("no solution\n");
}