#include <stdio.h>

int sumRiver(int riverPrefix[], int l, int r) {
    return riverPrefix[r] - riverPrefix[l - 1];
}

int findTreasure(int riverPrefix[], int l, int r) {
    while (l < r) {
        int m = (l + r) / 2;

        int sumLeft = sumRiver(riverPrefix, l, m - 1);
        int sumRight = sumRiver(riverPrefix, m + 1, r);

        if (sumLeft > sumRight) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return sumRiver(riverPrefix, l, r);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int riverPrefix[n + 2];
    riverPrefix[0] = 0;

    // Input the river and store it as a prefix sum array right away.
    // Note that the first tile of the river is index 1 because the question said so.
    for (int i = 1; i <= n; i++) {
        int currentChunk;
        scanf("%d", &currentChunk);

        riverPrefix[i] = riverPrefix[i - 1] + currentChunk;
    }
    riverPrefix[n + 1] = riverPrefix[n];

    // Input the intervals and output the result.
    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", findTreasure(riverPrefix, l, r));
    }

    return 0;
}