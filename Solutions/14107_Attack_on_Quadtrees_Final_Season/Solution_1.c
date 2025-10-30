#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int array[85][85];

int count = 0;

void checkSquare(int startX, int endX, int startY, int endY)
{
    if (startX == endX - 1 && startY == endY - 1) {
        if (array[startX][startY])
        {
            count += 1;
        }
        return;
    }

    bool flag = true;
    for (int i = startX; i < endX; i++)
    {
        for (int j = startY; j < endY; j++)
        {
            if (array[i][j] == 0)
            {
                flag = false;
            }
        }
    }

    if (flag && array[startX][startY] == 1)
    {
        count += 1;
    }
    else if (!flag)
    {
        int mid1X = startX + (endX - startX) / 3;
        int mid2X = startX + 2 * (endX - startX) / 3;

        int mid1Y = startY + (endY - startY) / 3;
        int mid2Y = startY + 2 * (endY - startY) / 3;

        checkSquare(startX, mid1X, startY, mid1Y);
        checkSquare(mid1X, mid2X, startY, mid1Y);
        checkSquare(mid2X, endX, startY, mid1Y);

        checkSquare(startX, mid1X, mid1Y, mid2Y);
        checkSquare(mid1X, mid2X, mid1Y, mid2Y);
        checkSquare(mid2X, endX, mid1Y, mid2Y);

        checkSquare(startX, mid1X, mid2Y, endY);
        checkSquare(mid1X, mid2X, mid2Y, endY);
        checkSquare(mid2X, endX, mid2Y, endY);
    }
}

int findNearestPower(int num)
{
    int power = 1;
    while (power < num)
    {
        power *= 3;
    }
    return power;
}

int main()
{
    int row, column;
    scanf("%d %d", &row, &column);

    int dim = findNearestPower(row > column ? row : column);

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (i < row && j < column)
            {
                scanf("%d", &array[i][j]);
            }
            else
            {
                array[i][j] = 0;
            }
        }
    }
    checkSquare(0, dim, 0, dim);

    printf("%d\n", count);

    return 0;
}
