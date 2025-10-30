#include<stdio.h>

int count = -1, steps, output, end, startX, startY, finishX, finishY, X, Y;
char array[301][301];

int hunting(int x, int y){
    count++;
    if(x == finishX && y == finishY){array[x][y] = '#'; end = 1; return count;}
    array[x][y] = '#';
    if(x+1<X  && array[x+1][y] == '.'){hunting(x+1, y);} if(end == 1){return count;}
    if(x-1>=0 && array[x-1][y] == '.'){hunting(x-1, y);} if(end == 1){return count;}
    if(y+1<Y && array[x][y+1]  == '.'){hunting(x, y+1);} if(end == 1){return count;}
    if(y-1>=0 && array[x][y-1] == '.'){hunting(x, y-1);} if(end == 1){return count;}
    count--;
}

int main(void){
    scanf("%d %d", &X, &Y);
    for(int i = 0; i<X; i++){
        for(int j = 0; j<Y; j++){
            scanf(" %c", &array[i][j]);
            if(array[i][j] == 'S'){startX = i; startY = j;}
            if(array[i][j] == 'M'){finishX = i; finishY = j; array[i][j] = '.';}
        }
    }
    hunting(startX, startY);
    printf("%d\n", count);
    return 0;
}
