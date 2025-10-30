#include <stdio.h>

int arr[20];

unsigned long long count(int n, int k) {
    unsigned long long A[n + 1];
    A[0] = 1;
    for (int i = 1; i <= n; i++) {
        A[i] = 0;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= A[i]) {
                A[j] += A[j - arr[i]];
            }
        }
    }

    return A[n];
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%llu\n", count(n, k));

}