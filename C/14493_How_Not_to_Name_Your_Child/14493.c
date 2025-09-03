#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

// ================================================================[GLOBAL VARIABLES]================================================================

char buff[1000];
char **names;
int capacity = 8;
int name_count = 0;

void HandleAdd();
void HandleQuery();

// ====================================================================[CRITERIA]====================================================================

int compareByAlphabeticalSum(const char*, const char*);         // higher sum first
int compareByConciseness(const char*, const char*);             // shorter name first
int compareByEnglishOrder(const char*, const char*);            // a -> z
int compareByLength(const char*, const char*);                  // longer name first
int compareByQwerty(const char*, const char*);                  // q w e r t y ...
int compareByReverseEnglishOrder(const char*, const char*);     // z -> a
int compareByScrabbleScore(const char*, const char*);           // higher sum first
int compareByZhuyin(const char*, const char*);                  // bo po mo fo ...

// ======================================================================[MAIN]======================================================================

int main() {
    names = (char**)malloc(capacity * sizeof(char*));
    while(1) {
        scanf("%s", buff);
        if(buff[0] == 'A') {            //Add
            HandleAdd();
        } else if (buff[0] == 'Q') {    //Query
            HandleQuery();
        } else if (buff[0] == 'E') {    //Exit
            break;
        }
    }

    for(int i = 0; i < name_count; i++)
        free(names[i]);
    free(names);
}

// =====================================================================[OPTION]=====================================================================

void HandleAdd() {
    if (name_count == capacity - 1) {
        capacity *= 2;
        names = reallocate_name_list(names, name_count, capacity);
    }

    scanf(" %[^\n]", buff);
    names[name_count] = (char*)malloc((strlen(buff) + 1) * sizeof(char));
    strcpy(names[name_count++], buff);
}

void HandleQuery() {
    int (*comparing_function)(const char*, const char*) = NULL;
    scanf(" %s", buff);
    switch(buff[0]) {
        case 'A': comparing_function = compareByAlphabeticalSum;    break;
        case 'B': comparing_function = compareByBackwardsString;    break;
        case 'C': comparing_function = compareByConciseness;        break;
        case 'D': comparing_function = compareByDictionary;         break;
        case 'E': comparing_function = compareByEnglishOrder;       break;
        case 'L': comparing_function = compareByLength;             break;
        case 'Q': comparing_function = compareByQwerty;             break;
        case 'R': comparing_function = compareByReverseEnglishOrder;break;
        case 'S': comparing_function = compareByScrabbleScore;      break;
        case 'Z': comparing_function = compareByZhuyin;             break;
        default:  comparing_function = NULL;
    }

    if(comparing_function == NULL) {
        printf("ERROR: INVALID COMPARING FUNCTION\n");
        return;
    }

    char *best_name = choose_best_name(names, name_count, comparing_function);
    printf("%s\n", (best_name != NULL)? best_name: "ERROR: NO BEST NAME");
}

// =================================================== THE IMPLEMENTATION OF COMPARISON FUNCTIONS ===================================================
// ===================================================  YOU DON'T HAVE TO UNDERSTAND ALL OF THEM  ===================================================

int exampleComparingFunction_compareByJustFirstLetter(const char* str1, const char* str2) {
    if(str1[0] > str2[0])   //EXAMPLE:          'B'ANANA VS 'A'PPLE
        return 10;          //POSITIVE VALUE:   "BANANA" COMES AFTER "APPLE"
    if(str1[0] > str2[0])   //EXAMPLE:          'A'PPLE VS 'B'ANANA
        return -156;        //NEGATIVE VALUE:   "APPLE" COMES BEFORE "BANANA"
    return 0;               //EXAMPLE:          'B'ANANA VS 'B'LUEBERRY
}

int alphabeticalSum(const char* str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            sum += str[i] - 'A' + 1;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            sum += str[i] - 'a' + 1;
        }
    }
    return sum;
}

int compareByAlphabeticalSum(const char* str1, const char* str2) {
    return alphabeticalSum(str2) - alphabeticalSum(str1);
}

int compareByConciseness(const char* str1, const char* str2) {
    return strlen(str1) - strlen(str2);
}

