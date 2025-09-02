#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char* str)
{
    int left = 0;
    int right = strlen(str) - 1;

    if (strlen(str) < 3)
    {
        return false;
    }

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int detectPalindrome(const char* str)
{
    int counter = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            char temp[1001];
            int k = i;
            int idx = 0;
            while (k <= j)
            {
                temp[idx] = str[k];
                k++;
                idx++;
            }
            temp[idx] = '\0';
            if (isPalindrome(temp))
            {
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
    char input[1001];

    scanf("%s", input);

    int count = detectPalindrome(input);

    printf("%d\n", count);

    return 0;
}
