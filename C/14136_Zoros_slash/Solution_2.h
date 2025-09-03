#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(char* string, char* pattern, int* splittedStrings) {
    char** stringArr;
    int stringLen = strlen(string);
    int patternLen = strlen(pattern);

    stringArr = (char**)malloc((stringLen / 2 + 1) * sizeof(char*));

    int idx = 0, start = 0, id = 0;
    while (idx < stringLen) {
        if (idx + patternLen >= stringLen) {
            if (strcmp(&string[idx], pattern) == 0) break;
            stringArr[id] = (char*)malloc((idx - start + 2) * sizeof(char));
            strcpy(&stringArr[id][0], &string[start]);
            id++;
            break;
        }

        char temp = string[idx + patternLen];
        string[idx + patternLen] = '\0';
        if (strcmp(&string[idx], pattern) == 0) {
            if (idx != start) {
                char temp2 = string[idx];
                string[idx] = '\0';
                stringArr[id] = (char*)malloc((idx - start + 2) * sizeof(char));
                strcpy(&stringArr[id][0], &string[start]);
                id++;

                string[idx] = temp2;
            }
            string[idx + patternLen] = temp;
            idx += patternLen;
            start = idx;
        }
        else {
            string[idx + patternLen] = temp;
            idx++;
        }

    }
    *splittedStrings = id;
    return stringArr;
}

void free_(char** result, int splittedStrings) {
    for (int i = 0;i < splittedStrings;i++) free(result[i]);
    free(result);
}