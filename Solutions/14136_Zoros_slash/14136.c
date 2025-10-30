#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
char **split(char* string, char* pattern, int* splittedStrings);
void free_(char **result, int splitsplittedStrings_num);

int main(){
    char pattern[10];
    char string[500];
    scanf("%s",string);
    scanf("%s",pattern);
    int splittedStrings = 0;
    char **result = split(string, pattern, &splittedStrings);
    for(int i=0; i<splittedStrings; ++i){
        printf("%s\n",result[i]);
    }
    free_(result, splittedStrings);
    return 0;
}