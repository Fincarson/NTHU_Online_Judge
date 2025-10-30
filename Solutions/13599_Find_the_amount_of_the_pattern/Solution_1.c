#include <stdio.h>

int main(void) {
    int N;
    int pattern_size;
    int find_pattern_amount = 0;
    int max_value = 0;
    int image[20][20] = {0};
    int pattern[20][20] = {0};

    //Input of the binary image
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    //Input of the pattern
    scanf("%d", &pattern_size);
    for (int i = 0; i < pattern_size; i++) {
        for (int j = 0; j < pattern_size; j++) {
            scanf("%d", &pattern[i][j]);
            max_value += pattern[i][j];
        }
    }

    //Start Comparing
    for (int i = 0; i < N - pattern_size + 1; i++) {
        for (int j = 0; j < N - pattern_size + 1; j++) {
            int value = 0;
            for (int r = i; r < i + pattern_size; r++) {
                for (int c = j; c < j + pattern_size; c++) {
                    value += image[r][c] * pattern[r - i][c - j];
                }
            }
            if (value == max_value) find_pattern_amount++;
        }
    }

    printf("%d\n", find_pattern_amount);
    return 0;
}
