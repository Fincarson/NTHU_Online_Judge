#include<stdio.h>
#include<stdlib.h>

int sol(unsigned long long N) {
    int ans = -1;
    int cur_idx = 0, old_idx = 0;
    int first = 1;

    while (N) {
        if (N & 1) {
            int d = cur_idx - old_idx - 1;
            if (first) {
                d = -1;
                first = 0;
            }
            ans = ans > d ? ans : d;
            old_idx = cur_idx;
        }
        cur_idx++;
        N >>= 1;
    }
    return ans;
}

int main() {
    int q;
    unsigned long long N;
    scanf("%d", &q);
    while (q--) {
        scanf("%lld", &N);
        printf("%d\n", sol(N));
    }
    return 0;
}