#include <stdio.h>
#include <string.h>

int actualPiles[10][10001];
int* piles[10];
char command[8];

void HandlePrint();
void HandleAll();
void HandlePlace();
void HandleSwap();
void HandleClear();
void HandleReverse();

int main() {
    for (int idx = 0; idx < 10; idx++) {
        piles[idx] = actualPiles[idx];
        actualPiles[idx][0] = 0;
    }

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "print") == 0)
            HandlePrint();
        else if (strcmp(command, "all") == 0)
            HandleAll();
        else if (strcmp(command, "place") == 0)
            HandlePlace();
        else if (strcmp(command, "swap") == 0)
            HandleSwap();
        else if (strcmp(command, "clear") == 0)
            HandleClear();
        else if (strcmp(command, "reverse") == 0)
            HandleReverse();
        else if (strcmp(command, "exit") == 0)
            break;
    }
}

void HandlePrint() {
    for (int idx = 0; idx < 10; idx++) {
        printf("%d:", idx);
        if (piles[idx][0] == 0) {
            printf(" No card\n");
            continue;
        }
        for (int i = 0; piles[idx][i] != 0; i++) {
            printf(" %d", piles[idx][i]);
        }
        printf("\n");
    }
}

void HandleAll() {
    int num, len;
    scanf("%d%d", &num, &len);
    for (int idx = 0; idx < 10; idx++) {
        for (int i = 0; i < len; i++) {
            piles[idx][i] = num;
        }
        piles[idx][len] = 0;
    }
}

void HandlePlace() {
    int idx, len;
    scanf("%d%d", &idx, &len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &piles[idx][i]);
    }
    piles[idx][len] = 0;
}

void HandleSwap() {
    int idx_a, idx_b;
    scanf("%d%d", &idx_a, &idx_b);
    int* tmp = piles[idx_a];
    piles[idx_a] = piles[idx_b];
    piles[idx_b] = tmp;
}

void HandleClear() {
    for (int idx = 0; idx < 10; idx++) {
        piles[idx][0] = 0;
    }
}

void HandleReverse() {
    int startingPile, stoppingPile;
    scanf("%d%d", &startingPile, &stoppingPile);
    if (stoppingPile < startingPile) {
        stoppingPile += 10;
    }

    while (stoppingPile > startingPile) {
        int* tmp = piles[startingPile % 10];
        piles[startingPile % 10] = piles[stoppingPile % 10];
        piles[stoppingPile % 10] = tmp;

        stoppingPile--, startingPile++;
    }
}
