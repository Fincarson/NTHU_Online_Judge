#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//implement split string function, return 2d char array to store result, set correct number of splitted strings
char **split(char* string, char* pattern, int* splittedStrings){
    int sizeString = strlen(string);
    int sizePattern = strlen(pattern);
    //Determine the length of the string

    //Start separating
    for(int i = 0; i < sizeString; i++){
        if(string[i] == pattern[0]){
            int validDelete = 0;
            for(int j = 0; j < sizePattern && i+j < sizeString; j++){
                if(string[i+j] != pattern[j]) break;
                if(j == sizePattern-1) validDelete = 1;
            }if(validDelete){
                for(int j = i; j < sizePattern+i; j++){
                    string[j] = '0';
                }
            }
        }
    }


    
    int maxIndex = sizeString/2+1;
    int*INDEX = (int*)malloc(maxIndex * sizeof(int));
    //Create a temporary index to POINT the first leter of each splitted string(s)
    /*
    EXAMPLE:
    I
    am
    luffy

    it will create 3 memory and each memory will point to
    'I' in I
    'a' in am
    'l' in luffy
    */
    int orderIndex = 0;
    for(int i = 0; i < sizeString; i++){
        if(string[i] != '0'){
            INDEX[orderIndex++] = i;
            (*splittedStrings)++;//Count how many splitted string
            while(string[i+1] != '0' && (i+1) < sizeString) i++;
        }
    }

    
    //Replacing the '0' with '\0'
    for(int i = 0; i < sizeString; i++){
        if(string[i] == '0') string[i] = '\0';
    }



    char**result = (char**)malloc((*splittedStrings)*sizeof(char*));
    //Create new memory to place the splitted string(s)

    //Putting the splitted string(s) into the result
    for(int i = 0; i < (*splittedStrings); i++){
        result[i] = (char*)malloc(strlen(&string[INDEX[i]]));
        strcpy(result[i], &string[INDEX[i]]);
    }

    //Free the INDEX memory and returning the splitted string(s)
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