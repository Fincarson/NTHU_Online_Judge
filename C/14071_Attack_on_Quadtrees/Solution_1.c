#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int array[128][128];

//ID array to create IDs
char ID[10];
//Storage array to store IDs
char arrayID[16500][10];

int count = 0;

void checkSquare(int startX, int endX, int startY, int endY, int layer, int idx)
{
    //Convert index to char value for easier printing
    ID[layer] = '0' + idx;
    ID[layer + 1] = '\0';

    if (startX == endX - 1 && startY == endY - 1) {
        if (array[startX][startY])
        {
            //If base case is activated, then the string is copied to storage array
            strcpy(arrayID[count], ID);

            count += 1;
        }
        return;
    }

    //Checking if area is homogenous
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
        ID[layer] = '0' + idx;
        ID[layer + 1] = '\0';

        strcpy(arrayID[count], ID);
        count += 1;
    }
    //recursive statement if it is not homogenous
    else if (flag == 0)
    {
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;

        //Layers are used to identify which slot to fill for the ID,
        //when entering the recursion for the first time it will be
        //layer 0, and as reh recursion goes deeper, they layer index increases
        //allowing for the naming of the selected quadrant.
        checkSquare(startX, midX, startY, midY, layer + 1, 0);
        checkSquare(startX, midX, midY, endY, layer + 1, 1);
        checkSquare(midX, endX, startY, midY, layer + 1, 2);
        checkSquare(midX, endX, midY, endY, layer + 1, 3);
    }
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

    for (int i = 0; i < 10; i++)
    {
        ID[i] = '\0';
    }

    checkSquare(0, dim, 0, dim, 0, 1);

    printf("%d\n", count);
    for (int idx = 0; idx < count; idx++)
    {
        printf("%s\n", arrayID[idx]);
    }
    return 0;
}