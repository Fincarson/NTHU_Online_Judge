#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define EPSILON 1e-6

bool judgePoint24(double cards[], int size)
{
    if (size == 1) {
        return fabs(cards[0] - 24.0) < EPSILON;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                double newCards[4];
                int newSize = 0;

                for (int k = 0; k < size; k++)
                {
                    if (k != i && k != j) {
                        newCards[newSize++] = cards[k];
                    }
                }

                newCards[newSize] = cards[i] + cards[j];
                if (judgePoint24(newCards, newSize + 1)) return true;

                newCards[newSize] = cards[i] - cards[j];
                if (judgePoint24(newCards, newSize + 1)) return true;

                newCards[newSize] = cards[i] * cards[j];
                if (judgePoint24(newCards, newSize + 1)) return true;

                if (cards[j] != 0)
                {
                    newCards[newSize] = cards[i] / cards[j];
                    if (judgePoint24(newCards, newSize + 1)) return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    double cards[4];

    int q;

    scanf("%d", &q);

    while (q--)
    {
        for (int i = 0; i < 4; i++)
        {
            scanf("%lf", &cards[i]);
        }

        bool result = judgePoint24(cards, 4);

        if (result) {
            printf("Safe\n");
        }
        else {
            printf("Disqualified\n");
        }
    }

    return 0;
}
