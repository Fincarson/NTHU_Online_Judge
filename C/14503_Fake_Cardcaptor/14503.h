#include <stdio.h>
#include <stdlib.h>

extern const int MAX_ARRAY;
extern const int MAX_ELEMENT;

typedef void (*myFunction)(int **, int *);

void placeFunction(int ** arr, int * size);
void deleteFunction(int ** arr, int * size);
void swapFunction(int ** arr, int * size);
void reverseFunction(int ** arr, int * size);
void popFunction(int ** arr, int * size);
void shiftFunction(int ** arr, int * size);
void sortFunction(int ** arr, int * size);
void printFunction(int ** arr, int * size);

myFunction assignFunction(char * str);