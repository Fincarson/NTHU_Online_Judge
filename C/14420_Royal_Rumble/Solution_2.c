#include <stdio.h>

int grid[256][256];
int tempGrid[256][256];
int H, W;

void ApplyRuleToGrid();
int CalculateSymbolAt_hw(int h, int w);

int main() {
    int days;
    scanf("%d%d%d", &H, &W, &days);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            scanf("%d", &grid[h][w]);
        }
    }


    for (int day = 0; day < days; day++) {
        ApplyRuleToGrid();
    }

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            printf("%d ", grid[h][w]);
        }
        printf("\n");
    }
}

void ApplyRuleToGrid() {
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            tempGrid[h][w] = CalculateSymbolAt_hw(h, w);
        }
    }

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            grid[h][w] = tempGrid[h][w];
        }
    }
}

int CalculateSymbolAt_hw(int h, int w) {
    int rockCount = 0, scissorsCount = 0, paperCount = 0;

    for (int rowNeighbor = h - 1; rowNeighbor <= h + 1; rowNeighbor++) {
        for (int colNeighbor = w - 1; colNeighbor <= w + 1; colNeighbor++) {
            if (rowNeighbor == h && colNeighbor == w)
                continue;
            if (rowNeighbor < 0 || rowNeighbor >= H || colNeighbor < 0 || colNeighbor >= W)
                continue;

            if (grid[rowNeighbor][colNeighbor] == 0) {
                rockCount++;
            }
            else if (grid[rowNeighbor][colNeighbor] == 2) {
                scissorsCount++;
            }
            else if (grid[rowNeighbor][colNeighbor] == 5) {
                paperCount++;
            }
            else {
                printf("Hey! Don't cheat at rock paper scissors!\n");
            }
        }
    }


    if (rockCount > scissorsCount && rockCount > paperCount) {
        return 5;
    }
    else if (paperCount > rockCount && paperCount > scissorsCount) {
        return 2;
    }
    else if (scissorsCount > rockCount && scissorsCount > paperCount) {
        return 0;
    }
    else {
        return grid[h][w];
    }
}
