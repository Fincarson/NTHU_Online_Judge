#include<stdio.h>
int n, m;
int arr[105][105];

int sum(int li, int lj, int ri, int rj){
    int res = 0;
    for(int i = li; i <= ri; i++){
        for(int j = lj; j <= rj; j++){
            res += arr[i][j];
        }
    }
    return res;
}

int solve(int li, int lj, int ri, int rj){
    if(li == ri && lj == rj){
        return arr[li][lj];
    }
    int mi = (li + ri) / 2;
    int mj = (lj + rj) / 2;
    int qli[5] = {0, li, li, mi+1, mi+1};
    int qlj[5] = {0, lj, mj+1, lj, mj+1};
    int qri[5] = {0, mi, mi, ri, ri};
    int qrj[5] = {0, mj, rj, mj, rj};
    int q;
    int biggest_sum = -1;
    for(int i = 1; i <= 4; i++){
        int qsum = sum(qli[i], qlj[i], qri[i], qrj[i]);
        if(qsum > biggest_sum){
            biggest_sum = qsum;
            q = i;
        }
    }
    return solve(qli[q], qlj[q], qri[q], qrj[q]);
}

signed main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d", solve(1, 1, n, m));
}
