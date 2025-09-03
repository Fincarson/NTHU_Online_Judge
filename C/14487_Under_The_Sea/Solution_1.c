#include<stdio.h>

//INITIALIZATION
int array[100][100], N, M, output;

//FUNCTION(S)
int findLuck(int topRow, int topCol, int bottomRow, int bottomCol);
int calculate(int topRow, int topCol, int bottomRow, int bottomCol);


//START
int main(void){
    scanf("%d %d", &N, &M);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            scanf("%d", &array[i][j]);
        }
    }
    output = findLuck(0, 0, N-1, M-1);
    printf("%d", output);
    return 0;
}


//Calculation
int calculate(int topRow, int topCol, int bottomRow, int bottomCol) {
    int sum = 0;
    for (int i = topRow; i <= bottomRow; i++) {
        for (int j = topCol; j <= bottomCol; j++) {
            sum += array[i][j];
        }
    }
    return sum;
}

//Find the lucky tile
int findLuck(int topRow, int topCol, int bottomRow, int bottomCol) {
    int sumMax, maxQ;
    if (topRow == bottomRow && topCol == bottomCol) { return array[topRow][topCol]; }

    int midRow = (topRow + bottomRow) / 2;
    int midCol = (topCol + bottomCol) / 2;

    int sumFirstQ = calculate(topRow, topCol, midRow, midCol);
    sumMax = sumFirstQ; maxQ = 1;

    int sumSecondQ = 0;
    if (midCol + 1 <= bottomCol) {
        sumSecondQ = calculate(topRow, midCol + 1, midRow, bottomCol);
        if (sumSecondQ > sumMax) { sumMax = sumSecondQ; maxQ = 2; }
    }

    int sumThirdQ = 0;
    if (midRow + 1 <= bottomRow) {
        sumThirdQ = calculate(midRow + 1, topCol, bottomRow, midCol);
        if (sumThirdQ > sumMax) { sumMax = sumThirdQ; maxQ = 3; }
    }

    int sumFourthQ = 0;
    if (midCol + 1 <= bottomCol && midRow + 1 <= bottomRow) {
        sumFourthQ = calculate(midRow + 1, midCol + 1, bottomRow, bottomCol);
        if (sumFourthQ > sumMax) { sumMax = sumFourthQ; maxQ = 4; }
    }

    if (maxQ == 1) { return findLuck(topRow, topCol, midRow, midCol); }
    else if (maxQ == 2) { return findLuck(topRow, midCol + 1, midRow, bottomCol); }
    else if (maxQ == 3) { return findLuck(midRow + 1, topCol, bottomRow, midCol); }
    else if (maxQ == 4) { return findLuck(midRow + 1, midCol + 1, bottomRow, bottomCol); }
}
