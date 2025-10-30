#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int array[128][128];
int dim;

char ID[10];
char arrayID[16500][10];

void fillSquare(int startX, int endX, int startY, int endY, char ID[], int layer)
{
    if (layer == strlen(ID))
    {
        for (int i = startX; i < endX; i++)
        {
            for (int j = startY; j < endY; j++)
            {
                array[i][j] = 1;
            }
        }
        return;
    }

    int midX = (startX + endX) / 2;
    int midY = (startY + endY) / 2;

    if (ID[layer] == '0')
    {
        fillSquare(startX, midX, startY, midY, ID, layer + 1);
    }
    else if (ID[layer] == '1')
    {
        fillSquare(startX, midX, midY, endY, ID, layer + 1);
    }
    else if (ID[layer] == '2')
    {
        fillSquare(midX, endX, startY, midY, ID, layer + 1);
    }
    else if (ID[layer] == '3')
    {
        fillSquare(midX, endX, midY, endY, ID, layer + 1);
    }

    return;
}

int findNearestPower(int num)
{
    int power = 1;
    while (power < num)
    {
        power *= 2;
    }
    return power;
}

void removeFirstCharacter(char* str) {
    if (strlen(str) > 0) {
        memmove(str, str + 1, strlen(str));
    }
}

int main()
{
    int count;
    int row, col;

    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%s", arrayID[i]);
    }

    scanf("%d %d", &row, &col);

    dim = findNearestPower(row > col ? row : col);

    for (int i = 0; i < count; i++)
    {
        fillSquare(0, dim, 0, dim, arrayID[i], 1);
    }

    for (int i = 0; i < row; i++)
    {
        if (i != 0)
            printf("\n");
        for (int j = 0; j < col; j++)
        {
            if (j != 0) printf(" ");
            printf("%d", array[i][j]);
        }
    }

}
