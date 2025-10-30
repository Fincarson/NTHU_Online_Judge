#include <stdio.h>
#include <string.h>

char string[10001];
int offset[10001];
int index[10001];

int main(void) {
    scanf("%s", string);
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        offset[i] = i;
        index[i] = i;
    }

    int m; scanf("%d", &m);

    while (m--) {
        int l, r, maxRange, temp = 0;
        long long k;
        scanf("%d %d %lld", &l, &r, &k);

        maxRange = r - l + 1;
        k %= maxRange;

        for (int i = l - 1; i < r; i++) {
            offset[index[i]] += k;
            if (i >= r - k) {
                if (temp == 0) temp = offset[index[i]];
                offset[index[i]] -= temp - (l - 1);
            }
        }

        for (int i = 0; i < length; i++) {
            index[offset[i]] = i;
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%c", string[index[offset[index[i]]]]);
    }
    printf("\n");

    return 0;
}