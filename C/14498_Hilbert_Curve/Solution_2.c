int hilbert(int x, int y, int n){
    if (n == 0) return 1;
    int mid = (1 << n) - 1;
    x = (x <= mid) ? x : 2*mid-x;
    return (x == mid)? y == mid+1: (y == mid)? x == 0: (y < mid) ? hilbert(y, x, n-1) : hilbert(x, y-mid-1, n-1);
}

void pattern(int ** board, int n){
    for (int i = 0; i < (1 << (n+1))-1; i++){
        for (int j = 0; j < (1 << (n+1))-1; j++){
            board[i][j] = hilbert(j, i, n);
        }
    }
}