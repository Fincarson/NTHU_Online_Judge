#include<stdio.h>

int N, S;
int array[100];
int output;

int main(void) {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (array[j] >= array[i]) {
                for (int k = j + 1; k < N; k++) {
                    if (array[k] >= array[j]) {
                        for (int l = k + 1; l < N; l++) {
                            if (array[l] >= array[k]) {
                                if (array[i] + array[j] + array[k] + array[l] == S) {
                                    output++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", output);
    return 0;
}
