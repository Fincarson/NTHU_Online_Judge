#include <stdio.h>

int main(void){
    long factorial[15];
    factorial[0] = 1;
    for(int i = 1; i < 15; i++) factorial[i] = factorial[i-1] * i;

    long n = 0, m = 0;
    scanf("%d %d", &n, &m);
    
    long result = 0;
    for (int i = 0; i <= m; i++) result += factorial[n] / (factorial[i] * factorial[n-i]);
    printf("%d\n", result);

    return 0;
}