#include<stdio.h>

/* INITIALIZATION(S) */
int H, W, A, B;
//H represents the height of the map
//W represents the width of the map
//A and B represents the location of "Wilson" ball

long long map[16][16], answer;
//Set the map and the answer


/* FUNCTION(S) */
void dynamic();
//Use dynamic programming when there's no (1)

void recursion(int x, int y, int validReverse);
//Use recursion when there is (1)



/*=======================================================*/


/* MAIN CODE */
int main(void){
    scanf("%d%d", &H, &W);
    //Scan the height and the width of the map

    scanf("%d%d", &A, &B);
    //Scan the location of the "Wilson" ball

    int validRecursion = 0;
    //If it's valid to use recursion
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%1lld", &map[i][j]);
            //Scan if it's 1 or 0

            if(map[i][j]) validRecursion = 1;
            //If there's 1, then it is valid to use recursion
        }
    }
    if(validRecursion == 1) recursion(0, 0, 1);
    //Use recursion when there's 1

    else dynamic();
    //Use dynamic programming if there's no 1

    printf("%lld\n", answer);
    //Print the answer

    return 0;
}


void dynamic() {
    for (int i = 0; i < H; i++) map[i][0] = 1;
    for (int j = 0; j < W; j++) map[0][j] = 1;
    //Set up the first row and the first col to be (1)s
    /*
    1 1 1 1 1 ...
    1 0 0 0 0 ...
    1 0 0 0 0 ...
    1 0 0 0 0 ...
    1 0 0 0 0 ...
    . . . . .
    . . . . .
    */

    //Start from map[1][1]
    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            map[i][j] = map[i - 1][j] + map[i][j - 1] + map[i - 1][j - 1];
            //Dynamic Programming
        }
    }
    answer = map[A][B];
    //After it's done, store the answer
}


void recursion(int x, int y, int validReverse) {
    if (x == A && y == B) {
        answer++;
        return;
    } //When it reaches the "Wilson" ball, it will count as A WAY and return to find another way

    int is_reverse_block = map[x][y];
    if (is_reverse_block == 1) validReverse = -validReverse;
    //Or you can do this:
    //if (is_reverse_block) validReverse *= -1;

    //If it's no valid, do original movements
    if (validReverse == 1) {
        if (x + 1 < H) recursion(x + 1, y, validReverse); //Goes down
        if (y + 1 < W) recursion(x, y + 1, validReverse); //Goes right
        if (x + 1 < H && y + 1 < W) recursion(x + 1, y + 1, validReverse); //Goes right diagonally
    }

    //If validReverse != 1, do it reverse
    else {
        if (x + 1 < H) recursion(x + 1, y, validReverse); //Goes down
        if (y - 1 >= 0) recursion(x, y - 1, validReverse); //Goes left
        if (x + 1 < H && y - 1 >= 0) recursion(x + 1, y - 1, validReverse); //Goes left diagonally
    }


    if (is_reverse_block == 1) validReverse = -validReverse;
    //This is to backtrack from 1 so it can find another way using original movements
    //If this part of the code does not exist, what should have been original movements, becomes reverse movements
}