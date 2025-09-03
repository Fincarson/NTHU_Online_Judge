#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alphabet[65];
//implement split string function, return 2d char array to store result, set correct number of splitted strings
char **split(char* string, char* pattern, int* splittedStrings){
    int sizeString = strlen(string), sizePattern = strlen(pattern);

    for(int i = 0; i < sizeString; i++){
        if(string[i] == pattern[0]){
            int validDelete = 0;
            for(int j = 0; j < sizePattern && j+i < sizeString; j++){
                if(string[i+j] != pattern[j]) break;
                if(j == sizePattern-1) validDelete = 1;
            }
            if(validDelete){
                for(int j = i; j < sizePattern + i; j++){
                    string[j] = '0';
                }
            }
        }
    }

    int maxIndex = sizeString/2 + 1;
    int *INDEX = (int*)malloc(maxIndex*sizeof(int));
    int orderIndex = 0;
    for(int i = 0; i < sizeString; i++){
        if(string[i] != '0'){
            (*splittedStrings)++;
            INDEX[orderIndex++] = i;
            while(string[i+1] != '0' && (i + 1) < sizeString) i++;
        }
    }

    for(int i = 0; i < sizeString; i++){
        if(string[i] == '0') string[i] = '\0';
    }

    char**result = (char**)malloc((*splittedStrings)*sizeof(char*));
    for(int i = 0; i < (*splittedStrings); i++){
        result[i] = (int*)malloc(strlen(&string[INDEX[i]]));
        strcpy(result[i], &string[INDEX[i]]);
    }

    free(INDEX);
    return result;
}
//free memory space
void free_(char **result, int splittedStrings){
        for(int i = 0; i < splittedStrings; i++){
        free(result[i]);
    }
    free(result);
}


//sort each splitted string
void sort(char* string){
    int sizeString = strlen(string);
    int freq[128] = {0};

    for(int i = 0; i < sizeString; i++){
        freq[(int)string[i]]++;
    }

    for(int f = sizeString; f > 0; f--){

        //Uppercase
        for(int c = 'A'; c <= 'Z'; c++){
            if(freq[c] == f){
                for(int i = 0; i < f; i++) printf("%c", c);
            }
        }

        //Lowercase
        for(int c = 'a'; c <= 'z'; c++){
            if(freq[c] == f){
                for(int i = 0; i < f; i++) printf("%c", c);
            }
        }

        //Digit
        for(int c = '0'; c <= '9'; c++){
            if(freq[c] == f){
                for(int i = 0; i < f; i++) printf("%c", c);
            }
        }
    }
    printf("\n");
}