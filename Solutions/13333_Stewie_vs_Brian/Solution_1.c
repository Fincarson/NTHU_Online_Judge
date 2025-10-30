#include<stdio.h>

//Initialization
int array[9][9], rowCheck[9][9], colCheck[9][9], box[9][9], end;

//Main Code
void sudoku(int x, int y) {
    if (x == 9) { end = 1; return; }
    if (y == 9) { sudoku(x + 1, y - 10); if (end) { return; } }
    else if (array[x][y]) { sudoku(x, y + 1); if (end) { return; } }
    else {
        for (int i = 1; i <= 9; i++) {
            int gridPosition = (x / 3) * 3 + (y / 3);
            if (rowCheck[x][i - 1] || colCheck[y][i - 1] || box[gridPosition][i - 1]) { continue; }
            else {
                rowCheck[x][i - 1] = 1; colCheck[y][i - 1] = 1; box[gridPosition][i - 1] = 1; array[x][y] = i;
                sudoku(x, y + 1); if (end) { return; }
                rowCheck[x][i - 1] = 0; colCheck[y][i - 1] = 0; box[gridPosition][i - 1] = 0; array[x][y] = 0;
            }
        }
    }
}

int main(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &array[i][j]);
            if (array[i][j] != 0) {
                int num = array[i][j] - 1;
                rowCheck[i][num] = 1; colCheck[j][num] = 1;
                int gridPosition = (i / 3) * 3 + (j / 3);
                box[gridPosition][num] = 1;
            }
        }
    }
    sudoku(0, 0);
    if (end) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (j == 0) { printf("%d", array[i][j]); }
                else { printf(" %d", array[i][j]); }
            }
            printf("\n");
        }
    }
    else { printf("no solution\n"); }
    return 0;
}