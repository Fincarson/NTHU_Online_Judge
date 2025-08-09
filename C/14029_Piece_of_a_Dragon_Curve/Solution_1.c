#include <stdio.h>

// define:
// up = 0
// right = 1
// down = 2
// left = 3

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int F(long long x) { // function to search the direction
    if (x == 1)
        return 0; // base case is up

    long long pair = 1;
    while (pair < x)
        pair *= 2;

    // in general, direction of x if x > 1 is
    // the 90 deg rotate of the mirrored index
    // up -> right -> down -> left -> up
    return (F(pair - x + 1) + 1) % 4;
}

int main() {
    int n;
    long long start;
    scanf("%d%lld", &n, &start);

    // initialize to have information size of array to print
    // update every time we move
    int max_up = 0;
    int min_down = 0;
    int max_right = 0;
    int min_left = 0;

    // current movement
    int cur_x = 0;
    int cur_y = 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = F(start);
        switch (arr[i]) {
        case 0: // go up
            cur_x += 2;
            max_up = max(max_up, cur_x);
            break;
        case 1: // go right
            cur_y += 2;
            max_right = max(max_right, cur_y);
            break;
        case 2: // go down
            cur_x -= 2;
            min_down = min(min_down, cur_x);
            break;
        case 3: // go left
            cur_y -= 2;
            min_left = min(min_left, cur_y);
            break;
        default:
            break;
        }
        start++;
    }

    /*
    In the end, we will have this array
    ---------------------------------------------------
    |                       ^                         |
    |                       |                         |
    |                       |                         |
    |                     max_up                      |
    |                       |                         |
    |                       |                         |
    |                       v                         |
    |  <-- min_left --> initialize <-- max_right -->  |
    |                       ^                         |
    |                       |                         |
    |                       |                         |
    |                    min_down                     |
    |                       |                         |
    |                       |                         |
    |                       v                         |
    --------------------------------------------------|
    */

    int row = max_up - min_down + 1;
    int col = max_right - min_left + 1;

    int x = max_up;
    int y = -min_left;

    char board[row][col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            board[i][j] = '.';

    board[x][y] = '#';
    for (int i = 0; i < n; i++) {
        switch (arr[i]) {
        case 0:
            board[--x][y] = '#';
            board[--x][y] = '#';
            break;
        case 1:
            board[x][++y] = '#';
            board[x][++y] = '#';
            break;
        case 2:
            board[++x][y] = '#';
            board[++x][y] = '#';
            break;
        case 3:
            board[x][--y] = '#';
            board[x][--y] = '#';
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

}