char alphabet[65];
//implement split string function, return 2d char array to store result, set correct number of splitted strings
char **split(char* string, char* pattern, int* splittedStrings);
//free memory space
void free_(char **result, int splittedStrings);
//sort each splitted string
void sort( char* string);