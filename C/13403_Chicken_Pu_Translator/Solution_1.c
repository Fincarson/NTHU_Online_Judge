#include<stdio.h>
#include <stdlib.h>

char alphabet[27] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                    'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

long long power(int base, int pow) {
    long long num = 1;
    for (int i = 0; i < pow; i++) num *= base;
    return num;
}

int main() {
    int q;
    char num[11];
    char answer[10000];

    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        for (int i = 0; i < 10; i++) scanf(" %c", &num[i]);

        long long temp = 0;

        for (int i = 0; i < 10; i++) {
            switch (num[i]) {
            case '0':
                temp += power(2, 9 - i) * 0;
                break;
            case '1':
                temp += power(2, 9 - i) * 1;
                break;
            }
        }
        printf("%c", alphabet[temp % 27]);
    }
    return 0;
}