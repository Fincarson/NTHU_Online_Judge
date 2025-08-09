#include<stdio.h>
#include<stdbool.h>

//INITIALIZATION(S)
int count = 0;
int placed[10];
int queenPlaced[10];

//FUNCTION(S)
void placing(int row, int countN, int countM, int maxN, int maxM);
bool validN(int row, int col);
bool validM(int row, int col);

//Main Code
int main(void){
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF){
        for(int i = 0; i<10; i++){
            placed[i] = -1;
            queenPlaced[i] = -1;
        }
        placing(0, 0, 0, N, M);
        printf("%d\n", count);
        count = 0;
    }
    return 0;
}


void placing(int row, int countN, int countM, int maxN, int maxM){
    if(row == maxN + maxM){
        count++;
        return;
    }

    for(int col = 0; col < maxN + maxM; col++){
        if(validN(row, col) &&  countN < maxN){
            placed[row] = col; queenPlaced[row] = col;
            placing(row+1, countN+1, countM, maxN, maxM);
            placed[row] = -1; queenPlaced[row] = -1;
        }
        if(validM(row, col) && countM < maxM){
            placed[row] = col;
            placing(row+1, countN, countM+1, maxN, maxM);
            placed[row] = -1;
        }
    }
}

bool validN(int row, int col){
    for(int i = 0; i <= row; i++){
        if(placed[i] == col || (placed[i] == col-row+i && placed[i] >= 0) || (placed[i] == col+row-i && placed[i] >= 0)) return false;
    }
    return true;
}


bool validM(int row, int col){
    for(int i = 0; i <= row; i++){
        if(placed[i] == col || (queenPlaced[i] == col-row+i && queenPlaced[i] >= 0) || (queenPlaced[i] == col+row-i && queenPlaced[i] >= 0)) return false;
    }
    return true;
}