#include<stdio.h>

//Initialization
char grid[100][100];
int visited[100][100][4];
char startDir[5];
int startX, startY;
int H, W, dx, dy;
int x, y, lastX, lastY;
int direction;

//Main Code
int main(void){
    scanf("%d %d %s", &H, &W, startDir);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf(" %c", &grid[i][j]);
            if(grid[i][j] == 'S'){startX = i; startY = j;}
        }
    }
    if (strcmp(startDir, "Left")  == 0){dy = -1;}
    if (strcmp(startDir, "Right") == 0){dy = 1;}
    if (strcmp(startDir, "Up")    == 0){dx = -1;}
    if (strcmp(startDir, "Down")  == 0){dx = 1;}

    x = startX; y = startY;
    lastX = startX; lastY = startY;

    while(1){
        lastX = x; lastY = y;
        x += dx; y += dy;

        if(x < 0 || y < 0 || x >= H || y >= W){printf("%d %d\n", lastX, lastY); break;}
        direction = (dx == -1)?0 : (dx == 1)?1 : (dy == -1)?2 : 3;

        if(visited[x][y][direction] == 1){printf("Stuck QQ\n"); break;}
        visited[x][y][direction] = 1; //Mark it as visited

        if(grid[x][y] == '/'){int temp = dx; dx = -dy; dy = -temp;}
        if(grid[x][y] == '\\'){int temp = dx; dx = dy; dy = temp;}
    }
    return 0;
}
