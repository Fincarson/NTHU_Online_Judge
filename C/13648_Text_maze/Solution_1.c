#include <stdio.h>

char _map[105][105];

int main() {
    int n, s, y, x;
    scanf("%d %d %d %d", &n, &s, &y, &x);

    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            scanf(" %c", &_map[i][k]); // using " %c" can avoid all the spaces and newline, but "%c" cannot.

    printf("%c", _map[y][x]);

    int find_min = 1;
    for (int i = 0; i < s; i++) { // at most s steps.

        // find the next chosen char.
        int ans = find_min ? 500 : 0, choose_x = -1, choose_y = -1;
        for (int py = -1; py <= 1; py++)
            for (int px = -1; px <= 1; px++) {
                if (py == 0 && px == 0) continue;
                if (y + py < 0 || y + py >= n) continue;
                if (x + px < 0 || x + px >= n) continue;

                if (find_min) {
                    if (ans >= _map[y + py][x + px]) {
                        choose_x = x + px;
                        choose_y = y + py;
                        ans = _map[y + py][x + px];
                    }
                }
                else {
                    if (ans <= _map[y + py][x + px]) {
                        choose_x = x + px;
                        choose_y = y + py;
                        ans = _map[y + py][x + px];
                    }
                }
            }

        // find the position of your next step
        if (ans >= 'A' && ans <= 'Z') {
            if (ans >= 'U') {
                x = choose_x;
                y = choose_y;
            }
            else {
                // you can try to find out the result of (ans - 'A') % 5 for every uppercase character
                switch ((ans - 'A') % 5) {
                case 0:
                    x = choose_x;
                    y = choose_y;
                    find_min = 1 - find_min;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    y--;
                    break;
                case 3:
                    x++;
                    break;
                case 4:
                    x--;
                }
            }
        }
        else {
            if (ans >= 'u') {
                x = choose_x;
                y = choose_y;
            }
            else {
                switch ((ans - 'a') % 5) {
                case 4:
                    x = choose_x;
                    y = choose_y;
                    find_min = 1 - find_min;
                    break;
                case 3:
                    y++;
                    break;
                case 2:
                    y--;
                    break;
                case 1:
                    x++;
                    break;
                case 0:
                    x--;
                }
            }
        }

        // if your next step is outside the map, terminate.
        if (x < 0 || x >= n) break;
        if (y < 0 || y >= n) break;

        printf("%c", _map[y][x]);
    }
}