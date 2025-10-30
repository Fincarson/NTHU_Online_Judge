#include<stdio.h>

int main()
{
    int a[100] = { 0 };
    int A;
    int b[100] = { 0 };
    int B;
    int sum[101] = { 0 };

    scanf("%d", &A);
    getchar();
    for (int i = 1; i <= A; i++) a[A - i] = getchar() - '0';
    scanf("%d", &B);
    getchar();
    for (int i = 1; i <= B; i++) b[B - i] = getchar() - '0';

    if (B > A)
        A = B;

    for (int i = 0; i < A; i++)
    {
        sum[i] += a[i];
        sum[i] += b[i];
        if (sum[i] > 9)
        {
            sum[i] -= 10;
            sum[i + 1] += 1;
            if (i == A - 1)
            {
                A++;
                break;
            }
        }
    }

    for (int i = 1; i <= A; i++)
        putchar(sum[A - i] + '0');

    return 0;
}