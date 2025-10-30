#include <stdio.h>
#include <string.h>

long long ans;

int len;
char str[26], order[26];

long long permutation(long long i)
{
    if (i <= 1)
        return 1;

    return i * permutation(i - 1);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        ans = 0;
        for (int i = 0; i < 26; i++) order[i] = 0;

        scanf("%s", str);

        len = strlen(str);

        for (int i = 0; i < len; i++)
            for (int k = str[i] - 'a' + 1; k < 26; k++)
                order[k]++;

        for (int i = 0; i < len; i++)
        {
            ans += order[str[i] - 'a'] * permutation(len - i - 1);

            for (int k = str[i] - 'a' + 1; k < 26; k++)
                if (order[k] != 0)
                    order[k]--;
        }

        printf("%lld\n", ans);
    }
}