int compareByEnglishOrder(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

int compareByLength(const char* str1, const char* str2) {
    return strlen(str2) - strlen(str1);
}

int qwertyValue(char c) {
    const int order[] = {11, 24, 22, 13, 3, 14, 15, 16, 8, 17, 18, 19, 26, 25, 9, 10, 1, 4, 12, 5, 7, 23, 2, 21, 6, 20};
    return (c == '\0')? 0: (c == '\'')? 1: ('A' <= c && c <= 'Z')? 1 + order[c - 'A']: 1 + 26 + order[c - 'a'];
}

int compareByQwerty(const char* str1, const char* str2) {
    int i;
    for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if(toupper(str1[i]) == toupper(str2[i])) continue;
        return qwertyValue(str1[i]) - qwertyValue(str2[i]);
    }
    return str1[i] - str2[i];
}

int compareByReverseEnglishOrder(const char* str1, const char* str2) {
    return strcmp(str2, str1);
}

int scrabbleScore(const char* str) {
    int score = 0;
    const int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0; str[i] != '\0'; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            score += scores[str[i] - 'A'];
        } else if ('a' <= str[i] && str[i] <= 'z') {
            score += scores[str[i] - 'a'];
        }
    }
    return score;
}

int compareByScrabbleScore(const char* str1, const char* str2) {
    return scrabbleScore(str2) - scrabbleScore(str1);
}

// DEAR STUDENTS: YOU SHOULDN'T BE WRITING CODE LIKE THIS.

#define tu toupper

char vwl(char C) {
    C = tu(C); return C == 'A' || C == 'E' || C == 'I' || C == 'O' || C == 'U' || C == 'V';
}

int syllableOrder(const char* str, int *ptr) {int ans = 0, i = *ptr; switch(tu(str[i])) {
    case 'B': ans = 0x0000; break; case 'P': ans = 0x0100; break; case 'M': ans = 0x0200; break; case 'F': ans = 0x0300; break;
    case 'D': ans = 0x0400; break; case 'T': ans = 0x0500; break; case 'N': ans = 0x0600; break; case 'L': ans = 0x0700; break;
    case 'G': ans = 0x0800; break; case 'K': ans = 0x0900; break; case 'H': ans = 0x0a00; break;
    case 'J': ans = 0x0b40; break; case 'Q': ans = 0x0c40; break; case 'X': ans = 0x0d40; break;
    case 'Z': ans = 0x0e00; if(tu(str[i+1]) != 'H') ans += 0x0400; else i++; break;
    case 'C': ans = 0x0f00; if(tu(str[i+1]) != 'H') ans += 0x0400; else i++; break;
    case 'S': ans = 0x1000; if(tu(str[i+1]) != 'H') ans += 0x0400; else i++; break;
    case 'R': ans = 0x1100; break; case 'A': case 'O': case 'E': ans = 0x1500; i--; break;
    case 'Y': ans = 0x1540; break; case 'W': ans = 0x1580; break; case'\'': ans = 0x1500; break;
    default: return 0xffff;} i++;

    switch(tu(str[i])){case 'I': i++; if (ans >= 0x0e00 && ans <= 0x1400) {*ptr = i; return ans;} ans |= 0x0040; break; case 'U': ans |= 0x0080, i++; break;
    case 'V': ans |= 0x00c0, i++; break;} if(strncasecmp(str + i, "ONG", 3) == 0) ans |= 0x0080, i++;switch (tu(str[i])) {case 'A': ans |= 1, i++; break;case
    'O': ans |= 2, i++; break; case 'E': ans |= 3, i++; break; case 'I': ans |= 3; break; case 'U': ans |= 2; break; case 'N': if(!vwl(str[i+1])) ans |= 3;
    break;} switch (tu(str[i])) {case 'I': ans |= 4, i++; break;case 'U':case 'O': ans |= 8, i++; break; case 'R': if(!vwl(str[i+1])) ans |= 20, i++; break;
    case 'N': if(vwl(str[i+1])) break; i++;if(tu(str[i]) != 'G' || vwl(str[i+1])) ans |= 12;else ans |= 16, i++;} *ptr = i; return ans;
}
#undef tu

int compareByZhuyin(const char *str1, const char *str2) {
    int x = 0, y = 0;
    while(str1[x] != '\0' && str2[y] != '\0') {
        int compareResult = syllableOrder(str1, &x) - syllableOrder(str2, &y);
        if(compareResult != 0) return compareResult;
        if(isspace(str1[x]) && !isspace(str2[y])) return -1;
        if(!isspace(str1[x]) && isspace(str2[y])) return 1;
        while(isspace(str1[x])) x++;
        while(isspace(str2[y])) y++;
    }
    return str1[x] - str2[y];
}