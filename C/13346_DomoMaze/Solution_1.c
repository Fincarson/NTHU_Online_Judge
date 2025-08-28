#include<stdio.h>

int H, W;
long long array[16][16], answer;

void dynamic(){
    for(int i = 0; i < H; i++) array[i][0] = 1;
    for(int j = 0; j < W; j++) array[0][j] = 1;

    for(int i = 1; i < H; i++){
        for(int j = 1; j < W; j++){
            array[i][j] = array[i-1][j] + array[i][j-1] + array[i-1][j-1];
        }
    }
    answer = array[H-1][W-1];
}

void recursion(int x, int y){
    if(x == H-1 && y == W-1) answer++;

    if(array[x][y]){
        array[x][y] = 0;
        recursion(x-2, y-2);
        array[x][y] = 1;

    }else{
        if(x+1 < H) recursion(x+1, y);
        if(y+1 < W) recursion(x, y+1);
        if(x+1 < H, y+1 < W) recursion(x+1, y+1);
    }
}

int main(void){
    scanf("%d%d", &H, &W);

    int valid = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%1lld", &array[i][j]);
            if(array[i][j]) valid = 1;
        }
    }
    if(valid) recursion(0,0);
    else dynamic();
    printf("%lld\n", answer);
    return 0;
}
