#include<stdio.h>

//Initialization(s)
int n, k, output;
char array[10][10];
int placed[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

//Function(s)
void placing(int row);
int validO(int row, int col); //African Elephant
int validI(int row, int col); //Asian Elephant

//Main Code
int main(void){
    scanf("%d %d", &n, &k);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf(" %c", &array[i][j]);
        }
    }
    placing(0);
    printf("%d", output);
    return 0;
}


void placing(int row) {
    if (row == n) { output++;return; }
    else {
        for (int j = 0; j < n; j++) {
            if (k == 0) {
                if (validO(row, j)) {
                    placed[row] = j;
                    placing(row + 1);
                }
            }
            else if (k == 1) {
                if (validI(row, j)) {
                    placed[row] = j;
                    placing(row + 1);
                    placed[row] = -1;
                }
            }
        }
    }
}


int validO(int row, int col) {
    if (array[row][col] == 'X') { return 0; }
    for (int i = 0; i <= row - 1; i++) {
        if (placed[i] == col || placed[i] == col - row + i || placed[i] == col + row - i) { return 0; }
    }
    return 1;
}


int validI(int row, int col) {
    if (array[row][col] == 'X') { return 0; }
    for (int i = 0; i <= row - 1; i++) {
        if (placed[i] == col) { return 0; }
    }
    if (row >= 2 && col >= 2 && placed[row - 2] == col - 2) { return 0; }
    if (row >= 2 && col + 2 < n && placed[row - 2] == col + 2) { return 0; }
    return 1;
}
