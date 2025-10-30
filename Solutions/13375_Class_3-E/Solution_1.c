#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[200001][105];
int cmp(const void* a, const void* b)
{
    const char* ia = (const char*)a;
    const char* ib = (const char*)b;
    return strcmp(ia, ib);
}

int main()
{
    int i = 0;
    while (scanf("%s", string[i]) != EOF) {
        if (string[i][0] == '0')break;
        i++;
    }
    qsort(string, i, sizeof(string[0]), cmp);
    for (int j = 0; j < i; j++) {
        printf("%s\n", string[j]);
    }
}