#include <stdio.h>

int CURSOL[8] = { 0 }; //Current Solution. CURSOL[n] -> The column with a queen on the n-th row.
int EQSOL[92][8] = { 0 }; //92 Eight Queen Solutions
int solIter = 0; //The # of each solution we will be getting.

void EightQueen(int row) {//int row: The row we're checking.
    for (int i = 0;i < 8;i++) {//Go through column 0~7 of the current row.

        int flag = 1;//Use a flag to check for legality.

        for (int j = 0;j < row;j++) {//Note that this won't be executed when row = 0.
            if (i == CURSOL[j] || i == CURSOL[j] + row - j\
                || i == CURSOL[j] - (row - j)) {
                //Illegal if it's on the same column or diagonal with previous Queens.
                //Note that we don't need to check the row.
                flag = 0;
                break;
            }
        }

        if (flag) {//If legal... (Always legal when row = 0)

            CURSOL[row] = i;//Store the position.

            if (row == 7) {//If this is the last row...
                for (int k = 0;k < 8;k++) {

                    EQSOL[solIter][k] = CURSOL[k]; //Store the current solution.

                }

                solIter++; //Move on to the next Eight Queen solution.
                break; //break, don't check the next row.
            }
            //If this isn't the last row...
            EightQueen(row + 1);
            //We check the next row.
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);//Get T.
    EightQueen(0); //Get EightQueen's solutions.

    for (int i = 0;i < T;i++) {

        int map[8][8];//Use an array to store the chessboard's values.

        for (int j = 0;j < 8;j++) {
            for (int k = 0;k < 8;k++) {
                scanf("%d", &map[j][k]);
            }
        }

        int minSum = 800;//minSum: Minimum Sum. Default is 800(8x100), the absolute maximum.

        for (int j = 0;j < 92;j++) {

            int curSum = 0;//curSum: Current Sum. Add up from 0.

            for (int k = 0;k < 8;k++) {
                curSum += map[k][EQSOL[j][k]];
                //EQSOL[j][k] -> The column with the queen
                //on the k-th row in the j-th solution.
            }

            if (curSum < minSum) {//Update maxSum if necessary.
                minSum = curSum;
            }
        }

        printf("%d\n", minSum);

    }

    return 0;
}