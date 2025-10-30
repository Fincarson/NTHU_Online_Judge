#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /*
        Coordinate

        O - - - - - - - - > (x)
        |
        |
        |
        |
        |
        v
        (y)

    */
    int h, w;
    char direction[10];

    scanf("%d %d %s", &h, &w, direction);
    char arr[h][w];
    int visit[h][w][4];
    memset(visit, 0, sizeof(visit));

    int sx, sy;
    int last_x, last_y;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'S') {
                sx = j;
                sy = i;
            }
        }
    }

    while (1) {

        if (sx < 0 || sy < 0 || sx >= w || sy >= h) {
            printf("%d %d\n", last_y, last_x);
            return 0;
        }

        // LEFT
        if (strcmp(direction, "Left") == 0) {
            if (visit[sy][sx][0] == 1) {
                printf("Stuck QQ\n");
                return 0;
            }
            else {
                visit[sy][sx][0] = 1;
            }
        }

        // RIGHT
        if (strcmp(direction, "Right") == 0) {
            if (visit[sy][sx][1] == 1) {
                printf("Stuck QQ\n");
                return 0;
            }
            else {
                visit[sy][sx][1] = 1;
            }
        }

        // UP
        if (strcmp(direction, "Up") == 0) {
            if (visit[sy][sx][2] == 1) {
                printf("Stuck QQ\n");
                return 0;
            }
            else {
                visit[sy][sx][2] = 1;
            }
        }

        // DOWN
        if (strcmp(direction, "Down") == 0) {
            if (visit[sy][sx][3] == 1) {
                printf("Stuck QQ\n");
                return 0;
            }
            else {
                visit[sy][sx][3] = 1;
            }
        }


        last_x = sx, last_y = sy;
        if (arr[sy][sx] == '.' || arr[sy][sx] == 'S') {
            if (strcmp(direction, "Left") == 0) sx--;
            if (strcmp(direction, "Right") == 0) sx++;
            if (strcmp(direction, "Up") == 0) sy--;
            if (strcmp(direction, "Down") == 0) sy++;
        }
        else if (arr[sy][sx] == '/') {
            if (strcmp(direction, "Left") == 0) {
                strcpy(direction, "Down");
                sy++;
            }
            else if (strcmp(direction, "Right") == 0) {
                strcpy(direction, "Up");
                sy--;
            }
            else if (strcmp(direction, "Up") == 0) {
                strcpy(direction, "Right");
                sx++;
            }
            else if (strcmp(direction, "Down") == 0) {
                strcpy(direction, "Left");
                sx--;
            }
        }
        else if (arr[sy][sx] == '\\') {
            if (strcmp(direction, "Left") == 0) {
                strcpy(direction, "Up");
                sy--;
            }
            else if (strcmp(direction, "Right") == 0) {
                strcpy(direction, "Down");
                sy++;
            }
            else if (strcmp(direction, "Up") == 0) {
                strcpy(direction, "Left");
                sx--;
            }
            else if (strcmp(direction, "Down") == 0) {
                strcpy(direction, "Right");
                sx++;
            }
        }
        else {
            exit(1);
        }

    }
}
