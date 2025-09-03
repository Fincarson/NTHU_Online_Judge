#include <stdio.h>

//Initialization
char grid[2048][2048];
char alphabet[2048];
int spread[2048];
int L, D, totalLayers, indexCenter;
int UP, DOWN, LEFT, RIGHT;

//Function(s)
char check(tempX, tempY) {
    while (grid[tempX][tempY] < 'A') { grid[tempX][tempY] += 26; }
}

//Main Code
int main(void) {
    scanf("%d %d", &L, &D);
    totalLayers = (L * 2) - 1; indexCenter = L - 1;

    //Spaces
    for (int i = 0; i < totalLayers; i++) {
        for (int j = 0; j < totalLayers; j++) {
            grid[i][j] = ' ';
        }
    }

    //Alphabets and spread
    for (int i = 0; i < totalLayers; i++) {
        int n = i % 26;
        if (i < L) {
            alphabet[i] = 'A' + n;
            spread[i] = 0 + i;
        }
        else {
            alphabet[i] = alphabet[i - 1] - 1;
            spread[i] = spread[i - 1] - 1;
            while (alphabet[i] < 'A') { alphabet[i] += 26; }
        }
    }

    //Spread out
    grid[indexCenter][indexCenter] = alphabet[D];
    UP = indexCenter; DOWN = indexCenter;
    for (int i = 0; i <= spread[D]; i++) {
        grid[UP][indexCenter] = grid[indexCenter][indexCenter] - i; check(UP, indexCenter);
        grid[DOWN][indexCenter] = grid[indexCenter][indexCenter] - i; check(DOWN, indexCenter);
        LEFT = indexCenter - 1; RIGHT = indexCenter + 1;
        for (int j = i; j < spread[D]; j++) {
            grid[UP][LEFT] = grid[UP][LEFT + 1] - 1; check(UP, LEFT);
            grid[UP][RIGHT] = grid[UP][RIGHT - 1] - 1; check(UP, RIGHT);
            grid[DOWN][LEFT] = grid[DOWN][LEFT + 1] - 1; check(DOWN, LEFT);
            grid[DOWN][RIGHT] = grid[DOWN][RIGHT - 1] - 1; check(DOWN, RIGHT);
            LEFT--; RIGHT++;
        }
        UP--; DOWN++;
    }

    //Output
    for (int i = 0; i < totalLayers; i++) {
        for (int j = 0; j < totalLayers; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}