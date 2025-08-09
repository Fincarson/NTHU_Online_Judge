/* TODO: Modify the board to make the pattern */

int hilbert(int x, int y, int n){
    if(n == 0) return 1;

    int mid = (1<<n)-1;
    if(x == mid && y == mid+1) return 1;
    if(y == mid && (x == 0 || x == 2*mid)) return 1;

    if(x < mid && y < mid) return hilbert(y, x, n-1);
    if(x > mid && y < mid) return hilbert(y, 2*mid-x, n-1);
    if(x < mid && y > mid) return hilbert(x, y-mid-1, n-1);
    if(x > mid && y > mid) return hilbert(x-mid-1, y-mid-1, n-1);

    return 0;
}

void pattern(int ** board, int n){
    int size = 2*(1<<n) - 1;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = hilbert(j, i, n);
        }
    }
}