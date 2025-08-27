#include <stdio.h>

int first = 1;

void prefix()
{
    char ch;
    scanf(" %c", &ch);

    if (ch >= '0' && ch <= '9')
    {
        if (first)
        {
            printf("%c", ch);
            first = 0;
        }
        else
            printf(" %c", ch);
    }
    else
    {
        prefix();
        prefix();

        if (first)
        {
            printf("%c", ch);
            first = 0;
        }
        else
            printf(" %c", ch);
    }
}

int main()
{
    prefix();
}