#include <stdio.h>

//Initialization
int tempGrid[1024][1024];
int kernelGrid[10][10];
int mainGrid[1050][1050];
int H, W, kH, kW, S, P;

//Main Code
int main(void){
    scanf("%d %d", &H, &W);

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%d", &tempGrid[i][j]);
        }
    }

    scanf("%d %d", &kH, &kW);
    for(int i = 0; i < kH; i++){
        for(int j = 0; j < kW; j++){
            scanf("%d", &kernelGrid[i][j]);
        }
    }
    scanf("%d %d", &S, &P);

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            mainGrid[i+P][j+P] = tempGrid[i][j];
        }
    }
    for(int i = 0; i <= H+(2*P)-kH; i+=S){
        for(int j = 0; j <= W+(2*P)-kW; j+=S){
            int output = 0;
            for(int a = 0; a < kH; a++){
                for(int b = 0; b< kW; b++){
                    output += mainGrid[a+i][b+j]*kernelGrid[a][b];
                }
            }
            if(j == 0){printf("%d", output);}
            else{printf(" %d", output);}
        }
        printf("\n");
    }
    return 0;
}
