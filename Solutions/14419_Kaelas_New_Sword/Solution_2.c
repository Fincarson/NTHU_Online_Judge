#include <stdio.h>

int abs(int x) {
    return (x >= 0) ? x : -x;
}

int main() {
    int L, D;
    scanf("%d%d", &L, &D);

    int x_center = L - 1, y_center = L - 1;
    int radius = x_center - abs(D - x_center);
    for (int y = 0; y < 2 * L - 1; y++) {
        for (int x = 0; x < 2 * L - 1; x++) {
            int distanceFromCenter = abs(x - x_center) + abs(y - y_center);
            char characterToPrint = (distanceFromCenter > radius) ? ' ' : 'A' + (radius - distanceFromCenter) % 26;
            printf("%c", characterToPrint);
        }
        printf("\n");
    }
    return 0;
}