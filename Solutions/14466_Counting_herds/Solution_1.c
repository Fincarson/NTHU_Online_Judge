#include<stdio.h>

//Initialization(s)
int n, m, count;
char array[1000][1000];

//Function(s)
void Herd(int x, int y);

//Main Code
int main(void){
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf(" %c", &array[i][j]);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(array[i][j] == '#'){
                count++; Herd(i, j);
            }
        }
    }
    printf("%d", count);
    return 0;
}

void Herd(int x, int y){
    array[x][y] = '.';
    if(x+1<n && array[x+1][y] == '#'){Herd(x+1, y);}
    if(x-1>=0 && array[x-1][y] == '#'){Herd(x-1, y);}
    if(y+1<m && array[x][y+1] == '#'){Herd(x, y+1);}
    if(y-1>=0 && array[x][y-1] == '#'){Herd(x, y-1);}
}
