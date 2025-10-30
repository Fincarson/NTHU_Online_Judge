#include <stdio.h>

int middle[8] = { 0,1 };
int cumulative[8] = { 0,1 };
void initialize_size() {
    for (int i = 2; i <= 7; i++) {
        middle[i] = 4 * cumulative[i - 2] - middle[i - 2] + 2;
        cumulative[i] = cumulative[i - 1] + middle[i];
    }
}

int size(int deg) {
    return cumulative[deg] + cumulative[deg - 1];
}

char func(int x, int y, int deg) {
    if (deg == 0) return ' ';
    if (deg == 1) { return (x == 0 && y == 0) ? '#' : ' '; }
    else {
        if (x > size(deg) / 2) x = size(deg) - x - 1;
        if (y > size(deg) / 2) y = size(deg) - y - 1;
        if (x >= cumulative[deg - 1] && y >= cumulative[deg - 1]) return '0' + deg;
        if (x + y >= 2 * cumulative[deg - 1] - 1) {
            int _y = y;
            y = 2 * cumulative[deg - 1] - x - 1;
            x = 2 * cumulative[deg - 1] - _y - 1;
        }
        return func(x, y, deg - 1);
    }
}

int main() {
    initialize_size();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < size(n); i++) {
        for (int j = 0; j < size(n); j++) {
            printf("%c", func(i, j, n));
        }
        printf("\n");
    }
}