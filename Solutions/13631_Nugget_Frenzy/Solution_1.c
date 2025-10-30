#include <stdio.h>

int arr[20];

unsigned long long count(int nugget, int index) {
    if (nugget == 0) {
        return 1;
    }
    if (index == -1) {
        return 0;
    }
    unsigned long long retval = 0;
    for (int i = nugget / arr[index]; i >= 0; i--) {
        retval += count(nugget - i * arr[index], index - 1);
    }
    return retval;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%llu\n", count(n, k - 1));
}