#include <stdio.h>

int valid(int[][9], int, int, int);
int solve(int[][9]);
int is_empty(int[][9], int*, int*);

int main() {
    int sudoku[9][9];

    for (int i = 0; i < 9; i++) scanf("%d %d %d %d %d %d %d %d %d", &sudoku[i][0], &sudoku[i][1], &sudoku[i][2], &sudoku[i][3], &sudoku[i][4], &sudoku[i][5], &sudoku[i][6], &sudoku[i][7], &sudoku[i][8]);
    if (solve(sudoku)) {
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                printf("%d", sudoku[x][y]);
                if (y == 9 - 1)printf("\n");
                else printf(" ");
            }
        }
    }
    else printf("no solution\n");
    return 0;
}

int valid(int sudoku[][9], int row, int col, int guess) {
    int corner_x = row / 3 * 3;
    int corner_y = col / 3 * 3;
    for (int x = 0; x < 9; ++x) {
        if (sudoku[row][x] == guess) return 0;
        if (sudoku[x][col] == guess) return 0;
        if (sudoku[corner_x + (x % 3)][corner_y + (x / 3)] == guess) return 0;
    }
    return 1;
}

int is_empty(int sudoku[][9], int* row, int* col) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!sudoku[i][j]) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

int solve(int sudoku[][9]) {
    int row;
    int col;
    if (!is_empty(sudoku, &row, &col)) return 1;
    for (int i = 1; i < 10; i++) {
        if (valid(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (solve(sudoku)) return 1;
            sudoku[row][col] = 0;
        }
    }
    return 0;
}