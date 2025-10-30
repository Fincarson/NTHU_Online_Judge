#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main(){
    char pattern[10];
    char string[500];

    scanf("%s",string);
    scanf("%s",pattern);
    int splittedStrings = 0;
    char **result = split(string, pattern, &splittedStrings);
    for( int i = 0 ; i < 26 ; i++ ) alphabet[i] = (char)('A' + i);
    for( int i = 26 ; i < 52 ; i++ ) alphabet[i] = (char)('a' + i - 26 );
    for( int i = 52 ; i < 62 ; i++ ) alphabet[i] = (char)('0' + i - 52 );

    for(int i=0; i<splittedStrings; ++i){
        sort(result[i]);
        // printf("%s\n",result[i]);
    }
    free_(result, splittedStrings);
    return 0;
}