#include <stdio.h>

int H, W, D;
int first[1024][1024]; int second[1024][1024];
int amountRock; amountScissors; amountPaper;
int offsetI[8] = {-1, 0, 1, 1, -1, 0, 1, -1};
int offsetJ[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

void check(int tempI, int tempJ){
    if(tempI >= 0 && tempI < H && tempJ >= 0 && tempJ < W){
        if     (first[tempI][tempJ] == 0){amountRock++;}
        else if(first[tempI][tempJ] == 2){amountScissors++;}
        else if(first[tempI][tempJ] == 5){amountPaper++;}
        }else{}
}

int main(void){
    scanf("%d %d %d", &H, &W, &D);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%d", &first[i][j]);
        }
    }

    for(int r = 0; r < D; r++){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                amountRock = 0; amountScissors = 0; amountPaper = 0;
                for(int a = 0; a < 8; a++){check(i + offsetI[a], j + offsetJ[a]);}
                if      (amountRock > amountScissors && amountRock > amountPaper)    {second[i][j] = 5;}
                else if (amountScissors > amountRock && amountScissors > amountPaper){second[i][j] = 0;}
                else if (amountPaper > amountScissors && amountPaper > amountRock)   {second[i][j] = 2;}
                else {second[i][j] = first[i][j];}

            }
        }

        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                first[i][j] = second[i][j];
            }
        }

    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            printf("%d ", first[i][j]);
        }
        printf("\n");
    }
    return 0;
}
